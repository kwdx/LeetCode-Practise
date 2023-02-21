/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    struct Ratio {
        int pass, total;
        bool operator < (const Ratio& oth) const {
            return (long long) (oth.total + 1) * oth.total * (total - pass) < (long long) (total + 1) * total * (oth.total - oth.pass);
        }
    };
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Ratio> q;
        for (auto &c : classes) {
            q.push({c[0], c[1]});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto [pass, total] = q.top();
            q.pop();
            q.push({pass + 1, total + 1});
        }

        double res = 0;
        for (int i = 0; i < classes.size(); i++) {
            auto [pass, total] = q.top();
            q.pop();
            res += 1.0 * pass / total;
        }
        return res / classes.size();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> classes;
    int extraStudents;
    double res;
    
    /**
     输入：classes = [[1,2],[3,5],[2,2]], extraStudents = 2
     输出：0.78333
     解释：你可以将额外的两个学生都安排到第一个班级，平均通过率为 (3/4 + 3/5 + 2/2) / 3 = 0.78333 。
     */
    classes = {{1,2},{3,5},{2,2}};
    extraStudents = 2;
    res = 0.78333;
    assert(res == Solution().maxAverageRatio(classes, extraStudents));
    
    /**
     输入：classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
     输出：0.53485
     */
    classes = {{2,4},{3,9},{4,5},{2,10}};
    extraStudents = 4;
    res = 0.53485;
    assert(res == Solution().maxAverageRatio(classes, extraStudents));
    
    cout << "OK~" << endl;
    
    return 0;
}
