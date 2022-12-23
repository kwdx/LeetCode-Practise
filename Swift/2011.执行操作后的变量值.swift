/*
 * @lc app=leetcode.cn id=2011 lang=swift
 *
 * [2011] 执行操作后的变量值
 */

// @lc code=start
class Solution {
    func finalValueAfterOperations(_ operations: [String]) -> Int {
        var ans = 0
        for operation in operations {
            if operation[operation.index(after: operation.startIndex)] == "-" {
                ans -= 1
            } else {
                ans += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var operations: [String]
    var res: Int
    
    /**
     输入：operations = ["--X","X++","X++"]
     输出：1
     解释：操作按下述步骤执行：
     最初，X = 0
     --X：X 减 1 ，X =  0 - 1 = -1
     X++：X 加 1 ，X = -1 + 1 =  0
     X++：X 加 1 ，X =  0 + 1 =  1
     */
    operations = ["--X","X++","X++"]
    res = 1
    assert(res == Solution().finalValueAfterOperations(operations))
    
    /**
     输入：operations = ["++X","++X","X++"]
     输出：3
     解释：操作按下述步骤执行：
     最初，X = 0
     ++X：X 加 1 ，X = 0 + 1 = 1
     ++X：X 加 1 ，X = 1 + 1 = 2
     X++：X 加 1 ，X = 2 + 1 = 3
     */
    operations = ["++X","++X","X++"]
    res = 3
    assert(res == Solution().finalValueAfterOperations(operations))
    
    /**
     输入：operations = ["X++","++X","--X","X--"]
     输出：0
     解释：操作按下述步骤执行：
     最初，X = 0
     X++：X 加 1 ，X = 0 + 1 = 1
     ++X：X 加 1 ，X = 1 + 1 = 2
     --X：X 减 1 ，X = 2 - 1 = 1
     X--：X 减 1 ，X = 1 - 1 = 0
     */
    operations = ["X++","++X","--X","X--"]
    res = 0
    assert(res == Solution().finalValueAfterOperations(operations))
}
