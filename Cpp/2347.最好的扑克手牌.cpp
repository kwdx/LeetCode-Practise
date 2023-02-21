/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_set<char> colors;
        for (char c : suits) {
            colors.emplace(c);
        }
        if (colors.size() == 1) {
            return "Flush";
        }
        unordered_map<int, int> nums;
        for (int rank : ranks) {
            ++nums[rank];
        }
        if (nums.size() == 5) {
            return "High Card";
        }
        for (auto [_, val] : nums) {
            if (val > 2) {
                return "Three of a Kind";
            }
        }

        return "Pair";
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> ranks;
    vector<char> suits;
    string res;
    
    /**
     输入：ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
     输出："Flush"
     解释：5 张扑克牌的花色相同，所以返回 "Flush" 。
     */
    ranks = {13,2,3,1,9};
    suits = {'a','a','a','a','a'};
    res = "Flush";
    assert(res == Solution().bestHand(ranks, suits));
    
    /**
     输入：ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
     输出："Three of a Kind"
     解释：第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
     注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
     有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。
     */
    ranks = {4,4,2,4,4};
    suits = {'d','a','a','b','c'};
    res = "Three of a Kind";
    assert(res == Solution().bestHand(ranks, suits));
    
    /**
     输入：ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
     输出："Pair"
     解释：第一和第二张牌大小相同，所以得到 "Pair" 。
     我们无法得到 "Flush" 或者 "Three of a Kind" 。
     */
    ranks = {10,10,2,12,9};
    suits = {'a','b','c','a','d'};
    res = "Pair";
    assert(res == Solution().bestHand(ranks, suits));

    cout << "OK~" << endl;
    
    return 0;
}
