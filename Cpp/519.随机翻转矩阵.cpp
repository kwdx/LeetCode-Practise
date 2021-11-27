/*
 * @lc app=leetcode.cn id=519 lang=cpp
 *
 * [519] 随机翻转矩阵
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
private:
    int m, n, total;
    unordered_map<int, int> map;
    
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
        srand((unsigned int)time(nullptr));
    }
    
    vector<int> flip() {
        int x = rand() % total;
        vector<int> ans;
        --total;
        if (map.count(x)) {
            ans = {map[x] / n, map[x] % n};
        } else {
            ans = {x / n, x % n};
        }
        // 将位置 x 对应的映射设置为位置 total 对应的映射
        if (map.count(total)) {
            map[x] = map[total];
        } else {
            map[x] = total;
        }
        return ans;
    }
    
    void reset() {
        this->total = this->m * this->n;
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["Solution", "flip", "flip", "flip", "reset", "flip"]
     [[3, 1], [], [], [], [], []]
     输出
     [null, [1, 0], [2, 0], [0, 0], null, [2, 0]]

     解释
     Solution solution = new Solution(3, 1);
     solution.flip();  // 返回 [1, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
     solution.flip();  // 返回 [2, 0]，因为 [1,0] 已经返回过了，此时返回 [2,0] 和 [0,0] 的概率应当相同
     solution.flip();  // 返回 [0, 0]，根据前面已经返回过的下标，此时只能返回 [0,0]
     solution.reset(); // 所有值都重置为 0 ，并可以再次选择下标返回
     solution.flip();  // 返回 [2, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
     */
    vector<int> ans;
    Solution *solution = new Solution(3, 1);
    ans = solution->flip();
    cout << "{" << ans[0] << "," << ans[1] << "}" << endl;
    ans = solution->flip();
    cout << "{" << ans[0] << "," << ans[1] << "}" << endl;
    ans = solution->flip();
    cout << "{" << ans[0] << "," << ans[1] << "}" << endl;
    solution->reset();
    ans = solution->flip();
    cout << "{" << ans[0] << "," << ans[1] << "}" << endl;
    
    cout << "OK~" << endl;

    return 0;
}
