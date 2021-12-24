/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int dayOfYear(string date) {
        tm t;
        strptime(date.c_str(), "%Y-%m-%d", &t);
        return t.tm_yday + 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string date;
    int res;
    
    /**
     输入：date = "2019-01-09"
     输出：9
     */
    date = "2019-01-09";
    res = 9;
    assert(res == Solution().dayOfYear(date));
    
    /**
     输入：date = "2019-02-10"
     输出：41
     */
    date = "2019-02-10";
    res = 41;
    assert(res == Solution().dayOfYear(date));
    
    /**
     输入：date = "2003-03-01"
     输出：60
     */
    date = "2003-03-01";
    res = 60;
    assert(res == Solution().dayOfYear(date));
    
    /**
     输入：date = "2004-03-01"
     输出：61
     */
    date = "2004-03-01";
    res = 61;
    assert(res == Solution().dayOfYear(date));

    cout << "OK~" << endl;

    return 0;
}
