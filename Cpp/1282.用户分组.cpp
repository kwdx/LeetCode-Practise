/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        int n = (int)groupSizes.size();
        for (int i = 0; i < n; i++) {
            int size = groupSizes[i];
            groups[size].emplace_back(i);
        }
        vector<vector<int>> groupList;
        for (auto &[size, people] : groups) {
            int groupCnt = (int)people.size() / size;
            for (int i = 0; i < groupCnt; ++i) {
                vector<int> group;
                int start = i * size;
                for (int j = 0; j < size; ++j) {
                    group.emplace_back(people[start + j]);
                }
                groupList.emplace_back(group);
            }
        }
        return groupList;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> groupSizes;
    vector<vector<int>> res;
    
    /**
     输入：groupSizes = [3,3,3,3,3,1,3]
     输出：[[5],[0,1,2],[3,4,6]]
     解释：
     第一组是 [5]，大小为 1，groupSizes[5] = 1。
     第二组是 [0,1,2]，大小为 3，groupSizes[0] = groupSizes[1] = groupSizes[2] = 3。
     第三组是 [3,4,6]，大小为 3，groupSizes[3] = groupSizes[4] = groupSizes[6] = 3。
     其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
     */
    groupSizes = {3,3,3,3,3,1,3};
    res = {{5},{0,1,2},{3,4,6}};
    assert(res == Solution().groupThePeople(groupSizes));
    
    /**
     输入：groupSizes = [2,1,3,3,3,2]
     输出：[[1],[0,5],[2,3,4]]
     */
    groupSizes = {2,1,3,3,3,2};
    res = {{2,3,4},{1},{0,5}};
    assert(res == Solution().groupThePeople(groupSizes));

    cout << "OK~" << endl;
    
    return 0;
}
