/*
 * @lc app=leetcode.cn id=1753 lang=cpp
 *
 * [1753] 移除石子的最大得分
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxVal = max({a, b, c});
        if (sum - maxVal < maxVal) {
            return sum - maxVal;
        }
        return sum >> 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a;
    int b;
    int c;
    int res;
    
    /**
     输入：a = 2, b = 4, c = 6
     输出：6
     解释：石子起始状态是 (2, 4, 6) ，最优的一组操作是：
     - 从第一和第三堆取，石子状态现在是 (1, 4, 5)
     - 从第一和第三堆取，石子状态现在是 (0, 4, 4)
     - 从第二和第三堆取，石子状态现在是 (0, 3, 3)
     - 从第二和第三堆取，石子状态现在是 (0, 2, 2)
     - 从第二和第三堆取，石子状态现在是 (0, 1, 1)
     - 从第二和第三堆取，石子状态现在是 (0, 0, 0)
     总分：6 分 。
     */
    a = 2;
    b = 4;
    c = 6;
    res = 6;
    assert(res == Solution().maximumScore(a, b, c));
    
    /**
     输入：a = 4, b = 4, c = 6
     输出：7
     解释：石子起始状态是 (4, 4, 6) ，最优的一组操作是：
     - 从第一和第二堆取，石子状态现在是 (3, 3, 6)
     - 从第一和第三堆取，石子状态现在是 (2, 3, 5)
     - 从第一和第三堆取，石子状态现在是 (1, 3, 4)
     - 从第一和第三堆取，石子状态现在是 (0, 3, 3)
     - 从第二和第三堆取，石子状态现在是 (0, 2, 2)
     - 从第二和第三堆取，石子状态现在是 (0, 1, 1)
     - 从第二和第三堆取，石子状态现在是 (0, 0, 0)
     总分：7 分 。
     */
    a = 4;
    b = 4;
    c = 6;
    res = 7;
    assert(res == Solution().maximumScore(a, b, c));
    
    /**
     输入：a = 1, b = 8, c = 8
     输出：8
     解释：最优的一组操作是连续从第二和第三堆取 8 回合，直到将它们取空。
     注意，由于第二和第三堆已经空了，游戏结束，不能继续从第一堆中取石子。
     */
    a = 1;
    b = 8;
    c = 8;
    res = 8;
    assert(res == Solution().maximumScore(a, b, c));

    cout << "OK~" << endl;
    
    return 0;
}
