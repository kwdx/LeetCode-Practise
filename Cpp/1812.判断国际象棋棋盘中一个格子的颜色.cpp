/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] - 'a') % 2 != (coordinates[1] - '1') % 2;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string coordinates;
    bool res;
    
    /**
     输入：coordinates = "a1"
     输出：false
     解释：如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
     */
    coordinates = "a1";
    res = false;
    assert(res == Solution().squareIsWhite(coordinates));
    
    /**
     输入：coordinates = "h3"
     输出：true
     解释：如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
     */
    coordinates = "h3";
    res = true;
    assert(res == Solution().squareIsWhite(coordinates));

    /**
     输入：coordinates = "c7"
     输出：false
     */
    coordinates = "c7";
    res = false;
    assert(res == Solution().squareIsWhite(coordinates));

    cout << "OK~" << endl;
    
    return 0;
}
