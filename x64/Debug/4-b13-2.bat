@echo off
get_input_data.exe 4-b13.dat 4-b13-1 | 4-b13-2-汉诺塔-步数记录-全局变量（C方式）.exe > 4-b13-1.out
get_input_data.exe 4-b13.dat 4-b13-1 | 4-b13-demo.exe > 4-b13-1.std.out
txt_compare.exe --file1 4-b13-1.out --file2 4-b13-1.std.out --trim right --display detailed

get_input_data.exe 4-b13.dat 4-b13-2 | 4-b13-2-汉诺塔-步数记录-全局变量（C方式）.exe > 4-b13-2.out
get_input_data.exe 4-b13.dat 4-b13-2 | 4-b13-demo.exe > 4-b13-2.std.out
txt_compare.exe --file1 4-b13-2.out --file2 4-b13-2.std.out --trim right --display detailed

get_input_data.exe 4-b13.dat 4-b13-3 | 4-b13-2-汉诺塔-步数记录-全局变量（C方式）.exe > 4-b13-3.out
get_input_data.exe 4-b13.dat 4-b13-3 | 4-b13-demo.exe > 4-b13-3.std.out
txt_compare.exe --file1 4-b13-3.out --file2 4-b13-3.std.out --trim right --display detailed

get_input_data.exe 4-b13.dat 4-b13-4 | 4-b13-2-汉诺塔-步数记录-全局变量（C方式）.exe > 4-b13-4.out
get_input_data.exe 4-b13.dat 4-b13-4 | 4-b13-demo.exe > 4-b13-4.std.out
txt_compare.exe --file1 4-b13-4.out --file2 4-b13-4.std.out --trim right --display detailed
