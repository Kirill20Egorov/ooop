SET MyProgram="%~1"

%MyProgram% 1010 > "%TEMP%\output.txt" || goto err2
fc out1.txt "%TEMP%\output.txt" > nul || goto err
echo Test 1/3 completed 

%MyProgram% 0 > "%TEMP%\output.txt" || goto err2
fc out2.txt "%TEMP%\output.txt" > nul || goto err
echo Test 2/3 completed 

%MyProgram% 12 > "%TEMP%\output.txt" || goto err2
fc out3.txt "%TEMP%\output.txt" || goto err
echo Test 3/3 completed 

echo All tests completed successfully
exit /B 0

:err2
echo Error
exit /B 0

:err
echo Test failed
exit /B 0

