# **GDB常见调试命令**
## gdb调试需要 gcc编译时加 **-g** `gcc -g test.c -o test.o`
<br/>

## **GDB调试命令**
1.  ## **`qiut`,退出gdb，结束调试**
2.  ## **`list`,查看程序源代码**
    1.  ## **`list 5,10`,**
    2.  ## **`list test.c:5,10`,显示5到10行的代码**
    3.  ## **`list get_sum`,显示get_sum函数周围的代码**
    4.  ## **`list test.c get_sum`,显示源文件5到10行的代码，在调试多个文件时使用**
3.  ## **`reverse-search`,字符串用来从当前行向前查找第一个匹配的字符串**
4.  ## **`run`,程序开始执行**
5.  ## **`help list/all`,查看帮助信息**
6.  ## **`break`,设置断点**
    1.  ## **`break 7`,在第七行设置断点**
    2.  ## **`break get_sum`,以函数名设置断点**
    3.  ## **`break 行号或函数名 if`,以条件表达式设置断点**
7.  ## **`watch 条件表达式`,条件表达式发生改变时程序就会停下来**
8.  ## **`next`,继续执行下一条语句 ，会把函数当作一条语句执行**
9.  ## **`step`,继续执行下一条语句，会跟踪进入函数，一次一条的执行函数内的代码**
10. ## **用`set follow-frok-mode child`调试子进程**
    ## **用`set follow-fork-mode parent`调试父进程**