/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        queue<Node* > nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int i = (int)nodes.size();
            while (i--) {
                Node* node = nodes.front();
                nodes.pop();
                if (i != 0) {
                    node->next = nodes.front();
                } else {
                    node->next = nullptr;
                }
                if (node->left != nullptr) nodes.push(node->left);
                if (node->right != nullptr) nodes.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    Node *node_4 = new Node(4);
    Node *node_5 = new Node(5);
    Node *node_6 = new Node(6);
    Node *node_7 = new Node(7);
    Node *node_2 = new Node(2, node_4, node_5, NULL);
    Node *node_3 = new Node(3, node_6, node_7, NULL);
    Node *node_1 = new Node(1, node_2, node_3, NULL);
    Solution solution = Solution();
    Node *node = solution.connect(node_1);
    return 0;
}
