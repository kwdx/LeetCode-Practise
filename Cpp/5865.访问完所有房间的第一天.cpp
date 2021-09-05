//
//  5865.访问完所有房间的第一天.cpp
//  Cpp
//
//  Created by warden on 2021/9/5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
//        int days = 0;
//
//        int MOD = 1000000007;
//        int count = 0;
//        bitset<100000> visited;
//        bitset<100000> visitCount;
//        int i = 0;
//
//        while (true) {
//            if (!visited.test(i)) {
//                // 未访问过
//                count += 1;
//                visited.set(i);
//            }
//            // 全部访问过了
//            if (count == nextVisit.size())
//                return days;
//            days = (days + 1) % MOD;
//
//            if (visitCount.test(i)) {
//                // 加上这次访问，次数为偶数
//                visitCount.reset(i);
//                i = (i == nextVisit.size()) ? 0 : (i + 1);
//            } else {
//                // 加上这次访问，次数为奇数
//                visitCount.set(i);
//                i = nextVisit[i];
//            }
//            nextVisit[i];
//        }
//
//        return days;
        
        int n = (int)nextVisit.size();
        int MOD = 1000000007;
        vector<long> dp(n, 0);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = (2 * dp[i - 1] + MOD - dp[nextVisit[i - 1]] + 2) % MOD;
        }
        return (int)dp[n - 1];
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nextVisit;
    int res;
    
    /**
     输入：nextVisit = [0,0]
     输出：2
     解释：
     - 第 0 天，你访问房间 0 。访问 0 号房间的总次数为 1 ，次数为奇数。
       下一天你需要访问房间的编号是 nextVisit[0] = 0
     - 第 1 天，你访问房间 0 。访问 0 号房间的总次数为 2 ，次数为偶数。
       下一天你需要访问房间的编号是 (0 + 1) mod 2 = 1
     - 第 2 天，你访问房间 1 。这是你第一次完成访问所有房间的那天。
     */
    nextVisit = {0,0};
    res = 2;
    assert(res == Solution().firstDayBeenInAllRooms(nextVisit));

    /**
     输入：nextVisit = [0,0,2]
     输出：6
     解释：
     你每天访问房间的次序是 [0,0,1,0,0,1,2,...] 。
     第 6 天是你访问完所有房间的第一天。
     */
    nextVisit = {0,0,2};
    res = 6;
    assert(res == Solution().firstDayBeenInAllRooms(nextVisit));

    /**
     输入：nextVisit = [0,1,2,0]
     输出：6
     解释：
     你每天访问房间的次序是 [0,0,1,0,0,1,2,...] 。
     第 6 天是你访问完所有房间的第一天。
     */
    nextVisit = {0,1,2,0};
    res = 6;
    assert(res == Solution().firstDayBeenInAllRooms(nextVisit));
    
    /**
     输入：nextVisit = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
     输出：320260018
     解释：
     你每天访问房间的次序是 [0,0,1,0,0,1,2,...] 。
     第 6 天是你访问完所有房间的第一天。
     */
    nextVisit = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//    cout << Solution().firstDayBeenInAllRooms(nextVisit) << endl;
    res = 320260018;
    assert(res == Solution().firstDayBeenInAllRooms(nextVisit));
    
    cout << "OK~" << endl;
    
    return 0;
}
