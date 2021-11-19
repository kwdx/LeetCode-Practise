/*
 * @lc app=leetcode.cn id=391 lang=swift
 *
 * [391] 完美矩形
 */

import Darwin

// @lc code=start
class Solution {
    private struct Pointer : Hashable {
        let x: Int
        let y: Int
        func hash(into hasher: inout Hasher) {
            x.hash(into: &hasher)
            y.hash(into: &hasher)
        }
    }
    func isRectangleCover(_ rectangles: [[Int]]) -> Bool {
        var points: [Pointer: Int] = [:]
        var area = 0
        var minX = rectangles[0][0]
        var minY = rectangles[0][1]
        var maxX = rectangles[0][2]
        var maxY = rectangles[0][3]
        
        for rect in rectangles {
            let x = rect[0]
            let y = rect[1]
            let a = rect[2]
            let b = rect[3]
            
            area += (a - x) * (b - y)
            
            minX = min(minX, x)
            minY = min(minY, y)
            maxX = max(maxX, a)
            maxY = max(maxY, b)
            
            let point1 = Pointer(x: x, y: y)
            let point2 = Pointer(x:a, y: b)
            let point3 = Pointer(x: x, y: b)
            let point4 = Pointer(x: a, y: y)
            points[point1] = (points[point1] ?? 0) + 1
            points[point2] = (points[point2] ?? 0) + 1
            points[point3] = (points[point3] ?? 0) + 1
            points[point4] = (points[point4] ?? 0) + 1
        }
        if (maxX - minX) * (maxY - minY) != area {
            return false
        }
        
        let leftBottom = Pointer(x: minX, y: minY)
        let leftTop = Pointer(x: minX, y: maxY)
        let rightTop = Pointer(x: maxX, y: maxY)
        let rightBottom = Pointer(x: maxX, y: minY)
        
        if points[leftBottom] == nil || points[leftTop] == nil || points[rightTop] == nil || points[rightBottom] == nil {
            return false
        }
        points.removeValue(forKey: leftBottom)
        points.removeValue(forKey: leftTop)
        points.removeValue(forKey: rightTop)
        points.removeValue(forKey: rightBottom)
        
        for item in points {
            if item.value != 2 && item.value != 4 {
                return false
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var rectangles: [[Int]]
    var res: Bool
    
    /**
     输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
     输出：true
     解释：5 个矩形一起可以精确地覆盖一个矩形区域。
     */
    rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
    res = true
    assert(res == Solution().isRectangleCover(rectangles))
    
    /**
     输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
     输出：false
     解释：两个矩形之间有间隔，无法覆盖成一个矩形。
     */
    rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]];
    res = false;
    assert(res == Solution().isRectangleCover(rectangles));
    
    /**
     输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
     输出：false
     解释：图形顶端留有空缺，无法覆盖成一个矩形。
     */
    rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
    res = false
    assert(res == Solution().isRectangleCover(rectangles))
    
    /**
     输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
     输出：false
     解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
     */
    rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
    res = false
    assert(res == Solution().isRectangleCover(rectangles))
    
    /**
     输入：rectangles = [[1,1,2,2],[1,1,2,2],[2,1,3,2]]
     输出：false
     */
    rectangles = [[1,1,2,2],[1,1,2,2],[2,1,3,2]]
    res = false
    assert(res == Solution().isRectangleCover(rectangles))
    
    /**
     输入：rectangles = [[0,0,1,1],[0,0,2,1],[1,0,2,1],[0,2,2,3]]
     输出：false
     */
    rectangles = [[0,0,1,1],[0,0,2,1],[1,0,2,1],[0,2,2,3]]
    res = false
    assert(res == Solution().isRectangleCover(rectangles))
}
