# **C++结构体和C结构体的区别**
<br/>

## （1）C的结构体内不允许有函数存在，C++允许有内部成员函数，且允许该函数是虚函数。

## （2）C的结构体对内部成员变量的访问权限只能是public，而C++允许public,protected,private三种。

## （3）C语言的结构体是不可以继承的，C++的结构体是可以从其他的结构体或者类继承过来的。

## （4）C 中使用结构体需要加上 struct 关键字，或者对结构体使用 typedef 取别名，而 C++ 中可以省略 struct 关键字直接使用。

| |C| C++|
|:---:|:---:|:---:|
|成员函数|不能有|可以|
|静态成员|不能有|可以|
|访问控制|默认public，不能修改|public/private/protected|
|继承关系|不可以继承|可以从类或其他结构体继承|
|初始化|不能直接初始化数据成员|可以|

## **C 中使用结构体需要加上 struct 关键字，或者对结构体使用 typedef 取别名，而 C++ 中可以省略 struct 关键字直接使用，例如：**

```c++
struct Student{
    int  iAgeNum;
    string strName;
}
typedef struct Student Student2;    //C中取别名

struct Student stu1;    // C 中正常使用
Student2 stu2;            // C 中通过取别名的使用
Student stu3;            // C++ 中使用**
```