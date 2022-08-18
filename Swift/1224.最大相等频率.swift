/*
 * @lc app=leetcode.cn id=1224 lang=swift
 *
 * [1224] 最大相等频率
 */

// @lc code=start
class Solution {
    func maxEqualFreq(_ nums: [Int]) -> Int {
        // 存放数字的个数
        var count = [Int: Int]()
        var maxFreq = 0
        // 记录最大数字频率的数字种类
        var maxSpecies = 0
        // 记录数字种类
        var species = 0
        var ans = 0
        for i in 0..<nums.count {
            let num = nums[i]
            // 当前没有的新数字
            if count[num] == nil {
                species += 1
            }
            count[num] = 1 + (count[num] ?? 0)
            if count[num]! > maxFreq {
                // 超过了 最大数字频率
                maxFreq = count[num]!
                // 最大数字频率的数字种类 只有一种
                maxSpecies = 1
            } else if count[num]! == maxFreq {
                // 新加入一个最大频率的数字
                maxSpecies += 1
            }
            // 有以下几种情况
            // ① 频率都是1 如 1、2、3、4、5 随便删除一个即可
            // ② 频率都是maxFreq 如 11、222、333、4 删除4即可
            // ③ 最大频率的种类是1个 并且maxFreq是 i / species （平均数量）多一个
            // 如 111 222 333 4444 删除1个4 或者如 11111111 岁便删除一个
            if maxFreq == 1 || maxFreq * maxSpecies == i || (maxSpecies == 1 && maxFreq == i / species + 1) {
                ans = i + 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [2,2,1,1,5,3,3,5]
     输出：7
     解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4] = 5，就可以得到 [2,2,1,1,3,3]，里面每个数字都出现了两次。
     */
    nums = [2,2,1,1,5,3,3,5]
    res = 7
    assert(res == Solution().maxEqualFreq(nums))
    
    /**
     输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
     输出：13
     */
    nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
    res = 13
    assert(res == Solution().maxEqualFreq(nums))
}
