# c++11 auto�ľ����÷�

1. **����ʹ�� ����������������������Զ��жϱ���������**

2. **auto�� const �Ľ��ʹ�� ��  �����Ͳ�Ϊ����ʱ��auto ���Ƶ���������������ʽ�� const ���ԣ� ������Ϊ����ʱ��auto ���Ƶ�������������ʽ�� const ����**
```c++
int  x = 0;
const  auto n = x;  //n Ϊ const int ��auto ���Ƶ�Ϊ int
auto f = n;         //f Ϊ const int��auto ���Ƶ�Ϊ int��const ���Ա�������
const auto &r1 = x; //r1 Ϊ const int& ���ͣ�auto ���Ƶ�Ϊ int
auto &r2 = r1;      //r1 Ϊ const int& ���ͣ�auto ���Ƶ�Ϊ const int ����
```

3. **ʹ��auto���������**
```c++
vector< vector<int> > v;
    //vector< vector<int> >::iterator i = v.begin();
    auto i = v.begin();  //ʹ�� auto ������������,�þ����һ����,���ݱ��ʽ v.begin() �����ͣ�begin() �����ķ���ֵ���ͣ����Ƶ�������i������
```

4. **���ڷ��ͱ�� : �����ǲ�֪��������ʲô���ͣ����߲�ϣ��ָ���������͵�ʱ��ʹ��auto**