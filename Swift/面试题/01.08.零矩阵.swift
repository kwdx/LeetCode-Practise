/*
 * @lc app=leetcode.cn id=zero-matrix-lcci lang=swift
 *
 * [面试题] 01.08. 零矩阵
 */

// @lc code=start
class Solution {
    func setZeroes(_ matrix: inout [[Int]]) {
        let m = matrix.count
        let n = matrix[0].count
        var row = [Bool](repeating: false, count: m)
        var col = [Bool](repeating: false, count: n)
        for i in 0..<m {
            for j in 0..<n {
                if matrix[i][j] == 0 {
                    row[i] = true
                    col[j] = true
                }
            }
        }
        for i in 0..<m {
            for j in 0..<n {
                if row[i] || col[j] {
                    matrix[i][j] = 0
                }
            }
        }
    }
}
// @lc code=end

func main() {
    var matrix: [[Int]]
    var res: [[Int]]
    
    /**
     输入：
     [
       [1,1,1],
       [1,0,1],
       [1,1,1]
     ]
     输出：
     [
       [1,0,1],
       [0,0,0],
       [1,0,1]
     ]
     */
    matrix = [
        [1,1,1],
        [1,0,1],
        [1,1,1]
    ]
    res = [
        [1,0,1],
        [0,0,0],
        [1,0,1]
    ]
    Solution().setZeroes(&matrix)
    assert(res == matrix)
    
    /**
     输入：
     [
       [0,1,2,0],
       [3,4,5,2],
       [1,3,1,5]
     ]
     输出：
     [
       [0,0,0,0],
       [0,4,5,0],
       [0,3,1,0]
     ]
     */
    matrix = [
        [0,1,2,0],
        [3,4,5,2],
        [1,3,1,5]
    ]
    res = [
        [0,0,0,0],
        [0,4,5,0],
        [0,3,1,0]
    ]
    Solution().setZeroes(&matrix)
    assert(res == matrix)
}
