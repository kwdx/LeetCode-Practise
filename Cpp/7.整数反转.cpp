/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x != 0) {
            if (r > INT32_MAX / 10 || r < INT32_MIN / 10) return 0;
            r = r * 10 + x % 10;
            x = x / 10;
        }
        return r;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int x, res;
    
    /**
     输入：x = 123
     输出：321
     */
    x = 123;
    res = 321;
    assert(res == Solution().reverse(x));
    
    /**
     输入：x = -123
     输出：-321
     */
    x = -123;
    res = -321;
    assert(res == Solution().reverse(x));
    
    /**
     输入：x = 120
     输出：21
     */
    x = 120;
    res = 21;
    assert(res == Solution().reverse(x));
    
    /**
     输入：x = 0
     输出：0
     */
    x = 0;
    res = 0;
    assert(res == Solution().reverse(x));

    cout << "OK~" << endl;
    
    return 0;
}
