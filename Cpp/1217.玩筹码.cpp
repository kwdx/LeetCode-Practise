/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < position.size(); ++i) {
            if (position[i] & 1) {
                a += 1;
            } else {
                b += 1;
            }
        }
        return min(a, b);
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> position;
    int res;
    
    /**
     输入：position = [1,2,3]
     输出：1
     解释：第一步:将位置3的筹码移动到位置1，成本为0。
     第二步:将位置2的筹码移动到位置1，成本= 1。
     总成本是1。
     */
    position = {1,2,3};
    res = 1;
    assert(res == Solution().minCostToMoveChips(position));
    
    /**
     输入：position = [2,2,2,3,3]
     输出：2
     解释：我们可以把位置3的两个筹码移到位置2。每一步的成本为1。总成本= 2。
     */
    position = {2,2,2,3,3};
    res = 2;
    assert(res == Solution().minCostToMoveChips(position));
    
    /**
     输入：position = [1,1000000000]
     输出：1
     */
    position = {1,1000000000};
    res = 1;
    assert(res == Solution().minCostToMoveChips(position));
    
    cout << "OK~" << endl;
    
    return 0;
}
