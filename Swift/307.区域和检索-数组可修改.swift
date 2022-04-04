/*
 * @lc app=leetcode.cn id=307 lang=swift
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start

class NumArray {
    
    private var tr: [Int]
    private var nums: [Int]
    var n: Int { nums.count }
    
    init(_ nums: [Int]) {
        self.nums = nums
        tr = [Int](repeating: 0, count: nums.count + 1)
        for i in 0..<n {
            add(i + 1, nums[i])
        }
    }
    
    func update(_ index: Int, _ val: Int) {
        add(index + 1, val - nums[index])
        nums[index] = val
    }
    
    func sumRange(_ left: Int, _ right: Int) -> Int {
        return query(right + 1) - query(left)
    }
    
    private func lowbit(_ x: Int) -> Int {
        x & -x
    }
    
    private func add(_ x: Int, _ u: Int) {
        var i = x
        while i <= n {
            tr[i] += u
            i += lowbit(i)
        }
    }
    
    private func query(_ x: Int) -> Int {
        var ans = 0
        var i = x
        while i > 0{
            ans += tr[i]
            i -= lowbit(i)
        }
        return ans
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray(nums)
 * obj.update(index, val)
 * let ret_2: Int = obj.sumRange(left, right)
 */
// @lc code=end

func main() {
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
    let numArray = NumArray([1,3,5])
    assert(9 == numArray.sumRange(0, 2))
    numArray.update(1, 2)
    assert(8 == numArray.sumRange(0, 2))
}
