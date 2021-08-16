//
//  5830_三除数.cpp
//  LeetCode
//
//  Created by warden on 2021/8/1.
//
// https://leetcode-cn.com/contest/weekly-contest-252/problems/three-divisors/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isThree(int n) {
        if (n <= 3) return false;
        bool canSqrt = false;
        int left = 2; int right = n >> 1;
        while (left <= right) {
            int multi = left * right;
            if (multi < n) {
                left += 1;
            } else if (multi > n) {
                right -= 1;
            } else { // multi == n
                if (left != right) return false;
                canSqrt = true;
                left += 1;
                right -= 1;
            }
        }
        return canSqrt;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    cout << Solution().isThree(2) << endl;
    cout << Solution().isThree(3) << endl;
    cout << Solution().isThree(5) << endl;
    cout << Solution().isThree(6) << endl;
    cout << Solution().isThree(7) << endl;
    cout << Solution().isThree(8) << endl;
    cout << Solution().isThree(16) << endl;
    cout << Solution().isThree(36) << endl;

    cout << Solution().isThree(4) << endl;
    cout << Solution().isThree(9) << endl;
    cout << Solution().isThree(25) << endl;
    cout << Solution().isThree(49) << endl;
    
    return 0;
}
