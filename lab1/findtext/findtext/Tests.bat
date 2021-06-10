SET MyProgram="%~1"

%MyProgram% input.txt Hello > "%TEMP%\output.txt" || goto err
fc out.txt "%TEMP%\output.txt" || goto err
echo Test 1/4 completed 

%MyProgram% missingfile.txt C++ > "%TEMP%\output.txt" && goto err
echo Test 2/4 completed 

%MyProgram% input.txt C++ > "%TEMP%\output.txt" || goto err
fc out2.txt "%TEMP%\output.txt" || goto err
echo Test 3/4 completed 

%MyProgram% input.txt f++ > "%TEMP%\output.txt" 
fc notfound.txt "%TEMP%\output.txt" || goto err2
echo Test 4/4 completed 

echo All Tests passed successfully
exit /B 0

:err2
echo Error
exit /B 0

:err
echo Test failed
exit /B 0

