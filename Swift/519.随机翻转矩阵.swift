/*
 * @lc app=leetcode.cn id=519 lang=swift
 *
 * [519] 随机翻转矩阵
 */

import Darwin

// @lc code=start

class Solution {
    
    private let m: Int
    private let n: Int
    private var total: Int
    private var map: [Int: Int] = [:]
    
    init(_ m: Int, _ n: Int) {
        self.m = m
        self.n = n
        self.total = m * n
    }
    
    func flip() -> [Int] {
        let x = Int.random(in: 0..<total)
        var ans: [Int] = []
        total -= 1
        if let v = map[x] {
            ans = [v / n, v % n]
        } else {
            ans = [x / n, x % n]
        }
        // 将位置 x 对应的映射设置为位置 total 对应的映射
        if let v = map[total] {
            map[x] = v
        } else {
            map[x] = total
        }
        return ans
    }
    
    func reset() {
        total = m * n
        map.removeAll()
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(m, n)
 * let ret_1: [Int] = obj.flip()
 * obj.reset()
 */
// @lc code=end

func main() {
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
    var sets: Set<[Int]> = .init(arrayLiteral: [0,0],[1,0],[2,0])
    let solution = Solution(3, 1)
    assert(sets.remove(solution.flip()) != nil)
    assert(sets.remove(solution.flip()) != nil)
    assert(sets.remove(solution.flip()) != nil)
    solution.reset()
    sets = .init(arrayLiteral: [0,0],[1,0],[2,0])
    assert(sets.remove(solution.flip()) != nil)
}
