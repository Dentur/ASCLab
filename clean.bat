@echo off
for %%i in (*.l) do (
    echo "Delete %%i files..."
	IF EXIST "%%~ni.c" (
		del "%%~ni.c"
	)
	IF EXIST "%%~ni.h" (
		del "%%~ni.h"
	)
	IF EXIST "%%~ni.v" (
		del "%%~ni.v"
	)
)
for %%i in (*.y) do (
	echo "Delete %%i files..."
	IF EXIST "%%~ni.c" (
		del "%%~ni.c"
	)
	IF EXIST "%%~ni.h" (
		del "%%~ni.h"
	)
	IF EXIST "%%~ni.v" (
		del "%%~ni.v"
	)
)
for %%i in (*.exe) do (
	echo "Delete %%i..."
	del "%%i"
)
echo "Delete lex.yy.c..."
IF EXIST "lex.yy.c" (
	del "lex.yy.c"
)
echo "Delete myparser.tab.c..."
IF EXIST "myparser.tab.c" (
	del "myparser.tab.c"
)
