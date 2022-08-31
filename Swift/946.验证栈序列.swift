/*
 * @lc app=leetcode.cn id=946 lang=swift
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
    func validateStackSequences(_ pushed: [Int], _ popped: [Int]) -> Bool {
        var st = [Int]()
        var i = 0, j = 0
        while i < pushed.count {
            st.append(pushed[i])
            i += 1
            while let top = st.last, top == popped[j] {
                j += 1
                st.removeLast()
            }
        }
        return st.isEmpty
    }
}
// @lc code=end

func main() {
    var pushed: [Int]
    var popped: [Int]
    var res: Bool
    
    /**
     输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
     输出：true
     解释：我们可以按以下顺序执行：
     push(1), push(2), push(3), push(4), pop() -> 4,
     push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
     */
    pushed = [1,2,3,4,5]
    popped = [4,5,3,2,1]
    res = true
    assert(res == Solution().validateStackSequences(pushed, popped))
    
    /**
     输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
     输出：false
     解释：1 不能在 2 之前弹出。
     */
    pushed = [1,2,3,4,5]
    popped = [4,3,5,1,2]
    res = false
    assert(res == Solution().validateStackSequences(pushed, popped))
}
