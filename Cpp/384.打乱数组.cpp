/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> ans(nums.size());
        copy(nums.begin(), nums.end(), ans.begin());
        for (int i = 0; i < ans.size(); ++i) {
            int j = i + rand() % (ans.size() - i);
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["Solution", "shuffle", "reset", "shuffle"]
     [[[1, 2, 3]], [], [], []]
     输出
     [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

     解释
     Solution solution = new Solution([1, 2, 3]);
     solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
     solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
     solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
     */
    vector<int> nums = {1,2,3};
    Solution* obj = new Solution(nums);
    assert(nums != obj->shuffle());
    assert(nums == obj->reset());
    assert(nums != obj->shuffle());
    
    delete obj;

    cout << "OK~" << endl;

    return 0;
}
