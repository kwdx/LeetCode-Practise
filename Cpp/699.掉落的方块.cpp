/*
 * @lc app=leetcode.cn id=699 lang=cpp
 *
 * [699] 掉落的方块
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = (int)positions.size();
        vector<int> ans(n, 0);
        vector<vector<int>> ranges;
        int maxHeight = 0;
        for (int i = 0; i < n; ++i) {
            int l = positions[i][0];
            int h = positions[i][1];
            int r = l + h;
            
            int fallHeight = 0;
            for (vector<int>& range : ranges) {
                if (l >= range[1] || r <= range[0]) {
                    continue;
                }
                fallHeight = max(fallHeight, range[2]);
            }
            int curHeight = fallHeight + h;
            vector<int> range = {l,r,curHeight};
            ranges.push_back(range);
            maxHeight = max(maxHeight, curHeight);
            ans[i] = maxHeight;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> positions;
    vector<int> res;
    
    /**
     输入: [[1, 2], [2, 3], [6, 1]]
     输出: [2, 5, 5]
     解释:

     第一个方块 positions[0] = [1, 2] 掉落：
     _aa
     _aa
     -------
     方块最大高度为 2 。

     第二个方块 positions[1] = [2, 3] 掉落：
     __aaa
     __aaa
     __aaa
     _aa__
     _aa__
     --------------
     方块最大高度为5。
     大的方块保持在较小的方块的顶部，不论它的重心在哪里，因为方块的底部边缘有非常大的粘性。

     第三个方块 positions[1] = [6, 1] 掉落：
     __aaa
     __aaa
     __aaa
     _aa
     _aa___a
     --------------
     方块最大高度为5。

     因此，我们返回结果[2, 5, 5]。
     */
    positions = {{1,2},{2,3},{6,1}};
    res = {2,5,5};
    assert(res == Solution().fallingSquares(positions));
    
    /**
     输入: [[100, 100], [200, 100]]
     输出: [100, 100]
     解释: 相邻的方块不会过早地卡住，只有它们的底部边缘才能粘在表面上。
     */
    positions = {{100,100},{200,100}};
    res = {100,100};
    assert(res == Solution().fallingSquares(positions));

    cout << "OK~" << endl;
    
    return 0;
}
