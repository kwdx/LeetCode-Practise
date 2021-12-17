/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int add = numBottles / numExchange;
            ans += add;
            numBottles = numBottles % numExchange + add;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int numBottles;
    int numExchange;
    int res;
    
    /**
     输入：numBottles = 9, numExchange = 3
     输出：13
     解释：你可以用 3 个空酒瓶兑换 1 瓶酒。
     所以最多能喝到 9 + 3 + 1 = 13 瓶酒。
     */
    numBottles = 9;
    numExchange = 3;
    res = 13;
    assert(res == Solution().numWaterBottles(numBottles, numExchange));
    
    /**
     输入：numBottles = 15, numExchange = 4
     输出：19
     解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
     所以最多能喝到 15 + 3 + 1 = 19 瓶酒。
     */
    numBottles = 15;
    numExchange = 4;
    res = 19;
    assert(res == Solution().numWaterBottles(numBottles, numExchange));
    
    /**
     输入：numBottles = 5, numExchange = 5
     输出：6
     */
    numBottles = 5;
    numExchange = 5;
    res = 6;
    assert(res == Solution().numWaterBottles(numBottles, numExchange));
    
    /**
     输入：numBottles = 2, numExchange = 3
     输出：2
     */
    numBottles = 2;
    numExchange = 3;
    res = 2;
    assert(res == Solution().numWaterBottles(numBottles, numExchange));

    cout << "OK~" << endl;

    return 0;
}
