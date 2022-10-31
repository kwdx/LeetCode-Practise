/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int magicalString(int n) {
        string s(n, '0');
        s[0] = '1';
        s[1] = '2';
        s[2] = '2';
        int res = 1;
        int i = 2;  // 当前需要构造组的大小
        int j = 3;  // 对应组的位置
        while (j < n) {
            int size = s[i] - '0';
            int num = 3 - (s[j - 1] - '0');
            while (size > 0 && j < n) {
                s[j] = '0' + num;
                if (num == 1) {
                    ++res;
                }
                ++j;
                --size;
            }
            ++i;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入：n = 6
     输出：3
     解释：神奇字符串 s 的前 6 个元素是 “122112”，它包含三个 1，因此返回 3 。
     */
    n = 6;
    res = 3;
    assert(res == Solution().magicalString(n));
    
    /**
     输入：n = 1
     输出：1
     */
    n = 1;
    res = 1;
    assert(res == Solution().magicalString(n));
    
    cout << "OK~" << endl;
    
    return 0;
}
