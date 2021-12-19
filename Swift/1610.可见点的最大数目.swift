/*
 * @lc app=leetcode.cn id=1610 lang=swift
 *
 * [1610] 可见点的最大数目
 */

import Darwin

// @lc code=start
class Solution {
    func visiblePoints(_ points: [[Int]], _ angle: Int, _ location: [Int]) -> Int {
        let x = location[0], y = location[1]
        
        var samePoints = 0  // 和location重合
        var polarDegrees: [Double] = []
        
        for point in points {
            if point == location {
                samePoints += 1
            } else {
                let degree = atan2(Double(point[1] - y), Double(point[0] - x))
                polarDegrees.append(degree)
            }
        }
        polarDegrees.sort()
        let m = polarDegrees.count
        polarDegrees += polarDegrees.map { $0 + .pi * 2}
        
        var maxPoints = 0
        var right = 0
        let degree = Double(angle) * .pi / 180
        for i in 0..<m {
            while right < polarDegrees.count && polarDegrees[right] <= polarDegrees[i] + degree {
                right += 1
            }
            maxPoints = max(maxPoints, right - i)
        }
        return maxPoints + samePoints
    }
}
// @lc code=end

func main() {
    var points: [[Int]]
    var angle: Int
    var location: [Int]
    var res: Int
    
    /**
     输入：points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
     输出：3
     解释：阴影区域代表你的视野。在你的视野中，所有的点都清晰可见，尽管 [2,2] 和 [3,3]在同一条直线上，你仍然可以看到 [3,3] 。
     */
    points = [[2,1],[2,2],[3,3]]
    angle = 90
    location = [1,1]
    res = 3
    assert(res == Solution().visiblePoints(points, angle, location))
    
    /**
     输入：points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
     输出：4
     解释：在你的视野中，所有的点都清晰可见，包括你所在位置的那个点。
     */
    points = [[2,1],[2,2],[3,4],[1,1]]
    angle = 90
    location = [1,1]
    res = 4
    assert(res == Solution().visiblePoints(points, angle, location))
    
    /**
     输入：points = [[1,0],[2,1]], angle = 13, location = [1,1]
     输出：1
     解释：如图所示，你只能看到两点之一。
     */
    points = [[1,0],[2,1]]
    angle = 13
    location = [1,1]
    res = 1
    assert(res == Solution().visiblePoints(points, angle, location))
}
