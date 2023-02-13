/*
 * @lc app=leetcode.cn id=2335 lang=swift
 *
 * [2335] 装满杯子需要的最短总时长
 */

// @lc code=start
class Solution {
    func fillCups(_ amount: [Int]) -> Int {
        let amount = amount.sorted()
        let x = amount[0] + amount[1]
        if x <= amount[2] {
            return x + (amount[2] - x)
        }
        return (amount[2] + x + 1) / 2
    }
}
// @lc code=end

func main() {
    var amount: [Int]
    var res: Int
    
    /**
     输入：amount = [1,4,2]
     输出：4
     解释：下面给出一种方案：
     第 1 秒：装满一杯冷水和一杯温水。
     第 2 秒：装满一杯温水和一杯热水。
     第 3 秒：装满一杯温水和一杯热水。
     第 4 秒：装满一杯温水。
     可以证明最少需要 4 秒才能装满所有杯子。
     */
    amount = [1,4,2]
    res = 4
    assert(res == Solution().fillCups(amount))
    
    /**
     输入：amount = [5,4,4]
     输出：7
     解释：下面给出一种方案：
     第 1 秒：装满一杯冷水和一杯热水。
     第 2 秒：装满一杯冷水和一杯温水。
     第 3 秒：装满一杯冷水和一杯温水。
     第 4 秒：装满一杯温水和一杯热水。
     第 5 秒：装满一杯冷水和一杯热水。
     第 6 秒：装满一杯冷水和一杯温水。
     第 7 秒：装满一杯热水。
     */
    amount = [5,4,4]
    res = 7
    assert(res == Solution().fillCups(amount))
    
    /**
     输入：amount = [5,0,0]
     输出：5
     解释：每秒装满一杯冷水。
     */
    amount = [5,0,0]
    res = 5
    assert(res == Solution().fillCups(amount))
}
