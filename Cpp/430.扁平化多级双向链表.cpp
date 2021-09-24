/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    Node(int val) : val(val), next(nullptr), prev(nullptr), child(nullptr) {}
    Node(int val, Node* next, Node* prev) : val(val), next(next), prev(prev), child(nullptr) {
        if (prev) prev->next = this;
        if (next) next->prev = this;
    }
    Node(int val, Node* next, Node* prev, Node* child) : val(val), next(next), prev(prev), child(child) {
        if (prev) prev->next = this;
        if (next) next->prev = this;
    }
};

Node* gengerateNodes(vector<int> nodes) {
    Node* vHead = new Node(0);
    Node* node = vHead;
    
    for (int val : nodes) {
        node = new Node(val, nullptr, node);
    }
    vHead->next->prev = nullptr;
    return vHead->next;
}

vector<int> getNodeVals(Node* node) {
    if (!node) return {};
    vector<int> res;
    Node* prev = nullptr;
    while (node) {
        if (node->prev != prev)
            assert(false);  // 生成的链表有问题
        assert(node->child == nullptr);
        res.push_back(node->val);
        prev = node;
        node = node->next;
    }
    return res;
}

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* node = nullptr;
        stack<Node*> st;
        st.push(head);
        
        while (!st.empty()) {
            st.top()->prev = node;
            if (node) node->next = st.top();
            node = st.top();
            st.pop();
            if (node->next) {
                st.push(node->next);
                node->next = nullptr;
            }
            if (node->child) {
                st.push(node->child);
                node->child = nullptr;
            }
        }
        
        return head;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    Node* node;
    Node* resNode;
    vector<int> res;
    
    /**
     输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
     输出：[1,2,3,7,8,11,12,9,10,4,5,6]
     */
    Node* node1 = gengerateNodes({1,2,3,4,5,6});
    Node* node7 = gengerateNodes({7,8,9,10});
    Node* node11 = gengerateNodes({11,12});
    node1->next->next->child = node7;
    node7->next->child = node11;
    
    node = node1;
    res = {1,2,3,7,8,11,12,9,10,4,5,6};
    resNode = Solution().flatten(node);
    assert(res == getNodeVals(resNode));
    
    /**
     输入：head = [1,2,null,3]
     输出：[1,3,2]
     解释：

     输入的多级列表如下图所示：

       1---2---NULL
       |
       3---NULL
     */
    node = new Node(1, new Node(2), nullptr, new Node(3));
    res = {1,3,2};
    resNode = Solution().flatten(node);
    assert(res == getNodeVals(resNode));
    
    /**
     输入：head = []
     输出：[]
     */
    node = nullptr;
    res = {};
    resNode = Solution().flatten(node);
    assert(res == getNodeVals(resNode));
    
    cout << "OK~" << endl;
    
    return 0;
}
