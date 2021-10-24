/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int ans = 0;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            ans = max(ans, area);
            if (height[left] <= height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> height;
    int res;
    
    /**
     输入：[1,8,6,2,5,4,8,3,7]
     输出：49
     解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
     */
    height = {1,8,6,2,5,4,8,3,7};
    res = 49;
    assert(res == Solution().maxArea(height));
    
    /**
     输入：height = [1,1]
     输出：1
     */
    height = {1,1};
    res = 1;
    assert(res == Solution().maxArea(height));
    
    /**
     输入：height = [4,3,2,1,4]
     输出：16
     */
    height = {4,3,2,1,4};
    res = 16;
    assert(res == Solution().maxArea(height));
    
    /**
     输入：height = [1,2,1]
     输出：2
     */
    height = {1,2,1};
    res = 2;
    assert(res == Solution().maxArea(height));

    cout << "OK~" << endl;
    
    return 0;
}
