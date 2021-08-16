//
//  5187_收集足够苹果的最小花园周长.cpp
//  LeetCode
//
//  Created by warden on 2021/8/1.
//
// https://leetcode-cn.com/contest/weekly-contest-252/problems/minimum-garden-perimeter-to-collect-enough-apples/

#include <iostream>

using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long n = 0;
        while (++n) {
            long long apples = (2 * n + 1) * (n + 1) * n * 2;
            if (apples >= neededApples) break;;
        }
        return n * 8;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    cout << 1 / 2 << endl;
    cout << (1 + 1) * 1 / 2 << endl;
    // 8
    cout << Solution().minimumPerimeter(1) << endl;
    // 16
    cout << Solution().minimumPerimeter(13) << endl;
    // 5040
    cout << Solution().minimumPerimeter(1000000000) << endl;
    // 355344
    cout << Solution().minimumPerimeter(350551360251708) << endl;
    
    return 0;
}
