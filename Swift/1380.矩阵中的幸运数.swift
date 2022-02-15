/*
 * @lc app=leetcode.cn id=1380 lang=swift
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution {
    func luckyNumbers (_ matrix: [[Int]]) -> [Int] {
        let m = matrix.count, n = matrix[0].count
        var row = matrix.flatMap { [$0[0]] }
        var col = matrix[0]
        for i in 0..<m {
            for j in 0..<n {
                row[i] = min(row[i], matrix[i][j])
                col[j] = max(col[j], matrix[i][j])
            }
        }
        var ans: [Int] = []
        for i in 0..<m {
            for j in 0..<n {
                if row[i] == matrix[i][j] && col[j] == matrix[i][j] {
                    ans.append(matrix[i][j])
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var matrix: [[Int]]
    var res: [Int]
    
    /**
     输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
     输出：[15]
     解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
     */
    matrix = [[3,7,8],[9,11,13],[15,16,17]]
    res = [15]
    assert(res == Solution().luckyNumbers(matrix))
    
    /**
     输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
     输出：[12]
     解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
     */
    matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
    res = [12]
    assert(res == Solution().luckyNumbers(matrix))
    
    /**
     输输入：matrix = [[7,8],[1,2]]
     输出：[7]
     */
    matrix = [[7,8],[1,2]]
    res = [7]
    assert(res == Solution().luckyNumbers(matrix))
}
