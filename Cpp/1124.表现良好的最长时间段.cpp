/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = (int)hours.size();
        vector<int> s(n + 1);
        stack<int> st;
        st.push(0);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (s[st.top()] > s[i]) {
                st.push(i);
            }
        }
        
        int ans = 0;
        for (int r = n; r >= 1; r--) {
            while (st.size() && s[st.top()] < s[r]) {
                ans = max(ans, r - st.top());
                st.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> hours;
    int res;
    
    /**
     输入：hours = [9,9,6,0,6,6,9]
     输出：3
     解释：最长的表现良好时间段是 [9,9,6]。
     */
    hours = {9,9,6,0,6,6,9};
    res = 3;
    assert(res == Solution().longestWPI(hours));
    
    /**
     输入：hours = [6,6,6]
     输出：0
     */
    hours = {6,6,6};
    res = 0;
    assert(res == Solution().longestWPI(hours));

    cout << "OK~" << endl;
    
    return 0;
}
