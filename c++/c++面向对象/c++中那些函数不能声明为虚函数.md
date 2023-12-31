# **c++中那些函数不能被声明为虚函数**

## **普通函数(非成员函数)、静态成员函数、内联成员函数、构造函数、友元函数**

<br/>

### **普通函数**
**普通函数只能被重载，不能被重写，声明为虚函数没有意义，因此编译器会在编译时绑定函数**

<br/>

### **静态成员函数**
1.  **静态成员函数对于每个类都只有一份，所有对象都共享这份代码，没有动态绑定的必要**
2.  **静态成员函数属于一个类而非某个对象，没有this指针，它无法进行对象的判别**

<br/>

### **内联成员函数**
**内联函数是为了在代码中直接展开，减少函数调用花费的代价，虚函数是为了在继承后对象能够准确地执行自己的动作，目的不同。**<br/>
**内联函数是在编译时期被展开，虚函数是在运行时动态绑定的函数**

<br/>

### **构造函数**
**虚构造函数在继承体系中没有意义,因为构造函数的作用是初始化对象,每个类都有自己特有的初始化工作,不需要基类构造函数来完成,因此不需要虚构造函数。虚函数对应一个虚表,这个表的地址是存储在对象的内存空间的。如果将构造函数设置为虚函数，就需要到虚表中调用，可是对象还没有实例化，没有内存空间分配,所以不能虚构造**

<br/>

### **友元函数**
**友元函数没有继承特性，所以没有虚函数的说法**
