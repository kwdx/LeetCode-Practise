/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnts[5] = {0};
        for (char c : text) {
            if (c == 'b') ++cnts[0];
            else if (c == 'a') ++cnts[1];
            else if (c == 'l') ++cnts[2];
            else if (c == 'o') ++cnts[3];
            else if (c == 'n') ++cnts[4];
        }
        cnts[2] >>= 1;
        cnts[3] >>= 1;
        int ans = cnts[0];
        for (int i = 0; i < 5; ++i) ans = min(ans, cnts[i]);
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string text;
    int res;
    
    /**
     输入：text = "nlaebolko"
     输出：1
     */
    text = "nlaebolko";
    res = 1;
    assert(res == Solution().maxNumberOfBalloons(text));
    
    /**
     输入：text = "loonbalxballpoon"
     输出：2
     */
    text = "loonbalxballpoon";
    res = 2;
    assert(res == Solution().maxNumberOfBalloons(text));
    
    /**
     输入：text = "leetcode"
     输出：0
     */
    text = "leetcode";
    res = 0;
    assert(res == Solution().maxNumberOfBalloons(text));

    cout << "OK~" << endl;

    return 0;
}
