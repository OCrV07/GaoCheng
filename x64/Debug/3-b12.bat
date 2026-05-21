@echo off
get_input_data.exe 3-b12.in.dat 3-b12-1 | 3-b12-1-C++½â¾öcinÊäÈëint´íÎó.exe > 3-b12-1.out
get_input_data.exe 3-b12.in.dat 3-b12-1 | 3-b12-C++.exe > 3-b12-1.std.out
txt_compare --file1 3-b12-1.out --file2 3-b12-1.std.out --trim right --display detailed