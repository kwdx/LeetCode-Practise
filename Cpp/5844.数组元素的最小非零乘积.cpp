//
//  5844.数组元素的最小非零乘积.cpp
//  Cpp
//
//  Created by warden on 2021/8/15.
//
// https://leetcode-cn.com/problems/minimum-non-zero-product-of-the-array-elements/

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int minNonZeroProduct(int p) {
        static const int MOD = 1000000007;
        using LL = long long;

        LL maxNum = (1LL << p) - 1;
        LL base = (maxNum - 1) % MOD;
        LL k = maxNum >> 1;
        LL res = 1;
        while (k) {
            if (k & 1) res = res * base % MOD;
            base = base * base % MOD;
            k >>= 1;
        }
        res = (res % MOD) * (maxNum % MOD) % MOD;
        return (int)res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
            
    // 1
    cout << Solution().minNonZeroProduct(1) << endl;

    // 6
    cout << Solution().minNonZeroProduct(2) << endl;

    // 1512
    cout << Solution().minNonZeroProduct(3) << endl;

    // 581202553
    cout << Solution().minNonZeroProduct(4) << endl;
    
    // 202795991
    cout << Solution().minNonZeroProduct(5) << endl;
    
    // 945196305
    cout << Solution().minNonZeroProduct(30) << endl;
    
    // 138191773
    cout << Solution().minNonZeroProduct(31) << endl;
    
    // 813987236
    cout << Solution().minNonZeroProduct(60) << endl;
    
    return 0;
}
