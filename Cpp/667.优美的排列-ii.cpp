/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        for (int i = 1; i < n - k; ++i) {
            ans.emplace_back(i);
        }
        for (int i = n - k, j = n; i <= j; ++i, --j) {
            ans.emplace_back(i);
            if (i != j) {
                ans.emplace_back(j);
            }
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int k;
    vector<int> res;
    
    /**
     输入：n = 3, k = 1
     输出：[1, 2, 3]
     解释：[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1 个不同整数：1
     */
    n = 3;
    k = 1;
    res = {1,2,3};
    assert(res == Solution().constructArray(n, k));
    
    /**
     输入：n = 3, k = 2
     输出：[1, 3, 2]
     解释：[1, 3, 2] 包含 3 个范围在 1-3 的不同整数，并且 [2, 1] 中有且仅有 2 个不同整数：1 和 2
     */
    n = 3;
    k = 2;
    res = {1,3,2};
    assert(res == Solution().constructArray(n, k));

    cout << "OK~" << endl;
    
    return 0;
}
