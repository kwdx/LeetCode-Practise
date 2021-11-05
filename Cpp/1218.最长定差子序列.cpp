/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> numToLengths;
        
        int ans = 0;
        for (int & num : arr) {
            numToLengths[num] = numToLengths[num - difference] + 1;
            ans = max(ans, numToLengths[num]);
        }
        
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    int difference;
    int res;
    
    /**
     输入：arr = [1,2,3,4], difference = 1
     输出：4
     解释：最长的等差子序列是 [1,2,3,4]。
     */
    arr = {1,2,3,4};
    difference = 1;
    res = 4;
    assert(res == Solution().longestSubsequence(arr, difference));
    
    /**
     输入：arr = [1,3,5,7], difference = 1
     输出：1
     解释：最长的等差子序列是任意单个元素。
     */
    arr = {1,3,5,7};
    difference = 1;
    res = 1;
    assert(res == Solution().longestSubsequence(arr, difference));
    
    /**
     输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
     输出：4
     解释：最长的等差子序列是 [7,5,3,1]。
     */
    arr = {1,5,7,8,5,3,4,2,1};
    difference = -2;
    res = 4;
    assert(res == Solution().longestSubsequence(arr, difference));

    
    cout << "OK~" << endl;

    return 0;
}
