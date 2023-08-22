@echo off
title Compiler SMA = AMXX
cls && color 08

for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do rem"') do (
  set "DEL=%%a"
)


set compiler=D:\SteamLibrary\steamapps\common\Half-Life\cstrike\addons\amxmodx\scripting\amxxpc.exe
if not exist "%compiler%" ( echo The %compiler% compiler does not exist & goto EXIT_COMPILE )

set include=D:\SteamLibrary\steamapps\common\Half-Life\cstrike\addons\amxmodx\scripting\include
if not exist "%include%" ( echo The %include% folder does not exist & goto EXIT_COMPILE )


rem OLD = set output=.\
set output=D:\SteamLibrary\steamapps\common\Half-Life\cstrike\addons\amxmodx\plugins\

if exist logs.log del logs.log
if "%output%" == ".\" (
	goto __COMPILACTION
) else (
	if not exist "%output%" (
		( mkdir "%output%" && echo The %output% folder has been created ) || ( echo The %output% folder could not be created & goto EXIT_COMPILE )
	)
)

:__COMPILACTION

if %1X==X (
	goto __COMPILACTION_ALL
) else (
	goto __COMPILACTION_FILE
)

:__COMPILACTION_ALL


<nul set /p="("
call :c_text 06 "I start compiling files .sma"   && <nul set /p=" )  "
echo.


rem Przeszukanie całego aktualnego folderu (skąd został uruchomiony skrypt) oraz kompilacja
for %%f in (*.sma) do (
echo ========================= File: %%f ========================= >> logs.log
echo. >> logs.log
"%compiler%" -i"%include%" -i"include" -o"%output%%%f" "%%f" >> logs.log
echo. >> logs.log
echo ========================================================================== >> logs.log

<nul set /p="("
call :c_text 0a "Compiled '%%f' file"   && <nul set /p=" )  "
echo.)

goto __COMPILACTION_END

:__COMPILACTION_FILE

set plik=%1
for /f "useback tokens=*" %%a in ('%file_sma%') do set file_sma=%%~a

echo compilation of the %file_sma% file
echo ****** File: %file_sma% ****** >> logs.log
"%compiler%" -i"%include%" -i"include" -o"%file_sma:~0,-3%amxx" "%file_sma%" >> logs.log

:__COMPILACTION_END

echo.
more .\logs.log
echo.

<nul set /p="("
call :c_text 04 "Compilation End"   && <nul set /p=" )  "
echo.


:EXIT_COMPILE

echo.
pause

:c_text
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1
goto :eof
