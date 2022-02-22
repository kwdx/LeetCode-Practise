/*
 * @lc app=leetcode.cn id=1994 lang=cpp
 *
 * [1994] 好子集的数目
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

// @lc code=start
class Solution {
public:
    static constexpr int num_max = 30;
    static constexpr int mod = 1000000007;

    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        vector<int> freq(num_max + 1);
        // 统计每个数出现次数
        for (int num: nums) {
            ++freq[num];
        }

        vector<int> f(1 << primes.size());
        f[0] = 1;
        // 因为所有的 1 可以选也可以不选
        for (int _ = 0; _ < freq[1]; ++_) {
            f[0] = f[0] * 2 % mod;
        }
        
        // 遍历所有的数
        for (int i = 2; i <= num_max; ++i) {
            if (!freq[i]) {
                continue;
            }
            
            // 检查 i 的每个质因数是否均不超过 1 个
            int subset = 0, x = i;
            bool check = true;
            for (int j = 0; j < primes.size(); ++j) {
                int prime = primes[j];
                if (x % (prime * prime) == 0) {
                    check = false;
                    break;
                }
                if (x % prime == 0) {
                    subset |= (1 << j);
                }
            }
            if (!check) {
                continue;
            }

            // 动态规划
            for (int mask = (1 << primes.size()) - 1; mask > 0; --mask) {
                if ((mask & subset) == subset) {
                    f[mask] = (f[mask] + static_cast<long long>(f[mask ^ subset]) * freq[i]) % mod;
                }
            }
        }

        int ans = 0;
        for (int mask = 1, mask_max = (1 << primes.size()); mask < mask_max; ++mask) {
            ans = (ans + f[mask]) % mod;
        }
        
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [1,2,3,4]
     输出：6
     解释：好子集为：
     - [1,2]：乘积为 2 ，可以表示为质数 2 的乘积。
     - [1,2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
     - [1,3]：乘积为 3 ，可以表示为质数 3 的乘积。
     - [2]：乘积为 2 ，可以表示为质数 2 的乘积。
     - [2,3]：乘积为 6 ，可以表示为互不相同的质数 2 和 3 的乘积。
     - [3]：乘积为 3 ，可以表示为质数 3 的乘积。
     */
    nums = {1,2,3,4};
    res = 6;
    assert(res == Solution().numberOfGoodSubsets(nums));
    
    /**
     输入：nums = [4,2,3,15]
     输出：5
     解释：好子集为：
     - [2]：乘积为 2 ，可以表示为质数 2 的乘积。
     - [2,3]：乘积为 6 ，可以表示为互不相同质数 2 和 3 的乘积。
     - [2,15]：乘积为 30 ，可以表示为互不相同质数 2，3 和 5 的乘积。
     - [3]：乘积为 3 ，可以表示为质数 3 的乘积。
     - [15]：乘积为 15 ，可以表示为互不相同质数 3 和 5 的乘积。
     */
    nums = {4,2,3,15};
    res = 5;
    assert(res == Solution().numberOfGoodSubsets(nums));

    cout << "OK~" << endl;
    
    return 0;
}
