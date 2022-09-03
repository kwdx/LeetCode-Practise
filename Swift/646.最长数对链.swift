/*
 * @lc app=leetcode.cn id=646 lang=swift
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
    func findLongestChain(_ pairs: [[Int]]) -> Int {
        let pairs = pairs.sorted { a, b in
            if a[0] == b[0] {
                return a[1] < b[1]
            } else {
                return a[0] < b[0]
            }
        }
        var ans = [Int]()
        for pair in pairs {
            let x = pair[0]
            let y = pair[1]
            if ans.isEmpty || x > ans.last! {
                ans.append(y)
            } else {
                let idx = ans.firstIndex(where: { $0 > y }) ?? (ans.count - 1)
                ans[idx] = min(ans[idx], y)
            }
        }
        return ans.count
    }
}
// @lc code=end

func main() {
    var pairs: [[Int]]
    var res: Int
    
    /**
     输入：[[1,2], [2,3], [3,4]]
     输出：2
     解释：最长的数对链是 [1,2] -> [3,4]
     */
    pairs = [[1,2], [2,3], [3,4]]
    res = 2
    assert(res == Solution().findLongestChain(pairs))
}
