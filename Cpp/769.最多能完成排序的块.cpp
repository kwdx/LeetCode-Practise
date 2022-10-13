/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int m = 0;
        for (int i = 0; i < arr.size(); ++i) {
            m = max(m, arr[i]);
            if (m == i) {
                ++ans;
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
     输入: arr = [4,3,2,1,0]
     输出: 1
     解释:
     将数组分成2块或者更多块，都无法得到所需的结果。
     例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。
     */
    arr = {4,3,2,1,0};
    res = 1;
    assert(res == Solution().maxChunksToSorted(arr));
    
    /**
     输入: arr = [1,0,2,3,4]
     输出: 4
     解释:
     我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
     然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
     */
    arr = {1,0,2,3,4};
    res = 4;
    assert(res == Solution().maxChunksToSorted(arr));

    cout << "OK~" << endl;
    
    return 0;
}

