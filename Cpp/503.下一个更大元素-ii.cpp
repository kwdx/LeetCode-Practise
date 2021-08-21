/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = (int)nums.size();
        vector<int> res(len);
        stack<int> st;
        for (int i = len * 2 - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <=  nums[i % len]) {
                st.pop();
            }
            res[i % len] = st.empty() ? -1 : st.top();
            st.push(nums[i % len]);
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> nums;
    vector<int> res;

    /**
     输入: [1,2,1]
     输出: [2,-1,2]
     解释: 第一个 1 的下一个更大的数是 2；
     数字 2 找不到下一个更大的数；
     第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
     */
    nums = {1,2,1};
    res = {2,-1,2};
    cout << (res == Solution().nextGreaterElements(nums)) << endl;

    return 0;
}
