/*
 * @lc app=leetcode.cn id=794 lang=swift
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
    private func win(_ board: [[Character]], _ c: Character) -> Bool {
        for i in 0..<3 {
            if board[i][0] == c && board[i][1] == c && board[i][2] == c {
                // 同一行
                return true
            }
            if board[0][i] == c && board[1][i] == c && board[2][i] == c {
                // 同一列
                return true
            }
        }
        // 对角线
        if board[0][0] == c && board[1][1] == c && board[2][2] == c {
            return true
        }
        if board[0][2] == c && board[1][1] == c && board[2][0] == c {
            return true
        }
        return false
    }
    
    func validTicTacToe(_ board: [String]) -> Bool {
        var xNum = 0
        var oNum = 0
        
        let board_ = board.map {
            $0.unicodeScalars.map { a -> Character in
                let c = Character(a)
                switch c {
                case "X":
                    xNum += 1
                case "O":
                    oNum += 1
                default:
                    break
                }
                return c
            }
        }
        
        if oNum != xNum && oNum != xNum - 1 {
            return false
        }
        if win(board_, "X") && oNum != xNum - 1 {
            return false
        }
        if win(board_, "O") && oNum != xNum {
            return false
        }
        return true
    }
}
// @lc code=end

func main() {
    var board: [String]
    var res: Bool
    
    /**
     输入: board = ["O  ", "   ", "   "]
     输出: false
     解释: 第一个玩家总是放置“X”。
     */
    board = ["O  ", "   ", "   "]
    res = false
    assert(res == Solution().validTicTacToe(board))
    
    /**
     输入: board = ["XOX", " X ", "   "]
     输出: false
     解释: 玩家应该是轮流放置的。
     */
    board = ["XOX", " X ", "   "]
    res = false
    assert(res == Solution().validTicTacToe(board))
    
    /**
     输入: board = ["XXX", "   ", "OOO"]
     输出: false
     */
    board = ["XXX", "   ", "OOO"]
    res = false
    assert(res == Solution().validTicTacToe(board))
    
    /**
     输入: board = ["XOX", "O O", "XOX"]
     输出: true
     */
    board = ["XOX", "O O", "XOX"]
    res = true
    assert(res == Solution().validTicTacToe(board))
}
