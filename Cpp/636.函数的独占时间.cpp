/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;   // {idx, 开始运行时间}
        for (string& log : logs) {
            char type[10];
            int idx, timestamp;
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);
            if (type[0] == 's') {
                if (!st.empty()) {
                    ans[st.top().first] += timestamp - st.top().second;
                    st.top().second = timestamp;
                }
                st.emplace(idx, timestamp);
            } else {
                auto t = st.top();
                st.pop();
                ans[t.first] += timestamp - t.second + 1;
                if (!st.empty()) {
                    st.top().second = timestamp + 1;
                }
            }

        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<string> logs;
    vector<int> res;
    
    /**
     输入：n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
     输出：[3,4]
     解释：
     函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，于时间戳 1 的末尾结束执行。
     函数 1 在时间戳 2 的起始开始执行，执行 4 个单位时间，于时间戳 5 的末尾结束执行。
     函数 0 在时间戳 6 的开始恢复执行，执行 1 个单位时间。
     所以函数 0 总共执行 2 + 1 = 3 个单位时间，函数 1 总共执行 4 个单位时间。
     */
    n = 2;
    logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    res = {3,4};
    assert(res == Solution().exclusiveTime(n, logs));
    
    /**
     输入：n = 1, logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
     输出：[8]
     解释：
     函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，并递归调用它自身。
     函数 0（递归调用）在时间戳 2 的起始开始执行，执行 4 个单位时间。
     函数 0（初始调用）恢复执行，并立刻再次调用它自身。
     函数 0（第二次递归调用）在时间戳 6 的起始开始执行，执行 1 个单位时间。
     函数 0（初始调用）在时间戳 7 的起始恢复执行，执行 1 个单位时间。
     所以函数 0 总共执行 2 + 4 + 1 + 1 = 8 个单位时间。
     */
    n = 1;
    logs = {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"};
    res = {8};
    assert(res == Solution().exclusiveTime(n, logs));
    
    /**
     输入：n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
     输出：[7,1]
     解释：
     函数 0 在时间戳 0 的起始开始执行，执行 2 个单位时间，并递归调用它自身。
     函数 0（递归调用）在时间戳 2 的起始开始执行，执行 4 个单位时间。
     函数 0（初始调用）恢复执行，并立刻调用函数 1 。
     函数 1在时间戳 6 的起始开始执行，执行 1 个单位时间，于时间戳 6 的末尾结束执行。
     函数 0（初始调用）在时间戳 7 的起始恢复执行，执行 1 个单位时间，于时间戳 7 的末尾结束执行。
     所以函数 0 总共执行 2 + 4 + 1 = 7 个单位时间，函数 1 总共执行 1 个单位时间。
     */
    n = 2;
    logs = {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
    res = {7,1};
    assert(res == Solution().exclusiveTime(n, logs));
    
    /**
     输入：n = 2, logs = ["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]
     输出：[8,1]
     */
    n = 2;
    logs = {"0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"};
    res = {8,1};
    assert(res == Solution().exclusiveTime(n, logs));
    
    /**
     输入：n = 1, logs = ["0:start:0","0:end:0"]
     输出：[1]
     */
    n = 1;
    logs = {"0:start:0","0:end:0"};
    res = {1};
    assert(res == Solution().exclusiveTime(n, logs));
    
    cout << "OK~" << endl;
    
    return 0;
}
