# LRU算法及其实现方法

## **LRU算法：LRU算法用于缓存淘汰。思路是将缓存中最近最少使用的对象删除掉**

## **实现方法:利用`链表`和`hashmap`**
### **插入：当需要插入新的数据的时候，如果新数据项在链表中存在（一般叫命中），则把该节点移动到链表头部，如果不存在，则新建一个节点，放到链表头部，若缓存满了，则把链表最后一个节点删除即可。**
### **访问：当访问数据的时候，如果数据项在链表中存在，则把该节点移动到链表头部，否则返回-1。这样一来链表尾部就是最近最久为访问的数据项。**

## **C++实现**
```c++
class LRUCache {
    list<pair<int, int>> cache;//创建双向链表
    unordered_map<int, list<pair<int, int>>::iterator> map;//创建哈希表
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
            map[key] = cache.begin();//映射头部
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
        map[key] = cache.begin();//映射头部
    }
};

```
