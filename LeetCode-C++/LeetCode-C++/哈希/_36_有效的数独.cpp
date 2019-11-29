//
//  _36_有效的数独.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_36_有效的数独.hpp"

bool _36_有效的数独::isValidSudoku(vector<vector<char>>& board) {
    short rows[9] = {0};
    short cols[9] = {0};
    short boxes[9] = {0};
    
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                continue;
            }
            int num = 1 << (board[row][col] - '1');
            if ((rows[row] & num) != 0) return false;
            if ((cols[col] & num) != 0) return false;
            
            int box = (row / 3) * 3 + col / 3;
            
            if ((boxes[box] & num) != 0) return false;
            
            rows[row] |= num;
            cols[col] |= num;
            boxes[box] |= num;
        }
    }
    
    return true;
}
