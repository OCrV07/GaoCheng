@echo off
get_input_data.exe 5-b10.dat 5-b10-1 | 5-b10-打印年历.exe > 5-b10-1.out
get_input_data.exe 5-b10.dat 5-b10-1 | 5-b10-demo.exe > 5-b10-1.std.out
txt_compare.exe --file1 5-b10-1.out --file2 5-b10-1.std.out --trim right --display detailed

get_input_data.exe 5-b10.dat 5-b10-2 | 5-b10-打印年历.exe > 5-b10-2.out
get_input_data.exe 5-b10.dat 5-b10-2 | 5-b10-demo.exe > 5-b10-2.std.out
txt_compare.exe --file1 5-b10-2.out --file2 5-b10-2.std.out --trim right --display detailed

get_input_data.exe 5-b10.dat 5-b10-3 | 5-b10-打印年历.exe > 5-b10-3.out
get_input_data.exe 5-b10.dat 5-b10-3 | 5-b10-demo.exe > 5-b10-3.std.out
txt_compare.exe --file1 5-b10-3.out --file2 5-b10-3.std.out --trim right --display detailed