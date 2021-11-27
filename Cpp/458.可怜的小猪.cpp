/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */

#include <iostream>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds = minutesToTest / minutesToDie + 1;
        int pigs = ceil(log(buckets) / log(rounds));
        return pigs;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int buckets, minutesToDie, minutesToTest;
    int res;
    
    /**
     输入：buckets = 1000, minutesToDie = 15, minutesToTest = 60
     输出：5
     */
    buckets = 1000;
    minutesToDie = 15;
    minutesToTest = 60;
    res = 5;
    assert(res == Solution().poorPigs(buckets, minutesToDie, minutesToTest));
    
    /**
     输入：buckets = 4, minutesToDie = 15, minutesToTest = 15
     输出：2
     */
    buckets = 4;
    minutesToDie = 15;
    minutesToTest = 15;
    res = 2;
    assert(res == Solution().poorPigs(buckets, minutesToDie, minutesToTest));
    
    /**
     输入：buckets = 4, minutesToDie = 15, minutesToTest = 30
     输出：2
     */
    buckets = 4;
    minutesToDie = 15;
    minutesToTest = 30;
    res = 2;
    assert(res == Solution().poorPigs(buckets, minutesToDie, minutesToTest));
    
    cout << "OK~" << endl;

    return 0;
}
