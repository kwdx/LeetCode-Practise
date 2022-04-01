/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        // 0 1,0
        // 1 3,2
        // 2 5,4
        // 3 7,6
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];
        
        if (cnt[0] % 2 == 1) return false;
        
        vector<int> vals(cnt.size());
        for (auto &[x, _] : cnt) vals.emplace_back(x);
        
        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });
        
        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) return false;
            cnt[2 * x] -= cnt[x];
        }

        return true;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    bool res;
    
    arr = {1,2,2,4};
    res = true;
    assert(res == Solution().canReorderDoubled(arr));
    
    /**
     输入：arr = [3,1,3,6]
     输出：false
     */
    arr = {3,1,3,6};
    res = false;
    assert(res == Solution().canReorderDoubled(arr));
    
    /**
     输入：arr = [2,1,2,6]
     输出：false
     */
    arr = {2,1,2,6};
    res = false;
    assert(res == Solution().canReorderDoubled(arr));
    
    /**
     输入：arr = [4,-2,2,-4]
     输出：true
     解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
     */
    arr = {4,-2,2,-4};
    res = true;
    assert(res == Solution().canReorderDoubled(arr));
    
    cout << "OK~" << endl;
    
    return 0;
}
