/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
private:
    bool win(vector<string>& board, char ch) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == ch && board[i][1] == ch && board[i][2] == ch) {
                // 同一行
                return true;
            }
            if (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch) {
                // 同一列
                return true;
            }
        }
        // 对角线
        if (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) {
            return true;
        }
        if (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch) {
            return true;
        }
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int xNum = 0, oNum = 0;
        for (string s : board) {
            for (char ch : s) {
                switch (ch) {
                    case 'X':
                        ++xNum;
                        break;
                    case 'O':
                        ++oNum;
                    default:
                        break;
                }
            }
        }
        if (oNum != xNum && oNum != xNum - 1) {
            return false;
        }
        if (win(board, 'X') && oNum != xNum - 1) {
            return false;
        }
        if (win(board, 'O') && oNum != xNum) {
            return false;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> board;
    bool res;
    
    /**
     输入: board = ["O  ", "   ", "   "]
     输出: false
     解释: 第一个玩家总是放置“X”。
     */
    board = {"O  ", "   ", "   "};
    res = false;
    assert(res == Solution().validTicTacToe(board));
    
    /**
     输入: board = ["XOX", " X ", "   "]
     输出: false
     解释: 玩家应该是轮流放置的。
     */
    board = {"XOX", " X ", "   "};
    res = false;
    assert(res == Solution().validTicTacToe(board));
    
    /**
     输入: board = ["XXX", "   ", "OOO"]
     输出: false
     */
    board = {"XXX", "   ", "OOO"};
    res = false;
    assert(res == Solution().validTicTacToe(board));
    
    /**
     输入: board = ["XOX", "O O", "XOX"]
     输出: true
     */
    board = {"XOX", "O O", "XOX"};
    res = true;
    assert(res == Solution().validTicTacToe(board));

    cout << "OK~" << endl;

    return 0;
}
