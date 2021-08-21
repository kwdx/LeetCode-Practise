/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 1;
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }
        
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (dayOf(weights, mid) <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    int dayOf(vector<int>& weights, int x) {
        int days = 0;
        for (int i = 0; i < weights.size(); ) {
            // 尽可能多装
            int cap = x;
            while (i < weights.size()) {
                if (cap < weights[i]) break;
                else cap -= weights[i];
                i++;
            }
            days++;
        }
        return days;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> weights;
    
    /**
     输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
     输出：15
     解释：
     船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
     第 1 天：1, 2, 3, 4, 5
     第 2 天：6, 7
     第 3 天：8
     第 4 天：9
     第 5 天：10

     请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。
     */
    weights = {1,2,3,4,5,6,7,8,9,10};
    cout << (15 == Solution().shipWithinDays(weights, 5)) << endl;
    
    /**
     输入：weights = [3,2,2,4,1,4], D = 3
     输出：6
     解释：
     船舶最低载重 6 就能够在 3 天内送达所有包裹，如下所示：
     第 1 天：3, 2
     第 2 天：2, 4
     第 3 天：1, 4
     */
    weights = {3,2,2,4,1,4};
    cout << (6 == Solution().shipWithinDays(weights, 3)) << endl;
    
    /**
     输入：weights = [1,2,3,1,1], D = 4
     输出：3
     解释：
     第 1 天：1
     第 2 天：2
     第 3 天：3
     第 4 天：1, 1
     */
    weights = {1,2,3,1,1};
    cout << (3 == Solution().shipWithinDays(weights, 4)) << endl;
    
    return 0;
}
