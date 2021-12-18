/*
 * @lc app=leetcode.cn id=419 lang=swift
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
class Solution {
    func countBattleships(_ board: [[Character]]) -> Int {
        var ans = 0
        for i in 0..<board.count {
            for j in 0..<board[i].count {
                if i > 0 && board[i - 1][j] == "X" {
                    continue
                }
                if j > 0 && board[i][j - 1] == "X" {
                    continue
                }
                if board[i][j] == "X" {
                    ans += 1
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var board: [[Character]]
    var res: Int
    
    /**
     输入：board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
     输出：2
     */
    board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
    res = 2
    assert(res == Solution().countBattleships(board))
    
    /**
     输入：board = [["."]]
     输出：0
     */
    board = [["."]]
    res = 0
    assert(res == Solution().countBattleships(board))
}
