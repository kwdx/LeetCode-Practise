/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        int n = (int)colors.length();
        for (int i = 1; i < n - 1; ++i) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A') ++a;
            if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B') ++b;
        }
        return a > b;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string colors;
    bool res;
    
    /**
     输入：colors = "AAABABB"
     输出：true
     解释：
     AAABABB -> AABABB
     Alice 先操作。
     她删除从左数第二个 'A' ，这也是唯一一个相邻颜色片段都是 'A' 的 'A' 。

     现在轮到 Bob 操作。
     Bob 无法执行任何操作，因为没有相邻位置都是 'B' 的颜色片段 'B' 。
     因此，Alice 获胜，返回 true 。
     */
    colors = "AAABABB";
    res = true;
    assert(res == Solution().winnerOfGame(colors));
    
    /**
     输入：colors = "AA"
     输出：false
     解释：
     Alice 先操作。
     只有 2 个 'A' 且它们都在字符串的两端，所以她无法执行任何操作。
     因此，Bob 获胜，返回 false 。
     */
    colors = "AA";
    res = false;
    assert(res == Solution().winnerOfGame(colors));
    
    /**
     输入：colors = "ABBBBBBBAAA"
     输出：false
     解释：
     ABBBBBBBAAA -> ABBBBBBBAA
     Alice 先操作。
     她唯一的选择是删除从右数起第二个 'A' 。

     ABBBBBBBAA -> ABBBBBBAA
     接下来轮到 Bob 操作。
     他有许多选择，他可以选择任何一个 'B' 删除。

     然后轮到 Alice 操作，她无法删除任何片段。
     所以 Bob 获胜，返回 false 。
     */
    colors = "ABBBBBBBAAA";
    res = false;
    assert(res == Solution().winnerOfGame(colors));

    cout << "OK~" << endl;
    
    return 0;
}
