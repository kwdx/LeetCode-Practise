//
//  5853.从子集的和还原数组.cpp
//  Cpp
//
//  Created by warden on 2021/8/22.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        int minVal = sums.front(), maxVal = sums.back();
        int allSum = accumulate(sums.begin(), sums.end(), 0);
        int sum = sqrt(allSum);
        
        vector<int> ans;
        if (sum * sum == allSum) {
            
        }
        
        sum = sqrt(sum);
        return {};
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> sums, ans;
    int n;

//    /**
//     输入：n = 3, sums = [-3,-2,-1,0,0,1,2,3]
//     输出：[1,2,-3]
//     解释：[1,2,-3] 能够满足给出的子集的和：
//     - []：和是 0
//     - [1]：和是 1
//     - [2]：和是 2
//     - [1,2]：和是 3
//     - [-3]：和是 -3
//     - [1,-3]：和是 -2
//     - [2,-3]：和是 -1
//     - [1,2,-3]：和是 0
//     注意，[1,2,-3] 的任何排列和 [-1,-2,3] 的任何排列都会被视作正确答案。
//     */
//    sums = {-3,-2,-1,0,0,1,2,3};
//    n = 3;
//    ans = Solution().recoverArray(n, sums);
//    for (int an : ans) {
//        cout << an << " ";
//    }
//    cout << endl;
//
//    /**
//     输入：n = 2, sums = [0,0,0,0]
//     输出：[0,0]
//     解释：唯一的正确答案是 [0,0] 。
//     */
//    sums = {0,0,0,0};
//    n = 2;
//    ans = Solution().recoverArray(n, sums);
//    for (int an : ans) {
//        cout << an << " ";
//    }
//    cout << endl;
    
    /**
     输入：n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
     输出：[0,-1,4,5]
     解释：[0,-1,4,5] 能够满足给出的子集的和。
     */
    sums = {0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8};
    n = 4;
    ans = Solution().recoverArray(n, sums);
    for (int an : ans) {
        cout << an << " ";
    }
    cout << endl;

    cout << "OK!" << endl;

    return 0;
}
