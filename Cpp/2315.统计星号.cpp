/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool flag = true;
        for (char c : s) {
            if (c == '|') {
                flag = !flag;
            } else if (c == '*' && flag) {
                ++ans;
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
     输入：s = "l|*e*et|c**o|*de|"
     输出：2
     解释：不在竖线对之间的字符加粗加斜体后，得到字符串："l|*e*et|c**o|*de|" 。
     第一和第二条竖线 '|' 之间的字符不计入答案。
     同时，第三条和第四条竖线 '|' 之间的字符也不计入答案。
     不在竖线对之间总共有 2 个星号，所以我们返回 2 。
     */
    s = "l|*e*et|c**o|*de|";
    res = 2;
    assert(res == Solution().countAsterisks(s));
    
    /**
     输入：s = "iamprogrammer"
     输出：0
     解释：在这个例子中，s 中没有星号。所以返回 0 。
     */
    s = "iamprogrammer";
    res = 0;
    assert(res == Solution().countAsterisks(s));
    
    /**
     输入：s = "yo|uar|e**|b|e***au|tifu|l"
     输出：5
     解释：需要考虑的字符加粗加斜体后："yo|uar|e**|b|e***au|tifu|l" 。不在竖线对之间总共有 5 个星号。所以我们返回 5 。
     */
    s = "yo|uar|e**|b|e***au|tifu|l";
    res = 5;
    assert(res == Solution().countAsterisks(s));

    cout << "OK~" << endl;
    
    return 0;
}
