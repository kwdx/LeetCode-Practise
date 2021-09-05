/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int rand10() {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += rand7();
        }
        return 1 + sum % 10 ;
    }
    
    int rand7() {
        return random() % 7;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    
    int n = 0;
    
    n = 30;
    while (n-- > 0) {
        cout << Solution().rand10() << endl;
    }
    
    cout << "OK~" << endl;
    
    return 0;
}
