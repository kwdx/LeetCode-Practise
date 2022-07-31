/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return isIsoscelesRightTriangle(p1, p2, p3)
            && isIsoscelesRightTriangle(p1, p2, p4)
            && isIsoscelesRightTriangle(p1, p3, p4)
            && isIsoscelesRightTriangle(p4, p2, p3);
    }
    
    bool isIsoscelesRightTriangle(vector<int>& a, vector<int>& b, vector<int>& c) {
        long l1 = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
        long l2 = (a[0] - c[0]) * (a[0] - c[0]) + (a[1] - c[1]) * (a[1] - c[1]);
        long l3 = (c[0] - b[0]) * (c[0] - b[0]) + (c[1] - b[1]) * (c[1] - b[1]);
        return (l1 > l2 && l2 == l3 && l2 + l3 == l1)
            || (l2 > l1 && l1 == l3 && l1 + l3 == l2)
            || (l3 > l1 && l1 == l2 && l1 + l2 == l3);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> p1;
    vector<int> p2;
    vector<int> p3;
    vector<int> p4;
    bool res;
    
    /**
     输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
     输出: True
     */
    p1 = {0,0};
    p2 = {1,1};
    p3 = {1,0};
    p4 = {0,1};
    res = true;
    assert(res == Solution().validSquare(p1, p2, p3, p4));
    
    /**
     输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
     输出：false
     */
    p1 = {0,0};
    p2 = {1,1};
    p3 = {1,0};
    p4 = {0,12};
    res = false;
    assert(res == Solution().validSquare(p1, p2, p3, p4));
    
    /**
     输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
     输出：true
     */
    p1 = {1,0};
    p2 = {-1,0};
    p3 = {0,1};
    p4 = {0,-1};
    res = true;
    assert(res == Solution().validSquare(p1, p2, p3, p4));
    
    cout << "OK~" << endl;
    
    return 0;
}
