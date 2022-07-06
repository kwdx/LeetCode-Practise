/*
 * @lc app=leetcode.cn id=736 lang=cpp
 *
 * [736] Lisp 语法解析
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
private:
    unordered_map<string, vector<int>> scope;
public:
    int evaluate(string expression) {
        int start = 0;
        return innerEvaluate(expression, start);
    }

    int innerEvaluate(const string &expression, int &start) {
        if (expression[start] != '(') { // 非表达式，可能为：整数或变量
            if (islower(expression[start])) {
                string var = parseVar(expression, start); // 变量
                return scope[var].back();
            } else { // 整数
                return parseInt(expression, start);
            }
        }
        int ret;
        start++; // 移除左括号
        if (expression[start] == 'l') { // "let" 表达式
            start += 4; // 移除 "let "
            vector<string> vars;
            while (true) {
                if (!islower(expression[start])) {
                    ret = innerEvaluate(expression, start); // let 表达式的最后一个 expr 表达式的值
                    break;
                }
                string var = parseVar(expression, start);
                if (expression[start] == ')') {
                    ret = scope[var].back(); // let 表达式的最后一个 expr 表达式的值
                    break;
                }
                vars.push_back(var);
                start++; // 移除空格
                int e = innerEvaluate(expression, start);
                scope[var].push_back(e);
                start++; // 移除空格
            }
            for (auto var : vars) {
                scope[var].pop_back(); // 清除当前作用域的变量
            }
        } else if (expression[start] == 'a') { // "add" 表达式
            start += 4; // 移除 "add "
            int e1 = innerEvaluate(expression, start);
            start++; // 移除空格
            int e2 = innerEvaluate(expression, start);
            ret = e1 + e2;
        } else { // "mult" 表达式
            start += 5; // 移除 "mult "
            int e1 = innerEvaluate(expression, start);
            start++; // 移除空格
            int e2 = innerEvaluate(expression, start);
            ret = e1 * e2;
        }
        start++; // 移除右括号
        return ret;
    }

    int parseInt(const string &expression, int &start) { // 解析整数
        int n = (int)expression.size();
        int ret = 0, sign = 1;
        if (expression[start] == '-') {
            sign = -1;
            start++;
        }
        while (start < n && isdigit(expression[start])) {
            ret = ret * 10 + (expression[start] - '0');
            start++;
        }
        return sign * ret;
    }

    string parseVar(const string &expression, int &start) { // 解析变量
        int n = (int)expression.size();
        string ret;
        while (start < n && expression[start] != ' ' && expression[start] != ')') {
            ret.push_back(expression[start]);
            start++;
        }
        return ret;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string expression;
    int res;
    
    /**
     输入：expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))"
     输出：14
     解释：
     计算表达式 (add x y), 在检查变量 x 值时，
     在变量的上下文中由最内层作用域依次向外检查。
     首先找到 x = 3, 所以此处的 x 值是 3 。
     */
    expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
    res = 14;
    assert(res == Solution().evaluate(expression));
    
    /**
     输入：expression = "(let x 3 x 2 x)"
     输出：2
     解释：let 语句中的赋值运算按顺序处理即可。
     */
    expression = "(let x 3 x 2 x)";
    res = 2;
    assert(res == Solution().evaluate(expression));
    
    /**
     输入：expression = "(let x 1 y 2 x (add x y) (add x y))"
     输出：5
     解释：
     第一个 (add x y) 计算结果是 3，并且将此值赋给了 x 。
     第二个 (add x y) 计算结果是 3 + 2 = 5 。
     */
    expression = "(let x 1 y 2 x (add x y) (add x y))";
    res = 5;
    assert(res == Solution().evaluate(expression));
    
    cout << "OK~" << endl;
    
    return 0;
}
