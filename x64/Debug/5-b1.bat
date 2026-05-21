@echo off
get_input_data.exe 5-b1.dat 5-b1-1 | 5-b1-有序数组中插入数据后仍保持有序.exe > 5-b1-1.out
get_input_data.exe 5-b1.dat 5-b1-1 | 5-b1-demo.exe > 5-b1-1.std.out
txt_compare.exe --file1 5-b1-1.out --file2 5-b1-1.std.out --trim right --display detailed

get_input_data.exe 5-b1.dat 5-b1-2 | 5-b1-有序数组中插入数据后仍保持有序.exe > 5-b1-2.out
get_input_data.exe 5-b1.dat 5-b1-2 | 5-b1-demo.exe > 5-b1-2.std.out
txt_compare.exe --file1 5-b1-2.out --file2 5-b1-2.std.out --trim right --display detailed


get_input_data.exe 5-b1.dat 5-b1-3 | 5-b1-有序数组中插入数据后仍保持有序.exe > 5-b1-3.out
get_input_data.exe 5-b1.dat 5-b1-3 | 5-b1-demo.exe > 5-b1-3.std.out
txt_compare.exe --file1 5-b1-3.out --file2 5-b1-3.std.out --trim right --display detailed

