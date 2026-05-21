@echo off
get_input_data.exe 5-b8.dat 5-b8-1 | 5-b8-高精度幂计算.exe > 5-b8-1.out
get_input_data.exe 5-b8.dat 5-b8-1 | 5-b8-demo.exe > 5-b8-1.std.out
txt_compare.exe --file1 5-b8-1.out --file2 5-b8-1.std.out --trim right --display detailed

get_input_data.exe 5-b8.dat 5-b8-2 | 5-b8-高精度幂计算.exe > 5-b8-2.out
get_input_data.exe 5-b8.dat 5-b8-2 | 5-b8-demo.exe > 5-b8-2.std.out
txt_compare.exe --file1 5-b8-2.out --file2 5-b8-2.std.out --trim right --display detailed

get_input_data.exe 5-b8.dat 5-b8-3 | 5-b8-高精度幂计算.exe > 5-b8-3.out
get_input_data.exe 5-b8.dat 5-b8-3 | 5-b8-demo.exe > 5-b8-3.std.out
txt_compare.exe --file1 5-b8-3.out --file2 5-b8-3.std.out --trim right --display detailed

get_input_data.exe 5-b8.dat 5-b8-4 | 5-b8-高精度幂计算.exe > 5-b8-4.out
get_input_data.exe 5-b8.dat 5-b8-4 | 5-b8-demo.exe > 5-b8-4.std.out
txt_compare.exe --file1 5-b8-4.out --file2 5-b8-4.std.out --trim right --display detailed
