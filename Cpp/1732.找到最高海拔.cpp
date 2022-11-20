/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int cur = 0;
        for (int &g : gain) {
            cur += g;
            ans = max(ans, cur);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> gain;
    int res;
    
    /**
     输入：gain = [-5,1,5,0,-7]
     输出：1
     解释：海拔高度依次为 [0,-5,-4,1,1,-6] 。最高海拔为 1 。
     */
    gain = {-5,1,5,0,-7};
    res = 1;
    assert(res == Solution().largestAltitude(gain));
    
    /**
     输入：gain = [-4,-3,-2,-1,4,3,2]
     输出：0
     解释：海拔高度依次为 [0,-4,-7,-9,-10,-6,-3,-1] 。最高海拔为 0 。
     */
    gain = {-4,-3,-2,-1,4,3,2};
    res = 0;
    assert(res == Solution().largestAltitude(gain));

    cout << "OK~" << endl;
    
    return 0;
}
