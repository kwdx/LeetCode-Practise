/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = (int)score.size();
        string desc[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i)
            arr.emplace_back(make_pair(-score[i], i));
        sort(arr.begin(), arr.end());
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            if (i > 2) {
                ans[arr[i].second] = to_string(i + 1);
            } else {
                ans[arr[i].second] = desc[i];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> score;
    vector<string> res;
    
    /**
     输入：score = [5,4,3,2,1]
     输出：["Gold Medal","Silver Medal","Bronze Medal","4","5"]
     解释：名次为 [1st, 2nd, 3rd, 4th, 5th] 。
     */
    score = {5,4,3,2,1};
    res = {"Gold Medal","Silver Medal","Bronze Medal","4","5"};
    assert(res == Solution().findRelativeRanks(score));
    
    /**
     输入：score = [10,3,8,9,4]
     输出：["Gold Medal","5","Bronze Medal","Silver Medal","4"]
     解释：名次为 [1st, 5th, 3rd, 2nd, 4th] 。
     */
    score = {10,3,8,9,4};
    res = {"Gold Medal","5","Bronze Medal","Silver Medal","4"};
    assert(res == Solution().findRelativeRanks(score));

    cout << "OK~" << endl;

    return 0;
}
