//
//  5832.构造元素不等于两相邻元素平均值的数组.cpp
//  Cpp
//
//  Created by warden on 2021/8/15.
//
// https://leetcode-cn.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
        for (int i = (int)nums.size() - 2; i > 0; i--) {
            if ((nums[i] << 1) == nums[i - 1] + nums[i + 1]) {
                int tmp = nums[i];
                nums[i] = nums[0];
                nums[0] = tmp;
            }
        }
        return nums;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    vector<int> nums;
    
    nums = {1,2,5,9};
    nums = Solution().rearrangeArray(nums);
    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] << 1 == nums[i - 1] + nums[i + 1]) {
            for (auto num : nums)
                cout << num << ",";
            cout << endl;
            break;
        }
    }
    
    nums = {1,2,3,4,5};
    nums = Solution().rearrangeArray(nums);
    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] << 1 == nums[i - 1] + nums[i + 1]) {
            for (auto num : nums)
                cout << num << ",";
            cout << endl;
            break;
        }
    }

    nums = {6,2,0,9,7};
    nums = Solution().rearrangeArray(nums);
    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] << 1 == nums[i - 1] + nums[i + 1]) {
            for (auto num : nums)
                cout << num << ",";
            cout << endl;
            break;
        }
    }


    nums = {1,5,2,6,3,7,4,8};
    nums = Solution().rearrangeArray(nums);
    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] << 1 == nums[i - 1] + nums[i + 1]) {
            for (auto num : nums)
                cout << num << ",";
            cout << endl;
            break;
        }
    }


    nums = {42,6,10,21,26,44,31,18,25,48,35,2,29,5,20};
    nums = Solution().rearrangeArray(nums);
    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] << 1 == nums[i - 1] + nums[i + 1]) {
            for (auto num : nums)
                cout << num << ",";
            cout << endl;
            break;
        }
    }

    nums = {3,1,12,10,7,6,17,14,4,13};
    nums = Solution().rearrangeArray(nums);
    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] << 1 == nums[i - 1] + nums[i + 1]) {
            for (auto num : nums)
                cout << num << ",";
            cout << endl;
            break;
        }
    }

    return 0;
}
