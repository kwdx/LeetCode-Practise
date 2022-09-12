/*
 * @lc app=leetcode.cn id=857 lang=cpp
 *
 * [857] 雇佣 K 名工人的最低成本
 */

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = (int)quality.size();
        vector<int> h(n, 0);
        iota(h.begin(), h.end(), 0);
        sort(h.begin(), h.end(), [&](int& a, int& b) {
            return quality[a] * wage[b] > quality[b] * wage[a];
        });
        double res = 1e9;
        double totalq = 0.0;
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < k - 1; ++i) {
            totalq += quality[h[i]];
            q.push(quality[h[i]]);
        }
        
        for (int i = k - 1; i < n; ++i) {
            int idx = h[i];
            totalq += quality[idx];
            q.push(quality[idx]);
            double totalc = ((double) wage[idx] / quality[idx]) * totalq;
            res = min(res, totalc);
            totalq -= q.top();
            q.pop();
        }
        
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> quality;
    vector<int> wage;
    int k;
    double res;
    
    /**
     输入： quality = [10,20,5], wage = [70,50,30], k = 2
     输出： 105.00000
     解释： 我们向 0 号工人支付 70，向 2 号工人支付 35。
     */
    quality = {10,20,5};
    wage = {70,50,30};
    k = 2;
    res = 105.00000;
    assert(res == Solution().mincostToHireWorkers(quality, wage, k));
    
    /**
     输入： quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
     输出： 30.66667
     解释： 我们向 0 号工人支付 4，向 2 号和 3 号分别支付 13.33333。
     */
    quality = {3,1,10,10,1};
    wage = {4,8,2,2,7};
    k = 3;
    res = 30.66667;
    assert(res == Solution().mincostToHireWorkers(quality, wage, k));

    cout << "OK~" << endl;
    
    return 0;
}
