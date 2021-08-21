/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> st;
        
        for (int i = (int)temperatures.size() - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            res[i] = st.empty() ? 0 : (st.top() - i);
            st.push(i);
        }
        return res;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    vector<int> temperatures;
    vector<int> res;

    /**
     输入: temperatures = [73,74,75,71,69,72,76,73]
     输出: [1,1,4,2,1,1,0,0]
     */
    temperatures = {73,74,75,71,69,72,76,73};
    res = {1,1,4,2,1,1,0,0};
    cout << (res == Solution().dailyTemperatures(temperatures)) << endl;

    /**
     输入: temperatures = [30,40,50,60]
     输出: [1,1,1,0]
     */
    temperatures = {30,40,50,60};
    res = {1,1,1,0};
    cout << (res == Solution().dailyTemperatures(temperatures)) << endl;

    /**
     输入: temperatures = [30,60,90]
     输出: [1,1,0]
     */
    temperatures = {30,60,90};
    res = {1,1,0};
    cout << (res == Solution().dailyTemperatures(temperatures)) << endl;

    return 0;
}
