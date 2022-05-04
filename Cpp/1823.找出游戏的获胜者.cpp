/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

#include <iostream>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int findTheWinner1(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.emplace(i);
        }
        while (q.size() > 1) {
            for (int i = 1; i < k; ++i) {
                q.emplace(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
    
    int findTheWinner(int n, int k) {
        if (n <= 1) return n;
        int ans = (findTheWinner(n - 1, k) + k) % n;
        return ans == 0 ? n : ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int k;
    int res;
    
    /**'
     输入：n = 5, k = 2
     输出：3
     解释：游戏运行步骤如下：
     1) 从小伙伴 1 开始。
     2) 顺时针数 2 名小伙伴，也就是小伙伴 1 和 2 。
     3) 小伙伴 2 离开圈子。下一次从小伙伴 3 开始。
     4) 顺时针数 2 名小伙伴，也就是小伙伴 3 和 4 。
     5) 小伙伴 4 离开圈子。下一次从小伙伴 5 开始。
     6) 顺时针数 2 名小伙伴，也就是小伙伴 5 和 1 。
     7) 小伙伴 1 离开圈子。下一次从小伙伴 3 开始。
     8) 顺时针数 2 名小伙伴，也就是小伙伴 3 和 5 。
     9) 小伙伴 5 离开圈子。只剩下小伙伴 3 。所以小伙伴 3 是游戏的获胜者。
     */
    n = 5;
    k = 2;
    res = 3;
    assert(res == Solution().findTheWinner(n, k));

    /**
     输入：n = 6, k = 5
     输出：1
     解释：小伙伴离开圈子的顺序：5、4、6、2、3 。小伙伴 1 是游戏的获胜者。
     */
    n = 6;
    k = 5;
    res = 1;
    assert(res == Solution().findTheWinner(n, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
