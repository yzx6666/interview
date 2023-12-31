# 简述c++的重载和重写

1.  ## 重载
    1.  **定义：函数重载是指同一可访问区内被声明的几个具有不同参数列（参数的类型，个数，顺序不同）的同名函数，根据参数列表确定调用哪个函数，重载不关心函数返回类型。**
    2.  **函数重载好处：函数重载通常用来命名一组功能相似的函数，这样做减少了函数名的数量，避免了名字空间的污染，对于程序的可读性有很大的好处。**
    3.  **函数重载的特征：**
        1.  **在同一作用域**
        2.  **名字相同**
        3.  **参数不同（个数，种类，顺序）** 
        4.  **返回值可以不同，也可以相同**
2. ## 重写（覆盖）
   1. **定义：是指派生类中存在重新定义的函数。其函数名，参数列表，返回值类型，所有都必须同基类中被重写的函数一致。只有函数体不同（花括号内），派生类对象调用时会调用派生类的重写函数，不会调用被重写函数。*<u>重写的基类中被重写的函数必须有virtual修饰</u>*。**
   2. **函数重写的好处：提高代码的可读性和可维护性，便于扩展和维护**
   3. **函数重写的特征：**
      1. **不在同一个作用域（分别位于派生类与基类）**
      2. **函数名字相同，参数相同**
      3. **基类函数必须有 virtual 关键字，不能有 static。**
      4. **返回值必须相同**

### 函数重写是子类和父类之间的关系，是垂直关系；而重载是同一个类中不同方法之间的关系，是水平关系；

<br/>

### 重载是在编译阶段区分函数。修改函数名，区分参数不同的同名函数。

<br/>

### 纯虚函数：virtual void fun()=0。即抽象类必须在子类实现这个函数，即先有名称，没有内容，在派生类实现内容。不能实例化