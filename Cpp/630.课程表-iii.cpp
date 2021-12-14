/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {
            return c0[1] < c1[1];
        });
        
        priority_queue<int> q;
        
        int day = 0;
        for (const auto& course: courses) {
            int t = course[0], lastDay = course[1];
            if (day + t <= lastDay) {
                day += t;
                q.push(t);
            } else if (!q.empty() && q.top() > t) {
                day -= q.top() - t;
                q.pop();
                q.push(t);
            }
        }
        
        return (int)q.size();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> courses;
    int res;
    
    /**
     输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
     输出：3
     解释：
     这里一共有 4 门课程，但是你最多可以修 3 门：
     首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
     第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
     第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
     第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
     */
    courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    res = 3;
    assert(res == Solution().scheduleCourse(courses));

    /**
     输入：courses = [[1,2]]
     输出：1
     */
    courses = {{1,2}};
    res = 1;
    assert(res == Solution().scheduleCourse(courses));

    /**
     输入：courses = [[3,2],[4,3]]
     输出：0
     */
    courses = {{3,2},{4,3}};
    res = 0;
    assert(res == Solution().scheduleCourse(courses));
    
    /**
     输入：courses = [[7,16],[2,3],[3,12],[3,14],[10,19],[10,16],[6,8],[6,11],[3,13],[6,16]]
     输出：4
     */
    courses = {{7,16},{2,3},{3,12},{3,14},{10,19},{10,16},{6,8},{6,11},{3,13},{6,16}};
    res = 4;
    assert(res == Solution().scheduleCourse(courses));

    cout << "OK~" << endl;

    return 0;
}
