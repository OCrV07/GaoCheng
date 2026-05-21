@echo off
get_input_data.exe 4-b12.dat 4-b12-1 | 4-b12-汉诺塔-基本移动.exe > 4-b12-1.out
get_input_data.exe 4-b12.dat 4-b12-1 | 4-b12-demo-new.exe > 4-b12-1.std.out
txt_compare --file1 4-b12-1.out --file2 4-b12-1.std.out --trim right --display detailed

get_input_data.exe 4-b12.dat 4-b12-2 | 4-b12-汉诺塔-基本移动.exe > 4-b12-2.out
get_input_data.exe 4-b12.dat 4-b12-2 | 4-b12-demo-new.exe > 4-b12-2.std.out
txt_compare --file1 4-b12-2.out --file2 4-b12-2.std.out --trim right --display detailed

get_input_data.exe 4-b12.dat 4-b12-3 | 4-b12-汉诺塔-基本移动.exe > 4-b12-3.out
get_input_data.exe 4-b12.dat 4-b12-3 | 4-b12-demo-new.exe > 4-b12-3.std.out
txt_compare --file1 4-b12-3.out --file2 4-b12-3.std.out --trim right --display detailed

get_input_data.exe 4-b12.dat 4-b12-4 | 4-b12-汉诺塔-基本移动.exe > 4-b12-4.out
get_input_data.exe 4-b12.dat 4-b12-4 | 4-b12-demo-new.exe > 4-b12-4.std.out
txt_compare --file1 4-b12-4.out --file2 4-b12-4.std.out --trim right --display detailed