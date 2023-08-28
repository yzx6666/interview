# emplace_back和push_back的区别
<br/>

**相同点： 都是在vector末尾添加元素**
<br/>

**不同点 ：emplace_back 可以直接在容器末尾构造对象，而push_back需要先构造对象再进行拷贝到容器尾**
```c++
class A {
public:
    A(int i){
        str = to_string(i);
        cout << "构造函数" << endl; 
    }
    ~A(){}
    A(const A& other): str(other.str){
        cout << "拷贝构造" << endl;
    }

public:
    string str;
};

int main()
{
    vector<A> vec;
    vec.reserve(10);
    for(int i=0;i<10;i++){
        vec.push_back(A(i)); //调用了10次构造函数和10次拷贝构造函数,
//        vec.emplace_back(i);  //调用了10次构造函数一次拷贝构造函数都没有调用过
    }
}
```