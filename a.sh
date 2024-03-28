#!/bin/bash

# 定义文件名
file="3.28新知识.txt"

# 使用循环向文件中写入数字
for ((i=1; i<=25; i++)); do
    echo "$i." >> "$file"
    echo "" >> "$file"  # 每隔一行插入一个空行
done

echo "数字已写入文件 $file"

