@echo off
5-b2-100ÕµµÆµÄÁÁÃð.exe > 5-b2.out
5-b2-demo.exe > 5-b2.std.out
txt_compare.exe --file1 5-b2.out --file2 5-b2.std.out --display detailed
