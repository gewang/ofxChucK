# ofxChucK
Design and Development of the ChucK addon to OpenFrameworks.  This allows
ChucK code to run "natively" in OpenFrameworks app -- with bindings 
that allow communication and data sharing between ChucK and OpenFrameworks.



## Steps to make a project with ofxChucK work in OF 0.8.4:

1. Use the project generator, select the `ofxChucK` addon (and any others you want).
2. Go to `Build Rules`, click `+` and make it `Process: Lex source files` `Using: Lex`.
3. Go to `Build Rules`, click `+` and make it `Process: Yacc source files` `Using: Yacc`.
4. Go to `Build Settings` > `Yacc - Build Options` > `Generated File Stem`. Change to `Input File Stem`
5. In `Build Phases` > `Comple Sources`, add the flag `-DHAVE_CONFIG_H` to all files from `libs/lo`. Also add `chuck.lex` and `chuck.y` to the project. Delete `chuck_main.cpp` and `chuck_win32.c/h`.
6. Go to the `chuck.lex file` -- on the top right, check `Identity and Type` -- make sure Type is `Lex Source`.
7. Go to `Build Settings` > `Apple LLVM 7.0 - Custom Compiler Flags` > `Other C Flags`. Add: `-D__MACOSX_CORE__`
8. Add the following to the `System Frameworks` ( or `General` > `Linked Frameworks and Libraries`): `MultitouchSupport.framework`, `CoreMidi.framework`



## Steps to get ofxChucK compiling on Windows with CodeBlocks:

1. Use the CodeBlocks template in example_Windows to get started ASAP. Otherwise, see below for manual steps.
2. Add the ofxChucK add-on to your project with the Project Generator.
3. In CodeBlocks, go to [Project] > Build Options > Compiler Settings > #defines, and paste in (on separate lines) `__WINDOWS_DS__`, `__PLATFORM_WIN32__`, and `HAVE_CONFIG_H`.
4. Then go to [Project] > Build Options > Linker Settings > Add, and add the libraries `dinput` and `dsound`.
5. Hit build and hope for the best.
