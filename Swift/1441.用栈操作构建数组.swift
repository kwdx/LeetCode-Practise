/*
 * @lc app=leetcode.cn id=1441 lang=swift
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
class Solution {
    func buildArray(_ target: [Int], _ n: Int) -> [String] {
        var ans = [String]()
        var prev = 0
        for number in target {
            var i = 0
            while i < number - prev - 1 {
                ans.append("Push")
                ans.append("Pop")
                i += 1
            }
            ans.append("Push")
            prev = number
        }
        return ans
    }
}
// @lc code=end

func main() {
    var target: [Int]
    var n: Int
    var res: [String]
    
    /**
     输入：target = [1,3], n = 3
     输出：["Push","Push","Pop","Push"]
     解释：
     读取 1 并自动推入数组 -> [1]
     读取 2 并自动推入数组，然后删除它 -> [1]
     读取 3 并自动推入数组 -> [1,3]
     */
    target = [1,3]
    n = 3
    res = ["Push","Push","Pop","Push"]
    assert(res == Solution().buildArray(target, n))
    
    /**
     输入：target = [1,2,3], n = 3
     输出：["Push","Push","Push"]
     */
    target = [1,2,3]
    n = 3
    res = ["Push","Push","Push"]
    assert(res == Solution().buildArray(target, n))
    
    /**
     输入：target = [1,2], n = 4
     输出：["Push","Push"]
     解释：只需要读取前 2 个数字就可以停止。
     */
    target = [1,2]
    n = 4
    res = ["Push","Push"]
    assert(res == Solution().buildArray(target, n))
}
