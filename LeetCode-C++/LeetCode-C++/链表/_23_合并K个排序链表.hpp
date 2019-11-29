//
//  _23_合并K个排序链表.hpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/merge-k-sorted-lists

#ifndef _23___K______hpp
#define _23___K______hpp

#include <stdio.h>
#include "ListNode.hpp"
#include <vector>

using namespace std;

class _23_合并K个排序链表 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists);
    
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

#endif /* _23___K______hpp */
