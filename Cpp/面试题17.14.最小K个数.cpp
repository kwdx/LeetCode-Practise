//
//  面试题17.14.最小K个数.cpp
//  Cpp
//
//  Created by warden on 2021/9/3.
//
// https://leetcode-cn.com/problems/smallest-k-lcci/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for (int num : arr) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res(pq.size());
        for (int i = (int)res.size() - 1; i >= 0; --i) {
            res[i] = pq.top();
            pq.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr, res;
    int k;
    
    /**
     输入： arr = [1,3,5,7,2,4,6,8], k = 4
     输出： [1,2,3,4]
     */
    arr = {1,3,5,7,2,4,6,8};
    k = 4;
    res = {1,2,3,4};
    
    assert(res == Solution().smallestK(arr, k));

    cout << "OK~" << endl;

    return 0;
}
