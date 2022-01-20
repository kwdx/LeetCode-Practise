/*
 * @lc app=leetcode.cn id=2029 lang=cpp
 *
 * [2029] 石子游戏 IX
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnts[3] = {0};
        for (int i : stones) {
            ++cnts[i % 3];
        }
        return cnts[0] % 2 == 0 ? !(cnts[1] == 0 || cnts[2] == 0) : !(abs(cnts[1] - cnts[2]) <= 2);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> stones;
    bool res;
    
    /**
     输入：stones = [2,1]
     输出：true
     解释：游戏进行如下：
     - 回合 1：Alice 可以移除任意一个石子。
     - 回合 2：Bob 移除剩下的石子。
     已移除的石子的值总和为 1 + 2 = 3 且可以被 3 整除。因此，Bob 输，Alice 获胜。
     */
    stones = {2,1};
    res = true;
    assert(res == Solution().stoneGameIX(stones));
    
    /**
     输入：stones = [2]
     输出：false
     解释：Alice 会移除唯一一个石子，已移除石子的值总和为 2 。
     由于所有石子都已移除，且值总和无法被 3 整除，Bob 获胜。
     */
    stones = {2};
    res = false;
    assert(res == Solution().stoneGameIX(stones));
    
    /**
     输入：stones = [5,1,2,4,3]
     输出：false
     解释：Bob 总会获胜。其中一种可能的游戏进行方式如下：
     - 回合 1：Alice 可以移除值为 1 的第 2 个石子。已移除石子值总和为 1 。
     - 回合 2：Bob 可以移除值为 3 的第 5 个石子。已移除石子值总和为 = 1 + 3 = 4 。
     - 回合 3：Alices 可以移除值为 4 的第 4 个石子。已移除石子值总和为 = 1 + 3 + 4 = 8 。
     - 回合 4：Bob 可以移除值为 2 的第 3 个石子。已移除石子值总和为 = 1 + 3 + 4 + 2 = 10.
     - 回合 5：Alice 可以移除值为 5 的第 1 个石子。已移除石子值总和为 = 1 + 3 + 4 + 2 + 5 = 15.
     Alice 输掉游戏，因为已移除石子值总和（15）可以被 3 整除，Bob 获胜。
     */
    stones = {5,1,2,4,3};
    res = false;
    assert(res == Solution().stoneGameIX(stones));

    cout << "OK~" << endl;

    return 0;
}
