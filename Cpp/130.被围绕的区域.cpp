/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

#include <iostream>
#include <vector>
//#include "UnionFind.h"

using namespace std;

// @lc code=start
class UnionFind {
private:
    // 图的容量
    int capacity;
    // 存储若干棵树
    std::vector<int> parents;
    // 记录树的重量
    std::vector<int> size;
public:
    UnionFind(int n) {
        capacity = n;
        
        parents.resize(n);
        size.resize(n);
        
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    void unionn(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP == rootQ) return;
        
        if (size[rootP] > size[rootQ]) {
            parents[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parents[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        capacity--;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int x) {
        while (parents[x] != x) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    int count() {
        return capacity;
    }
 };

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        
        int m = (int)board.size();
        int n = (int)board[0].size();
        
        int dummy = n * m;
        UnionFind uf(dummy + 1);
        
        // 将首列和尾列的 0 与 dummy 相连
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                uf.unionn(i * n, dummy);
            if (board[i][n - 1] == 'O')
                uf.unionn(i * n + n - 1, dummy);
        }
        // 将首行和尾行的 0 与 dummy 相连
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                uf.unionn(j, dummy);
            if (board[m - 1][j] == 'O')
                uf.unionn((m - 1) * n + j, dummy);
        }
        
        int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O') {
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (board[x][y] == 'O')
                            uf.unionn(x * n + y, i * n + j);
                    }
                }
            }
        }
        
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O' && !uf.connected(i * n + j, dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    vector<vector<char>> board;
    vector<vector<char>> result;
    
    board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    result = {
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','O','X','X'}
    };
    Solution().solve(board);
    cout << (result == board) << endl;

    board = {
        {'X'}
    };
    result = {
        {'X'}
    };
    Solution().solve(board);
    cout << (result == board) << endl;
    
    board = {
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','X','O','X'},
        {'X','X','O','X'}
    };
    result = {
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','X','O','X'},
        {'X','X','O','X'}
    };
    Solution().solve(board);
    cout << (result == board) << endl;

    return 0;
}

