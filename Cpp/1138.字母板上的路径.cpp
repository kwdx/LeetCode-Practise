/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        int cx = 0, cy = 0;
        string ans;
        for (char c : target) {
            int nx = (c - 'a') / 5;
            int ny = (c - 'a') % 5;
            if (nx < cx) {
                ans.append(cx - nx, 'U');
            }
            if (ny < cy) {
                ans.append(cy - ny, 'L');
            }
            if (nx > cx) {
                ans.append(nx - cx, 'D');
            }
            if (ny > cy) {
                ans.append(ny - cy, 'R');
            }
            ans.push_back('!');
            cx = nx;
            cy = ny;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string target;
    string res;
    
    /**
     输入：target = "leet"
     输出："DDR!UURRR!!DDD!"
     */
    target = "leet";
    res = "DDR!UURRR!!DDD!";
    assert(res == Solution().alphabetBoardPath(target));
    
    /**
     输入：target = "code"
     输出："RR!DDRR!UUL!R!"
     */
    target = "code";
    res = "RR!DDRR!UUL!R!";
    assert(res == Solution().alphabetBoardPath(target));
    

    cout << "OK~" << endl;
    
    return 0;
}
