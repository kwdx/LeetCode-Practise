/*
 * @lc app=leetcode.cn id=1139 lang=swift
 *
 * [1139] 最大的以 1 为边界的正方形
 */

// @lc code=start
class Solution {
    func largest1BorderedSquare(_ grid: [[Int]]) -> Int {
        let m = grid.count
        let n = grid[0].count
        var left = [[Int]](repeating: [Int](repeating: 0, count: n + 1), count: m + 1)
        var up = [[Int]](repeating: [Int](repeating: 0, count: n + 1), count: m + 1)
        
        var maxLen = 0
        for i in 1...m {
            for j in 1...n {
                if grid[i - 1][j - 1] == 1 {
                    left[i][j] = left[i][j - 1] + 1;
                    up[i][j] = up[i - 1][j] + 1;
                    var len = min(left[i][j], up[i][j])
                    while left[i - len + 1][j] < len || up[i][j - len + 1] < len {
                        len -= 1
                    }
                    maxLen = max(maxLen, len)
                }
            }
        }
        return maxLen * maxLen
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var res: Int
    
    /**
     输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
     输出：9
     */
    grid = [[1,1,1],[1,0,1],[1,1,1]]
    res = 9
    assert(res == Solution().largest1BorderedSquare(grid))
    
    /**
     输入：grid = [[1,1,0,0]]
     输出：1
     */
    grid = [[1,1,0,0]]
    res = 1
    assert(res == Solution().largest1BorderedSquare(grid))
}
