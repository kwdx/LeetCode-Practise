/*
 * @lc app=leetcode.cn id=1460 lang=swift
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
class Solution {
    func canBeEqual(_ target: [Int], _ arr: [Int]) -> Bool {
        target.sorted() == arr.sorted()
    }
}
// @lc code=end

func main() {
    var target: [Int]
    var arr: [Int]
    var res: Bool
    
    /**
     输入：target = [1,2,3,4], arr = [2,4,1,3]
     输出：true
     解释：你可以按照如下步骤使 arr 变成 target：
     1- 翻转子数组 [2,4,1] ，arr 变成 [1,4,2,3]
     2- 翻转子数组 [4,2] ，arr 变成 [1,2,4,3]
     3- 翻转子数组 [4,3] ，arr 变成 [1,2,3,4]
     上述方法并不是唯一的，还存在多种将 arr 变成 target 的方法。
     */
    target = [1,2,3,4]
    arr = [2,4,1,3]
    res = true
    assert(res == Solution().canBeEqual(target, arr))
    
    /**
     输入：target = [7], arr = [7]
     输出：true
     解释：arr 不需要做任何翻转已经与 target 相等。
     */
    target = [7]
    arr = [7]
    res = true
    assert(res == Solution().canBeEqual(target, arr))
    
    /**
     输入：target = [3,7,9], arr = [3,7,11]
     输出：false
     解释：arr 没有数字 9 ，所以无论如何也无法变成 target 。
     */
    target = [3,7,9]
    arr = [3,7,11]
    res = false
    assert(res == Solution().canBeEqual(target, arr))
}
