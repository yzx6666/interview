# emplace_back��push_back������
<br/>

**��ͬ�㣺 ������vectorĩβ���Ԫ��**
<br/>

**��ͬ�� ��emplace_back ����ֱ��������ĩβ������󣬶�push_back��Ҫ�ȹ�������ٽ��п���������β**
```c++
class A {
public:
    A(int i){
        str = to_string(i);
        cout << "���캯��" << endl; 
    }
    ~A(){}
    A(const A& other): str(other.str){
        cout << "��������" << endl;
    }

public:
    string str;
};

int main()
{
    vector<A> vec;
    vec.reserve(10);
    for(int i=0;i<10;i++){
        vec.push_back(A(i)); //������10�ι��캯����10�ο������캯��,
//        vec.emplace_back(i);  //������10�ι��캯��һ�ο������캯����û�е��ù�
    }
}
```