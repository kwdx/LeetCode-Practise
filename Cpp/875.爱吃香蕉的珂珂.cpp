/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (eatTime(piles, mid) <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return  left;
    }
    
    
    int eatTime(vector<int>& piles, int speed) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / speed;
            if (piles[i] % speed > 0) {
                hours++;
            }
        }
        return hours;

    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> piles;
    
    /**
     输入: piles = [3,6,7,11], H = 8
     输出: 4
     */
    piles = {3,6,7,11};
    cout << (4 == Solution().minEatingSpeed(piles, 8)) << endl;
    
    /**
     输入: piles = [30,11,23,4,20], H = 5
     输出: 30
     */
    piles = {30,11,23,4,20};
    cout << (30 == Solution().minEatingSpeed(piles, 5)) << endl;
    
    /**
     输入: piles = [30,11,23,4,20], H = 6
     输出: 23
     */
    piles = {30,11,23,4,20};
    cout << (23 == Solution().minEatingSpeed(piles, 6)) << endl;
    
    return 0;
}
