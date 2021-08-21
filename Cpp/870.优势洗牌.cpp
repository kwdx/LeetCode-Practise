/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<pair<int, int>> valToIndexQ;
        for (int i = 0; i < nums2.size(); i++) {
            valToIndexQ.push({nums2[i], i});
        }
        sort(nums1.begin(), nums1.end());
        
        int left = 0, right = (int)nums1.size() - 1;
        vector<int> res(nums1.size());
        while (left <= right) {
            pair<int, int> valIndex = valToIndexQ.top();
            if (nums1[right] > valIndex.first) {
                // 够大，压死
                res[valIndex.second] = nums1[right--];
            } else {
                // 不够大，拿小的送命
                res[valIndex.second] = nums1[left++];
            }
            valToIndexQ.pop();
        }
        
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums1, nums2, res;
    
//    /**
//     输入：A = [2,7,11,15], B = [1,10,4,11]
//     输出：[2,11,7,15]
//     */
//    nums1 = {2,7,11,15};
//    nums2 = {1,10,4,11};
//    res = {2,11,7,15};
//    cout << (res == Solution().advantageCount(nums1, nums2)) << endl;
//
//    /**
//     输入：A = [12,24,8,32], B = [13,25,32,11]
//     输出：[24,32,8,12]
//
//     */
//    nums1 = {12,24,8,32};
//    nums2 = {13,25,32,11};
//    res = {24,32,8,12};
//    cout << (res == Solution().advantageCount(nums1, nums2)) << endl;
    
    /**
     输入：A = [2,0,4,1,2], B = [1,3,0,0,2]
     输出：[2,0,2,1,4]

     */
    nums1 = {2,0,4,1,2};
    nums2 = {1,3,0,0,2};
    res = {2,0,2,1,4};
    cout << (res == Solution().advantageCount(nums1, nums2)) << endl;
    cout << (res == Solution().advantageCount(nums1, nums2)) << endl;

    return 0;
}
