/*
 * @lc app=leetcode.cn id=478 lang=swift
 *
 * [478] 在圆内随机生成点
 */

import CoreGraphics

// @lc code=start

class Solution {
    private let r: Double
    private let xc: Double
    private let yc: Double
    
    init(_ radius: Double, _ x_center: Double, _ y_center: Double) {
        r = radius
        xc = x_center
        yc = y_center
    }
    
    func randPoint() -> [Double] {
        while true {
            let x = Double.random(in: -r...r)
            let y = Double.random(in: -r...r)
            if x * x + y * y <= r * r {
                return [x + xc, y + yc]
            }
        }
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(radius, x_center, y_center)
 * let ret_1: [Double] = obj.randPoint()
 */
// @lc code=end

func main() {
    
    /**
     输入:
     ["Solution","randPoint","randPoint","randPoint"]
     [[1.0, 0.0, 0.0], [], [], []]
     输出: [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
     解释:
     Solution solution = new Solution(1.0, 0.0, 0.0);
     solution.randPoint ();//返回[-0.02493，-0.38077]
     solution.randPoint ();//返回[0.82314,0.38945]
     solution.randPoint ();//返回[0.36572,0.17248]
     */
    let solution = Solution(1.0, 0.0, 0.0)
    print(solution.randPoint())
    print(solution.randPoint())
    print(solution.randPoint())
}
