/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        deque<int> q;
        int val;
        for (int i = 0; i < ops.size(); ++i) {
            string op = ops[i];
            if (op == "+") {
                val = q.back() + q[q.size() - 2];
                q.push_back(val);
            } else if (op == "D") {
                val = q.back() * 2;
                q.push_back(val);
            } else if (op == "C") {
                q.pop_back();
            } else {
                val = atoi(op.c_str());
                q.push_back(val);
            }
        }
        return accumulate(q.begin(), q.end(), 0);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> ops;
    int res;
    
    /**
     输入：ops = ["5","2","C","D","+"]
     输出：30
     解释：
     "5" - 记录加 5 ，记录现在是 [5]
     "2" - 记录加 2 ，记录现在是 [5, 2]
     "C" - 使前一次得分的记录无效并将其移除，记录现在是 [5].
     "D" - 记录加 2 * 5 = 10 ，记录现在是 [5, 10].
     "+" - 记录加 5 + 10 = 15 ，记录现在是 [5, 10, 15].
     所有得分的总和 5 + 10 + 15 = 30
     */
    ops = {"5","2","C","D","+"};
    res = 30;
    assert(res == Solution().calPoints(ops));
    
    /**
     输入：ops = ["5","-2","4","C","D","9","+","+"]
     输出：27
     解释：
     "5" - 记录加 5 ，记录现在是 [5]
     "-2" - 记录加 -2 ，记录现在是 [5, -2]
     "4" - 记录加 4 ，记录现在是 [5, -2, 4]
     "C" - 使前一次得分的记录无效并将其移除，记录现在是 [5, -2]
     "D" - 记录加 2 * -2 = -4 ，记录现在是 [5, -2, -4]
     "9" - 记录加 9 ，记录现在是 [5, -2, -4, 9]
     "+" - 记录加 -4 + 9 = 5 ，记录现在是 [5, -2, -4, 9, 5]
     "+" - 记录加 9 + 5 = 14 ，记录现在是 [5, -2, -4, 9, 5, 14]
     所有得分的总和 5 + -2 + -4 + 9 + 5 + 14 = 27
     */
    ops = {"5","-2","4","C","D","9","+","+"};
    res = 27;
    assert(res == Solution().calPoints(ops));
    
    /**
     输入：ops = ["1"]
     输出：1
     */
    ops = {"1"};
    res = 1;
    assert(res == Solution().calPoints(ops));

    cout << "OK~" << endl;
    
    return 0;
}
