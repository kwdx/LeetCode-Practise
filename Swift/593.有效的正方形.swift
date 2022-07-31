/*
 * @lc app=leetcode.cn id=593 lang=swift
 *
 * [593] 有效的正方形
 */

// @lc code=start
class Solution {
    func validSquare(_ p1: [Int], _ p2: [Int], _ p3: [Int], _ p4: [Int]) -> Bool {
        return isIsoscelesRightTriangle(p1, p2, p3)
            && isIsoscelesRightTriangle(p1, p2, p4)
            && isIsoscelesRightTriangle(p1, p3, p4)
            && isIsoscelesRightTriangle(p2, p3, p4)
    }
    
    func isIsoscelesRightTriangle(_ a: [Int], _ b: [Int], _ c: [Int]) -> Bool {
        let l1 = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1])
        let l2 = (a[0] - c[0]) * (a[0] - c[0]) + (a[1] - c[1]) * (a[1] - c[1])
        let l3 = (b[0] - c[0]) * (b[0] - c[0]) + (b[1] - c[1]) * (b[1] - c[1])
        return (l1 > l2 && l2 == l3 && l2 + l3 == l1)
            || (l2 > l1 && l1 == l3 && l1 + l3 == l2)
            || (l3 > l1 && l1 == l2 && l1 + l2 == l3)
    }
}
// @lc code=end

func main() {
    var p1: [Int]
    var p2: [Int]
    var p3: [Int]
    var p4: [Int]
    var res: Bool
    
    /**
     输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
     输出: True
     */
    p1 = [0,0]
    p2 = [1,1]
    p3 = [1,0]
    p4 = [0,1]
    res = true
    assert(res == Solution().validSquare(p1, p2, p3, p4))
    
    /**
     输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
     输出：false
     */
    p1 = [0,0]
    p2 = [1,1]
    p3 = [1,0]
    p4 = [0,12]
    res = false
    assert(res == Solution().validSquare(p1, p2, p3, p4))
    
    /**
     输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
     输出：true
     */
    p1 = [1,0]
    p2 = [-1,0]
    p3 = [0,1]
    p4 = [0,-1]
    res = true
    assert(res == Solution().validSquare(p1, p2, p3, p4))
}
