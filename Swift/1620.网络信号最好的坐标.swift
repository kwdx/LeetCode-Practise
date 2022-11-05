/*
 * @lc app=leetcode.cn id=1620 lang=swift
 *
 * [1620] 网络信号最好的坐标
 */

import Darwin

// @lc code=start
class Solution {
    func bestCoordinate(_ towers: [[Int]], _ radius: Int) -> [Int] {
        var xMax = 0
        var yMax = 0
        for tower in towers {
            xMax = max(xMax, tower[0])
            yMax = max(yMax, tower[1])
        }
        var cx = 0, cy = 0
        var maxQuality = 0
        for x in 0...xMax {
            for y in 0...yMax {
                var quality = 0
                for tower in towers {
                    let squaredDistance = getSquaredDistance((x, y), tower: tower)
                    if squaredDistance <= radius * radius {
                        let distance = sqrt(Double(squaredDistance))
                        quality += Int(floor(Double(tower[2]) / (1 + distance)))
                    }
                }
                if quality > maxQuality {
                    cx = x
                    cy = y
                    maxQuality = quality
                }
            }
        }
        
        return [cx, cy]
    }
    
    func getSquaredDistance(_ point: (Int, Int), tower: [Int]) -> Int {
        return (tower[0] - point.0) * (tower[0] - point.0) + (tower[1] - point.1) * (tower[1] - point.1)
    }
}
// @lc code=end

func main() {
    var towers: [[Int]]
    var radius: Int
    var res: [Int]

    /**
     输入：towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
     输出：[2,1]
     解释：
     坐标 (2, 1) 信号强度之和为 13
     - 塔 (2, 1) 强度参数为 7 ，在该点强度为 ⌊7 / (1 + sqrt(0)⌋ = ⌊7⌋ = 7
     - 塔 (1, 2) 强度参数为 5 ，在该点强度为 ⌊5 / (1 + sqrt(2)⌋ = ⌊2.07⌋ = 2
     - 塔 (3, 1) 强度参数为 9 ，在该点强度为 ⌊9 / (1 + sqrt(1)⌋ = ⌊4.5⌋ = 4
     没有别的坐标有更大的信号强度。
     */
    towers = [[1,2,5],[2,1,7],[3,1,9]]
    radius = 2
    res = [2,1]
    assert(res == Solution().bestCoordinate(towers, radius))
    
    /**
     输入：towers = [[23,11,21]], radius = 9
     输出：[23,11]
     解释：由于仅存在一座信号塔，所以塔的位置信号强度最大。
     */
    towers = [[23,11,21]]
    radius = 9
    res = [23,11]
    assert(res == Solution().bestCoordinate(towers, radius))
    
    /**
     输入：towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
     输出：[1,2]
     解释：坐标 (1, 2) 的信号强度最大。
     */
    towers = [[1,2,13],[2,1,7],[0,1,9]]
    radius = 2
    res = [1,2]
    assert(res == Solution().bestCoordinate(towers, radius))
}
