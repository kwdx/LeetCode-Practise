/*
 * @lc app=leetcode.cn id=1672 lang=swift
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
class Solution {
    func maximumWealth(_ accounts: [[Int]]) -> Int {
        var ans = 0
        for account in accounts {
            ans = max(ans, account.reduce(0, +))
        }
        return ans
    }
}
// @lc code=end

func main() {
    var accounts: [[Int]]
    var res: Int
    
    /**
     输入：accounts = [[1,2,3],[3,2,1]]
     输出：6
     解释：
     第 1 位客户的资产总量 = 1 + 2 + 3 = 6
     第 2 位客户的资产总量 = 3 + 2 + 1 = 6
     两位客户都是最富有的，资产总量都是 6 ，所以返回 6 。
     */
    accounts = [[1,2,3],[3,2,1]]
    res = 6
    assert(res == Solution().maximumWealth(accounts))
    
    /**
     输入：accounts = [[1,5],[7,3],[3,5]]
     输出：10
     解释：
     第 1 位客户的资产总量 = 6
     第 2 位客户的资产总量 = 10
     第 3 位客户的资产总量 = 8
     第 2 位客户是最富有的，资产总量是 10
     */
    accounts = [[1,5],[7,3],[3,5]]
    res = 10
    assert(res == Solution().maximumWealth(accounts))
    
    /**
     输入：accounts = [[2,8,7],[7,1,3],[1,9,5]]
     输出：17
     */
    accounts = [[2,8,7],[7,1,3],[1,9,5]]
    res = 17
    assert(res == Solution().maximumWealth(accounts))
}
