/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = (int)pushed.size();
        for (int i = 0, j = 0; i < n; ++i) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j] && ++j >= 0) {
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> pushed;
    vector<int> popped;
    bool res;
    
    /**
     输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
     输出：true
     解释：我们可以按以下顺序执行：
     push(1), push(2), push(3), push(4), pop() -> 4,
     push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
     */
    pushed = {1,2,3,4,5};
    popped = {4,5,3,2,1};
    res = true;
    assert(res == Solution().validateStackSequences(pushed, popped));
    
    /**
     输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
     输出：false
     解释：1 不能在 2 之前弹出。
     */
    pushed = {1,2,3,4,5};
    popped = {4,3,5,1,2};
    res = false;
    assert(res == Solution().validateStackSequences(pushed, popped));

    cout << "OK~" << endl;
    
    return 0;
}
