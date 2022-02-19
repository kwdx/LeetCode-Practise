/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for (int i = (int)arr.size(); i > 1; --i) {
            int idx = int(max_element(arr.begin(), arr.begin() + i) - arr.begin());
            if (idx == i - 1) {
                continue;
            }
            reverse(arr.begin(), arr.begin() + idx + 1);
            reverse(arr.begin(), arr.begin() + i);
            ans.push_back(idx + 1);
            ans.push_back(i);
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
     输入：[3,2,4,1]
     输出：[4,2,4,3]
     解释：
     我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
     初始状态 arr = [3, 2, 4, 1]
     第一次翻转后（k = 4）：arr = [1, 4, 2, 3]
     第二次翻转后（k = 2）：arr = [4, 1, 2, 3]
     第三次翻转后（k = 4）：arr = [3, 2, 1, 4]
     第四次翻转后（k = 3）：arr = [1, 2, 3, 4]，此时已完成排序。
     */
    arr = {3,2,4,1};
    res = {4,2,4,3};
    Solution().pancakeSort(arr);
    assert(is_sorted(arr.begin(), arr.end()));

    /**
     输入：[1,2,3]
     输出：[]
     解释：
     输入已经排序，因此不需要翻转任何内容。
     请注意，其他可能的答案，如 [3，3] ，也将被判断为正确。
     */
    arr = {1,2,3};
    res = {};
    Solution().pancakeSort(arr);
    assert(is_sorted(arr.begin(), arr.end()));

    cout << "OK~" << endl;
    
    return 0;
}
