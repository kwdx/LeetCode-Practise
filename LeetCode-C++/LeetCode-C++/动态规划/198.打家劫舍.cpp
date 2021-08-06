//
//  198.打家劫舍.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/house-robber/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int first = 0;  // 上上家
        int second = 0; // 上一家
        int tmp;
        for (int num : nums) {
            tmp = second;
            first += num;
            second = first > second ? first : second;
            first = tmp;
        }
        return first > second ? first : second;
    }
};

/**
输入: [1,2,3,1]
输出: 4

输入: [2,7,9,3,1]
输出: 12
*/
/**
int main(int argc, const char * argv[]) {
    Solution solution = Solution();
//    vector<int> nums = {1, 2, 3, 1};
    vector<int> nums = {2, 7, 9, 3, 1};
    printf("%d\n", solution.rob(nums));

    return 0;
}
*/
