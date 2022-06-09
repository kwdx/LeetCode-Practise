/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> arr;
    vector<vector<int>>& rects;
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        arr.emplace_back(0);
        for (vector<int>& rect : rects) {
            int cnt = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            arr.emplace_back(arr.back() + cnt);
        }
    }
    
    vector<int> pick() {
        int num = random() % arr.back();
        int rectIdx = (int)(upper_bound(arr.begin(), arr.end(), num) - arr.begin() - 1);
        num -= arr[rectIdx];
        
        int a = rects[rectIdx][0], b = rects[rectIdx][1];
        int x = rects[rectIdx][2];
        int cols = x - a + 1;
        int row = num / cols;
        int col = num - cols * row;
        return {a + col, b + row};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入:
     ["Solution", "pick", "pick", "pick", "pick", "pick"]
     [[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
     输出:
     [null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

     解释：
     Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
     solution.pick(); // 返回 [1, -2]
     solution.pick(); // 返回 [1, -1]
     solution.pick(); // 返回 [-1, -2]
     solution.pick(); // 返回 [-2, -2]
     solution.pick(); // 返回 [0, 0]
     */
    vector<vector<int>> rects = {{-2, -2, 1, 1}, {2, 2, 4, 6}};
    vector<int> res;
    Solution solution(rects);
    res = solution.pick();
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    res = solution.pick();
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    res = solution.pick();
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    res = solution.pick();
    cout << "[" << res[0] << "," << res[1] << "]" << endl;
    res = solution.pick();
    cout << "[" << res[0] << "," << res[1] << "]" << endl;

    cout << "OK~" << endl;
    
    return 0;
}
