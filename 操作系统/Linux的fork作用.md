# Linux的fork
## fork函数用来创建一个子进程。对于父进程，fork()函数返回新创建的子进程的PID。对于子进程，fork()函数调用成功会返回0。如果创建出错，fork()函数返回-1。

```c++
#include <unistd.h>  
pid_t fork(void);  
```
### fork不需要参数，返回的是进程标识符PID

（1） 对于父进程，fork()函数返回新创建的子进程的PID。
（2） 对于子进程，fork()函数调用成功会返回0。
（3） 如果创建出错，fork()函数返回-1。