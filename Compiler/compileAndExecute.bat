@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x64     
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:program.exe
set addFlags=/subsystem:windows /entry:mainCRTStartup
cl.exe %compilerflags% program.cpp Labyrinth.cpp /link %linkerflags%
program.exe
del program.exe
del program.obj
del program.ilk
del program.pdb
del Labyrinth.obj
del vc120.pdb