/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int left = 0, right = 0;
        int ans = 0, n = (int)ages.size();
        for (int i = 0; i < n; ++i) {
            while (left < i && !check(ages[left], ages[i]))
                left += 1;
            if (right < i)
                right = i;
            while (right < n && check(ages[right], ages[i])) {
                right += 1;
            }
            if (right > left) {
                ans += right - left - 1;
            }
        }
        return ans;
    }
    
private:
    bool check(int x, int y) {
        if (y <= (x >> 1) + 7) return false;
        if (y > x) return false;
        if (y > 100 && x < 100) return false;
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> ages;
    int res;
    
    /**
     输入：ages = [16,16]
     输出：2
     解释：2 人互发好友请求。
     */
    ages = {16,16};
    res = 2;
    assert(res == Solution().numFriendRequests(ages));
    
    /**
     输入：ages = [16,17,18]
     输出：2
     解释：产生的好友请求为 17 -> 16 ，18 -> 17 。
     */
    ages = {16,17,18};
    res = 2;
    assert(res == Solution().numFriendRequests(ages));
    
    /**
     输入：ages = [20,30,100,110,120]
     输出：3
     解释：产生的好友请求为 110 -> 100 ，120 -> 110 ，120 -> 100 。
     */
    ages = {20,30,100,110,120};
    res = 3;
    assert(res == Solution().numFriendRequests(ages));

    cout << "OK~" << endl;

    return 0;
}
