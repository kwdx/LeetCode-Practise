/*
 * @lc app=leetcode.cn id=1945 lang=cpp
 *
 * [1945] 字符串转化后的各位数字之和
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int getLucky(string s, int k) {
        string digit;
        for (char c : s) {
            digit += to_string(c - 'a' + 1);
        }
        for (int i = 1; i <= k && digit.size() > 1; ++i) {
            int sum = 0;
            for (char c : digit) {
                sum += c - '0';
            }
            digit = to_string(sum);
        }
        return stoi(digit);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int k;
    int res;
    
    /**
     输入：s = "iiii", k = 1
     输出：36
     解释：操作如下：
     - 转化："iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
     - 转换 #1：9999 ➝ 9 + 9 + 9 + 9 ➝ 36
     因此，结果整数为 36 。
     */
    s = "iiii";
    k = 1;
    res = 36;
    assert(res == Solution().getLucky(s, k));
    
    /**
     输入：s = "leetcode", k = 2
     输出：6
     解释：操作如下：
     - 转化："leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
     - 转换 #1：12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
     - 转换 #2：33 ➝ 3 + 3 ➝ 6
     因此，结果整数为 6 。
     */
    s = "leetcode";
    k = 2;
    res = 6;
    assert(res == Solution().getLucky(s, k));

    cout << "OK~" << endl;
    
    return 0;
}
