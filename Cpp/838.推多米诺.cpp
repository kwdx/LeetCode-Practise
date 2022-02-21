/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = (int)dominoes.size();
        vector<int> g(n, 0);
        deque<vector<int>> d;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == '.') continue;
            int dir = dominoes[i] == 'L' ? -1 : 1;
            d.push_back({i, 1, dir});
            g[i] = 1;
        }
        while (!d.empty()) {
            vector<int> info = d.front();
            d.pop_front();
            int loc = info[0], time = info[1], dir = info[2];
            int next = loc + dir;
            if (dominoes[loc] == '.' || next < 0 || next >= n) continue;
            if (g[next] == 0) { // 首次受力
                dominoes[next] = dir == -1 ? 'L' : 'R';
                d.push_back({next, time + 1, dir});
                g[next] = time + 1;
            } else if (g[next] == time + 1) {   // 多次受力
                dominoes[next] = '.';
            }
        }
        return dominoes;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string dominoes;
    string res;
    
    /**
     输入：dominoes = "RR.L"
     输出："RR.L"
     解释：第一张多米诺骨牌没有给第二张施加额外的力。
     */
    dominoes = "RR.L";
    res = "RR.L";
    assert(res == Solution().pushDominoes(dominoes));
    
    /**
     输入：dominoes = ".L.R...LR..L.."
     输出："LL.RR.LLRRLL.."
     */
    dominoes = ".L.R...LR..L..";
    res = "LL.RR.LLRRLL..";
    assert(res == Solution().pushDominoes(dominoes));
    
    cout << "OK~" << endl;
    
    return 0;
}
