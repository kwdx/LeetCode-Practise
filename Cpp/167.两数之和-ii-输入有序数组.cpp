/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = (int)numbers.size() - 1;
        
        while (left < right) {
            if (numbers[left] + numbers[right] < target)
                left++;
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                return {left + 1, right + 1};
        }
        return {-1, -1};
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> numbers, res;
    int target;
    
    /**
     输入：numbers = [2,7,11,15], target = 9
     输出：[1,2]
     解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
     */
    numbers = {2,7,11,15};
    target = 9;
    res = {1,2};
    cout << (res == Solution().twoSum(numbers, target)) << endl;
    
    /**
     输入：numbers = [2,3,4], target = 6
     输出：[1,3]
     */
    numbers = {2,3,4};
    target = 6;
    res = {1,3};
    cout << (res == Solution().twoSum(numbers, target)) << endl;
    
    /**
     输入：numbers = [-1,0], target = -1
     输出：[1,2]
     */
    numbers = {-1,0};
    target = -1;
    res = {1,2};
    cout << (res == Solution().twoSum(numbers, target)) << endl;
    
    return 0;
}
