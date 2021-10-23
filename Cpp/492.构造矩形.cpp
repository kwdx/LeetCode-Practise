/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int w = sqrt(area); w > 0; --w) {
            int l = area / w;
            if (w * l == area) {
                return {l, w};
            }
        }
        return {};
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int area;
    vector<int> res;
    
    /**
     输入: 4
     输出: [2, 2]
     解释: 目标面积是 4， 所有可能的构造方案有 [1,4], [2,2], [4,1]。
     但是根据要求2，[1,4] 不符合要求; 根据要求3，[2,2] 比 [4,1] 更能符合要求. 所以输出长度 L 为 2， 宽度 W 为 2。
     */
    area = 4;
    res = {2,2};
    assert(res == Solution().constructRectangle(area));
    
    cout << "OK~" << endl;
    
    return 0;
}
