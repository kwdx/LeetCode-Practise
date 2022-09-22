/*
 * @lc app=leetcode.cn id=1640 lang=swift
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
class Solution {
    func canFormArray(_ arr: [Int], _ pieces: [[Int]]) -> Bool {
        var indexes = [Int: Int]()
        for i in 0..<pieces.count {
            indexes[pieces[i][0]] = i
        }
        var i = 0
        while i < arr.count {
            if let index = indexes[arr[i]] {
                for j in pieces[index] {
                    if arr[i] != j {
                        return false
                    }
                    i += 1
                }
            } else {
                return false
            }
        }
        return true
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var pieces: [[Int]]
    var res: Bool
    
    /**
     输入：arr = [15,88], pieces = [[88],[15]]
     输出：true
     解释：依次连接 [15] 和 [88]
     */
    arr = [15,88]
    pieces = [[88],[15]]
    res = true
    assert(res == Solution().canFormArray(arr, pieces))
    
    /**
     输入：arr = [49,18,16], pieces = [[16,18,49]]
     输出：false
     解释：即便数字相符，也不能重新排列 pieces[0]
     */
    arr = [49,18,16]
    pieces = [[16,18,49]]
    res = false
    assert(res == Solution().canFormArray(arr, pieces))
    
    /**
     输入：arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
     输出：true
     解释：依次连接 [91]、[4,64] 和 [78]
     */
    arr = [91,4,64,78]
    pieces = [[78],[4,64],[91]]
    res = true
    assert(res == Solution().canFormArray(arr, pieces))
}
