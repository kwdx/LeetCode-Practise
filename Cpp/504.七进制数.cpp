/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        int flag = num < 0;
        if (flag) num = -num;
        
        do {
            ans = to_string(num % 7) + ans;
            num /= 7;
        } while (num != 0);
        
        if (flag) {
            ans = "-" + ans;
        }
        
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num;
    string res;
    
    /**
     输入: num = 100
     输出: "202"
     */
    num = 100;
    res = "202";
    assert(res == Solution().convertToBase7(num));
    
    /**
     输入: num = -7
     输出: "-10"
     */
    num = -7;
    res = "-10";
    assert(res == Solution().convertToBase7(num));
    
    num = 0;
    res = "0";
    assert(res == Solution().convertToBase7(num));

    cout << "OK~" << endl;
    
    return 0;
}
