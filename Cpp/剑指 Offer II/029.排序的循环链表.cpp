//
//  剑指 Offer II 029. 排序的循环链表
//  Cpp
//
//  Created by warden on 2022/6/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        node->next = node;
        if (head == nullptr) {
            return node;
        }
        Node* p = head;
        
        while (p->next != head) {
            if (p->val > p->next->val) {
                break;
            }
            p = p->next;
        }
        if (p->val <= insertVal || p->next->val >= insertVal) {
            node->next = p->next;
            p->next = node;
        } else {
            while (p->next->val < insertVal) {
                p = p->next;
            }
            node->next = p->next;
            p->next = node;
        }
        return head;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "OK~" << endl;

    return 0;
}
