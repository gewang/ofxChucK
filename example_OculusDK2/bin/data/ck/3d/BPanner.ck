// title BPanner.ck
// A binaural panner using the mit kemar dataset
// 2016-02-04 kittyshi@ccrma
// Note: the hrtf data is loaded and stored in kemarhrtf.dat file
//       in order of set of elevations (-40,-30,-20,...,90)
//       For each set of elevation, Left and Right hrir for each aimuth is stored
// usage: yourSignal => Gain g => BPanner bp
//        500 => g.gain;   (0 - 1000 for gain)
//        bp.setPos(elevation, azimuth)    elevation: -40 to 90, azimuth: 0 - 360

public class BPanner extends Chubgraph{
    
    /* Load the hrtf file */
    /* This is suitable for the MIT kemar dataset ONLY (which was stored in allhrtf) */
    
    me.sourceDir() + "kemarhrtf.dat" => string filehrtf;
    512 => int NUM_IR_SAMPLE;   // # of sample for each hrir
    1420 => int numHRTF;        // 710 each ear
    numHRTF * NUM_IR_SAMPLE => int totalSamp; // 727040
    
    /* some parameters for the kemar dataset */
    // elevation
    [-40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90] @=> int elev[];
    // number of azimuth for each elevation
    [56, 60, 72, 72, 72, 72, 72, 60, 56, 45, 36, 24, 12, 1] @=> int num_azim[];
 
    // offset: the index to start the next set of elevation
    [0, 57344, 118784, 192512, 266240, 339968, 413696, 487424, 548864, 606208, 652288, 689152, 713728, 726016] @=> int offset[];
    
    
    // read in
    FileIO fio;
    fio.open( filehrtf, FileIO.READ );
    // ensure it's ok
    if( !fio.good() )
    {
        cherr <= "can't open file: " <= filehrtf <= " for reading..."
        <= IO.newline();
        me.exit();
    }
    

    // test array has the first pair of hrtf: L0e270a R0e270a
    float hrtfarray[totalSamp]; 
    float leftArray[NUM_IR_SAMPLE];
    float rightArray[NUM_IR_SAMPLE];
    
    // copy the hrtf data into the test array
    for (0 => int i;i < totalSamp; i++){
        Std.atof(fio.readLine()) => hrtfarray[i];
    }

    
    /* setup for the input and output */
    inlet => FFT fftx => blackhole;
    IFFT outy1  => dac.chan(0);            
    IFFT outy2  => dac.chan(1); 
    
    /* Prepare for convolution */
    NUM_IR_SAMPLE * 2 => int fftSize;
    FFT ffth1 =>blackhole;
    FFT ffth2 => blackhole;
    
    fftSize => ffth1.size => ffth2.size => fftx.size => outy1.size => outy2.size;
    complex H1[fftSize];   // for hrtf
    complex H2[fftSize];
    complex Z1[fftSize/2]; // for output
    complex Z2[fftSize/2];
    
    fftSize/2 => int windowSize;
    Windowing.hann(windowSize) => fftx.window;
    Windowing.hann(windowSize) => outy1.window;
    Windowing.hann(windowSize) => outy2.window;

    windowSize/4 => int hopSize;
    
    // Given elevation and azimuth, find the closest hrir (array offset)
    fun int getIdx(float el, float az){
        int elev_idx;
        if (el < -40){
            0 => elev_idx;
        }
        else if (el > 90){
            13 => elev_idx;
        }
        else{
            (el/10+4) $ int => elev_idx;
        }
        Math.floor(az / (360./num_azim[elev_idx])) $ int => int azim_idx;  //azimuth_incr[elev_idx]
        offset[elev_idx] + azim_idx * 2* NUM_IR_SAMPLE => int final_offset;
        return final_offset;
    }
    
    int _offst;
    
    fun void setPos(float elev, float azim){
        getIdx(elev,azim) => _offst;
         
    }
    
    fun void convHRTF(){
        
        while(true){
            
            /* copy to left and right array */
            for (0 => int i; i < NUM_IR_SAMPLE; i++){
                hrtfarray[_offst+i] => leftArray[i];
                hrtfarray[_offst+i+NUM_IR_SAMPLE] => rightArray[i];
            }  
            
            /* load the sound source */
            /* Do fft for the hrir */
            ffth1.transform(leftArray);
            ffth1.spectrum(H1);
            ffth2.transform(rightArray);
            ffth2.spectrum(H2);
            
            /* Do fft for the sound source */
            fftx.upchuck();
            
            for (0 => int i; i < fftSize/2; i++){
                fftx.cval(i) * H1[i] => Z1[i];
                fftx.cval(i) * H2[i] => Z2[i];
            }
            
            outy1.transform(Z1);
            outy2.transform(Z2);
            hopSize ::samp => now;
        }
        
    }
    
    // spork the mixing
    spork ~convHRTF();
}
