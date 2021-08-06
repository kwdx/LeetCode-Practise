//
//  215.数组中的第K个最大元素.cpp
//  LeetCode-C++
//
//  Created by warden on 2020/2/23.
//  Copyright © 2020 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
private:
    int numSize;
public:
    int findKthLargest(vector<int>& nums, int k) {
        numSize = (int)nums.size();
        heapify(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[numSize-1], nums[0]);
            numSize--;
            siftDown(nums, 0);
        }
        return nums[nums.size() - k];
    }
    
    /**
     建堆
     */
    void heapify(vector<int>& nums) {
        // 自下而上的下溢
        for (int i = (numSize >> 1) - 1; i >= 0; i--) {
            siftDown(nums, i);
        }
    }
    
    void siftDown(vector<int>& nums, int index) {
        int num = nums[index];
        int half = numSize >> 1;
        // 让第一个叶子节点的索引 == 非叶子节点的数量
        while (index < half) {
            int childIndex = (index << 1) + 1;
            int child = nums[childIndex];
            
            int rightIndex = childIndex + 1;
            
            // 选出左右子节点最大的那个
            if (rightIndex < numSize && nums[rightIndex] > child) {
                child = nums[rightIndex];
                childIndex = rightIndex;
            }
            
            if (num >= child) {
                break;
            }
            nums[index] = child;
            index = childIndex;
        }
        nums[index] = num;
    }
};

/**
 示例 1:

 输入: [3,2,1,5,6,4] 和 k = 2
 输出: 5
 示例 2:

 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 输出: 4
 */
/**
int main(int argc, const char * argv[]) {
    Solution solution = Solution();
//    vector<int> nums = {3, 2, 1, 5, 6, 4};
//    int result = solution.findKthLargest(nums, 2);
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int result = solution.findKthLargest(nums, 4);
    printf("%d\n", result);

    return 0;
}
 */
