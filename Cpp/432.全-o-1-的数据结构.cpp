/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class AllOne {
private:
    class Node {
    public:
        int cnt;
        Node *left = nullptr, *right = nullptr;
        unordered_set<string> sets;
        
        Node(int cnt) {
            this->cnt = cnt;
        }
    };
    
    Node *head, *tail;
    unordered_map<string, Node*> map;
    
public:
    AllOne() {
        head = new Node(-1000);
        tail = new Node(-1000);
        head->right = tail;
        tail->left = head;
    }
    
    void inc(string key) {
        Node *node = map[key];
        if (node != nullptr) {
            node->sets.erase(key);
            Node *next = nullptr;
            if (node->right->cnt == node->cnt + 1) {
                next = node->right;
            } else {
                next = new Node(node->cnt + 1);
                next->right = node->right;
                next->left = node;
                node->right->left = next;
                node->right = next;
            }
            next->sets.insert(key);
            map[key] = next;
            clear(node);
        } else {
            if (head->right->cnt == 1) {
                node = head->right;
            } else {
                node = new Node(1);
                node->right = head->right;
                node->left = head;
                head->right->left = node;
                head->right = node;
            }
            node->sets.insert(key);
            map[key] = node;
        }
    }
    
    void dec(string key) {
        Node *node = map[key];
        if (node == nullptr) return;
        node->sets.erase(key);
        
        if (node->cnt == 1) {
            map.erase(key);
        } else {
            Node *prev;
            if (node->left->cnt == node->cnt - 1) {
                prev = node->left;
            } else {
                prev = new Node(node->cnt - 1);
                prev->right = node;
                prev->left = node->left;
                node->left->right = prev;
                node->left = prev;
            }
            prev->sets.insert(key);
            map[key] = prev;
        }
        clear(node);
    }
    
    string getMaxKey() {
        if (!tail->left->sets.empty()) {
            return *(tail->left->sets.begin());
        }
        return "";
    }
    
    string getMinKey() {
        if (!head->right->sets.empty()) {
            return *(head->right->sets.begin());
        }
        return "";
    }
    
    void clear(Node *node) {
        if (node->sets.empty()) {
            node->right->left = node->left;
            node->left->right = node->right;
            delete node;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
     [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
     输出
     [null, null, null, "hello", "hello", null, "hello", "leet"]

     解释
     AllOne allOne = new AllOne();
     allOne.inc("hello");
     allOne.inc("hello");
     allOne.getMaxKey(); // 返回 "hello"
     allOne.getMinKey(); // 返回 "hello"
     allOne.inc("leet");
     allOne.getMaxKey(); // 返回 "hello"
     allOne.getMinKey(); // 返回 "leet"
     */
    AllOne allOne;
    allOne.inc("hello");
    allOne.inc("hello");
    assert("hello" == allOne.getMaxKey());
    assert("hello" == allOne.getMinKey());
    allOne.inc("leet");
    assert("hello" == allOne.getMaxKey());
    assert("leet" == allOne.getMinKey());

    cout << "OK~" << endl;

    return 0;
}
