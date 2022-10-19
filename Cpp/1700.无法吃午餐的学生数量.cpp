/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s1 = accumulate(students.begin(), students.end(), 0);
        int s0 = (int)students.size() - s1;
        for (int x : sandwiches) {
            if (x == 0 && s0 > 0) {
                s0 -= 1;
            } else if (x == 1 && s1 > 0) {
                s1 -= 1;
            } else {
                break;
            }
        }
        return s1 + s0;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> students;
    vector<int> sandwiches;
    int res;
    
    /**
     输入：students = [1,1,0,0], sandwiches = [0,1,0,1]
     输出：0
     解释：
     - 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,0,0,1]。
     - 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,0,1,1]。
     - 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [0,1,1]，三明治栈为 sandwiches = [1,0,1]。
     - 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,1,0]。
     - 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1,0]，三明治栈为 sandwiches = [0,1]。
     - 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,1]。
     - 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1]，三明治栈为 sandwiches = [1]。
     - 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = []，三明治栈为 sandwiches = []。
     所以所有学生都有三明治吃。
     */
    students = {1,1,0,0};
    sandwiches = {0,1,0,1};
    res = 0;
    assert(res == Solution().countStudents(students, sandwiches));
    
    /**
     输入：students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
     输出：3
     */
    students = {1,1,1,0,0,1};
    sandwiches = {1,0,0,0,1,1};
    res = 3;
    assert(res == Solution().countStudents(students, sandwiches));
    
    cout << "OK~" << endl;
    
    return 0;
}
