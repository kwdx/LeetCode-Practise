/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> count;
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int box = 0, x = i;
            while (x) {
                box += x % 10;
                x /= 10;
            }
            count[box]++;
            ans = max(ans, count[box]);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int lowLimit;
    int highLimit;
    int res;
    
    /**
     输入：lowLimit = 1, highLimit = 10
     输出：2
     解释：
     盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
     小球数量：2 1 1 1 1 1 1 1 1 0  0  ...
     编号 1 的盒子放有最多小球，小球数量为 2 。
     */
    lowLimit = 1;
    highLimit = 10;
    res = 2;
    assert(res == Solution().countBalls(lowLimit, highLimit));
    
    /**
     输入：lowLimit = 5, highLimit = 15
     输出：2
     解释：
     盒子编号：1 2 3 4 5 6 7 8 9 10 11 ...
     小球数量：1 1 1 1 2 2 1 1 1 0  0  ...
     编号 5 和 6 的盒子放有最多小球，每个盒子中的小球数量都是 2 。
     */
    lowLimit = 5;
    highLimit = 15;
    res = 2;
    assert(res == Solution().countBalls(lowLimit, highLimit));
    
    /**
     输入：lowLimit = 19, highLimit = 28
     输出：2
     解释：
     盒子编号：1 2 3 4 5 6 7 8 9 10 11 12 ...
     小球数量：0 1 1 1 1 1 1 1 1 2  0  0  ...
     编号 10 的盒子放有最多小球，小球数量为 2 。
     */
    lowLimit = 19;
    highLimit = 28;
    res = 2;
    assert(res == Solution().countBalls(lowLimit, highLimit));

    cout << "OK~" << endl;
    
    return 0;
}
