/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

#include <iostream>
#include <string>
#include <queue>
#include <stack>

#include "TreeNode.h"

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
                
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        return to_string(root->val) + "_" + left + "_" + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.size()) return  NULL;
                
        queue<string> dataArray;
        string str;
        for (auto ch : data) {
            if (ch == '_') {
                dataArray.push(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) dataArray.push(str);
        
        stack<TreeNode*> st;
        TreeNode* root = nodeFor(dataArray.front());
        dataArray.pop();
        TreeNode* node = root;
        while (!dataArray.empty()) {
            while (node) {
                st.push(node);
                node->left = nodeFor(dataArray.front());
                dataArray.pop();
                node = node->left;
            }
            node = st.top();
            st.pop();
            node->right = nodeFor(dataArray.front());
            dataArray.pop();
            node = node->right;
        }
        
        return root;;
    }
    
    TreeNode* nodeFor(string val) {
        if (val == "#") return NULL;
        return new TreeNode(atoi(val.c_str()));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Codec* ser = new Codec();
    Codec* deser = new Codec();
    vector<int> nodes;
    TreeNode* root;
    string tree;
    TreeNode* ans;

    /**
     输入：root = [2,1,3]
     输出：[2,1,3]
     */
    nodes = {2,1,3};
    root = generateBinaryTree(nodes);
    tree = ser->serialize(root);
    ans = deser->deserialize(tree);
    assert(nodes == getTreeLevel(ans));
    
    /**
     输入：root = []
     输出：[]
     */
    nodes = {};
    root = generateBinaryTree(nodes);
    tree = ser->serialize(root);
    ans = deser->deserialize(tree);
    assert(nodes == getTreeLevel(ans));
    
    cout << "OK~" << endl;
    
    return 0;
}
