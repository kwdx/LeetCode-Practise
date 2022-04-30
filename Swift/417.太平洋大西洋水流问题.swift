/*
 * @lc app=leetcode.cn id=417 lang=swift
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
    static let dirs = [(0,1),(0,-1),(-1,0),(1,0)]
    
    private var heights: [[Int]] = []
    private var m: Int { heights.count }
    private var n: Int { heights[0].count }
    
    func pacificAtlantic(_ heights: [[Int]]) -> [[Int]] {
        self.heights = heights
        
        var pacific: [[Bool]] = .init(repeating: .init(repeating: false, count: n), count: m)
        var atlantic: [[Bool]] = .init(repeating: .init(repeating: false, count: n), count: m)

        for i in 0..<m {
            bfs(i, 0, &pacific)
            bfs(i, n - 1, &atlantic)
        }
        for j in 0..<n {
            bfs(0, j, &pacific)
            bfs(m - 1, j, &atlantic)
        }
        
        var ans: [[Int]] = []
        for i in 0..<m {
            for j in 0..<n {
                if pacific[i][j] && atlantic[i][j] {
                    ans.append([i, j])
                }
            }
        }
        return ans
    }
    
    private func bfs(_ row: Int, _ col: Int, _ ocean: inout [[Bool]]) {
        if ocean[row][col] {
            return;
        }
        
        ocean[row][col] = true
        var q: [(Int, Int)] = [(row, col)]
        
        while !q.isEmpty {
            let (row, col) = q.removeFirst()
            for dir in Self.dirs {
                let x = row + dir.0, y = col + dir.1
                if x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[row][col] && !ocean[x][y] {
                    ocean[x][y] = true
                    q.append((x, y))
                }
            }
        }
    }
}
// @lc code=end

func main() {
    var heights: [[Int]]
    var res: [[Int]]
    
    /**
     输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
     输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
     */
    heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    res = [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    assert(res == Solution().pacificAtlantic(heights))
    
    /**
     输入: heights = [[2,1],[1,2]]
     输出: [[0,0],[0,1],[1,0],[1,1]]
     */
    heights = [[2,1],[1,2]]
    res = [[0,0],[0,1],[1,0],[1,1]]
    assert(res == Solution().pacificAtlantic(heights))
}
