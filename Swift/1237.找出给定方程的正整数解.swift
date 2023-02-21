/*
 * @lc app=leetcode.cn id=1237 lang=swift
 *
 * [1237] 找出给定方程的正整数解
 */

// @lc code=start
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     func f(_ x: Int, _ y: Int) -> Int {}
 * }
 */
class CustomFunction {
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    func f(_ x: Int, _ y: Int) -> Int { 0 }
}

class Solution {
    func findSolution(_ customfunction: CustomFunction, _ z: Int) -> [[Int]] {
        var ans = [[Int]]()
        for x in 1...1000 {
            for y in 1...1000 {
                if customfunction.f(x, y) == z {
                    ans.append([x, y])
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    
}
