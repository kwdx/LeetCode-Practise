/*
 * @lc app=leetcode.cn id=1996 lang=cpp
 *
 * [1996] 游戏中弱角色的数量
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        
        int ans = 0;
        int maxDefense = properties[0][1];
        for (int i = 1; i < properties.size(); ++i) {
            if (properties[i][1] >= maxDefense) {
                maxDefense = properties[i][1];
            } else {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> properties;
    int res;
    
    /**
     输入：properties = [[5,5],[6,3],[3,6]]
     输出：0
     解释：不存在攻击和防御都严格高于其他角色的角色。
     */
    properties = {{5,5},{6,3},{3,6}};
    res = 0;
    assert(res == Solution().numberOfWeakCharacters(properties));

    /**
     输入：properties = [[2,2],[3,3]]
     输出：1
     解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
     */
    properties = {{2,2},{3,3}};
    res = 1;
    assert(res == Solution().numberOfWeakCharacters(properties));
    
    /**
     输入：properties = [[1,5],[10,4],[4,3]]
     输出：1
     解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
     */
    properties = {{1,5},{10,4},{4,3}};
    res = 1;
    assert(res == Solution().numberOfWeakCharacters(properties));

    cout << "OK~" << endl;

    return 0;
}
