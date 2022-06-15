/*
 * @lc app=leetcode.cn id=498 lang=swift
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
    func findDiagonalOrder(_ mat: [[Int]]) -> [Int] {
        let m = mat.count, n = mat[0].count, cnt = m * n
        var x = 0, y = 0, idx = 0, dir = true
        var ans: [Int] = .init(repeating: 0, count: cnt)
        while idx < cnt {
            ans[idx] = mat[x][y]
            idx += 1
            var nx = x, ny = y
            if dir {
                // 走左下
                nx = x - 1
                ny = y + 1
            } else {
                // 走右上
                nx = x + 1
                ny = y - 1
            }
            if idx < cnt && (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                if dir {
                    nx = y + 1 < n ? x : x + 1
                    ny = y + 1 < n ? y + 1 : y
                } else {
                    nx = x + 1 < m ? x + 1 : x
                    ny = x + 1 < m ? y : y + 1
                }
                dir.toggle()
            }
            x = nx
            y = ny
        }
        return ans
    }
}
// @lc code=end

func main() {
    var mat: [[Int]]
    var res: [Int]
    
    /**
     输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
     输出：[1,2,4,7,5,3,6,8,9]
     */
    mat = [[1,2,3],[4,5,6],[7,8,9]]
    res = [1,2,4,7,5,3,6,8,9]
    assert(res == Solution().findDiagonalOrder(mat));
    
    /**
     输入：mat = [[1,2],[3,4]]
     输出：[1,2,3,4]
     */
    mat = [[1,2],[3,4]]
    res = [1,2,3,4]
    assert(res == Solution().findDiagonalOrder(mat))
}
