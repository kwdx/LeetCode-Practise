/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        for (auto& s : cpdomains) {
            int n = (int)s.length();
            int idx = 0;
            while (idx < n && s[idx] != ' ') ++idx;
            int cnt = stoi(s.substr(0, idx));
            int start = idx + 1;
            idx = n - 1;
            while (idx >= start) {
                while (idx >= start && s[idx] != '.') --idx;
                string cur = s.substr(idx + 1);
                map[cur] += cnt;
                --idx;
            }
        }
        vector<string> ans;
        for (auto item : map) {
            ans.push_back(to_string(item.second) + " " + item.first);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> cpdomains;
    vector<string> res;
    
    /**
     输入：cpdomains = ["9001 discuss.leetcode.com"]
     输出：["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
     解释：例子中仅包含一个网站域名："discuss.leetcode.com"。
     按照前文描述，子域名 "leetcode.com" 和 "com" 都会被访问，所以它们都被访问了 9001 次。
     */
    cpdomains = {"9001 discuss.leetcode.com"};
    res = {"9001 discuss.leetcode.com","9001 leetcode.com","9001 com"};
    assert(res == Solution().subdomainVisits(cpdomains));
    
    /**
     输入：cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
     输出：["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
     解释：按照前文描述，会访问 "google.mail.com" 900 次，"yahoo.com" 50 次，"intel.mail.com" 1 次，"wiki.org" 5 次。
     而对于父域名，会访问 "mail.com" 900 + 1 = 901 次，"com" 900 + 50 + 1 = 951 次，和 "org" 5 次。
     */
    cpdomains = {"9001 discuss.leetcode.com"};
    res = {"9001 discuss.leetcode.com","9001 leetcode.com","9001 com"};
    assert(res == Solution().subdomainVisits(cpdomains));
    
    cout << "OK~" << endl;
    
    return 0;
}
