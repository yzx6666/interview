# sleep和wait的区别

## sleep
**`sleep`是延时函数，让进程进入休眠。休眠完毕之后继续运行。**<br/>
**在Linux中`sleep`的参数是秒，windows是毫秒**<br/>
```cpp 
//windows
#include <windows.h>// 首先应该先导入头文件 
Sleep (500) ; //注意第一个字母是大写。 
//就是到这里停半秒，然后继续向下执行
```
```cpp
//Linux
#include <unistd.h>// 首先应该先导入头文件 
sleep(5); //停5秒 
//就是到这里停5秒，然后继续向下执行。
```

<br/>

## wait
**`wait`是父进程回收子进程PCB资源的一个系统调用。进程一旦调用`wait`函数，就立刻阻塞自身，然后由`wait`函数自动分析当前进程的某一个子进程是否已经退出，找到一个已经变成僵尸进程的子进程，`wait`会收集这个子进程的信息，并把它彻底销毁后返回；如果没有找到这样的子进程，wait会一直阻塞，直到有一个出现为止**
```cpp
#include<sys/types.h>   
#include<sys/wait.h>     
pid_t wait(int* status);  
```

**子进程结束状态由参数`status`返回，而进程的识别码也会一起返回，如果不需要，则参数可以设置为`null`**
