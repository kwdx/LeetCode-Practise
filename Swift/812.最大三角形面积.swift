/*
 * @lc app=leetcode.cn id=812 lang=swift
 *
 * [812] 最大三角形面积
 */

// @lc code=start
class Solution {
    func largestTriangleArea(_ points: [[Int]]) -> Double {
        var ans: Double = 0
        for i in 0..<points.count {
            for j in (i+1)..<points.count {
                for k in (j+1)..<points.count {
                    let cur = cross(points[j][0] - points[i][0],
                                    points[j][1] - points[i][1],
                                    points[k][0] - points[i][0],
                                    points[k][1] - points[i][1])
                    ans = max(ans, abs(Double(cur) / 2.0))
                }
            }
        }
        return ans
    }
    
    func cross(_ a: Int, _ b: Int, _ c: Int, _ d: Int) -> Int {
        return a * d - b * c
    }
}
// @lc code=end

func main() {
    var points: [[Int]]
    var res: Double
    
    /**
     示例:
     输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
     输出: 2
     解释:
     这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
     */
    points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    res = 2
    assert(res == Solution().largestTriangleArea(points))
}
