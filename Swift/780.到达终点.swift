/*
 * @lc app=leetcode.cn id=780 lang=swift
 *
 * [780] 到达终点
 */

// @lc code=start
class Solution {
    func reachingPoints(_ sx: Int, _ sy: Int, _ tx: Int, _ ty: Int) -> Bool {
        if sx > tx || sy > ty {
            return false
        }
        if sx == tx && sy == ty {
            return true
        }
        if sx == tx && (ty - sy) % sx == 0 {
            return true
        }
        if sy == ty && (tx - sx) % sy == 0 {
            return true
        }
        if tx < ty {
            return reachingPoints(sx, sy, tx, ty % tx)
        }
        if tx > ty {
            return reachingPoints(sx, sy, tx % ty, ty)
        }
        return false
    }
}
// @lc code=end

func main() {
    var sx: Int
    var sy: Int
    var tx: Int
    var ty: Int
    var res: Bool
    
    /**
     输入: sx = 1, sy = 1, tx = 3, ty = 5
     输出: true
     解释:
     可以通过以下一系列转换从起点转换到终点：
     (1, 1) -> (1, 2)
     (1, 2) -> (3, 2)
     (3, 2) -> (3, 5)
     */
    sx = 1
    sy = 1
    tx = 3
    ty = 5
    res = true
    assert(res == Solution().reachingPoints(sx, sy, tx, ty))
    
    /**
     输入: sx = 1, sy = 1, tx = 2, ty = 2
     输出: false
     */
    sx = 1
    sy = 1
    tx = 2
    ty = 2
    res = false
    assert(res == Solution().reachingPoints(sx, sy, tx, ty))
    
    /**
     输入: sx = 1, sy = 1, tx = 1, ty = 1
     输出: true
     */
    sx = 1
    sy = 1
    tx = 1
    ty = 1
    res = true
    assert(res == Solution().reachingPoints(sx, sy, tx, ty))
}
