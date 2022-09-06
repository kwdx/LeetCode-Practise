/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int uniqueLetterString(string s) {
        int ans = 0;
        unordered_map<char, vector<int>> index;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            index[s[i]].emplace_back(i);
        }
        for (auto &[_, arr] : index) {
            arr.insert(arr.begin(), -1);
            arr.emplace_back(n);
            for (int i = 1; i < arr.size() - 1; ++i) {
                ans += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
            }
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
     输入: s = "ABC"
     输出: 10
     解释: 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
          其中，每一个子串都由独特字符构成。
          所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
     */
    s = "ABC";
    res = 10;
    assert(res == Solution().uniqueLetterString(s));
    
    /**
     输入: s = "ABA"
     输出: 8
     解释: 除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
     */
    s = "ABA";
    res = 8;
    assert(res == Solution().uniqueLetterString(s));
    
    /**
     输入：s = "LEETCODE"
     输出：92
     */
    s = "LEETCODE";
    res = 92;
    assert(res == Solution().uniqueLetterString(s));

    cout << "OK~" << endl;
    
    return 0;
}
