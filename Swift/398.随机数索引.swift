/*
 * @lc app=leetcode.cn id=398 lang=swift
 *
 * [398] 随机数索引
 */

// @lc code=start

class Solution {
    
    private let nums: [Int]
    
    init(_ nums: [Int]) {
        self.nums = nums
    }
    
    func pick(_ target: Int) -> Int {
        var ans = 0
        var cnt = 0
        for i in 0..<nums.count {
            if nums[i] == target {
                cnt += 1
                if Int.random(in: 0..<cnt) == 0 {
                    ans = i
                }
            }
        }
        return ans
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(nums)
 * let ret_1: Int = obj.pick(target)
 */
// @lc code=end

func main() {
    /**
     int[] nums = new int[] {1,2,3,3,3};
     Solution solution = new Solution(nums);

     // pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
     solution.pick(3);

     // pick(1) 应该返回 0。因为只有nums[0]等于1。
     solution.pick(1);
     */
    let nums = [1,2,3,3,3]
    let solution = Solution(nums)
    assert([2,3,4].contains(solution.pick(3)))
    assert(0 == solution.pick(1))
}
