/*
 * @lc app=leetcode.cn id=2037 lang=cpp
 *
 * [2037] 使每位学生都有座位的最少移动次数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i < seats.size(); ++i) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> seats;
    vector<int> students;
    int res;
    
    /**
     输入：seats = [3,1,5], students = [2,7,4]
     输出：4
     解释：学生移动方式如下：
     - 第一位学生从位置 2 移动到位置 1 ，移动 1 次。
     - 第二位学生从位置 7 移动到位置 5 ，移动 2 次。
     - 第三位学生从位置 4 移动到位置 3 ，移动 1 次。
     总共 1 + 2 + 1 = 4 次移动。
     */
    seats = {3,1,5};
    students = {2,7,4};
    res = 4;
    assert(res == Solution().minMovesToSeat(seats, students));
    
    /**
     输入：seats = [4,1,5,9], students = [1,3,2,6]
     输出：7
     解释：学生移动方式如下：
     - 第一位学生不移动。
     - 第二位学生从位置 3 移动到位置 4 ，移动 1 次。
     - 第三位学生从位置 2 移动到位置 5 ，移动 3 次。
     - 第四位学生从位置 6 移动到位置 9 ，移动 3 次。
     总共 0 + 1 + 3 + 3 = 7 次移动。
     */
    seats = {4,1,5,9};
    students = {1,3,2,6};
    res = 7;
    assert(res == Solution().minMovesToSeat(seats, students));
    
    /**
     输入：seats = [2,2,6,6], students = [1,3,2,6]
     输出：4
     解释：学生移动方式如下：
     - 第一位学生从位置 1 移动到位置 2 ，移动 1 次。
     - 第二位学生从位置 3 移动到位置 6 ，移动 3 次。
     - 第三位学生不移动。
     - 第四位学生不移动。
     总共 1 + 3 + 0 + 0 = 4 次移动。
     */
    seats = {2,2,6,6};
    students = {1,3,2,6};
    res = 4;
    assert(res == Solution().minMovesToSeat(seats, students));

    cout << "OK~" << endl;
    
    return 0;
}
