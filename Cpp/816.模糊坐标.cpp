/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<string> getPos(string s) {
        vector<string> pos;
        if (s[0] != '0' || s == "0") pos.push_back(s);
        for (int p = 1; p < s.size(); ++p) {
            if ((p != 1 && s[0] == '0') || s.back() == '0') continue;
            pos.push_back(s.substr(0, p) + "." + s.substr(p));
        }
        return pos;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = (int)s.size() - 2;
        vector<string> ans;
        s = s.substr(1, n);
        for (int l = 1; l < n; ++l) {
            vector<string> lt = getPos(s.substr(0, l));
            if (lt.empty()) continue;;
            vector<string> rt = getPos(s.substr(l));;
            if (rt.empty()) continue;
            for (auto& i : lt) {
                for (auto& j : rt) {
                    ans.push_back("(" + i + ", " + j + ")");
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s;
    vector<string> res;
    
    /**
     示例 1:
     输入: "(123)"
     输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
     */
    s = "(123)";
    res = {"(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"};
    sort(res.begin(), res.end());
    assert(res == Solution().ambiguousCoordinates(s));
    
    /**
     示例 2:
     输入: "(00011)"
     输出:  ["(0.001, 1)", "(0, 0.011)"]
     解释:
     0.0, 00, 0001 或 00.01 是不被允许的。
     */
    s = "(00011)";
    res = {"(0.001, 1)", "(0, 0.011)"};
    sort(res.begin(), res.end());
    assert(res == Solution().ambiguousCoordinates(s));
    
    /**
     示例 3:
     输入: "(0123)"
     输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
     */
    s = "(0123)";
    res = {"(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"};
    sort(res.begin(), res.end());
    assert(res == Solution().ambiguousCoordinates(s));
    
    /**
     示例 4:
     输入: "(100)"
     输出: [(10, 0)]
     解释:
     1.0 是不被允许的。
     */
    s = "(100)";
    res = {"(10, 0)"};
    sort(res.begin(), res.end());
    assert(res == Solution().ambiguousCoordinates(s));
    
    cout << "OK~" << endl;
    
    return 0;
}
