@echo off
5-b4-已知成绩统计各分数人数.exe < 5-b4-1.dat > 5-b4-1.out
5-b4-demo.exe < 5-b4-1.dat > 5-b4-1.std.out
txt_compare.exe --file1 5-b4-1.out --file2 5-b4-1.std.out --trim right --display detailed

5-b4-已知成绩统计各分数人数.exe < 5-b4-2.dat > 5-b4-2.out
5-b4-demo.exe < 5-b4-2.dat > 5-b4-2.std.out
txt_compare.exe --file1 5-b4-2.out --file2 5-b4-2.std.out --trim right --display detailed


5-b4-已知成绩统计各分数人数.exe < 5-b4-3.dat > 5-b4-3.out
5-b4-demo.exe < 5-b4-3.dat > 5-b4-3.std.out
txt_compare.exe --file1 5-b4-3.out --file2 5-b4-3.std.out --trim right --display detailed


5-b4-已知成绩统计各分数人数.exe < 5-b4-4.dat > 5-b4-4.out
5-b4-demo.exe < 5-b4-4.dat > 5-b4-4.std.out
txt_compare.exe --file1 5-b4-4.out --file2 5-b4-4.std.out --trim right --display detailed

