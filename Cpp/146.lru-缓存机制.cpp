/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
// 最近最少使用
//class Node {
//public:
//    int key, val;
//    Node* next;
//    Node* prev;
//    Node(int k, int v){
//      key = k;
//      val = v;
//    }
//};
//
//class DoubleList {
//private:
//    // 头尾指针
//    Node* head;
//    Node* tail;
//    // 链表元素数
//    int _size;
//public:
//    DoubleList() {
//        head = new Node(0, 0);
//        tail = new Node(0, 0);
//        head->next = tail;
//        tail->prev = head;
//        _size = 0;
//    }
//
//    ~DoubleList() {
//        Node* node = head->next;
//        Node* temp = nullptr;
//        while (node != tail) {
//            temp = node->next;
//            delete node;
//            node = temp;
//        }
//        delete head;
//        delete tail;
//    }
//
//    // 在链尾添加节点
//    void addLast(Node* x) {
//        x->prev = tail->prev;
//        x->next = tail;
//        tail->prev->next = x;
//        tail->prev = x;
//        _size++;
//    }
//
//    // 删除链表中的 x 节点 (x 节点一定存在)
//    void remove(Node* x) {
//        x->prev->next = x->next;
//        x->next->prev = x->prev;
//        _size--;
//    }
//
//    Node* removeFirst() {
//        if (head->next == tail) return NULL;
//        Node* first = head->next;
//        remove(first);
//        return first;
//    }
//
//    int size() {
//        return _size;
//    }
//};
//
//class LRUCache {
//private:
//    unordered_map<int, Node*> map;
//    DoubleList* cache;
//    // 最大容量
//    int capacity;
//
//public:
//    LRUCache(int capacity) : capacity(capacity) {
//        map.clear();
//        cache = new DoubleList();
//    }
//
//    ~LRUCache() {
//        delete cache;
//    }
//
//    int get(int key) {
//        if (map.find(key) == map.end()) {
//            return -1;
//        }
//        // 将该数据提升为最近使用的
//        makeRecently(key);
//        return map[key]->val;
//    }
//
//    void put(int key, int value) {
//        if (map.find(key) != map.end()) {
//            // 删除旧的数据
//            deleteKey(key);
//            // 新插入的数据为最近使用的数据
//            addRecently(key, value);
//            return;
//        }
//
//        if (capacity == cache->size()) {
//            // 删除最久未使用的元素
//            removeLeastRecently();
//        }
//        // 添加为最近使用的元素
//        addRecently(key, value);
//    }
//
//private:
//    // 将某个 key 提升为最近使用的
//    void makeRecently(int key) {
//        Node* x = map[key];
//        // 先从链表中删除这个节点
//        cache->remove(x);
//        // 重新插到队尾
//        cache->addLast(x);
//    }
//
//    // 添加最近使用的元素
//    void addRecently(int key, int val) {
//        Node* x = new Node(key, val);
//        // 链表尾部就是最近使用的元素
//        cache->addLast(x);
//        // 别忘了在 map 中添加 key 的映射
//        map[key] = x;
//    }
//
//    // 删除某一个 key
//    void deleteKey(int key) {
//        Node* x = map[key];
//        // 从链表中删除
//        cache->remove(x);
//        // 从 map 中删除
//        map.erase(key);
//    }
//
//    // 删除最久未使用的元素
//    void removeLeastRecently() {
//        // 链表头部的第一个元素就是最久未使用的
//        Node* deletedNode = cache->removeFirst();
//        // 同时别忘了从 map 中删除它的 key
//        int deletedKey = deletedNode->key;
//        map.erase(deletedKey);
//        delete deletedNode;
//    }
//};
class Node {
public:
    int key, val;
    Node* next, * prev;
    Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    Node(int k, int v, Node* next, Node* prev) : key(k), val(v), next(next), prev(prev) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;
    int size;
    // 最大容量
    int capacity;
    
    void moveToLast(Node* node) {
        removeNode(node);
        addToLast(node);
    }
        
    void removeFirst() {
        Node *node = head->next;
        removeNode(node);
        map.erase(node->key);
        delete node;
    }
        
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToLast(Node* node) {
        node->prev = tail->prev;
        node->prev->next = node;
        tail->prev = node;
        node->next = tail;
    }
    
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    ~LRUCache() {
        Node* node = head->next;
        Node* temp = nullptr;
        while (node != tail) {
            temp = node->next;
            delete node;
            node = temp;
        }
        delete head;
        delete tail;
    }
    
    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }
        Node* node = map[key];
        // 将该数据提升为最近使用的
        moveToLast(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (map.count(key)) {
            // 删除旧的数据
            Node* node = map[key];
            node->val = value;
            moveToLast(node);
            return;
        } else {
            Node* node = new Node(key, value);
            map[key] = node;
            addToLast(node);
            size++;
            
            if (size > capacity) {
                // 删除最久未使用的元素
                removeFirst();
                size--;
            }
        }
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    /**
     输入
     ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
     [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
     输出
     [null, null, null, 1, null, -1, null, -1, 3, 4]

     解释
     LRUCache lRUCache = new LRUCache(2);
     lRUCache.put(1, 1); // 缓存是 {1=1}
     lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
     lRUCache.get(1);    // 返回 1
     lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
     lRUCache.get(2);    // 返回 -1 (未找到)
     lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
     lRUCache.get(1);    // 返回 -1 (未找到)
     lRUCache.get(3);    // 返回 3
     lRUCache.get(4);    // 返回 4
     */
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    // 1
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    // -1
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    // -1
    cout << cache.get(1) << endl;
    // 3
    cout << cache.get(3) << endl;
    // 4
    cout << cache.get(4) << endl;
    return 0;
}
