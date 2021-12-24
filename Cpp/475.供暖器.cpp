/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = (int)1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(houses, heaters, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
private:
    bool check(vector<int>& houses, vector<int>& heaters, int x) {
        int n = (int)houses.size(), m = (int)heaters.size();
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && houses[i] > heaters[j] + x) ++j;
            if (j < m && heaters[j] - x <= houses[i] && houses[i] <= heaters[j] + x) continue;
            return false;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> houses;
    vector<int> heaters;
    int res;
    
    /**
     输入: houses = [1,2,3], heaters = [2]
     输出: 1
     解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
     */
    houses = {1,2,3};
    heaters = {2};
    res = 1;
    assert(res == Solution().findRadius(houses, heaters));
    
    /**
     输入: houses = [1,2,3,4], heaters = [1,4]
     输出: 1
     解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
     */
    houses = {1,2,3,4};
    heaters = {1,4};
    res = 1;
    assert(res == Solution().findRadius(houses, heaters));
    
    /**
     输入：houses = [1,5], heaters = [2]
     输出：3
     */
    houses = {1,5};
    heaters = {2};
    res = 3;
    assert(res == Solution().findRadius(houses, heaters));

    cout << "OK~" << endl;

    return 0;
}
