/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = (int)strs.size(), n = (int)strs[0].size();
        int ans = 0;
        for (int col = 0; col < n; ++col) {
            for (int row = 1; row < m; ++row) {
                if (strs[row][col] < strs[row - 1][col]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> strs;
    int res;
    
    /**
     输入：strs = ["cba","daf","ghi"]
     输出：1
     解释：网格示意如下：
       cba
       daf
       ghi
     列 0 和列 2 按升序排列，但列 1 不是，所以只需要删除列 1 。
     */
    strs = {"cba","daf","ghi"};
    res = 1;
    assert(res == Solution().minDeletionSize(strs));
    
    /**
     输入：strs = ["a","b"]
     输出：0
     解释：网格示意如下：
       a
       b
     只有列 0 这一列，且已经按升序排列，所以不用删除任何列。
     */
    strs = {"a","b"};
    res = 0;
    assert(res == Solution().minDeletionSize(strs));
    
    /**
     输入：strs = ["zyx","wvu","tsr"]
     输出：3
     解释：网格示意如下：
       zyx
       wvu
       tsr
     所有 3 列都是非升序排列的，所以都要删除。
     */
    strs = {"zyx","wvu","tsr"};
    res = 3;
    assert(res == Solution().minDeletionSize(strs));
    
    cout << "OK~" << endl;
    
    return 0;
}
