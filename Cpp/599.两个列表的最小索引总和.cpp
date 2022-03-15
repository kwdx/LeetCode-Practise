/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> rests;
        int i;
        for (i = 0; i < list1.size(); ++i) {
            rests[list1[i]] = i;
        }
        vector<string> ans;
        int minScore = 2000;
        for (i = 0; i < list2.size() && i <= minScore; ++i) {
            string& rest = list2[i];
            if (!rests.count(rest)) continue;
            int idx = rests[rest];
            if (idx + i < minScore) {
                minScore = idx + i;
                ans = {rest};
            } else if (idx + i == minScore) {
                ans.emplace_back(rest);
            }
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> list1;
    vector<string> list2;
    vector<string> res;
    
    /**
     输入: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
     输出: ["Shogun"]
     解释: 他们唯一共同喜爱的餐厅是“Shogun”。
     */
    list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    res = {"Shogun"};
    assert(res == Solution().findRestaurant(list1, list2));
    
    /**
     输入:list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["KFC", "Shogun", "Burger King"]
     输出: ["Shogun"]
     解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
     */
    list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    list2 = {"KFC", "Shogun", "Burger King"};
    res = {"Shogun"};
    assert(res == Solution().findRestaurant(list1, list2));

    cout << "OK~" << endl;

    return 0;
}
