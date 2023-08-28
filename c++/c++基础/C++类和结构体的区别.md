# **c++类和结构体的区别**
1.  ## struct 一般用于描述一个数据结构集合，而 class 是对一个对象数据的封装；
2.  ## struct 中默认的访问控制权限是 public 的，而 class 中默认的访问控制权限是 private 的
3.  ## 在继承关系中，struct 默认是公有继承，而 class 是私有继承；
4.  ## class 关键字可以用于定义模板参数，就像 typename，而 struct 不能用于定义模板参数

```c++
template<typename T, typename Y>    // 可以把typename 换成 class 
int Func(const T& t, const Y& y) { 
    //TODO 
}
```