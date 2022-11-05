/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target > 0) {
            target -= ++k;
        }
        int delta = target % 2;
        return delta == 0 ? k : k + 1 + k % 2;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int target;
    int res;
    
    /**
     输入: target = 2
     输出: 3
     解释:
     第一次移动，从 0 到 1 。
     第二次移动，从 1 到 -1 。
     第三次移动，从 -1 到 2 。
     */
    target = 2;
    res = 3;
    assert(res == Solution().reachNumber(target));
    
    /**
     输入: target = 3
     输出: 2
     解释:
     第一次移动，从 0 到 1 。
     第二次移动，从 1 到 3 。
     */
    target = 3;
    res = 2;
    assert(res == Solution().reachNumber(target));
    
    cout << "OK~" << endl;
    
    return 0;
}
