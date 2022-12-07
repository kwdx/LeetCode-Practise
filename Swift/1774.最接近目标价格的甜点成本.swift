/*
 * @lc app=leetcode.cn id=1774 lang=swift
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
class Solution {
    private var ans = 0
    
    func closestCost(_ baseCosts: [Int], _ toppingCosts: [Int], _ target: Int) -> Int {
        ans = baseCosts.min()!
        for baseCost in baseCosts {
            dfs(toppingCosts, 0, baseCost, target)
        }
        return ans
    }
    
    func dfs(_ toppingCosts: [Int], _ idx: Int, _ curCost: Int, _ target: Int) {
        if abs(ans - target) < curCost - target {
            return
        }
        if abs(ans - target) >= abs(curCost - target) {
            if abs(ans - target) > abs(curCost - target) {
                ans = curCost
            } else {
                ans = min(ans, curCost)
            }
        }
        if idx == toppingCosts.count {
            return
        }
        dfs(toppingCosts, idx + 1, curCost + toppingCosts[idx] * 2, target)
        dfs(toppingCosts, idx + 1, curCost + toppingCosts[idx], target)
        dfs(toppingCosts, idx + 1, curCost, target)
    }
}
// @lc code=end

func main() {
    var baseCosts: [Int]
    var toppingCosts: [Int]
    var target: Int
    var res: Int
    
    /**
     输入：baseCosts = [1,7], toppingCosts = [3,4], target = 10
     输出：10
     解释：考虑下面的方案组合（所有下标均从 0 开始）：
     - 选择 1 号基料：成本 7
     - 选择 1 份 0 号配料：成本 1 x 3 = 3
     - 选择 0 份 1 号配料：成本 0 x 4 = 0
     总成本：7 + 3 + 0 = 10 。
     */
    baseCosts = [1,7]
    toppingCosts = [3,4]
    target = 10
    res = 10
    assert(res == Solution().closestCost(baseCosts, toppingCosts, target))
    
    /**
     输入：baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
     输出：17
     解释：考虑下面的方案组合（所有下标均从 0 开始）：
     - 选择 1 号基料：成本 3
     - 选择 1 份 0 号配料：成本 1 x 4 = 4
     - 选择 2 份 1 号配料：成本 2 x 5 = 10
     - 选择 0 份 2 号配料：成本 0 x 100 = 0
     总成本：3 + 4 + 10 + 0 = 17 。不存在总成本为 18 的甜点制作方案。
     */
    baseCosts = [2,3]
    toppingCosts = [4,5,100]
    target = 18
    res = 17
    assert(res == Solution().closestCost(baseCosts, toppingCosts, target))
    
    /**
     输入：baseCosts = [3,10], toppingCosts = [2,5], target = 9
     输出：8
     解释：可以制作总成本为 8 和 10 的甜点。返回 8 ，因为这是成本更低的方案。
     */
    baseCosts = [3,10]
    toppingCosts = [2,5]
    target = 9
    res = 8
    assert(res == Solution().closestCost(baseCosts, toppingCosts, target))
    
    /**
     输入：baseCosts = [10], toppingCosts = [1], target = 1
     输出：10
     解释：注意，你可以选择不添加任何配料，但你必须选择一种基料。
     */
    baseCosts = [10]
    toppingCosts = [1]
    target = 1
    res = 10
    assert(res == Solution().closestCost(baseCosts, toppingCosts, target))
}
