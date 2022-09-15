/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] 灯泡开关 Ⅱ
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int flipLights(int n, int presses) {
        unordered_set<int> seen;
        for (int i = 0; i < (1 << 4); ++i) {
            vector<int> pressArr(4);
            for (int j = 0; j < 4; ++j) {
                pressArr[j] = (i >> j) & 1;
            }
            int sum = accumulate(pressArr.begin(), pressArr.end(), 0);
            if (sum % 2 == presses % 2 && sum <= presses) {
                int status = pressArr[0] ^ pressArr[1] ^ pressArr[3];
                if (n >= 2) {
                    status |= (pressArr[0] ^ pressArr[1]) << 1;
                }
                if (n >= 3) {
                    status |= (pressArr[0] ^ pressArr[2]) << 2;
                }
                if (n >= 4) {
                    status |= (pressArr[0] ^ pressArr[1] ^ pressArr[3]) << 3;
                }
                seen.emplace(status);
            }
        }
        return (int)seen.size();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int presses;
    int res;
    
    /**
     输入：n = 1, presses = 1
     输出：2
     解释：状态可以是：
     - 按压开关 1 ，[关]
     - 按压开关 2 ，[开]
     */
    n = 1;
    presses = 1;
    res = 2;
    assert(res == Solution().flipLights(n, presses));
    
    /**
     输入：n = 2, presses = 1
     输出：3
     解释：状态可以是：
     - 按压开关 1 ，[关, 关]
     - 按压开关 2 ，[开, 关]
     - 按压开关 3 ，[关, 开]
     */
    n = 2;
    presses = 1;
    res = 3;
    assert(res == Solution().flipLights(n, presses));
    
    /**
     输入：n = 3, presses = 1
     输出：4
     解释：状态可以是：
     - 按压开关 1 ，[关, 关, 关]
     - 按压开关 2 ，[关, 开, 关]
     - 按压开关 3 ，[开, 关, 开]
     - 按压开关 4 ，[关, 开, 开]
     */
    n = 3;
    presses = 1;
    res = 4;
    assert(res == Solution().flipLights(n, presses));

    cout << "OK~" << endl;
    
    return 0;
}
