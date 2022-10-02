/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = (int)start.size();
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (i == n || j == n) return i == j;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            ++i;
            ++j;
        }
        return i == j;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string start;
    string end;
    bool res;
    
    /**
     输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
     输出: True
     解释:
     我们可以通过以下几步将start转换成end:
     RXXLRXRXL ->
     XRXLRXRXL ->
     XRLXRXRXL ->
     XRLXXRRXL ->
     XRLXXRRLX
     */
    start = "RXXLRXRXL";
    end = "XRLXXRRLX";
    res = true;
    assert(res == Solution().canTransform(start, end));
    
    cout << "OK~" << endl;
    
    return 0;
}
