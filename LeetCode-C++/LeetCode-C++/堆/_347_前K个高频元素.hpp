//
//  _347_前K个高频元素.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/top-k-frequent-elements/

#ifndef _347__K______hpp
#define _347__K______hpp

#include <stdio.h>
#include <vector>

using namespace std;

class _347_前K个高频元素 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k);
private:
    int pivotIndex(vector<pair<int, int>>& entries, int begin, int end);
};

#endif /* _347__K______hpp */
