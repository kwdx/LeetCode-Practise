/*
 * @lc app=leetcode.cn id=384 lang=swift
 *
 * [384] 打乱数组
 */

import Darwin

// @lc code=start

class Solution {

    private let nums: [Int]

    init(_ nums: [Int]) {
        self.nums = nums
    }
    
    func reset() -> [Int] {
        return nums
    }
    
    func shuffle() -> [Int] {
        var ans = nums
        for i in 0..<ans.count {
            let j = Int.random(in: 0..<ans.count)
            ans.swapAt(i, j)
        }
        return ans
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(nums)
 * let ret_1: [Int] = obj.reset()
 * let ret_2: [Int] = obj.shuffle()
 */
// @lc code=end

func main() {
    /**
     输入
     ["Solution", "shuffle", "reset", "shuffle"]
     [[[1, 2, 3]], [], [], []]
     输出
     [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

     解释
     Solution solution = new Solution([1, 2, 3]);
     solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
     solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
     solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
     */
    let nums = [1,2,3]
    let obj = Solution(nums)
    assert(nums != obj.shuffle())
    assert(nums == obj.reset())
    assert(nums != obj.shuffle())
}
