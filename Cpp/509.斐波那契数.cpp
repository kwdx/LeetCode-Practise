/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int a = 0, b = 1;
        for (int i = 1; i < n; i++)
        {
            b = a + b;
            a = b - a;
        }
        return b;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {

    assert(0 == Solution().fib(0));
    assert(1 == Solution().fib(1));
    assert(1 == Solution().fib(2));
    assert(2 == Solution().fib(3));
    assert(3 == Solution().fib(4));
    assert(5 == Solution().fib(5));
    assert(8 == Solution().fib(6));
    assert(13 == Solution().fib(7));
    assert(21 == Solution().fib(8));

    cout << "OK~" << endl;

    return 0;
}
