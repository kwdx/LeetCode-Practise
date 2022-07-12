/*
 * @lc app=leetcode.cn id=1252 lang=swift
 *
 * [1252] 奇数值单元格的数目
 */

// @lc code=start
class Solution {
    func oddCells(_ m: Int, _ n: Int, _ indices: [[Int]]) -> Int {
        var rows: [Int] = .init(repeating: 0, count: m)
        var cols: [Int] = .init(repeating: 0, count: n)
        for indice in indices {
            rows[indice[0]] += 1
            cols[indice[1]] += 1
        }
        var ans = 0
        for row in rows {
            for col in cols {
                if (row + col) & 1 == 1 {
                    ans += 1
                }
            }
        }
        return ans   
    }
}
// @lc code=end

func main() {
    var m: Int
    var n: Int
    var indices: [[Int]]
    var res: Int
    
    /**
     输入：m = 2, n = 3, indices = [[0,1],[1,1]]
     输出：6
     解释：最开始的矩阵是 [[0,0,0],[0,0,0]]。
     第一次增量操作后得到 [[1,2,1],[0,1,0]]。
     最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
     */
    m = 2
    n = 3
    indices = [[0,1],[1,1]]
    res = 6
    assert(res == Solution().oddCells(m, n, indices))
    
    /**
     输入：m = 2, n = 2, indices = [[1,1],[0,0]]
     输出：0
     解释：最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
     */
    
    m = 2
    n = 2
    indices = [[1,1],[0,0]]
    res = 0
    assert(res == Solution().oddCells(m, n, indices))
}
