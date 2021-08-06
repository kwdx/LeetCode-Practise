//
//  11.盛最多水的容器.cpp
//  LeetCode-C++
//
//  Created by warden on 2021/7/28.
//  Copyright © 2021 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/container-with-most-water/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

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

//int main(int argc, const char * argv[]) {
//    // insert code here...
//
//    vector<int> height;
//
//    height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//    cout << "49 == " << Solution().maxArea(height) << endl;
//
//    height = {1, 1};
//    cout << "1 == " << Solution().maxArea(height) << endl;
//
//    height = {4, 3, 2, 1, 4};
//    cout << "16 == " << Solution().maxArea(height) << endl;
//
//    height = {1, 2, 1};
//    cout << "2 == " << Solution().maxArea(height) << endl;
//
//    height = {1, 2, 4, 3};
//    cout << "4 == " << Solution().maxArea(height) << endl;
//
//    height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//    cout << "49 == " << Solution().maxArea(height) << endl;
//
//    return 0;
//}
