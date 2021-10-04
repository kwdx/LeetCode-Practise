/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int len = 0;
        for (auto & c : s)
            if (c != '-')
                ++len;
        if (len == 0) return "";
        
        int groups = (len + k - 1) / k;
        int first = len - (groups - 1) * k;
        
        string ans;
        int i = 0;
        int group = 0;
        for (char & c : s) {
            if (c == '-') {
                continue;
            }
            ans.push_back(c - (c < 'a' ? 0 : ('a' - 'A')));
            ++i;
            if ((group == 0 && i == first) || i == k) {
                i = 0;
                ++group;
                ans.push_back('-');
            }
        }
        if (ans[ans.size() - 1] == '-') ans.pop_back();
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s, res;
    int k;
    
    /**
     输入：S = "5F3Z-2e-9-w", K = 4
     输出："5F3Z-2E9W"
     解释：字符串 S 被分成了两个部分，每部分 4 个字符；
          注意，两个额外的破折号需要删掉。
     */
    s = "5F3Z-2e-9-w";
    k = 4;
    res = "5F3Z-2E9W";
    assert(res == Solution().licenseKeyFormatting(s, k));

    /**
     输入：S = "2-5g-3-J", K = 2
     输出："2-5G-3J"
     解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
     */
    s = "2-5g-3-J";
    k = 2;
    res = "2-5G-3J";
    assert(res == Solution().licenseKeyFormatting(s, k));
    
    /**
     输入：S = "---", K = 3
     输出：""
     解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
     */
    s = "---";
    k = 3;
    res = "";
    assert(res == Solution().licenseKeyFormatting(s, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
