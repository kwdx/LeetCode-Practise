/*
 * @lc app=leetcode.cn id=762 lang=swift
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
    static var hash: [Bool] = {
        var hashes = [Bool](repeating: false, count: 40)
        for x in [2,3,5,7,11,13,17,19,23,29,31] {
            hashes[x] = true
        }
        return hashes
    }()
    
    func countPrimeSetBits(_ left: Int, _ right: Int) -> Int {
        (left...right)
            .filter {
                var x = $0
                var cnt = 0
                while x != 0 {
                    cnt += 1
                    x -= x & -x
                }
                return Self.hash[cnt]
            }
            .count
    }
}
// @lc code=end

func main() {
    var left: Int
    var right: Int
    var res: Int
    
    /**
     输入：left = 6, right = 10
     输出：4
     解释：
     6 -> 110 (2 个计算置位，2 是质数)
     7 -> 111 (3 个计算置位，3 是质数)
     9 -> 1001 (2 个计算置位，2 是质数)
     10-> 1010 (2 个计算置位，2 是质数)
     共计 4 个计算置位为质数的数字。
     */
    left = 6
    right = 10
    res = 4
    assert(res == Solution().countPrimeSetBits(left, right))
    
    /**
     输入：left = 10, right = 15
     输出：5
     解释：
     10 -> 1010 (2 个计算置位, 2 是质数)
     11 -> 1011 (3 个计算置位, 3 是质数)
     12 -> 1100 (2 个计算置位, 2 是质数)
     13 -> 1101 (3 个计算置位, 3 是质数)
     14 -> 1110 (3 个计算置位, 3 是质数)
     15 -> 1111 (4 个计算置位, 4 不是质数)
     共计 5 个计算置位为质数的数字。
     */
    left = 10
    right = 15
    res = 5
    assert(res == Solution().countPrimeSetBits(left, right))
}
