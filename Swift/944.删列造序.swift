/*
 * @lc app=leetcode.cn id=944 lang=swift
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution {
    func minDeletionSize(_ strs: [String]) -> Int {
        let m = strs.count, n = strs[0].count
        let chars = strs.map { Array($0) }
        var ans = 0
        for col in 0..<n {
            for row in 1..<m {
                if chars[row][col] < chars[row - 1][col] {
                    ans += 1
                    break
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var strs: [String]
    var res: Int
    
    /**
     输入：strs = ["cba","daf","ghi"]
     输出：1
     解释：网格示意如下：
       cba
       daf
       ghi
     列 0 和列 2 按升序排列，但列 1 不是，所以只需要删除列 1 。
     */
    strs = ["cba","daf","ghi"]
    res = 1
    assert(res == Solution().minDeletionSize(strs))
    
    /**
     输入：strs = ["a","b"]
     输出：0
     解释：网格示意如下：
       a
       b
     只有列 0 这一列，且已经按升序排列，所以不用删除任何列。
     */
    strs = ["a","b"]
    res = 0
    assert(res == Solution().minDeletionSize(strs))
    
    /**
     输入：strs = ["zyx","wvu","tsr"]
     输出：3
     解释：网格示意如下：
       zyx
       wvu
       tsr
     所有 3 列都是非升序排列的，所以都要删除。
     */
    strs = ["zyx","wvu","tsr"]
    res = 3
    assert(res == Solution().minDeletionSize(strs))
}
