/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = (int)fruits.size();
        unordered_map<int, int> cnt;
        
        int left = 0, ans = 0;
        for (int right = 0; right < n; ++right) {
            ++cnt[fruits[right]];
            while (cnt.size() > 2) {
                auto it = cnt.find(fruits[left]);
                --it->second;
                if (it->second == 0) {
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> fruits;
    int res;
    
    /**
     输入：fruits = [1,2,1]
     输出：3
     解释：可以采摘全部 3 棵树。
     */
    fruits = {1,2,1};
    res = 3;
    assert(res == Solution().totalFruit(fruits));
    
    /**
     输入：fruits = [0,1,2,2]
     输出：3
     解释：可以采摘 [1,2,2] 这三棵树。
     如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
     */
    fruits = {0,1,2,2};
    res = 3;
    assert(res == Solution().totalFruit(fruits));
    
    /**
     输入：fruits = [1,2,3,2,2]
     输出：4
     解释：可以采摘 [2,3,2,2] 这四棵树。
     如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
     */
    fruits = {1,2,3,2,2};
    res = 4;
    assert(res == Solution().totalFruit(fruits));
    
    /**
     输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
     输出：5
     解释：可以采摘 [1,2,1,1,2] 这五棵树。
     */
    fruits = {3,3,3,1,2,1,1,2,3,3,4};
    res = 5;
    assert(res == Solution().totalFruit(fruits));

    cout << "OK~" << endl;
    
    return 0;
}
