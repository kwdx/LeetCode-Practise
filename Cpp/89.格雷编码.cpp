/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int head = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = (int)ans.size() - 1; j >= 0; --j)
                ans.push_back(head + ans[j]);
            head <<= 1;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<int> res;
    
    /**
     输入：n = 2
     输出：[0,1,3,2]
     解释：
     [0,1,3,2] 的二进制表示是 [00,01,11,10] 。
     - 00 和 01 有一位不同
     - 01 和 11 有一位不同
     - 11 和 10 有一位不同
     - 10 和 00 有一位不同
     [0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
     - 00 和 10 有一位不同
     - 10 和 11 有一位不同
     - 11 和 01 有一位不同
     - 01 和 00 有一位不同
     */
    n = 2;
    res = {0,1,3,2};
    assert(res == Solution().grayCode(n));
    
    /**
     输入：n = 1
     输出：[0,1]
     */
    n = 1;
    res = {0,1};
    assert(res == Solution().grayCode(n));

    cout << "OK~" << endl;

    return 0;
}
