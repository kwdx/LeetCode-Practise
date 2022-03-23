/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        while (k > 1) {
            int cnt = getCnts(ans, n);
            if (cnt < k) {
                k -= cnt;
                ++ans;
            } else {
                --k;
                ans *= 10;
            }
        }
        return ans;
    }
    
    int getCnts(int x, int limit) {
        string a = to_string(x), b = to_string(limit);
        int k = (int)(b.size() - a.size());
        int ans = 0, u = atoi(b.substr(0, a.size()).c_str());
        for (int i = 0; i < k; ++i) {
            ans += pow(10, i);
        }
        if (u > x) {
            ans += pow(10, k);
        } else if (u == x) {
            ans += limit - x * pow(10, k) + 1;
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int k;
    int res;
    
    /**
     输入: n = 13, k = 2
     输出: 10
     解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
     */
    n = 13;
    k = 2;
    res = 10;
    assert(res == Solution().findKthNumber(n, k));
    
    /**
     输入: n = 1, k = 1
     输出: 1
     */
    n = 1;
    k = 1;
    res = 1;
    assert(res == Solution().findKthNumber(n, k));

    cout << "OK~" << endl;
    
    return 0;
}
