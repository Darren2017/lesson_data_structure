//.m文件的行数
find . -name "*.m" | xargs wc -l

//.m .h .xib .c 文件内容总行数
find . -name "*.m" -or -name "*.h" -or -name "*.xib" -or -name "*.c" |xargs grep -v "^$"|wc -l 