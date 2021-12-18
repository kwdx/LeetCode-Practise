/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (i > 0 && board[i - 1][j] == 'X') continue;
                if (j > 0 && board[i][j - 1] == 'X') continue;
                if (board[i][j] == 'X') ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<char>> board;
    int res;
    
    /**
     输入：board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
     输出：2
     */
    board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    res = 2;
    assert(res == Solution().countBattleships(board));
    
    /**
     输入：board = [["."]]
     输出：0
     */
    board = {{'.'}};
    res = 0;
    assert(res == Solution().countBattleships(board));

    cout << "OK~" << endl;

    return 0;
}
