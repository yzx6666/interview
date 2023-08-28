# LRU�㷨����ʵ�ַ���

## **LRU�㷨��LRU�㷨���ڻ�����̭��˼·�ǽ��������������ʹ�õĶ���ɾ����**

## **ʵ�ַ���:����`����`��`hashmap`**
### **���룺����Ҫ�����µ����ݵ�ʱ��������������������д��ڣ�һ������У�����Ѹýڵ��ƶ�������ͷ������������ڣ����½�һ���ڵ㣬�ŵ�����ͷ�������������ˣ�����������һ���ڵ�ɾ�����ɡ�**
### **���ʣ����������ݵ�ʱ������������������д��ڣ���Ѹýڵ��ƶ�������ͷ�������򷵻�-1������һ������β������������Ϊ���ʵ������**

## **C++ʵ��**
```c++
class LRUCache {
    list<pair<int, int>> cache;//����˫������
    unordered_map<int, list<pair<int, int>>::iterator> map;//������ϣ��
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (map.count(key) > 0){
            auto temp = *map[key];
            cache.erase(map[key]);
            map.erase(key);
            cache.push_front(temp);
            map[key] = cache.begin();//ӳ��ͷ��
            return temp.second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.count(key) > 0){
            cache.erase(map[key]);
            map.erase(key);
        }
        else if (cap == cache.size()){
            auto temp = cache.back();
            map.erase(temp.first);
            cache.pop_back();
        }
        cache.push_front(pair<int, int>(key, value));
        map[key] = cache.begin();//ӳ��ͷ��
    }
};

```
