//
//  091.粉刷房子.cpp
//  Cpp
//
//  Created by warden on 2022/6/25.
//

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = (int)costs.size();
        int a = costs[0][0], b = costs[0][1], c = costs[0][2];
        for (int i = 1; i < n; ++i) {
            int d = min(b, c) + costs[i][0];
            int e = min(a, c) + costs[i][1];
            int f = min(a, b) + costs[i][2];
            a = d;
            b = e;
            c = f;
        }
        return min(min(a, b), c);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> costs;
    int res;
    
    /**
     输入: costs = [[17,2,17],[16,16,5],[14,3,19]]
     输出: 10
     解释: 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
          最少花费: 2 + 5 + 3 = 10。
     */
    costs = {{17,2,17},{16,16,5},{14,3,19}};
    res = 10;
    assert(res == Solution().minCost(costs));
    
    /**
     输入: costs = [[7,6,2]]
     输出: 2
     */
    costs = {{7,6,2}};
    res = 2;
    assert(res == Solution().minCost(costs));
    
    cout << "OK~" << endl;
    
    return 0;
}
