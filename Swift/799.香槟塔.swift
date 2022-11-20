/*
 * @lc app=leetcode.cn id=799 lang=swift
 *
 * [799] 香槟塔
 */

// @lc code=start
class Solution {
    func champagneTower(_ poured: Int, _ query_row: Int, _ query_glass: Int) -> Double {
        var row: [Double] = [Double(poured)]
        guard query_row > 0 else {
            return min(1.0, row[query_glass])
        }
        for i in 1...query_row {
            var nextRow = [Double](repeating: 0, count: i + 1)
            for j in 0..<row.count {
                let volume = row[j]
                if (volume > 1) {
                    nextRow[j] += (volume - 1) / 2
                    nextRow[j + 1] += (volume - 1) / 2
                }
            }
            row = nextRow
        }
        return min(1.0, row[query_glass])
    }
}
// @lc code=end

func main() {
    var poured: Int
    var query_row: Int
    var query_glass: Int
    var res: Double
    
    poured = 1
    query_glass = 0
    query_row = 0
    res = 1.00000
    assert(res == Solution().champagneTower(poured, query_row, query_glass))

    /**
     输入: poured(倾倒香槟总杯数) = 1, query_glass(杯子的位置数) = 1, query_row(行数) = 1
     输出: 0.00000
     解释: 我们在顶层（下标是（0，0））倒了一杯香槟后，没有溢出，因此所有在顶层以下的玻璃杯都是空的。
     */
    poured = 1
    query_glass = 1
    query_row = 1
    res = 0.00000
    assert(res == Solution().champagneTower(poured, query_row, query_glass))
    
    /**
     输入: poured(倾倒香槟总杯数) = 2, query_glass(杯子的位置数) = 1, query_row(行数) = 1
     输出: 0.50000
     解释: 我们在顶层（下标是（0，0）倒了两杯香槟后，有一杯量的香槟将从顶层溢出，位于（1，0）的玻璃杯和（1，1）的玻璃杯平分了这一杯香槟，所以每个玻璃杯有一半的香槟。
     */
    poured = 2
    query_glass = 1
    query_row = 1
    res = 0.50000
    assert(res == Solution().champagneTower(poured, query_row, query_glass))
    
    /**
     输入: poured = 100000009, query_row = 33, query_glass = 17
     输出: 1.00000
     */
    poured = 100000009
    query_row = 33
    query_glass = 17
    res = 1.00000
    assert(res == Solution().champagneTower(poured, query_row, query_glass))
}
