/*
 * @lc app=leetcode.cn id=904 lang=swift
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
    func totalFruit(_ fruits: [Int]) -> Int {
        var ans = 0
        var cnt = [Int: Int]()
        var left = 0
        for right in 0..<fruits.count {
            let fruit = fruits[right]
            cnt[fruit] = 1 + (cnt[fruit] ?? 0)
            while cnt.count > 2 {
                let old = fruits[left]
                cnt[old] = cnt[old]! - 1
                if cnt[old]! == 0 {
                    cnt.removeValue(forKey: old)
                }
                left += 1
            }
            ans = max(ans, right - left + 1)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var fruits: [Int]
    var res: Int
    
    /**
     输入：fruits = [1,2,1]
     输出：3
     解释：可以采摘全部 3 棵树。
     */
    fruits = [1,2,1]
    res = 3
    assert(res == Solution().totalFruit(fruits))
    
    /**
     输入：fruits = [0,1,2,2]
     输出：3
     解释：可以采摘 [1,2,2] 这三棵树。
     如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
     */
    fruits = [0,1,2,2]
    res = 3
    assert(res == Solution().totalFruit(fruits))
    
    /**
     输入：fruits = [1,2,3,2,2]
     输出：4
     解释：可以采摘 [2,3,2,2] 这四棵树。
     如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
     */
    fruits = [1,2,3,2,2]
    res = 4
    assert(res == Solution().totalFruit(fruits))
    
    /**
     输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
     输出：5
     解释：可以采摘 [1,2,1,1,2] 这五棵树。
     */
    fruits = [3,3,3,1,2,1,1,2,3,3,4]
    res = 5
    assert(res == Solution().totalFruit(fruits))
}
