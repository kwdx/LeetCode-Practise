/*
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) {
            return {-1,-1};
        }
        if (sum == 0) {
            return {0,2};
        }
        int part = sum / 3;
        int first = 0, second = 0, third = 0, cur = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 1) {
                if (cur == 0) {
                    first = i;
                }
                else if (cur == part) {
                    second = i;
                }
                else if (cur == part * 2) {
                    third = i;
                }
                ++cur;
            }
        }

        int len = (int)arr.size() - third;
        if (first + len <= second && second + len <= third) {
            int i = 0;
            while (third + i < arr.size()) {
                if (arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i]) {
                    return {-1,-1};
                }
                ++i;
            }
            return {first + len - 1, second + len};
        }
        return {-1,-1};
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    vector<int> res;
    
    /**
     输入：arr = [1,0,1,0,1]
     输出：[0,3]
     */
    arr = {1,0,1,0,1};
    res = {0,3};
    assert(res == Solution().threeEqualParts(arr));
    
    /**
     输入：arr = [1,1,0,1,1]
     输出：[-1,-1]
     */
    arr = {1,1,0,1,1};
    res = {-1,-1};
    assert(res == Solution().threeEqualParts(arr));
    
    /**
     输入：arr = [1,1,0,0,1]
     输出：[0,2]
     */
    arr = {1,1,0,0,1};
    res = {0,2};
    assert(res == Solution().threeEqualParts(arr));
    
    cout << "OK~" << endl;
    
    return 0;
}
