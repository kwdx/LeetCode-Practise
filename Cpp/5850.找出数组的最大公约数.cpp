//
//  5850.找出数组的最大公约数.cpp
//  Cpp
//
//  Created by warden on 2021/8/22.
//

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int low = nums[0], high = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            low = low < nums[i] ? low : nums[i];
            high = high > nums[i] ? high : nums[i];
        }
                
        //求余
        while (low != 0) {
            int temp = high % low;
            high = low;
            low = temp;
        }
        return high;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    
    /**
     输入：nums = [2,5,6,9,10]
     输出：2
     解释：
     nums 中最小的数是 2
     nums 中最大的数是 10
     2 和 10 的最大公约数是 2
     */
    nums = {2,5,6,9,10};
    assert(2 == Solution().findGCD(nums));
    
    /**
     输入：nums = [7,5,6,8,3]
     输出：1
     解释：
     nums 中最小的数是 3
     nums 中最大的数是 8
     3 和 8 的最大公约数是 1
     */
    nums = {7,5,6,8,3};
    assert(1 == Solution().findGCD(nums));

    /**
     输入：nums = [3,3]
     输出：3
     解释：
     nums 中最小的数是 3
     nums 中最大的数是 3
     3 和 3 的最大公约数是 3
     */
    nums = {3,3};
    assert(3 == Solution().findGCD(nums));
    
    cout << "OK!" << endl;

    return 0;
}
