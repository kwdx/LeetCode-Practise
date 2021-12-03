/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = (int)arr.size();
        double left = 0, right = 1;
        
        while (true) {
            double mid = (left + right) / 2;
            int i = -1, count = 0;
            
            int x = 0, y = 1;
            
            for (int j = 1; j < n; ++j) {
                while ((double)arr[i + 1] / arr[j] < mid) {
                    ++i;
                    if (arr[i] * y > arr[j] * x) {
                        x = arr[i];
                        y = arr[j];
                    }
                }
                count += i + 1;
            }
            
            if (count == k) {
                return {x, y};
            } else if (count < k) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    int k;
    vector<int> res;
    
    /**
     输入：arr = [1,2,3,5], k = 3
     输出：[2,5]
     解释：已构造好的分数,排序后如下所示:
     1/5, 1/3, 2/5, 1/2, 3/5, 2/3
     很明显第三个最小的分数是 2/5
     */
    arr = {1,2,3,5};
    k = 3;
    res = {2,5};
    assert(res == Solution().kthSmallestPrimeFraction(arr, k));
    
    /**
     输入：arr = [1,7], k = 1
     输出：[1,7]
     */
    arr = {1,7};
    k = 1;
    res = {1,7};
    assert(res == Solution().kthSmallestPrimeFraction(arr, k));
    
    cout << "OK~" << endl;

    return 0;
}
