:KODOVANI 852 !!!
:P��li� �lu�ou�k� k�� �p�l Ԡbelsk� � - P��LI� �LU�OU�K� K�� �P�L ҵBELSK� �
@echo off
echo ###########################################################################
echo ###                                                                     ###
echo ###        Opravdu smazat vsechny p�elo�en� soubory Pythonu?            ###
echo ###                                                                     ###
echo ###########################################################################
echo 
echo 
echo on
pause

@prompt $g$s

@echo off
echo 
echo Chyst�m se mazat slo�ky __pycache__
for /R /D %%i in (__pycache__) do (
    if EXIST %%i (
        rd /S /Q "%%i"
        @echo SMAZANO: %%i
REM Kdybych chtel pri neuspechu jeste neco delat, vlozim sem:    
REM     ) else (
REM     nasledovane definici akce, ktera by se mela provadet
    )
)
echo Chyst�m se mazat p��padn� zbyl� p�elo�en� soubory
del /s *.pyc

@echo off
echo 
echo 
echo ###########################################################################
echo ###                                                                     ###
echo ###                               KONEC
echo ###                                                                     ###
echo ###########################################################################
echo 
echo 
pause 
