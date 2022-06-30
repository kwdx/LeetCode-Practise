/*
 * @lc app=leetcode.cn id=1089 lang=swift
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution {
    func duplicateZeros(_ arr: inout [Int]) {
        var i = -1, j = 0
        while j < arr.count {
            i += 1
            if arr[i] == 0 {
                j += 2
            } else {
                j += 1
            }
        }
        if j == arr.count + 1 {
            // 最后一个数为0
            arr[arr.count - 1] = 0
            j = arr.count - 2
            i -= 1
        } else {
            j = arr.count - 1
        }
        while j >= 0 {
            arr[j] = arr[i]
            j -= 1
            if arr[i] == 0 {
                arr[j] = arr[i]
                j -= 1
            }
            i -= 1
        }
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: [Int]

    /**
     输入：[1,0,2,3,0,4,5,0]
     输出：null
     解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
     */
    arr = [1,0,2,3,0,4,5,0]
    res = [1,0,0,2,3,0,0,4]
    Solution().duplicateZeros(&arr)
    assert(res == arr)
    
    /**
     输入：[1,2,3]
     输出：null
     解释：调用函数后，输入的数组将被修改为：[1,2,3]
     */
    arr = [1,2,3]
    res = [1,2,3]
    Solution().duplicateZeros(&arr)
    assert(res == arr)
}
