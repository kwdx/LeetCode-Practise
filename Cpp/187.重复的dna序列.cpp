/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
private:
    const int L = 10;
    unordered_map<char, int> kv = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = (int)s.size();
        if (n <= L) {
            return ans;
        }
        int x = 0;
        for (int i = 0; i < L; ++i) {
            x = (x << 2) | kv[s[i]];
        }
        unordered_map<int, int> cnt;
        ++cnt[x];
        for (int i = L; i < n; ++i) {
            x = ((x << 2) | kv[s[i]]) & ((1 << (L * 2)) - 1);
            if (++cnt[x] == 2) {
                ans.push_back(s.substr(i - L + 1, L));
            }
        }
        
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    string s;
    vector<string> res;
    
    /**
     输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
     输出：["AAAAACCCCC","CCCCCAAAAA"]
     */
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    res = {"AAAAACCCCC","CCCCCAAAAA"};
    assert(res == Solution().findRepeatedDnaSequences(s));
    
    /**
     输入：s = "AAAAAAAAAAAAA"
     输出：["AAAAAAAAAA"]
     */
    s = "AAAAAAAAAAAAA";
    res = {"AAAAAAAAAA"};
    assert(res == Solution().findRepeatedDnaSequences(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
