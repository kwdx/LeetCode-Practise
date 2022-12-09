/*
 * @lc app=leetcode.cn id=1812 lang=swift
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start
class Solution {
    func squareIsWhite(_ coordinates: String) -> Bool {
        let coordinates = Array(coordinates)
        let x = Int(coordinates[0].asciiValue!) - 97
        let y = Int(coordinates[1].wholeNumberValue!) - 1
        return x % 2 != y % 2
    }
}
// @lc code=end

func main() {
    var coordinates: String
    var res: Bool
    
    /**
     输入：coordinates = "a1"
     输出：false
     解释：如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
     */
    coordinates = "a1"
    res = false
    assert(res == Solution().squareIsWhite(coordinates))
    
    /**
     输入：coordinates = "h3"
     输出：true
     解释：如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
     */
    coordinates = "h3"
    res = true
    assert(res == Solution().squareIsWhite(coordinates))

    /**
     输入：coordinates = "c7"
     输出：false
     */
    coordinates = "c7"
    res = false
    assert(res == Solution().squareIsWhite(coordinates))
}
