/*
 * @lc app=leetcode.cn id=1200 lang=swift
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution {
    func minimumAbsDifference(_ arr: [Int]) -> [[Int]] {
        let sortedArr = arr.sorted()
        var ans: [[Int]] = []
        var minVal = sortedArr[1] - sortedArr[0]
        for i in 0..<(arr.count - 1) {
            let val = sortedArr[i + 1] - sortedArr[i]
            if val < minVal {
                ans.removeAll()
                minVal = val
            }
            if val == minVal {
                ans.append([sortedArr[i], sortedArr[i + 1]])
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: [[Int]]
    
    /**
     输入：arr = [4,2,1,3]
     输出：[[1,2],[2,3],[3,4]]
     */
    arr = [4,2,1,3]
    res = [[1,2],[2,3],[3,4]]
    assert(res == Solution().minimumAbsDifference(arr))
    
    /**
     输入：arr = [1,3,6,10,15]
     输出：[[1,3]]
     */
    arr = [1,3,6,10,15]
    res = [[1,3]]
    assert(res == Solution().minimumAbsDifference(arr))
    
    /**
     输入：arr = [3,8,-10,23,19,-4,-14,27]
     输出：[[-14,-10],[19,23],[23,27]]
     */
    arr = [3,8,-10,23,19,-4,-14,27]
    res = [[-14,-10],[19,23],[23,27]]
    assert(res == Solution().minimumAbsDifference(arr))
}
