/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

#include <iostream>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入：n = 3
     输出：1
     解释：
     初始时, 灯泡状态 [关闭, 关闭, 关闭].
     第一轮后, 灯泡状态 [开启, 开启, 开启].
     第二轮后, 灯泡状态 [开启, 关闭, 开启].
     第三轮后, 灯泡状态 [开启, 关闭, 关闭].

     你应该返回 1，因为只有一个灯泡还亮着。
     */
    n = 3;
    res = 1;
    assert(res == Solution().bulbSwitch(n));
    
    /**
     输入：n = 0
     输出：0
     */
    n = 0;
    res = 0;
    assert(res == Solution().bulbSwitch(n));
    
    /**
     输入：n = 1
     输出：1
     */
    n = 1;
    res = 1;
    assert(res == Solution().bulbSwitch(n));

    cout << "OK~" << endl;

    return 0;
}
