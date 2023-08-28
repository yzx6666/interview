# c++11 auto的具体用法

1. **基本使用 ：定义变量，编译器可以自动判断变量的类型**

2. **auto和 const 的结合使用 ：  当类型不为引用时，auto 的推导结果将不保留表达式的 const 属性， 当类型为引用时，auto 的推导结果将保留表达式的 const 属性**
```c++
int  x = 0;
const  auto n = x;  //n 为 const int ，auto 被推导为 int
auto f = n;         //f 为 const int，auto 被推导为 int（const 属性被抛弃）
const auto &r1 = x; //r1 为 const int& 类型，auto 被推导为 int
auto &r2 = r1;      //r1 为 const int& 类型，auto 被推导为 const int 类型
```

3. **使用auto定义迭代器**
```c++
vector< vector<int> > v;
    //vector< vector<int> >::iterator i = v.begin();
    auto i = v.begin();  //使用 auto 代替具体的类型,该句比上一句简洁,根据表达式 v.begin() 的类型（begin() 函数的返回值类型）来推导出变量i的类型
```

4. **用于泛型编程 : 当我们不知道变量是什么类型，或者不希望指明具体类型的时候使用auto**