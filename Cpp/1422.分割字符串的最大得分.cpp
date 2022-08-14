/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int n = (int)s.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + (s[i - 1] - '0');
        }
        for (int i = 1; i < n; ++i) {
            int a = i - sum[i];
            int b = sum[n] - sum[i];
            ans = max(ans, a + b);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    int res;
    
    /**
     输入：s = "011101"
     输出：5
     解释：
     将字符串 s 划分为两个非空子字符串的可行方案有：
     左子字符串 = "0" 且 右子字符串 = "11101"，得分 = 1 + 4 = 5
     左子字符串 = "01" 且 右子字符串 = "1101"，得分 = 1 + 3 = 4
     左子字符串 = "011" 且 右子字符串 = "101"，得分 = 1 + 2 = 3
     左子字符串 = "0111" 且 右子字符串 = "01"，得分 = 1 + 1 = 2
     左子字符串 = "01110" 且 右子字符串 = "1"，得分 = 2 + 1 = 3
     */
    s = "011101";
    res = 5;
    assert(res == Solution().maxScore(s));
    
    /**
     输入：s = "00111"
     输出：5
     解释：当 左子字符串 = "00" 且 右子字符串 = "111" 时，我们得到最大得分 = 2 + 3 = 5
     */
    s = "00111";
    res = 5;
    assert(res == Solution().maxScore(s));
    
    /**
     输入：s = "1111"
     输出：3
     */
    s = "1111";
    res = 3;
    assert(res == Solution().maxScore(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
