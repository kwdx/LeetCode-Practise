//
//  A.面试题04.06.cpp
//  cpp
//
//  Created by kingsoft on 2022/5/16.
//

#include <iostream>
#include <string>
#include <stack>
#include "TreeNode.h"

using namespace std;

// @lc code=start
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val <= p->val) return inorderSuccessor(root->right, p);
        TreeNode* ans = inorderSuccessor(root->left, p);
        return ans == nullptr ? root : ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* root;
    TreeNode* p;
    int res;
    
    /**
     输入: root = [2,1,3], p = 1

       2
      / \
     1   3

     输出: 2
     */
    root = generateBinaryTree({2,1,3});
    p = new TreeNode(1);
    res = 2;
    assert(res == Solution().inorderSuccessor(root, p)->val);
    
    /**
     输入: root = [5,3,6,2,4,null,null,1], p = 6

           5
          / \
         3   6
        / \
       2   4
      /
     1

     输出: null
     */
    root = generateBinaryTree({5,3,6,2,4,1});
    p = new TreeNode(6);
    assert(Solution().inorderSuccessor(root, p) == NULL);
    
    cout << "OK~" << endl;
    
    return 0;
}
