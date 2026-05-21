@echo off
get_input_data.exe 5-b6.dat 5-b6-1 | "5-b6-2-汉诺塔-每步详细(横向)-1个一维+1个二维.exe" > 5-b6-2-1.out
get_input_data.exe 5-b6.dat 5-b6-1 | 5-b6-demo.exe > 5-b6-2-1.std.out
txt_compare.exe --file1 5-b6-2-1.out --file2 5-b6-2-1.std.out --trim right --display detailed

get_input_data.exe 5-b6.dat 5-b6-2 | "5-b6-2-汉诺塔-每步详细(横向)-1个一维+1个二维.exe" > 5-b6-2-2.out
get_input_data.exe 5-b6.dat 5-b6-2 | 5-b6-demo.exe > 5-b6-2-2.std.out
txt_compare.exe --file1 5-b6-2-2.out --file2 5-b6-2-2.std.out --trim right --display detailed


get_input_data.exe 5-b6.dat 5-b6-3 | "5-b6-2-汉诺塔-每步详细(横向)-1个一维+1个二维.exe" > 5-b6-2-3.out
get_input_data.exe 5-b6.dat 5-b6-3 | 5-b6-demo.exe > 5-b6-2-3.std.out
txt_compare.exe --file1 5-b6-2-3.out --file2 5-b6-2-3.std.out --trim right --display detailed


get_input_data.exe 5-b6.dat 5-b6-4 | "5-b6-2-汉诺塔-每步详细(横向)-1个一维+1个二维.exe" > 5-b6-2-4.out
get_input_data.exe 5-b6.dat 5-b6-4 | 5-b6-demo.exe > 5-b6-2-4.std.out
txt_compare.exe --file1 5-b6-2-4.out --file2 5-b6-2-4.std.out --trim right --display detailed

