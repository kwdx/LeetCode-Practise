/*
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = (int)distance.size();
        if (n < 4) return false;
        
        for (int i = 3; i < n; ++i) {
            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
                return true;
            }
            if (i >= 4 && distance[i - 1] == distance[i - 3] &&
                distance[i] + distance[i - 4] >= distance[i - 2]) {
                return true;
            }
            if (i >= 5 && distance[i - 1] <= distance[i - 3] &&
                distance[i - 2] > distance[i - 4] &&
                distance[i] + distance[i - 4] >= distance[i - 2] &&
                distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
                return true;
            }
        }
        
        return false;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> distance;
    bool res;
    
    /**
     输入：distance = [2,1,1,2]
     输出：true
     */
    distance = {2,1,1,2};
    res = true;
    assert(res == Solution().isSelfCrossing(distance));

    /**
     输入：distance = [1,2,3,4]
     输出：false
     */
    distance = {1,2,3,4};
    res = false;
    assert(res == Solution().isSelfCrossing(distance));

    /**
     输入：distance = [1,1,1,1]
     输出：true
     */
    distance = {1,1,1,1};
    res = true;
    assert(res == Solution().isSelfCrossing(distance));
    
    /**
     输入：distance = [1,2,3,4]
     输出：false
     */
    distance = {1,2,3,4};
    res = false;
    assert(res == Solution().isSelfCrossing(distance));

    cout << "OK~" << endl;

    return 0;
}
