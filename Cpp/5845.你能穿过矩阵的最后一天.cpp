//
//  5845.你能穿过矩阵的最后一天.cpp
//  Cpp
//
//  Created by warden on 2021/8/15.
//
// https://leetcode-cn.com/problems/last-day-where-you-can-still-cross/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int days = 0;
        
        int dp[row + 1][col + 1];
        for (int i = 1; i <= row; i++) {
            memset(dp[0], 0, sizeof(int) * (col + 1));
        }
        
        
        
        return days;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    vector<vector<int>> cells;
    
    cells = {
        {1,1},
        {2,1},
        {1,2},
        {2,2}
    };
    // 2
    cout << Solution().latestDayToCross(2, 2, cells) << endl;
    
    cells = {
        {1,1},
        {1,2},
        {2,1},
        {2,2}
    };
    // 1
    cout << Solution().latestDayToCross(2, 2, cells) << endl;
    
    cells = {
        {1,2},
        {2,1},
        {3,3},
        {2,2},
        {1,1},
        {1,3},
        {2,3},
        {3,2},
        {3,1}
    };
    // 3
    cout << Solution().latestDayToCross(2, 2, cells) << endl;
    
    return 0;
}
