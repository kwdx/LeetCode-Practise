/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = (int)arr.size();
        int i = -1, j = 0;
        while (j < n) {
            ++i;
            if (arr[i] == 0) {
                j += 2;
            } else {
                ++j;
            }
        }
        if (j == n + 1) {
            // 最后一个数为0
            arr[n - 1] = 0;
            j = n - 2;
            --i;
        } else {
            // 最后一个数不为0
            j = n - 1;
        }
        while (j >= 0) {
            arr[j--] = arr[i];
            if (arr[i] == 0) {
                arr[j--] = arr[i];
            }
            --i;
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    vector<int> res;

    /**
     输入：[1,0,2,3,0,4,5,0]
     输出：null
     解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
     */
    arr = {1,0,2,3,0,4,5,0};
    res = {1,0,0,2,3,0,0,4};
    Solution().duplicateZeros(arr);
    assert(res == arr);
    
    /**
     输入：[1,2,3]
     输出：null
     解释：调用函数后，输入的数组将被修改为：[1,2,3]
     */
    arr = {1,2,3};
    res = {1,2,3};
    Solution().duplicateZeros(arr);
    assert(res == arr);
    
    cout << "OK~" << endl;
    
    return 0;
}
