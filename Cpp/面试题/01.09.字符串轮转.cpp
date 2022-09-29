/*
 * @lc app=leetcode.cn id=string-rotation-lcci lang=cpp
 *
 * [面试题] 01.09. 字符串轮转
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        
        return (s1 + s1).find(s2) != string::npos;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string s1;
    string s2;
    bool res;
    
    /**
     输入：s1 = "waterbottle", s2 = "erbottlewat"
     输出：True
     */
    s1 = "waterbottle";
    s2 = "erbottlewat";
    res = true;
    assert(res == Solution().isFlipedString(s1, s2));
    
    /**
     输入：s1 = "aa", s2 = "aba"
     输出：False
     */
    s1 = "aa";
    s2 = "aba";
    res = false;
    assert(res == Solution().isFlipedString(s1, s2));

    cout << "OK~" << endl;
    
    return 0;
}

