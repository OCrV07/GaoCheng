@echo off
get_input_data.exe 5-b3.dat 5-b3-1 | 5-b3-输入日期求天数.exe > 5-b3-1.out
get_input_data.exe 5-b3.dat 5-b3-1 | 5-b3-demo.exe > 5-b3-1.std.out
txt_compare.exe --file1 5-b3-1.out --file2 5-b3-1.std.out --trim right --display detailed

get_input_data.exe 5-b3.dat 5-b3-2 | 5-b3-输入日期求天数.exe > 5-b3-2.out
get_input_data.exe 5-b3.dat 5-b3-2 | 5-b3-demo.exe > 5-b3-2.std.out
txt_compare.exe --file1 5-b3-2.out --file2 5-b3-2.std.out --trim right --display detailed

get_input_data.exe 5-b3.dat 5-b3-3 | 5-b3-输入日期求天数.exe > 5-b3-3.out
get_input_data.exe 5-b3.dat 5-b3-3 | 5-b3-demo.exe > 5-b3-3.std.out
txt_compare.exe --file1 5-b3-3.out --file2 5-b3-3.std.out --trim right --display detailed

get_input_data.exe 5-b3.dat 5-b3-4 | 5-b3-输入日期求天数.exe > 5-b3-4.out
get_input_data.exe 5-b3.dat 5-b3-4 | 5-b3-demo.exe > 5-b3-4.std.out
txt_compare.exe --file1 5-b3-4.out --file2 5-b3-4.std.out --trim right --display detailed
