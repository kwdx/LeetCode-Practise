/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
private:
    string expression;
public:
    vector<int> diffWaysToCompute(string expression) {
        this->expression = expression;
        return dfs(0, (int)expression.size() - 1);
    }
    
    vector<int> dfs(int left, int right) {
        if (right < left) {
            return {};
        }
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            if (expression[i] >= '0' && expression[i] <= '9') {
                continue;
            }
            vector<int> num1 = dfs(left, i - 1);
            vector<int> num2 = dfs(i + 1, right);
            for (int a : num1) {
                for (int b : num2) {
                    int val = 0;
                    switch (expression[i]) {
                        case '+':
                            val = a + b;
                            break;
                        case '-':
                            val = a - b;
                            break;
                        default:
                            val = a * b;
                            break;
                    }
                    ans.emplace_back(val);
                }
            }
        }
        if (ans.empty()) {
            int val = 0;
            for (int i = left; i <= right; ++i) {
                val = val * 10 + (expression[i] - '0');
            }
            ans.emplace_back(val);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string expression;
    vector<int> res;
    
    /**
     输入：expression = "2-1-1"
     输出：[0,2]
     解释：
     ((2-1)-1) = 0
     (2-(1-1)) = 2
     */
    expression = "2-1-1";
    res = {0,2};
    assert(res == Solution().diffWaysToCompute(expression));
    
    /**
     输入：expression = "2*3-4*5"
     输出：[-34,-14,-10,-10,10]
     解释：
     (2*(3-(4*5))) = -34
     ((2*3)-(4*5)) = -14
     ((2*(3-4))*5) = -10
     (2*((3-4)*5)) = -10
     (((2*3)-4)*5) = 10
     */
    expression = "2*3-4*5";
    res = {-34,-14,-10,-10,10};
    assert(res == Solution().diffWaysToCompute(expression));
    
    cout << "OK~" << endl;
    
    return 0;
}
