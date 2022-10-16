/*
 * @lc app=leetcode.cn id=886 lang=swift
 *
 * [886] 可能的二分法
 */

// @lc code=start
class Solution {
    func possibleBipartition(_ n: Int, _ dislikes: [[Int]]) -> Bool {
        var color = [Int](repeating: 0, count: n + 1)
        var g = [[Int]](repeating: [], count: n + 1)
        for p in dislikes {
            g[p[0]].append(p[1])
            g[p[1]].append(p[0])
        }
        for i in 1...n {
            if color[i] == 0 && !dfs(i, nowColor: 1, &color, g) {
                return false
            }
        }
        return true
    }
    
    private func dfs(_ cur: Int, nowColor: Int, _ color: inout [Int], _ g: [[Int]]) -> Bool {
        color[cur] = nowColor
        for nextNode in g[cur] {
            if (color[nextNode] != 0) && color[nextNode] == color[cur] {
                return false
            }
            if (color[nextNode] == 0) && !dfs(nextNode, nowColor: 3 ^ nowColor, &color, g) {
                return false
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var n: Int
    var dislikes: [[Int]]
    var res: Bool
    
    /**
     输入：n = 4, dislikes = [[1,2],[1,3],[2,4]]
     输出：true
     解释：group1 [1,4], group2 [2,3]
     */
    n = 4
    dislikes = [[1,2],[1,3],[2,4]]
    res = true
    assert(res == Solution().possibleBipartition(n, dislikes))
    
    /**
     输入：n = 3, dislikes = [[1,2],[1,3],[2,3]]
     输出：false
     */
    n = 3
    dislikes = [[1,2],[1,3],[2,3]]
    res = false
    assert(res == Solution().possibleBipartition(n, dislikes))
    
    /**
     输入：n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
     输出：false
     */
    n = 5
    dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
    res = false
    assert(res == Solution().possibleBipartition(n, dislikes))
}
