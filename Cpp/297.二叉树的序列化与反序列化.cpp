/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>
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
        
        return root;
    }
    
    TreeNode* nodeFor(string val) {
        if (val == "#") return NULL;
        return new TreeNode(atoi(val.c_str()));
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

int main(int argc, const char * argv[]) {
    Codec codec;
    TreeNode *root;
    string json;
    
    /**
         1
        /     \
       2        3
           /    \
          4       5
     */
    root = generateTreeByLevel({1,2,3,INT_MAX,INT_MAX,4,5});
    json = codec.serialize(root);
    cout << json << endl;
    root = codec.deserialize(json);
    
    /**
     
     */
    root = generateTreeByLevel({});
    json = codec.serialize(root);
    cout << json << endl;
    root = codec.deserialize(json);
    
    /**
            1
           /
          2
     */
    root = generateTreeByLevel({1, 2});
    json = codec.serialize(root);
    cout << json << endl;
    root = codec.deserialize(json);
    
    return 0;
}
