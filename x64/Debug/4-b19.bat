@echo off
get_input_data.exe 4-b18.dat 4-b18-1 | 4-b19-min带缺省参数.exe > 4-b19-1.out
get_input_data.exe 4-b18.dat 4-b18-1 | 4-b19-demo.exe > 4-b19-1.std.out
txt_compare.exe --file1 4-b19-1.out --file2 4-b19-1.std.out --trim right --display detailed

get_input_data.exe 4-b18.dat 4-b18-2 | 4-b19-min带缺省参数.exe > 4-b19-2.out
get_input_data.exe 4-b18.dat 4-b18-2 | 4-b19-demo.exe > 4-b19-2.std.out
txt_compare.exe --file1 4-b19-2.out --file2 4-b19-2.std.out --trim right --display detailed


get_input_data.exe 4-b18.dat 4-b18-3 | 4-b19-min带缺省参数.exe > 4-b19-3.out
get_input_data.exe 4-b18.dat 4-b18-3 | 4-b19-demo.exe > 4-b19-3.std.out
txt_compare.exe --file1 4-b19-3.out --file2 4-b19-3.std.out --trim right --display detailed

