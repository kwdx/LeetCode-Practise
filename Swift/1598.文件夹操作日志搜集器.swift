/*
 * @lc app=leetcode.cn id=1598 lang=swift
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
class Solution {
    func minOperations(_ logs: [String]) -> Int {
        var ans = 0
        for log in logs {
            switch log {
            case "./":
                break
            case "../":
                if ans > 0 {
                    ans -= 1
                }
            default:
                ans += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var logs: [String]
    var res: Int
    
    /**
     输入：logs = ["d1/","d2/","../","d21/","./"]
     输出：2
     解释：执行 "../" 操作变更文件夹 2 次，即可回到主文件夹
     */
    logs = ["d1/","d2/","../","d21/","./"]
    res = 2
    assert(res == Solution().minOperations(logs))
    
    /**
     输入：logs = ["d1/","d2/","./","d3/","../","d31/"]
     输出：3
     */
    logs = ["d1/","d2/","./","d3/","../","d31/"]
    res = 3
    assert(res == Solution().minOperations(logs))
    
    /**
     输入：logs = ["d1/","../","../","../"]
     输出：0
     */
    logs = ["d1/","../","../","../"]
    res = 0
    assert(res == Solution().minOperations(logs))
}
