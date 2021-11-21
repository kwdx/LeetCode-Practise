/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

// @lc code=start
/*
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
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        
        int ans = 0;
        queue<Node*> q;
        q.push(root);
        Node* cur;
        while (!q.empty()) {
            int n = (int)q.size();
            for (int i = 0; i < n; ++i) {
                cur = q.front();
                q.pop();
                for (Node* node : cur->children) {
                    q.push(node);
                }
            }
            ++ans;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Node* root;
    int res;
    
    /**
     输入：root = [1,null,3,2,4,null,5,6]
     输出：3
     */
    {
        Node* node5 = new Node(5);
        Node* node6 = new Node(6);
        
        Node* node3 = new Node(3, {node5, node6});
        Node* node2 = new Node(2);
        Node* node4 = new Node(4);
        
        root = new Node(1, {node3, node2, node4});
    }
    res = 3;
    assert(res == Solution().maxDepth(root));
    
    /**
     输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
     输出：5
     */
    {
        Node* node14 = new Node(14);
        
        Node* node11 = new Node(11, {node14});
        Node* node12 = new Node(12);
        Node* node13 = new Node(13);
        
        Node* node6 = new Node(6);
        Node* node7 = new Node(7, {node11});
        Node* node8 = new Node(8, {node12});
        Node* node9 = new Node(9, {node13});
        Node* node10 = new Node(10);
        
        Node* node2 = new Node(2);
        Node* node3 = new Node(3, {node6, node7});
        Node* node4 = new Node(4, {node8});
        Node* node5 = new Node(5, {node9, node10});
        
        root = new Node(1, {node2, node3, node4, node5});
    }
    res = 5;
    assert(res == Solution().maxDepth(root));

    cout << "OK~" << endl;

    return 0;
}
