/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;

public:
    Solution(double radius, double x_center, double y_center): dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}
    
    vector<double> randPoint() {
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r) {
                return {xc + x, yc + y};
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入:
     ["Solution","randPoint","randPoint","randPoint"]
     [[1.0, 0.0, 0.0], [], [], []]
     输出: [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
     解释:
     Solution solution = new Solution(1.0, 0.0, 0.0);
     solution.randPoint ();//返回[-0.02493，-0.38077]
     solution.randPoint ();//返回[0.82314,0.38945]
     solution.randPoint ();//返回[0.36572,0.17248]
     */
    Solution solution(1.0, 0.0, 0.0);
    vector<double> point;
    point = solution.randPoint();
    cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    point = solution.randPoint();
    cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    point = solution.randPoint();
    cout << "[" << point[0] << ", " << point[1] << "]" << endl;

    cout << "OK~" << endl;
    
    return 0;
}

