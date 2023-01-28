/*
 * @lc app=leetcode.cn id=1824 lang=cpp
 *
 * [1824] 最少侧跳次数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    static constexpr int inf = 0x3f3f3f3f;
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = (int)obstacles.size() - 1;
        vector<int> d = {1,0,1};
        for (int i = 1; i <= n; ++i) {
            int minCnt = inf;
            for (int j = 0; j < 3; ++j) {
                if (j == obstacles[i] - 1) {
                    d[j] = inf;
                } else {
                    minCnt = min(minCnt, d[j]);
                }
            }
            for (int j = 0; j < 3; ++j) {
                if (j == obstacles[i] - 1) {
                    continue;
                }
                d[j] = min(d[j], minCnt + 1);
            }
        }
        return *min_element(d.begin(), d.end());
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> obstacles;
    int res;

    /**
     输入：obstacles = [0,1,2,3,0]
     输出：2
     解释：最优方案如上图箭头所示。总共有 2 次侧跳（红色箭头）。
     注意，这只青蛙只有当侧跳时才可以跳过障碍（如上图点 2 处所示）。
     */
    obstacles = {0,1,2,3,0};
    res = 2;
    assert(res == Solution().minSideJumps(obstacles));
    
    /**
     输入：obstacles = [0,1,1,3,3,0]
     输出：0
     解释：跑道 2 没有任何障碍，所以不需要任何侧跳。
     */
    obstacles = {0,1,1,3,3,0};
    res = 0;
    assert(res == Solution().minSideJumps(obstacles));
    
    /**
     输入：obstacles = [0,2,1,0,3,0]
     输出：2
     解释：最优方案如上图所示。总共有 2 次侧跳。
     */
    obstacles = {0,2,1,0,3,0};
    res = 2;
    assert(res == Solution().minSideJumps(obstacles));
    
    cout << "OK~" << endl;
    
    return 0;
}
