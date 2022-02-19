/*
 * @lc app=leetcode.cn id=969 lang=swift
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
    func pancakeSort(_ arr: [Int]) -> [Int] {
        var ans: [Int] = []
        var arr_ = arr
        for i in (1...arr.count).reversed() {
            let idx = arr_.firstIndex(of: i)!
            if idx == i - 1 {
                continue
            }
            arr_ = arr_[0...idx].reversed() + arr_[(idx+1)...]
            arr_ = arr_[0..<i].reversed() + arr_[i...]
            ans.append(idx + 1)
            ans.append(i)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: [Int]
    
    /**
     输入：[3,2,4,1]
     输出：[4,2,4,3]
     解释：
     我们执行 4 次煎饼翻转，k 值分别为 4，2，4，和 3。
     初始状态 arr = [3, 2, 4, 1]
     第一次翻转后（k = 4）：arr = [1, 4, 2, 3]
     第二次翻转后（k = 2）：arr = [4, 1, 2, 3]
     第三次翻转后（k = 4）：arr = [3, 2, 1, 4]
     第四次翻转后（k = 3）：arr = [1, 2, 3, 4]，此时已完成排序。
     */
    arr = [3,2,4,1]
    res = [4,2,4,3]
    print(Solution().pancakeSort(arr))
//    assert(res == Solution().pancakeSort(arr))

    /**
     输入：[1,2,3]
     输出：[]
     解释：
     输入已经排序，因此不需要翻转任何内容。
     请注意，其他可能的答案，如 [3，3] ，也将被判断为正确。
     */
    arr = [1,2,3]
    res = []
    print(Solution().pancakeSort(arr))
//    assert(res == Solution().pancakeSort(arr))
}
