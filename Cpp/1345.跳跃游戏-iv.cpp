/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int inf = 0x3f3f3f3f;
        int n = (int)arr.size();
        unordered_map<int, vector<int>> map;
        for(int i = n - 1; ~i; i--) {
            map[arr[i]].push_back(i);
        }
        vector<int> dist(n, inf);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(q.size()) {
            auto t = q.front(), step = dist[t];
            q.pop();
            if(t == n - 1) return step;
            if(t + 1 < n and dist[t + 1] == inf) {
                q.push(t + 1);
                dist[t + 1] = step + 1;
            }
            if(t - 1 >= 0 and dist[t - 1] == inf) {
                q.push(t - 1);
                dist[t - 1] = step + 1;
            }
            const auto& list = map[arr[t]];
            for(auto ne :list) {
                if(dist[ne] == inf) {
                    q.push(ne);
                    dist[ne] = step + 1;
                }
            }
            map[arr[t]].clear();
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    int res;
    
    /**
     输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
     输出：3
     解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
     */
    arr = {100,-23,-23,404,100,23,23,23,3,404};
    res = 3;
    assert(res == Solution().minJumps(arr));
    
    /**
     输入：arr = [7]
     输出：0
     解释：一开始就在最后一个元素处，所以你不需要跳跃。
     */
    arr = {7};
    res = 0;
    assert(res == Solution().minJumps(arr));
    
    /**
     输入：arr = [7,6,9,6,9,6,9,7]
     输出：1
     解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
     */
    arr = {7,6,9,6,9,6,9,7};
    res = 1;
    assert(res == Solution().minJumps(arr));
    
    /**
     输入：arr = [6,1,9]
     输出：2
     */
    arr = {6,1,9};
    res = 2;
    assert(res == Solution().minJumps(arr));
    
    /**
     输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
     输出：3
     */
    arr = {11,22,7,7,7,7,7,7,7,22,13};
    res = 3;
    assert(res == Solution().minJumps(arr));

    cout << "OK~" << endl;

    return 0;
}
