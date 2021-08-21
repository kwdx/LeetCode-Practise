/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        unordered_map<int, int> valToNexts;
        stack<int> st;
        
        for (int i = (int)nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            valToNexts[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = valToNexts[nums1[i]];
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums1, nums2, result, nextGreaters;

    nums1 = {4,1,2};
    nums2 = {1,3,4,2};
    result = {-1,3,-1};
    nextGreaters = Solution().nextGreaterElement(nums1, nums2);
    cout << (result == nextGreaters) << endl;

    nums1 = {2,4};
    nums2 = {1,2,3,4};
    result = {3,-1};
    nextGreaters = Solution().nextGreaterElement(nums1, nums2);
    cout << (result == nextGreaters) << endl;

    return 0;
}
