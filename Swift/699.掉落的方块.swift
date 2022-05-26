/*
 * @lc app=leetcode.cn id=699 lang=swift
 *
 * [699] 掉落的方块
 */

// @lc code=start
class Solution {
    func fallingSquares(_ positions: [[Int]]) -> [Int] {
        var ans: [Int] = []
        var ranges: [(l: Int, r: Int, h: Int)] = []
        var maxHeight = 0
        for position in positions {
            let l = position[0]
            let h = position[1]
            let r = l + h
            
            var fallHeight = 0
            for range in ranges {
                if r <= range.l || l >= range.r {
                    continue
                }
                fallHeight = max(fallHeight, range.h)
            }
            let curHeight = fallHeight + h
            ranges.append((l, r, curHeight))
            maxHeight = max(maxHeight, curHeight)
            
            ans.append(maxHeight)
        }
        return ans
    }
}
// @lc code=end

func main() {
    var positions: [[Int]]
    var res: [Int]
    
    /**
     输入: [[1, 2], [2, 3], [6, 1]]
     输出: [2, 5, 5]
     解释:

     第一个方块 positions[0] = [1, 2] 掉落：
     _aa
     _aa
     -------
     方块最大高度为 2 。

     第二个方块 positions[1] = [2, 3] 掉落：
     __aaa
     __aaa
     __aaa
     _aa__
     _aa__
     --------------
     方块最大高度为5。
     大的方块保持在较小的方块的顶部，不论它的重心在哪里，因为方块的底部边缘有非常大的粘性。

     第三个方块 positions[1] = [6, 1] 掉落：
     __aaa
     __aaa
     __aaa
     _aa
     _aa___a
     --------------
     方块最大高度为5。

     因此，我们返回结果[2, 5, 5]。
     */
    positions = [[1,2], [2,3], [6,1]]
    res = [2,5,5]
    assert(res == Solution().fallingSquares(positions))
    
    /**
     输入: [[100, 100], [200, 100]]
     输出: [100, 100]
     解释: 相邻的方块不会过早地卡住，只有它们的底部边缘才能粘在表面上。
     */
    positions = [[100, 100], [200, 100]]
    res = [100, 100]
    assert(res == Solution().fallingSquares(positions))
    
    /**
     输入: [[6,1],[9,2],[2,4]]
     输出: [1,2,4]
     */
    positions = [[6,1],[9,2],[2,4]]
    res = [1,2,4]
    assert(res == Solution().fallingSquares(positions))
}
