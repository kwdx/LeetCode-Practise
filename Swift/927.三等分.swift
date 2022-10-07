/*
 * @lc app=leetcode.cn id=927 lang=swift
 *
 * [927] 三等分
 */

// @lc code=start
class Solution {
    func threeEqualParts(_ arr: [Int]) -> [Int] {
        let sum = arr.reduce(0, +)
        guard sum % 3 == 0 else {
            return [-1,-1]
        }
        if sum == 0 {
            return [0,2]
        }
        let part = sum / 3
        var first = 0, second = 0, third = 0, cur = 0;
        for i in 0..<arr.count {
            if arr[i] == 1 {
                if cur == 0 {
                    first = i
                }
                else if cur == part {
                    second = i
                }
                else if cur == part * 2 {
                    third = i
                }
                cur += 1
            }
        }
        let len = arr.count - third
        if first + len <= second && second + len <= third {
            var i = 0
            while third + i < arr.count {
                if arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i] {
                    return [-1,-1]
                }
                i += 1
            }
            return [first + len - 1, second + len]
        }
        return [-1,-1]
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: [Int]
    
    /**
     输入：arr = [1,0,1,0,1]
     输出：[0,3]
     */
    arr = [1,0,1,0,1]
    res = [0,3]
    assert(res == Solution().threeEqualParts(arr))
    
    /**
     输入：arr = [1,1,0,1,1]
     输出：[-1,-1]
     */
    arr = [1,1,0,1,1]
    res = [-1,-1]
    assert(res == Solution().threeEqualParts(arr))
    
    /**
     输入：arr = [1,1,0,0,1]
     输出：[0,2]
     */
    arr = [1,1,0,0,1]
    res = [0,2]
    assert(res == Solution().threeEqualParts(arr))
}
