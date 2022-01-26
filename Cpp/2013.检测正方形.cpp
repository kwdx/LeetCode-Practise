/*
 * @lc app=leetcode.cn id=2013 lang=cpp
 *
 * [2013] 检测正方形
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> x2y;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        x2y[x][y] += 1;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        unordered_map<int, int> yCnts = x2y[x];
        for (auto yCnt : yCnts) {
            int ny = yCnt.first;
            int cnt = yCnt.second;
            if (ny == y) continue;
            int side = y - ny;  // 边长
            vector<int> xs = {x + side, x - side};  // x的可能值
            for (int nx : xs) {
                ans += cnt * x2y[nx][y] * x2y[nx][ny];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
     [[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
     输出：
     [null, null, null, null, 1, 0, null, 2]

     解释：
     DetectSquares detectSquares = new DetectSquares();
     detectSquares.add([3, 10]);
     detectSquares.add([11, 2]);
     detectSquares.add([3, 2]);
     detectSquares.count([11, 10]); // 返回 1 。你可以选择：
                                    //   - 第一个，第二个，和第三个点
     detectSquares.count([14, 8]);  // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
     detectSquares.add([11, 2]);    // 允许添加重复的点。
     detectSquares.count([11, 10]); // 返回 2 。你可以选择：
                                    //   - 第一个，第二个，和第三个点
                                    //   - 第一个，第三个，和第四个点
     */
    DetectSquares detectSquares;
    detectSquares.add({3, 10});
    detectSquares.add({11, 2});
    detectSquares.add({3, 2});
    assert(1 == detectSquares.count({11, 10}));
    assert(0 == detectSquares.count({14, 8}));
    detectSquares.add({11, 2});
    assert(2 == detectSquares.count({11, 10}));

    cout << "OK~" << endl;

    return 0;
}
