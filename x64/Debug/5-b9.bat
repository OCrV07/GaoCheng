@echo off
get_input_data.exe 5-b9-sudoku.txt 5-b9-1 | 5-b9-Êý¶ÀÅÐ¶Ï.exe > 5-b9-1.out
get_input_data.exe 5-b9-sudoku.txt 5-b9-1 | 5-b9-demo.exe > 5-b9-1.std.out
txt_compare.exe --file1 5-b9-1.out --file2 5-b9-1.std.out --trim right --display detailed

get_input_data.exe 5-b9-sudoku.txt 5-b9-2 | 5-b9-Êý¶ÀÅÐ¶Ï.exe > 5-b9-2.out
get_input_data.exe 5-b9-sudoku.txt 5-b9-2 | 5-b9-demo.exe > 5-b9-2.std.out
txt_compare.exe --file1 5-b9-2.out --file2 5-b9-2.std.out --trim right --display detailed