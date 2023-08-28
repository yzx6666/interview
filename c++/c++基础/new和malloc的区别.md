# **`new`和`malloc`区别**

1.  ## **`new`是C++运算符，`malloc`是C/C++语言标准库函数**
2.  ## **`new`自动分配空间大小，`malloc`需要手动计算**
3.  ## **`new`是类型安全的，`malloc`不是**
   ```c++
    int *p = new float[2]; //编译错误
    int *p = (int*)malloc(2 * sizeof(double));//编译无错误
   ```
4.  ## **`new`不仅分配内存还调用和构造函数，`malloc`没有**
5.  ## **`malloc/free`需要库文件支持，`new`不需要**
6.  ## **`new`封装了`malloc`，直接调用`free`不会报错，只释放内存，不会析构对象。**

<br/>

## **有了`malloc/free`为什么还要`new/delete`**
**在对非基本数据类型的对象使用的时候，对象创建的时候还需要执行构造函数，销毁的时候要执行析构函数。而`malloc/free`是库函数，是已经编译的代码，所以不能把构造函数和析构函数的功能强加给`malloc/free`，所以`new/delete`是必不可少的**