/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int minVal = arr[1] - arr[0];
        int n = (int)arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int val = arr[i + 1] - arr[i];
            if (val < minVal) {
                ans.clear();
                minVal = val;
            }
            if (val == minVal) {
                vector<int> tmp;
                tmp.emplace_back(arr[i]);
                tmp.emplace_back(arr[i + 1]);
                ans.emplace_back(tmp);
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    vector<vector<int>> res;
    
    /**
     输入：arr = [4,2,1,3]
     输出：[[1,2],[2,3],[3,4]]
     */
    arr = {4,2,1,3};
    res = {{1,2},{2,3},{3,4}};
    assert(res == Solution().minimumAbsDifference(arr));
    
    /**
     输入：arr = [1,3,6,10,15]
     输出：[[1,3]]
     */
    arr = {1,3,6,10,15};
    res = {{1,3}};
    assert(res == Solution().minimumAbsDifference(arr));
    
    /**
     输入：arr = [3,8,-10,23,19,-4,-14,27]
     输出：[[-14,-10],[19,23],[23,27]]
     */
    arr = {3,8,-10,23,19,-4,-14,27};
    res = {{-14,-10},{19,23},{23,27}};
    assert(res == Solution().minimumAbsDifference(arr));
    
    cout << "OK~" << endl;
    
    return 0;
}
