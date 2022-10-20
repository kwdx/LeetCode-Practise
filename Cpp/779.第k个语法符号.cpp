/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k == 1) {
            return 0;
        }
        if (k > (1 << (n - 2))) {
            // 在后半段
            return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));
        }
        // 在前半段
        return kthGrammar(n - 1, k);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int k;
    int res;
    
    /**
     输入: n = 1, k = 1
     输出: 0
     解释: 第一行：0
     */
    n = 1;
    k = 1;
    res = 0;
    assert(res == Solution().kthGrammar(n, k));
    
    /**
     输入: n = 2, k = 1
     输出: 0
     解释:
     第一行: 0
     第二行: 01
     */
    n = 2;
    k = 1;
    res = 0;
    assert(res == Solution().kthGrammar(n, k));
    
    /**
     输入: n = 2, k = 2
     输出: 1
     解释:
     第一行: 0
     第二行: 01
     */
    n = 2;
    k = 2;
    res = 1;
    assert(res == Solution().kthGrammar(n, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
