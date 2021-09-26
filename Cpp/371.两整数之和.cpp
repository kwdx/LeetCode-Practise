/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int c = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int a, b, res;
    
    /**
     输入：a = 1, b = 2
     输出：3
     */
    a = 1;
    b = 2;
    res = 3;
    assert(res == Solution().getSum(a, b));
    
    /**
     输入：a = 2, b = 3
     输出：5
     */
    a = 2;
    b = 3;
    res = 5;
    assert(res == Solution().getSum(a, b));
    
    cout << "OK~" << endl;
    
    return 0;
}
