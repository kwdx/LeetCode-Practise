/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

// @lc code=start
class Solution {
private:
    long** memo;

    long count(int lo, int hi) {
        if (lo > hi) return 1;

        if (memo[lo][hi] != 0) return memo[lo][hi];

        long res = 0;
        for (int mid = lo; mid <= hi; mid++) {
            res += count(lo, mid - 1) * count(mid + 1, hi);
        }
        memo[lo][hi] = res;
        return res;
    }

public:
    long numTrees(int n) {
        memo = new long*[n + 1];
        for (int i = 0; i <= n; i++) {
            memo[i] = new long[n + 1];
            memset(memo[i], 0, sizeof(long) * (n + 1));
        }
        return count(1, n);
    }
    
    long numTrees1(int n) {
        long dp[n + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            long res = 0;
            for (int left = 0; left < i; left++) {
                int right = i - left - 1;
                res += dp[left] * dp[right];
            }
            dp[i] = res;
        }
        return dp[n];
    }

};
// @lc code=end

int main(int argc, const char * argv[]) {
    // 1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 742900 2674440 9694845 35357670 129644790 477638700 1767263190
    vector<long> results = {
        1, 2, 5, 14, 42,
        132, 429, 1430, 4862, 16796,
        58786, 208012, 742900, 2674440, 9694845,
        35357670, 129644790, 477638700, 1767263190, 6564120420,
        24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452,
        18367353072152, 69533550916004, 263747951750360, 1002242216651368, 3814986502092304
    };

    clock_t startTime, endTime;

    startTime = clock(); // 计时开始
    for (int i = 1; i <= 30; i++) {
        long count = Solution().numTrees(i);
        if (count != results[i-1])
            cout << i << " " << count << " != " << results[i-1] << endl;
    }
    endTime = clock(); // 计时结束
    cout << "递归运行时间是: " << (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    
    startTime = clock(); // 计时开始
    for (int i = 1; i <= 30; i++) {
        long count = Solution().numTrees1(i);
        if (count != results[i-1])
            cout << i << " " << count << " != " << results[i-1] << endl;
    }
    endTime = clock(); // 计时结束
    cout << "动态规划运行时间是: " << (double)(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    
    return 0;
}
