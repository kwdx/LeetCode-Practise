/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = 0;
        if (ruleKey == "color") {
            idx = 1;
        } else if (ruleKey == "name") {
            idx = 2;
        }
        int ans = 0;
        for (vector<string>& item : items) {
            if (item[idx] == ruleValue) {
                ans += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<string>> items;
    string ruleKey;
    string ruleValue;
    int res;
    
    /**
     输入：items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
     输出：1
     解释：只有一件物品匹配检索规则，这件物品是 ["computer","silver","lenovo"] 。
     */
    items = {{"phone","blue","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}};
    ruleKey = "color";
    ruleValue = "silver";
    res = 1;
    assert(res == Solution().countMatches(items, ruleKey, ruleValue));
    
    /**
     输入：items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
     输出：2
     解释：只有两件物品匹配检索规则，这两件物品分别是 ["phone","blue","pixel"] 和 ["phone","gold","iphone"] 。注意，["computer","silver","phone"] 未匹配检索规则。
     */
    items = {{"phone","blue","pixel"},{"computer","silver","phone"},{"phone","gold","iphone"}};
    ruleKey = "type";
    ruleValue = "phone";
    res = 2;
    assert(res == Solution().countMatches(items, ruleKey, ruleValue));
    
    cout << "OK~" << endl;
    
    return 0;
}
