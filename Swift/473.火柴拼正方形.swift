/*
 * @lc app=leetcode.cn id=473 lang=swift
 *
 * [473] 火柴拼正方形
 */

// @lc code=start
class Solution {
    func makesquare(_ matchsticks: [Int]) -> Bool {
        let sum = matchsticks.reduce(0, +)
        let sideLen = sum / 4
        if sideLen * 4 != sum {
            return false
        }
        let n = matchsticks.count
        var dp: [Int] = .init(repeating: -1, count: 1 << n)
        dp[0] = 0
        for i in 1..<(1 << n) {
            for j in 0..<n {
                if (i & (1 << j)) == 0 {
                    continue
                }
                let k = i & ~(1 << j)
                if dp[k] >= 0 && dp[k] + matchsticks[j] <= sideLen {
                    dp[i] = (dp[k] + matchsticks[j]) % sideLen
                    break
                }
            }
        }
        return dp[(1 << n) - 1] == 0
    }
    
//    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
//    int len = sum / 4, n = (int)matchsticks.size();
//    if (len * 4 != sum) {
//        return false;
//    }
//    vector<int> dp(1 << n, -1);
//    dp[0] = 0;
//    for (int i = 1; i < (1 << n); ++i) {
//        for (int j = 0; j < n; ++j) {
//            if ((i & (1 << j)) == 0) {
//                continue;
//            }
//            int k = i & ~(1 << j);
//            if (dp[k] >= 0 && dp[k] + matchsticks[j] <= len) {
//                dp[i] = (dp[k] + matchsticks[j]) % len;
//                break;
//            }
//        }
//    }
//    return dp[(1 << n) - 1] == 0;
}
// @lc code=end

func main() {
    var matchsticks: [Int]
    var res: Bool
    
    /**
     输入: matchsticks = [1,1,2,2,2]
     输出: true
     解释: 能拼成一个边长为2的正方形，每边两根火柴。
     */
    matchsticks = [1,1,2,2,2]
    res = true
    assert(res == Solution().makesquare(matchsticks))
    
    /**
     输入: matchsticks = [3,3,3,3,4]
     输出: false
     解释: 不能用所有火柴拼成一个正方形。
     */
    matchsticks = [3,3,3,3,4]
    res = false
    assert(res == Solution().makesquare(matchsticks))
}
