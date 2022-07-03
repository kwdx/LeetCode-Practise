/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int i = (int)str.size() - 1;
        while (i > 0 && str[i] <= str[i -1]) --i;
        if (i <= 0) {
            return -1;
        }
        int j = (int)str.size() - 1;
        while (str[j] <= str[i - 1]) --j;
        swap(str[i - 1], str[j]);
        reverse(str.begin() + i, str.end());
        long ans = stol(str);
        return ans > INT_MAX ? -1 : (int)ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;

    n = 2147483486;
    res = -1;
    assert(res == Solution().nextGreaterElement(n));

    /**
     输入：n = 12
     输出：21
     */
    n = 12;
    res = 21;
    assert(res == Solution().nextGreaterElement(n));
    
    /**
     输入：n = 21
     输出：-1
     */
    n = 21;
    res = -1;
    assert(res == Solution().nextGreaterElement(n));

    cout << "OK~" << endl;
    
    return 0;
}
