/*
 * @lc app=leetcode.cn id=1001 lang=swift
 *
 * [1001] 网格照明
 */

// @lc code=start
class Solution {
    private var dirs: [(Int, Int)] = [(-1, -1),(0, -1),(1,-1),(-1,0),(0,0),(1,0),(-1,1),(0,1),(1,1)]
    func gridIllumination(_ n: Int, _ lamps: [[Int]], _ queries: [[Int]]) -> [Int] {
        var row: [Int: Int] = [:]
        var col: [Int: Int] = [:]
        var left: [Int: Int] = [:]
        var right: [Int: Int] = [:]
        var set: Set<Int> = []
        for lamp in lamps {
            let x = lamp[0], y = lamp[1]
            if set.contains(x * n + y) {
                continue
            }
            increment(&row, x)
            increment(&col, y)
            increment(&left, x + y)
            increment(&right, x - y)
            set.insert(x * n + y)
        }
        var ans: [Int] = .init(repeating: 0, count: queries.count)
        for i in 0..<queries.count {
            let x = queries[i][0]
            let y = queries[i][1]
            if row[x] != nil || col[y] != nil || left[x + y] != nil || right[x - y] != nil {
                ans[i] = 1
            }
            for dir in dirs {
                let nx = x + dir.0, ny = y + dir.1
                if nx < 0 || nx >= n || ny < 0 || ny >= n {
                    continue
                }
                if set.remove(nx * n + ny) != nil {
                    decrement(&row, nx)
                    decrement(&col, ny)
                    decrement(&left, nx + ny)
                    decrement(&right, nx - ny)
                }
            }
        }
        return ans
    }
    
    func increment(_ map: inout [Int: Int], _ key: Int) {
        map[key] = 1 + (map[key] ?? 0)
    }
    
    func decrement(_ map: inout [Int: Int], _ key: Int) {
        if map[key] == 1 {
            map.removeValue(forKey: key)
        } else {
            map[key] = map[key]! - 1
        }
    }
}
// @lc code=end

func main() {
    var n: Int
    var lamps: [[Int]]
    var queries: [[Int]]
    var res: [Int]
    
    /**
     输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
     输出：[1,0]
     解释：最初所有灯都是关闭的。在执行查询之前，打开位于 [0, 0] 和 [4, 4] 的灯。第 0 次查询检查 grid[1][1] 是否被照亮（蓝色方框）。该单元格被照亮，所以 ans[0] = 1 。然后，关闭红色方框中的所有灯。
     */
    n = 5
    lamps = [[0,0],[4,4]]
    queries = [[1,1],[1,0]]
    res = [1,0]
    assert(res ==  Solution().gridIllumination(n, lamps, queries))
    
    /**
     输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
     输出：[1,1]
     */
    n = 5
    lamps = [[0,0],[4,4]]
    queries = [[1,1],[1,1]]
    res = [1,1]
    assert(res ==  Solution().gridIllumination(n, lamps, queries))
    
    /**
     输入：n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
     输出：[1,1,0]
     */
    n = 5
    lamps = [[0,0],[0,4]]
    queries = [[0,4],[0,1],[1,4]]
    res = [1,1,0]
    assert(res ==  Solution().gridIllumination(n, lamps, queries))
}
