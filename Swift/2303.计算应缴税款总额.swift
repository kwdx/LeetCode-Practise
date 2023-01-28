/*
 * @lc app=leetcode.cn id=2303 lang=swift
 *
 * [2303] 计算应缴税款总额
 */

// @lc code=start
class Solution {
    func calculateTax(_ brackets: [[Int]], _ income: Int) -> Double {
        var totalTax = 0
        var lower = 0
        for bracket in brackets {
            let upper = bracket[0], percent = bracket[1]
            let tax = (min(income, upper) - lower) * percent
            totalTax += tax
            if income <= upper {
                break
            }
            lower = upper;
        }
        return Double(totalTax) / 100.0
    }
}
// @lc code=end

func main() {
    var brackets: [[Int]]
    var income: Int
    var res: Double

    /**
     输入：brackets = [[3,50],[7,10],[12,25]], income = 10
     输出：2.65000
     解释：
     前 $3 的税率为 50% 。需要支付税款 $3 * 50% = $1.50 。
     接下来 $7 - $3 = $4 的税率为 10% 。需要支付税款 $4 * 10% = $0.40 。
     最后 $10 - $7 = $3 的税率为 25% 。需要支付税款 $3 * 25% = $0.75 。
     需要支付的税款总计 $1.50 + $0.40 + $0.75 = $2.65 。
     */
    brackets = [[3,50],[7,10],[12,25]]
    income = 10
    res = 2.65000
    assert(res == Solution().calculateTax(brackets, income))
    
    /**
     输入：brackets = [[1,0],[4,25],[5,50]], income = 2
     输出：0.25000
     解释：
     前 $1 的税率为 0% 。需要支付税款 $1 * 0% = $0 。
     剩下 $1 的税率为 25% 。需要支付税款 $1 * 25% = $0.25 。
     需要支付的税款总计 $0 + $0.25 = $0.25 。
     */
    brackets = [[1,0],[4,25],[5,50]]
    income = 2
    res = 0.25000
    assert(res == Solution().calculateTax(brackets, income))
    
    /**
     输入：brackets = [[2,50]], income = 0
     输出：0.00000
     解释：
     没有收入，无需纳税，需要支付的税款总计 $0 。
     */
    brackets = [[2,50]]
    income = 0
    res = 0
    assert(res == Solution().calculateTax(brackets, income))
}
