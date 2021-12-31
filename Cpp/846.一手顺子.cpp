/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> maps;
        priority_queue<int> q;
        for (int num : hand) {
            ++maps[num];
            q.push(num);
        }
        while (!q.empty()) {
            int val = q.top();
            q.pop();
            if (maps[val] == 0) {
                continue;
            }
            --maps[val];
            for (int i = 1; i < groupSize; ++i) {
                if (maps[val - i] < 1) {
                    return false;
                }
                --maps[val - i];
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> hand;
    int groupSize;
    bool res;
    
    /**
     输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
     输出：true
     解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
     */
    hand = {1,2,3,6,2,3,4,7,8};
    groupSize = 3;
    res = true;
    assert(res == Solution().isNStraightHand(hand, groupSize));
    
    /**
     输入：hand = [1,2,3,4,5], groupSize = 4
     输出：false
     解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。
     */
    hand = {1,2,3,4,5};
    groupSize = 4;
    res = false;
    assert(res == Solution().isNStraightHand(hand, groupSize));

    cout << "OK~" << endl;

    return 0;
}
