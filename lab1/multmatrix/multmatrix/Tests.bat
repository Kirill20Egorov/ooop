SET MyProgram="%~1"

%MyProgram% matrix1.txt matrix3.txt > "%TEMP%\output.txt" || goto err
fc out3.txt "%TEMP%\output.txt" || goto err
echo Test 1/4 completed 

%MyProgram% missingfile.txt C++ > "%TEMP%\output.txt" && goto err
echo Test 2/4 completed 


echo All Tests passed successfully
exit /B 0

:err2
echo Error
exit /B 0

:err
echo Test failed
exit /B 0

