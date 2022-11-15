/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int ans = 0;
        for (auto& boxType : boxTypes) {
            int numberOfBoxes = boxType[0];
            int numberOfUnitsPerBox = boxType[1];
            if (numberOfBoxes < truckSize) {
                ans += numberOfBoxes * numberOfUnitsPerBox;
                truckSize -= numberOfBoxes;
            } else {
                ans += truckSize * numberOfUnitsPerBox;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> boxTypes;
    int truckSize;
    int res;
    
    /**
     输入：boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
     输出：8
     解释：箱子的情况如下：
     - 1 个第一类的箱子，里面含 3 个单元。
     - 2 个第二类的箱子，每个里面含 2 个单元。
     - 3 个第三类的箱子，每个里面含 1 个单元。
     可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
     单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8
     */
    boxTypes = {{1,3},{2,2},{3,1}};
    truckSize = 4;
    res = 8;
    assert(res == Solution().maximumUnits(boxTypes, truckSize));
    
    /**
     输入：boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
     输出：91
     */
    boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    truckSize = 10;
    res = 91;
    assert(res == Solution().maximumUnits(boxTypes, truckSize));

    cout << "OK~" << endl;
    
    return 0;
}
