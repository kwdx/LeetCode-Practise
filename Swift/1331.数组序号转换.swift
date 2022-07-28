/*
 * @lc app=leetcode.cn id=1331 lang=swift
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution {
    func arrayRankTransform(_ arr: [Int]) -> [Int] {
        let sortedArr = arr.sorted()
        var num2Index: [Int: Int] = [:]
        var index = 1
        for num in sortedArr {
            if num2Index[num] == nil {
                num2Index[num] = index
                index += 1
            }
        }
        return arr.map { num2Index[$0]! }
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: [Int]
    
    /**
     输入：arr = [40,10,20,30]
     输出：[4,1,2,3]
     解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
     */
    arr = [40,10,20,30]
    res = [4,1,2,3]
    assert(res == Solution().arrayRankTransform(arr))
    
    /**
     输入：arr = [100,100,100]
     输出：[1,1,1]
     解释：所有元素有相同的序号。
     */
    arr = [100,100,100]
    res = [1,1,1]
    assert(res == Solution().arrayRankTransform(arr))
    
    /**
     输入：arr = [37,12,28,9,100,56,80,5,12]
     输出：[5,3,4,2,8,6,7,1,3]
     */
    arr = [37,12,28,9,100,56,80,5,12]
    res = [5,3,4,2,8,6,7,1,3]
    assert(res == Solution().arrayRankTransform(arr))
}
