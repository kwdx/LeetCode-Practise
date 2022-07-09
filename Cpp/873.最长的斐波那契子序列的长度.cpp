/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = (int)arr.size();
        int ans = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; ++i) {
            map[arr[i]] = i;
        }
        vector<vector<int>> f(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0 && j + 2 > ans; --j) {
                if (arr[i] - arr[j] >= arr[j]) break;
                int t = arr[i] - arr[j];
                if (!map.count(t)) {
                    continue;
                }
                f[i][j] = max(3, f[j][map[t]] + 1);
                ans = max(ans, f[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    int res;
    
    /**
     输入: arr = [1,2,3,4,5,6,7,8]
     输出: 5
     解释: 最长的斐波那契式子序列为 [1,2,3,5,8] 。
     */
    arr = {1,2,3,4,5,6,7,8};
    res = 5;
    assert(res == Solution().lenLongestFibSubseq(arr));
    
    /**
     输入: arr = [1,3,7,11,12,14,18]
     输出: 3
     解释: 最长的斐波那契式子序列有 [1,11,12]、[3,11,14] 以及 [7,11,18] 。
     */
    arr = {1,3,7,11,12,14,18};
    res = 3;
    assert(res == Solution().lenLongestFibSubseq(arr));
    
    cout << "OK~" << endl;
    
    return 0;
}
