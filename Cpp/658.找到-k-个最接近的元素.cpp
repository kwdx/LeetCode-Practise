/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = (int)(lower_bound(arr.begin(), arr.end(), x) - arr.begin());
        int left = right - 1;
        while (k--) {
            if (left < 0) {
                ++right;
            } else if (right >= arr.size()) {
                --left;
            } else if (x - arr[left] <= arr[right] - x) {
                --left;
            } else {
                ++right;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    int k;
    int x;
    vector<int> res;
    
    /**
     输入：arr = [1,2,3,4,5], k = 4, x = 3
     输出：[1,2,3,4]
     */
    arr = {1,2,3,4,5};
    k = 4;
    x = 3;
    res = {1,2,3,4};
    assert(res == Solution().findClosestElements(arr, k, x));
    
    /**
     输入：arr = [1,2,3,4,5], k = 4, x = -1
     输出：[1,2,3,4]
     */
    arr = {1,2,3,4,5};
    k = 4;
    x = 1;
    res = {1,2,3,4};
    assert(res == Solution().findClosestElements(arr, k, x));

    cout << "OK~" << endl;
    
    return 0;
}

