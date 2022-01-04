/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        int ans = 4;
        for (int i = 1971; i < year; ++i) {
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                ans += 366;
            } else {
                ans += 365;
            }
        }
        for (int i = 1; i < month; ++i) {
            ans += days[i - 1];
            if (i == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
                ++ans;
            }
        }
        ans += day;
        return weekdays[ans % 7];
    }
    
    string dayOfTheWeek1(int day, int month, int year) {
        vector<string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        tm t{0,0,0,day,month-1,year-1900};
        mktime(&t);
        return weekdays[t.tm_wday];
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int day, month, year;
    string res;
    
    /**
     输入：day = 31, month = 8, year = 2019
     输出："Saturday"
     */
    day = 31;
    month = 8;
    year = 2019;
    res = "Saturday";
    assert(res == Solution().dayOfTheWeek(day, month, year));

    /**
     输入：day = 18, month = 7, year = 1999
     输出："Sunday"
     */
    day = 18;
    month = 7;
    year = 1999;
    res = "Sunday";
    assert(res == Solution().dayOfTheWeek(day, month, year));

    /**
     输入：day = 15, month = 8, year = 1993
     输出："Sunday"
     */
    day = 15;
    month = 8;
    year = 1993;
    res = "Sunday";
    assert(res == Solution().dayOfTheWeek(day, month, year));
    
    /**
     输入：day = 21, month = 12, year = 1980
     输出："Sunday"
     */
    day = 21;
    month = 12;
    year = 1980;
    res = "Sunday";
    assert(res == Solution().dayOfTheWeek(day, month, year));
    
    cout << "OK~" << endl;

    return 0;
}
