/*
 * @lc app=leetcode.cn id=1828 lang=swift
 *
 * [1828] 统计一个圆中点的数目
 */

// @lc code=start
class Solution {
    func countPoints(_ points: [[Int]], _ queries: [[Int]]) -> [Int] {
        let n = queries.count
        var ans = [Int](repeating: 0, count: n)
        for i in 0..<n {
            let cx = queries[i][0]
            let cy = queries[i][1]
            let cr = queries[i][2]
            for point in points {
                let px = point[0]
                let py = point[1]
                if (cx - px) * (cx - px) + (cy - py) * (cy - py) <= cr * cr {
                    ans[i] += 1
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var points: [[Int]]
    var queries: [[Int]]
    var res: [Int]
    
    /**
     输入：points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
     输出：[3,2,2]
     解释：所有的点和圆如上图所示。
     queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆。
     */
    points = [[1,3],[3,3],[5,3],[2,2]]
    queries = [[2,3,1],[4,3,1],[1,1,2]]
    res = [3,2,2]
    
    /**
     输入：points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
     输出：[2,3,2,4]
     解释：所有的点和圆如上图所示。
     queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆，queries[3] 是紫色的圆。
     */
    points = [[1,1],[2,2],[3,3],[4,4],[5,5]]
    queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
    res = [2,3,2,4]
    assert(res == Solution().countPoints(points, queries))
}
