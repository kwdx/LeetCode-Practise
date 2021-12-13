/*
 * @lc app=leetcode.cn id=807 lang=swift
 *
 * [807] 保持城市天际线
 */

// @lc code=start
class Solution {
    func maxIncreaseKeepingSkyline(_ grid: [[Int]]) -> Int {
        let m = grid.count
        let n = grid[0].count
        var rows = [Int](repeating: 0, count: m)
        var cols = [Int](repeating: 0, count: n)
        for i in 0..<m {
            for j in 0..<n {
                rows[i] = max(rows[i], grid[i][j])
                cols[j] = max(cols[j], grid[i][j])
            }
        }
        var ans = 0
        for i in 0..<m {
            for j in 0..<n {
                ans += min(rows[i], cols[j]) - grid[i][j]
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var grid: [[Int]]
    var res: Int
    
    /**
     输入： grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
     输出： 35
     解释：
     The grid is:
     [ [3, 0, 8, 4],
       [2, 4, 5, 7],
       [9, 2, 6, 3],
       [0, 3, 1, 0] ]

     从数组竖直方向（即顶部，底部）看“天际线”是：[9, 4, 8, 7]
     从水平水平方向（即左侧，右侧）看“天际线”是：[8, 7, 9, 3]

     在不影响天际线的情况下对建筑物进行增高后，新数组如下：

     gridNew = [ [8, 4, 8, 7],
                 [7, 4, 7, 7],
                 [9, 4, 8, 7],
                 [3, 3, 3, 3] ]
     */
    grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
    res = 35
    assert(res == Solution().maxIncreaseKeepingSkyline(grid))
}
