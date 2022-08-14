/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (auto &num : arr) {
            if (st.empty() || num >= st.top()) {
                st.emplace(num);
            } else {
                int mx = st.top();
                st.pop();
                while (!st.empty() && st.top() > num) {
                    st.pop();
                }
                st.emplace(mx);
            }
        }
        return (int)st.size();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    int res;
    
    /**
     输入: arr = [5,4,3,2,1]
     输出: 1
     解释:
     将数组分成2块或者更多块，都无法得到所需的结果。
     例如，分成 [5, 4], [3, 2, 1] 的结果是 [4, 5, 1, 2, 3]，这不是有序的数组。
     */
    arr = {5,4,3,2,1};
    res = 1;
    assert(res == Solution().maxChunksToSorted(arr));
    
    /**
     输入: arr = [2,1,3,4,4]
     输出: 4
     解释:
     我们可以把它分成两块，例如 [2, 1], [3, 4, 4]。
     然而，分成 [2, 1], [3], [4], [4] 可以得到最多的块数。
     */
    arr = {2,1,3,4,4};
    res = 4;
    assert(res == Solution().maxChunksToSorted(arr));

    cout << "OK~" << endl;
    
    return 0;
}
