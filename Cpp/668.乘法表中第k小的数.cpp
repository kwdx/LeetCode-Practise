/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 1; i <= m; i++) {
                count += mid / i >= n ? n : mid / i;
            }
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int m;
    int n;
    int k;
    int res;
    
    /**
     输入: m = 3, n = 3, k = 5
     输出: 3
     解释:
     乘法表:
     1    2    3
     2    4    6
     3    6    9

     第5小的数字是 3 (1, 2, 2, 3, 3).
     */
    m = 3;
    n = 3;
    k = 5;
    res = 3;
    assert(res == Solution().findKthNumber(m, n, k));
    
    /**
     输入: m = 2, n = 3, k = 6
     输出: 6
     解释:
     乘法表:
     1    2    3
     2    4    6

     第6小的数字是 6 (1, 2, 2, 3, 4, 6).
     */
    m = 2;
    n = 3;
    k = 6;
    res = 6;
    assert(res == Solution().findKthNumber(m, n, k));
    
    cout << "OK~" << endl;
    
    return 0;
}
