/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
private:
    vector<int> ans;
    void dfs(Node* node) {
        if (node == nullptr) return;
        for (Node* child : node->children) {
            dfs(child);
        }
        ans.push_back(node->val);
    }
public:
    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << "OK~" << endl;
    
    return 0;
}
