/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> ans(n);
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        unordered_map<int, int> numToIdx;
        int index = 1;
        for (int& num : sortedArr) {
            if (!numToIdx.count(num)) {
                numToIdx[num] = index++;
            }
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = numToIdx[arr[i]];
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    vector<int> res;
    
    /**
     输入：arr = [40,10,20,30]
     输出：[4,1,2,3]
     解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
     */
    arr = {40,10,20,30};
    res = {4,1,2,3};
    assert(res == Solution().arrayRankTransform(arr));
    
    /**
     输入：arr = [100,100,100]
     输出：[1,1,1]
     解释：所有元素有相同的序号。
     */
    arr = {100,100,100};
    res = {1,1,1};
    assert(res == Solution().arrayRankTransform(arr));
    
    /**
     输入：arr = [37,12,28,9,100,56,80,5,12]
     输出：[5,3,4,2,8,6,7,1,3]
     */
    arr = {37,12,28,9,100,56,80,5,12};
    res = {5,3,4,2,8,6,7,1,3};
    assert(res == Solution().arrayRankTransform(arr));
    
    cout << "OK~" << endl;
    
    return 0;
}
