/*
 * @lc app=leetcode.cn id=749 lang=cpp
 *
 * [749] 隔离病毒
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int containVirus(vector<vector<int>>& isInfected) {
        auto pair_hash = [fn = hash<int>()](const pair<int, int>& o) {
            return (fn(o.first) << 16) ^ fn(o.second);
        };

        int m = (int)isInfected.size(), n = (int)isInfected[0].size();
        int ans = 0;
        while (true) {
            vector<unordered_set<pair<int, int>, decltype(pair_hash)>> neighbors;
            vector<int> firewalls;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] == 1) {
                        queue<pair<int, int>> q;
                        unordered_set<pair<int, int>, decltype(pair_hash)> neighbor(0, pair_hash);
                        int firewall = 0, idx = (int)neighbors.size() + 1;
                        q.emplace(i, j);
                        isInfected[i][j] = -idx;

                        while (!q.empty()) {
                            auto [x, y] = q.front();
                            q.pop();
                            for (int d = 0; d < 4; ++d) {
                                int nx = x + dirs[d][0];
                                int ny = y + dirs[d][1];
                                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                    if (isInfected[nx][ny] == 1) {
                                        q.emplace(nx, ny);
                                        isInfected[nx][ny] = -idx;
                                    }
                                    else if (isInfected[nx][ny] == 0) {
                                        ++firewall;
                                        neighbor.emplace(nx, ny);
                                    }
                                }
                            }
                        }
                        neighbors.push_back(move(neighbor));
                        firewalls.push_back(firewall);
                    }
                }
            }
            
            if (neighbors.empty()) {
                break;
            }

            int idx = (int)(max_element(neighbors.begin(), neighbors.end(), [](const auto& v0, const auto& v1) { return v0.size() < v1.size(); }) - neighbors.begin());
            ans += firewalls[idx];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] < 0) {
                        if (isInfected[i][j] != -idx - 1) {
                            isInfected[i][j] = 1;
                        }
                        else {
                            isInfected[i][j] = 2;
                        }
                    }
                }
            }
            for (int i = 0; i < neighbors.size(); ++i) {
                if (i != idx) {
                    for (const auto& [x, y]: neighbors[i]) {
                        isInfected[x][y] = 1;
                    }
                }
            }
            if (neighbors.size() == 1) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> isInfected;
    int res;
    
    /**
     输入: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
     输出: 10
     解释:一共有两块被病毒感染的区域。
     在第一天，添加 5 墙隔离病毒区域的左侧。病毒传播后的状态是:

     第二天，在右侧添加 5 个墙来隔离病毒区域。此时病毒已经被完全控制住了。
     */
    isInfected = {{0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0}};
    res = 10;
    assert(res == Solution().containVirus(isInfected));
    
    /**
     输入: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
     输出: 4
     解释: 虽然只保存了一个小区域，但却有四面墙。
     注意，防火墙只建立在两个不同区域的共享边界上。
     */
    isInfected = {{1,1,1},{1,0,1},{1,1,1}};
    res = 4;
    assert(res == Solution().containVirus(isInfected));
    
    /**
     输入: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
     输出: 13
     解释: 在隔离右边感染区域后，隔离左边病毒区域只需要 2 个防火墙。
     */
    isInfected = {{1,1,1,0,0,0,0,0,0},{1,0,1,0,1,1,1,1,1},{1,1,1,0,0,0,0,0,0}};
    res = 13;
    assert(res == Solution().containVirus(isInfected));
    
    cout << "OK~" << endl;
    
    return 0;
}
