/*
 * @lc app=leetcode.cn id=1005 lang=swift
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
    func largestSumAfterKNegations(_ nums: [Int], _ k: Int) -> Int {
        var arr: [Int] = .init(repeating: 0, count: 201)
        var ans = 0
        for num in nums {
            ans += num
            arr[num + 100] += 1
        }
        
        var cnt = k
        for i in 0..<100 {
            if arr[i] > 0 {
                let ops = min(cnt, arr[i])
                let num = i - 100
                ans += (-num) * ops * 2
                arr[i] -= ops
                arr[100 - num] += ops
                cnt -= ops
                if cnt == 0 {
                    break
                }
            }
        }
        if cnt > 0 && (cnt % 2 == 1) && arr[100] == 0 {
            for i in 101..<201 {
                if arr[i] > 0 {
                    ans -= (i - 100) * 2
                    break
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var k: Int
    var res: Int
    
    /**
     输入：nums = [4,2,3], k = 1
     输出：5
     解释：选择下标 1 ，nums 变为 [4,-2,3] 。
     */
    nums = [4,2,3]
    k = 1
    res = 5
    assert(res == Solution().largestSumAfterKNegations(nums, k))

    /**
     输入：nums = [3,-1,0,2], k = 3
     输出：6
     解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
     */
    nums = [3,-1,0,2]
    k = 3
    res = 6
    assert(res == Solution().largestSumAfterKNegations(nums, k))
    
    /**
     输入：nums = [2,-3,-1,5,-4], k = 2
     输出：13
     解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
     */
    nums = [2,-3,-1,5,-4]
    k = 2
    res = 13
    assert(res == Solution().largestSumAfterKNegations(nums, k))
    
    /**
     输入：nums = [-2,5,0,2,-2], k = 3
     输出：11
     */
    nums = [-2,5,0,2,-2]
    k = 3
    res = 11
    assert(res == Solution().largestSumAfterKNegations(nums, k))
}
