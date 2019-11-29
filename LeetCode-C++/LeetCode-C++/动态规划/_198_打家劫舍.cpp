//
//  _198_打家劫舍.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_198_打家劫舍.hpp"

int _198_打家劫舍::rob(vector<int>& nums) {
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
