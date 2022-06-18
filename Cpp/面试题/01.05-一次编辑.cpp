//
//  A.面试题-01.-05-一次编辑.cpp
//  cpp
//
//  Created by kingsoft on 2022/5/13.
//

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int m = (int)first.length(), n = (int)second.length();
        if (abs(m - n) > 1) return false;
        int ans = 0;
        if (m == n) {
            // 只能替换
            for (int i = 0; i < m && ans <= 1; ++i) {
                if (first[i] != second[i]) {
                    ++ans;
                }
            }
        } else {
            // 可以增加或减少
            int i = 0, j = 0;
            while (i < m && j < n && ans <= 1) {
                if (first[i] == second[j]) {
                    ++i;
                    ++j;
                } else {
                    if (m < n) {
                        ++j;
                    } else {
                        ++i;
                    }
                    ++ans;
                }
            }
        }
        return ans <= 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string first, second;
    bool res;
    
    /**
     输入:
     first = "pale"
     second = "ple"
     输出: True
     */
    first = "pale";
    second = "ple";
    res = true;
    assert(res == Solution().oneEditAway(first, second));
    
    /**
     输入：
     first = "pales"
     second = "pal"
     输出: False
     */
    first = "pales";
    second = "pal";
    res = false;
    assert(res == Solution().oneEditAway(first, second));
    
    /**
     输入：
     first = "islander"
     second = "slander"
     输出: False
     */
    first = "islander";
    second = "slander";
    res = true;
    assert(res == Solution().oneEditAway(first, second));
    
    cout << "OK~" << endl;
    
    return 0;
}
