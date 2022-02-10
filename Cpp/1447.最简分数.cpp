/*
 * @lc app=leetcode.cn id=1447 lang=cpp
 *
 * [1447] 最简分数
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (gcd(i, j) == 1) {
                    stringstream ss;
                    ss << i << "/" << j;
                    ans.push_back(ss.str());
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<string> res;
    
    /**
     输入：n = 2
     输出：["1/2"]
     解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
     */
    n = 2;
    res = {"1/2"};
    assert(res == Solution().simplifiedFractions(n));
    
    /**
     输入：n = 3
     输出：["1/2","1/3","2/3"]
     */
    n = 3;
    res = {"1/2","1/3","2/3"};
    assert(res == Solution().simplifiedFractions(n));
    
    /**
     输入：n = 4
     输出：["1/2","1/3","1/4","2/3","3/4"]
     解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
     */
    n = 4;
    res = {"1/2","1/3","1/4","2/3","3/4"};
    assert(res == Solution().simplifiedFractions(n));
    
    /**
     输入：n = 1
     输出：[]
     */
    n = 1;
    res = {};
    assert(res == Solution().simplifiedFractions(n));

    cout << "OK~" << endl;

    return 0;
}
