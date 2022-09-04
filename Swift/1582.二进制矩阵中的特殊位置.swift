/*
 * @lc app=leetcode.cn id=1582 lang=swift
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start
class Solution {
    func numSpecial(_ mat: [[Int]]) -> Int {
        let m = mat.count, n = mat[0].count
        var ans = 0
        var r = [Int](repeating: 0, count: m)
        var c = [Int](repeating: 0, count: n)
        for i in 0..<m {
            for j in 0..<n {
                r[i] += mat[i][j]
                c[j] += mat[i][j]
            }
        }
        for i in 0..<m {
            for j in 0..<n {
                if mat[i][j] == 1 && r[i] == 1 && c[j] == 1 {
                    ans += 1
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var mat: [[Int]]
    var res: Int
    
    /**
     输入：mat = [[1,0,0],
                 [0,0,1],
                 [1,0,0]]
     输出：1
     解释：(1,2) 是一个特殊位置，因为 mat[1][2] == 1 且所处的行和列上所有其他元素都是 0
     */
    mat = [[1,0,0],
             [0,0,1],
             [1,0,0]]
    res = 1
    assert(res == Solution().numSpecial(mat))
    
    /**
     输入：mat = [[1,0,0],
                 [0,1,0],
                 [0,0,1]]
     输出：3
     解释：(0,0), (1,1) 和 (2,2) 都是特殊位置
     */
    mat = [[1,0,0],
           [0,1,0],
           [0,0,1]]
    res = 3
    assert(res == Solution().numSpecial(mat))
    
    /**
     输入：mat = [[0,0,0,1],
                 [1,0,0,0],
                 [0,1,1,0],
                 [0,0,0,0]]
     输出：2
     */
    mat = [[0,0,0,1],
           [1,0,0,0],
           [0,1,1,0],
           [0,0,0,0]]
    res = 2
    assert(res == Solution().numSpecial(mat))
    
    /**
     输入：mat = [[0,0,0,0,0],
                 [1,0,0,0,0],
                 [0,1,0,0,0],
                 [0,0,1,0,0],
                 [0,0,0,1,1]]
     输出：3
     */
    mat = [[0,0,0,0,0],
           [1,0,0,0,0],
           [0,1,0,0,0],
           [0,0,1,0,0],
           [0,0,0,1,1]]
    res = 3
    assert(res == Solution().numSpecial(mat))
}
