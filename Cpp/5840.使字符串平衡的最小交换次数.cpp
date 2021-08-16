//
//  5840.使字符串平衡的最小交换次数.cpp
//  Cpp
//
//  Created by warden on 2021/8/8.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        if (s.empty()) return true;
        if (s.length() & 0x1) return false;
        
        int cnt = 0, minCnt = 0;
        for (auto ch : s) {
            if (ch == '[') {
                cnt ++;
            } else {
                cnt --;
                minCnt = min(cnt, minCnt);
            }
        }
        return (-minCnt + 1) / 2;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution solution;
    
    // 1
    cout << solution.minSwaps("][][") << endl;
    
    // 2
    cout << solution.minSwaps("]]][[[") << endl;
    
    // 0
    cout << solution.minSwaps("[]") << endl;
    
    // 1
    cout << solution.minSwaps("][[]][][[][]") << endl;
    
    return 0;
}
