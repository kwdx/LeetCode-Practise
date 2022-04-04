/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class NumArray {
private:
    vector<int> tr;
    vector<int> nums;
    int n;
    
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int u) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += u;
    }
    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) ans += tr[i];
        return ans;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = (int)nums.size();
        tr.resize(n + 10);
        for (int i = 0; i < n; i++) add(i + 1, nums[i]);
    }
    
    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["NumArray", "sumRange", "update", "sumRange"]
     [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
     输出：
     [null, 9, null, 8]

     解释：
     NumArray numArray = new NumArray([1, 3, 5]);
     numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
     numArray.update(1, 2);   // nums = [1,2,5]
     numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
     */
    vector<int> nums = {1,3,5};
    NumArray numArray(nums);
    assert(9 == numArray.sumRange(0, 2));
    numArray.update(1, 2);
    assert(8 == numArray.sumRange(0, 2));
    
    cout << "OK~" << endl;
    
    return 0;
}
