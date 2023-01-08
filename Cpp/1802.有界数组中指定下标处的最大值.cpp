/*
 * @lc app=leetcode.cn id=1802 lang=cpp
 *
 * [1802] 有界数组中指定下标处的最大值
 */

#include <iostream>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        double left = index;
        double right = n - index - 1;
        if (left > right) {
            double temp = left;
            left = right;
            right = temp;
        }

        double upper = ((left + 1) * (left + 1) - 3 * (left + 1)) / 2 + left + 1 + (left + 1) + ((left + 1) * (left + 1) - 3 * (left + 1)) / 2 + right + 1;
        if (upper >= maxSum) {
            double a = 1;
            double b = -2;
            double c = left + right + 2 - maxSum;
            return (int)floor((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
        }

        upper = (2 * (right + 1) - left - 1) * left / 2 + (right + 1) + ((right + 1) * (right + 1) - 3 * (right + 1)) / 2 + right + 1;
        if (upper >= maxSum) {
            double a = 1.0 / 2;
            double b = left + 1 - 3.0 / 2;
            double c = right + 1 + (-left - 1) * left / 2 - maxSum;
            return (int)floor((-b + sqrt(b * b - 4 * a * c)) / (2 * a));
        } else {
            double a = left + right + 1;
            double b = (-left * left - left - right * right - right) / 2 - maxSum;
            return (int)floor(-b / a);
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int index;
    int maxSum;
    int res;
    
    n =  8;
    index = 7;
    maxSum = 14;
    res = 4;
    assert(res == Solution().maxValue(n, index, maxSum));

    /**
     输入：n = 4, index = 2,  maxSum = 6
     输出：2
     解释：数组 [1,1,2,1] 和 [1,2,2,1] 满足所有条件。不存在其他在指定下标处具有更大值的有效数组。
     */
    n = 4;
    index = 2;
    maxSum = 6;
    res = 2;
    assert(res == Solution().maxValue(n, index, maxSum));
    
    /**
     输入：n = 6, index = 1,  maxSum = 10
     输出：3
     */
    n = 6;
    index = 1;
    maxSum = 10;
    res = 3;
    assert(res == Solution().maxValue(n, index, maxSum));

    cout << "OK~" << endl;
    
    return 0;
}
