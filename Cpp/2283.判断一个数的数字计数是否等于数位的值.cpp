/*
 * @lc app=leetcode.cn id=2283 lang=cpp
 *
 * [2283] 判断一个数的数字计数是否等于数位的值
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool digitCount(string num) {
        vector<int> bucket(10);
        for (int i = 0; i < num.size(); ++i) {
            int digit = num[i] - '0';
            bucket[digit] += 1;
        }
        for (int i = 0; i < num.size(); ++i) {
            int digit = num[i] - '0';
            if (bucket[i] != digit) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string num;
    bool res;

    /**
     输入：num = "1210"
     输出：true
     解释：
     num[0] = '1' 。数字 0 在 num 中出现了一次。
     num[1] = '2' 。数字 1 在 num 中出现了两次。
     num[2] = '1' 。数字 2 在 num 中出现了一次。
     num[3] = '0' 。数字 3 在 num 中出现了零次。
     "1210" 满足题目要求条件，所以返回 true 。
     */
    num = "1210";
    res = true;
    assert(res == Solution().digitCount(num));
    
    /**
     输入：num = "030"
     输出：false
     解释：
     num[0] = '0' 。数字 0 应该出现 0 次，但是在 num 中出现了一次。
     num[1] = '3' 。数字 1 应该出现 3 次，但是在 num 中出现了零次。
     num[2] = '0' 。数字 2 在 num 中出现了 0 次。
     下标 0 和 1 都违反了题目要求，所以返回 false 。
     */
    num = "030";
    res = false;
    assert(res == Solution().digitCount(num));
    
    cout << "OK~" << endl;
    
    return 0;
}
