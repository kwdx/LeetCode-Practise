/*
 * @lc app=leetcode.cn id=1765 lang=swift
 *
 * [1765] 地图中的最高点
 */

// @lc code=start
class Solution {
    static private let directions: [(Int, Int)] = [(1,0),(-1,0),(0,1),(0,-1)]
    func highestPeak(_ isWater: [[Int]]) -> [[Int]] {
        let n = isWater.count, m = isWater[0].count
        var q: [(Int, Int)] = []
        var ans: [[Int]] = .init(repeating: .init(repeating: 0, count: m), count: n)
        for i in 0..<n {
            for j in 0..<m {
                if isWater[i][j] == 1 {
                    q.append((i, j))
                } else {
                    ans[i][j] = -1
                }
            }
        }
        
        while !q.isEmpty {
            let (x, y) = q.removeFirst()
            for dir in Self.directions {
                let a = x + dir.0, b = y + dir.1
                if a < 0 || a == n || b < 0 || b == m || ans[a][b] >= 0 {
                    continue
                }
                ans[a][b] = ans[x][y] + 1
                q.append((a, b))
            }
        }
        
        return ans
    }
}
// @lc code=end

func main() {
    var isWater: [[Int]]
    var res: [[Int]]
    
    /**
     输入：isWater = [[0,1],[0,0]]
     输出：[[1,0],[2,1]]
     解释：上图展示了给各个格子安排的高度。
     蓝色格子是水域格，绿色格子是陆地格。
     */
    isWater = [[0,1],[0,0]]
    res = [[1,0],[2,1]]
    assert(res == Solution().highestPeak(isWater))
    
    /**
     输入：isWater = [[0,0,1],[1,0,0],[0,0,0]]
     输出：[[1,1,0],[0,1,1],[1,2,2]]
     解释：所有安排方案中，最高可行高度为 2 。
     任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。
     */
    isWater = [[0,0,1],[1,0,0],[0,0,0]]
    res = [[1,1,0],[0,1,1],[1,2,2]]
    assert(res == Solution().highestPeak(isWater))
}
