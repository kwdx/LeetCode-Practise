/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = (int)profits.size();
        priority_queue<int, vector<int>, less<int>> pq;
        
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {capital[i], profits[i]};
        }
        sort(arr.begin(), arr.end());
        
        int index = 0;
        while (k > 0) {
            while (index < n && arr[index].first <= w) {
                pq.push(arr[index].second);
                ++index;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
            k--;
        }
        
        return w;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<int> profits, capital;
    int k, w;
    int res;
    
    /**
     输入：k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
     输出：4
     解释：
     由于你的初始资本为 0，你仅可以从 0 号项目开始。
     在完成后，你将获得 1 的利润，你的总资本将变为 1。
     此时你可以选择开始 1 号或 2 号项目。
     由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
     因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。
     */
    profits = {1,2,3};
    capital = {0,1,1};
    k = 2;
    w = 0;
    res = 4;
    assert(res == Solution().findMaximizedCapital(k, w, profits, capital));
    
    /**
     输入：k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
     输出：6
     */
    profits = {1,2,3};
    capital = {0,1,2};
    k = 3;
    w = 0;
    res = 6;
    assert(res == Solution().findMaximizedCapital(k, w, profits, capital));

    cout << "OK~" << endl;
    
    return 0;
}
