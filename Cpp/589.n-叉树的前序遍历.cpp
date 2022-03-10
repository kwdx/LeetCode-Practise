/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<pair<int, Node*>> st;
        st.push({0, root});
        pair<int, Node*> node;
        while (!st.empty()) {
            node = st.top();
            st.pop();
            if (node.second == nullptr) continue;
            if (node.first == 0) {
                // 第一次遍历
                ans.push_back(node.second->val);
                st.push({1, node.second});
            } else if (node.first == 1) {
                // 第二次遍历，遍历子节点
                int n = (int)node.second->children.size();
                for (int i = n - 1; i >= 0; i--) {
                    st.push({0, node.second->children[i]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "OK~" << endl;
    
    return 0;
}
