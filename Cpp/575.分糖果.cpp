/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candySet(candyType.begin(), candyType.end());
        return (int)min(candySet.size(), candyType.size() / 2);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> candyType;
    int res;
    
    /**
     输入：candyType = [1,1,2,2,3,3]
     输出：3
     解释：Alice 只能吃 6 / 2 = 3 枚糖，由于只有 3 种糖，她可以每种吃一枚。
     */
    candyType = {1,1,2,2,3,3};
    res = 3;
    assert(res == Solution().distributeCandies(candyType));
    
    /**
     输入：candyType = [1,1,2,3]
     输出：2
     解释：Alice 只能吃 4 / 2 = 2 枚糖，不管她选择吃的种类是 [1,2]、[1,3] 还是 [2,3]，她只能吃到两种不同类的糖。
     */
    candyType = {1,1,2,3};
    res = 2;
    assert(res == Solution().distributeCandies(candyType));
    
    /**
     输入：candyType = [6,6,6,6]
     输出：1
     解释：Alice 只能吃 4 / 2 = 2 枚糖，尽管她能吃 2 枚，但只能吃到 1 种糖。
     */
    candyType = {6,6,6,6};
    res = 1;
    assert(res == Solution().distributeCandies(candyType));

    cout << "OK~" << endl;

    return 0;
}
