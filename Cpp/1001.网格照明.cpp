/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<pair<int, int>> dirs = {{0,0},{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{1,-1},{-1,1},{1,1}};
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        long N = n;
        unordered_map<int, int> row, col;
        unordered_map<int, int> left, right;
        unordered_set<long> set;
        for (vector<int>& lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            int a = x + y, b = x - y;
            if (set.count(x * N + y)) continue;
            increment(row, x); increment(col, y);
            increment(left, a); increment(right, b);
            set.insert(x * N + y);
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int x = queries[i][0], y = queries[i][1];
            int a = x + y, b = x - y;
            if (row.count(x) || col.count(y) || left.count(a) || right.count(b)) {
                ans[i] = 1;
            }
            for (pair<int, int>& dir : dirs) {
                int nx = x + dir.first, ny = y + dir.second;
                int na = nx + ny, nb = nx - ny;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (set.count(nx * N + ny)) {
                    set.erase(nx * N + ny);
                    decrement(row, nx); decrement(col, ny);
                    decrement(left, na); decrement(right, nb);
                }
            }
        }
        return ans;
    }
    
    void increment(unordered_map<int, int>& map, int key) {
        ++map[key];
    }
    
    void decrement(unordered_map<int, int>& map, int key) {
        if (map[key] == 1) map.erase(key);
        else --map[key];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<vector<int>> lamps;
    vector<vector<int>> queries;
    vector<int> res;
    
    /**
     输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
     输出：[1,0]
     解释：最初所有灯都是关闭的。在执行查询之前，打开位于 [0, 0] 和 [4, 4] 的灯。第 0 次查询检查 grid[1][1] 是否被照亮（蓝色方框）。该单元格被照亮，所以 ans[0] = 1 。然后，关闭红色方框中的所有灯。
     */
    n = 5;
    lamps = {{0,0},{4,4}};
    queries = {{1,1},{1,0}};
    res = {1,0};
    assert(res ==  Solution().gridIllumination(n, lamps, queries));
    
    /**
     输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
     输出：[1,1]
     */
    n = 5;
    lamps = {{0,0},{4,4}};
    queries = {{1,1},{1,1}};
    res = {1,1};
    assert(res ==  Solution().gridIllumination(n, lamps, queries));
    
    /**
     输入：n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
     输出：[1,1,0]
     */
    n = 5;
    lamps = {{0,0},{0,4}};
    queries = {{0,4},{0,1},{1,4}};
    res = {1,1,0};
    assert(res ==  Solution().gridIllumination(n, lamps, queries));

    cout << "OK~" << endl;

    return 0;
}
