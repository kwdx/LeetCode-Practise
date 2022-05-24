/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int row;
    int col;
    
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) {
            // 起始点和目标点一致
            return 0;
        }

        int step = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        q.emplace(sx, sy);
        visited[sx][sy] = true;
        while (!q.empty()) {
            step++;
            int cnt = (int)q.size();
            for (int i = 0; i < cnt; ++i) {
                auto [cx, cy] = q.front();
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = cx + dirs[j][0];
                    int ny = cy + dirs[j][1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                        if (!visited[nx][ny] && forest[nx][ny] > 0) {
                            if (nx == tx && ny == ty) {
                                return step;
                            }
                            q.emplace(nx, ny);
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> trees;
        row = (int)forest.size();
        col = (int)forest[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i, j);
                }
            }
        }
        sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        
        int cx = 0;
        int cy = 0;
        int ans = 0;
        for (int i = 0; i < trees.size(); ++i) {
            int steps = bfs(forest, cx, cy, trees[i].first, trees[i].second);
            if (steps == -1) {
                return -1;
            }
            ans += steps;
            cx = trees[i].first;
            cy = trees[i].second;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> forest;
    int res;
    
    /**
     输入：forest = [[1,2,3],[0,0,4],[7,6,5]]
     输出：6
     解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。。
     */
    forest = {{1,2,3},{0,0,4},{7,6,5}};
    res = 6;
    assert(res == Solution().cutOffTree(forest));
    
    /**
     输入：forest = [[1,2,3],[0,0,0],[7,6,5]]
     输出：-1
     解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
     */
    forest = {{1,2,3},{0,0,0},{7,6,5}};
    res = -1;
    assert(res == Solution().cutOffTree(forest));

    /**
     输入：forest = [[2,3,4],[0,0,5],[8,7,6]]
     输出：6
     解释：可以按与示例 1 相同的路径来砍掉所有的树。
     (0,0) 位置的树，可以直接砍去，不用算步数。
     */
    forest = {{2,3,4},{0,0,5},{8,7,6}};
    res = 6;
    assert(res == Solution().cutOffTree(forest));

    cout << "OK~" << endl;
    
    return 0;
}
