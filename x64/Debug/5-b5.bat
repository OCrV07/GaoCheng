@echo off
5-b5-含相同值的成绩排序.exe < 5-b4-1.dat > 5-b5-1.out
5-b5-demo.exe < 5-b4-1.dat > 5-b5-1.std.out
txt_compare.exe --file1 5-b5-1.out --file2 5-b5-1.std.out --trim right --display detailed

5-b5-含相同值的成绩排序.exe < 5-b4-1.dat > 5-b5-2.out
5-b5-demo.exe < 5-b4-1.dat > 5-b5-2.std.out
txt_compare.exe --file1 5-b5-2.out --file2 5-b5-2.std.out --trim right --display detailed

5-b5-含相同值的成绩排序.exe < 5-b4-1.dat > 5-b5-3.out
5-b5-demo.exe < 5-b4-1.dat > 5-b5-3.std.out
txt_compare.exe --file1 5-b5-3.out --file2 5-b5-3.std.out --trim right --display detailed

5-b5-含相同值的成绩排序.exe < 5-b4-1.dat > 5-b5-4.out
5-b5-demo.exe < 5-b4-1.dat > 5-b5-4.std.out
txt_compare.exe --file1 5-b5-4.out --file2 5-b5-4.std.out --trim right --display detailed
