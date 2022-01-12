/*
 * @lc app=leetcode.cn id=1036 lang=cpp
 *
 * [1036] 逃离大迷宫
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
private:
    int EDGE = 1e6, MAX = 1e5;
    long long BASE = 13331;
    unordered_set<long long> set;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for (vector<int>& p : blocked) set.insert(p[0] * BASE + p[1]);
        int n = (int)blocked.size();
        MAX = (n * (n - 1)) >> 1;
        return check(source, target) && check(target, source);
    }
    bool check(vector<int>& a, vector<int>& b) {
        unordered_set<long long> vis;
        queue<pair<int, int>> q;
        q.push({a[0], a[1]});
        vis.insert(a[0] * BASE + a[1]);
        while (q.size() and vis.size() <= MAX) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            if (x == b[0] and y == b[1]) return true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < 0 or nx >= EDGE or ny < 0 or ny >= EDGE) continue;
                if (set.count(nx * BASE + ny)) continue;
                if (vis.count(nx * BASE + ny)) continue;
                q.push({nx, ny});
                vis.insert(nx * BASE + ny);
            }
        }
        return vis.size() > MAX;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> blocked;
    vector<int> source, target;
    bool res;
    
    /**
     输入：blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
     输出：false
     解释：
     从源方格无法到达目标方格，因为我们无法在网格中移动。
     无法向北或者向东移动是因为方格禁止通行。
     无法向南或者向西移动是因为不能走出网格。
     */
    blocked = {{0,1},{1,0}};
    source = {0,0};
    target = {0,2};
    res = false;
    assert(res == Solution().isEscapePossible(blocked, source, target));
    
    /**
     输入：blocked = [], source = [0,0], target = [999999,999999]
     输出：true
     解释：
     因为没有方格被封锁，所以一定可以到达目标方格。
     */
    blocked = {};
    source = {0,0};
    target = {999999,999999};
    res = true;
    assert(res == Solution().isEscapePossible(blocked, source, target));
    
    /**
     输入：blocked = [], source = [0,0], target = [999999,999999]
     输出：true
     解释：
     因为没有方格被封锁，所以一定可以到达目标方格。
     */
    blocked = {{100059,100063},{100060,100064},{100061,100065},{100062,100066},{100063,100067},{100064,100068},{100065,100069},{100066,100070},{100067,100071},{100068,100072},{100069,100073},{100070,100074},{100071,100075},{100072,100076},{100073,100077},{100074,100078},{100075,100079},{100076,100080},{100077,100081},{100078,100082},{100079,100083},{100080,100082},{100081,100081},{100082,100080},{100083,100079},{100084,100078},{100085,100077},{100086,100076},{100087,100075},{100088,100074},{100089,100073},{100090,100072},{100091,100071},{100092,100070},{100093,100069},{100094,100068},{100095,100067},{100096,100066},{100097,100065},{100098,100064},{100099,100063},{100098,100062},{100097,100061},{100096,100060},{100095,100059},{100094,100058},{100093,100057},{100092,100056},{100091,100055},{100090,100054},{100089,100053},{100088,100052},{100087,100051},{100086,100050},{100085,100049},{100084,100048},{100083,100047},{100082,100046},{100081,100045},{100080,100044},{100079,100043},{100078,100044},{100077,100045},{100076,100046},{100075,100047},{100074,100048},{100073,100049},{100072,100050},{100071,100051},{100070,100052},{100069,100053},{100068,100054},{100067,100055},{100066,100056},{100065,100057},{100064,100058},{100063,100059},{100062,100060},{100061,100061},{100060,100062}};
    source = {100079,100063};
    target = {999948,999967};
    res = false;
    assert(res == Solution().isEscapePossible(blocked, source, target));

    cout << "OK~" << endl;

    return 0;
}
