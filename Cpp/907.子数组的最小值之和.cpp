/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> st;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[i] <= arr[st.back()]) {
                st.pop_back();
            }
            left[i] = i - (st.empty() ? -1 : st.back());
            st.emplace_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[i] < arr[st.back()]) {
                st.pop_back();
            }
            right[i] = (st.empty() ? n : st.back()) - i;
            st.emplace_back(i);
        }
        long long ans = 0;
        long long mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans = (ans + (long long)left[i] * right[i] * arr[i]) % mod;
        }
        return (int)ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    int res;
    
    /**
     输入：arr = [3,1,2,4]
     输出：17
     解释：
     子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
     最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
     */
    arr = {3,1,2,4};
    res = 17;
    assert(res == Solution().sumSubarrayMins(arr));
    
    /**
     输入：arr = [11,81,94,43,3]
     输出：444
     */
    arr = {11,81,94,43,3};
    res = 444;
    assert(res == Solution().sumSubarrayMins(arr));
    
    cout << "OK~" << endl;
    
    return 0;
}
