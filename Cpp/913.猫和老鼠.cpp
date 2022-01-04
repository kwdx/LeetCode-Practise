/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
const int MOUSE_WIN = 1;
const int CAT_WIN = 2;
const int DRAW = 0;
const int MAXN = 51;
class Solution {
public:
    int n;
    int dp[MAXN][MAXN][MAXN*2];
    vector<vector<int>> graph;
    
    int catMouseGame(vector<vector<int>>& graph) {
        this->n = (int)graph.size();
        this->graph = graph;
        memset(dp, -1, sizeof(dp));
        return getResult(1, 2, 0);
    }

    int getResult(int mouse, int cat, int turns) {
        if (turns == n * 2) {
            return DRAW;
        }
        if (dp[mouse][cat][turns] < 0) {
            if (mouse == 0) {
                dp[mouse][cat][turns] = MOUSE_WIN;
            } else if (cat == mouse) {
                dp[mouse][cat][turns] = CAT_WIN;
            } else {
                getNextResult(mouse, cat, turns);
            }
        }
        return dp[mouse][cat][turns];
    }

    void getNextResult(int mouse, int cat, int turns) {
        int curMove = turns % 2 == 0 ? mouse : cat;
        int defaultResult = curMove == mouse ? CAT_WIN : MOUSE_WIN;
        int result = defaultResult;
        for (int next : graph[curMove]) {
            if (curMove == cat && next == 0) {
                continue;
            }
            int nextMouse = curMove == mouse ? next : mouse;
            int nextCat = curMove == cat ? next : cat;
            int nextResult = getResult(nextMouse, nextCat, turns + 1);
            if (nextResult != defaultResult) {
                result = nextResult;
                if (result != DRAW) {
                    break;
                }
            }
        }
        dp[mouse][cat][turns] = result;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> graph;
    int res;
    
    /**
     输入：graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
     输出：0
     */
    graph = {{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}};
    res = 0;
    assert(res == Solution().catMouseGame(graph));
    
    /**
     输入：graph = [[1,3],[0],[3],[0,2]]
     输出：1
     */
    graph = {{1,3},{0},{3},{0,2}};
    res = 1;
    assert(res == Solution().catMouseGame(graph));
    
    cout << "OK~" << endl;

    return 0;
}
