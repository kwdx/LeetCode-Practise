//
//  剑指 Offer II 069.山峰数组的顶部.cpp
//  Cpp
//
//  Created by warden on 2021/9/5.
//

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 1, right = (int)arr.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (arr[mid - 1] < arr[mid]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> arr;
    int res;
    
    /**
     输入：arr = [0,1,0]
     输出：1
     */
    arr = {0,1,0};
    res = 1;
    assert(res == Solution().peakIndexInMountainArray(arr));

    /**
     输入：arr = [1,3,5,4,2]
     输出：2
     */
    arr = {1,3,5,4,2};
    res = 2;
    assert(res == Solution().peakIndexInMountainArray(arr));

    /**
     输入：arr = [0,10,5,2]
     输出：1
     */
    arr = {0,10,5,2};
    res = 1;
    assert(res == Solution().peakIndexInMountainArray(arr));

    /**
     输入：arr = [3,4,5,1]
     输出：2
     */
    arr = {3,4,5,1};
    res = 2;
    assert(res == Solution().peakIndexInMountainArray(arr));
    
    /**
     输入：arr = [24,69,100,99,79,78,67,36,26,19]
     输出：2
     */
    arr = {24,69,100,99,79,78,67,36,26,19};
    res = 2;
    assert(res == Solution().peakIndexInMountainArray(arr));

    cout << "OK~" << endl;
    
    return 0;
}
