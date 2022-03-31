/*
 * @lc app=leetcode.cn id=728 lang=swift
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
    func selfDividingNumbers(_ left: Int, _ right: Int) -> [Int] {
        (left...right).filter {
            var num = $0
            while num > 0 {
                let a = num % 10
                if a == 0 || $0 % a != 0 {
                    return false
                }
                num /= 10
            }
            return true
        }
    }
}
// @lc code=end

func main() {
    var left: Int
    var right: Int
    var res: [Int]
    
    /**
     输入：left = 1, right = 22
     输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
     */
    left = 1
    right = 22
    res = [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
    assert(res == Solution().selfDividingNumbers(left, right))
    
    /**
     输入：left = 47, right = 85
     输出：[48,55,66,77]
     */
    left = 47
    right = 85
    res = [48,55,66,77]
    assert(res == Solution().selfDividingNumbers(left, right))
}
