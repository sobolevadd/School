:KODOVANI 852 !!!
:P˝°liÁ ßluúouükÏ kÖÂ £pÿl ‘†belskÇ ¢ - P¸÷LIÊ ¶LUõOU¨KÌ Kﬁ’ ÈP∑L “µBELSKê ‡
@echo off
echo ###########################################################################
echo ###                                                                     ###
echo ###        Opravdu smazat vsechny p˝eloßenÇ soubory Pythonu?            ###
echo ###                                                                     ###
echo ###########################################################################
echo 
echo 
echo on
pause

@prompt $g$s

@echo off
echo 
echo Chyst†m se mazat sloßky __pycache__
for /R /D %%i in (__pycache__) do (
    if EXIST %%i (
        rd /S /Q "%%i"
        @echo SMAZANO: %%i
REM Kdybych chtel pri neuspechu jeste neco delat, vlozim sem:    
REM     ) else (
REM     nasledovane definici akce, ktera by se mela provadet
    )
)
echo Chyst†m se mazat p˝°padnÇ zbylÇ p˝eloßenÇ soubory
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
