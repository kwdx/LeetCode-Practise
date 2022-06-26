/*
 * @lc app=leetcode.cn id=710 lang=swift
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start

class Solution {
    private var m: Int
    private var mapping: [Int: Int] = [:]

    init(_ n: Int, _ blacklist: [Int]) {
        m = n - blacklist.count
        for blacklist in blacklist {
            mapping[blacklist] = -1
        }
        var last = n - 1
        for blacklist in blacklist {
            if blacklist >= m {
                continue
            }
            while mapping[last] != nil {
                last -= 1
            }
            mapping[blacklist] = last
            last -= 1
        }
    }
    
    func pick() -> Int {
        let idx = Int.random(in: 0..<m)
        if let val = mapping[idx] {
            return val
        }
        return idx
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(n, blacklist)
 * let ret_1: Int = obj.pick()
 */
// @lc code=end

func main() {
    var blacklist: [Int]
    var obj: Solution
    var pick: Int

    /**
     输入：
     ["Solution","pick","pick","pick"]
     [[1,[]],[],[],[]]
     输出：[null,0,0,0]
     */
    blacklist = []
    obj = Solution(1, blacklist)
    assert(!blacklist.contains(obj.pick()))
    assert(!blacklist.contains(obj.pick()))
    assert(!blacklist.contains(obj.pick()))
    
    /**
     输入：
     ["Solution","pick","pick","pick"]
     [[2,[]],[],[],[]]
     输出：[null,1,1,1]
     */
    blacklist = []
    obj = Solution(2, blacklist)
    assert(!blacklist.contains(obj.pick()))
    assert(!blacklist.contains(obj.pick()))
    assert(!blacklist.contains(obj.pick()))

    /**
     输入：
     ["Solution","pick","pick","pick"]
     [[3,[1]],[],[],[]]
     输出：[null,0,0,2]
     */
    blacklist = [1]
    obj = Solution(3, blacklist)
    assert(!blacklist.contains(obj.pick()))
    assert(!blacklist.contains(obj.pick()))
    assert(!blacklist.contains(obj.pick()))

    /**
     输入：
     ["Solution","pick","pick","pick"]
     [[4,[2]],[],[],[]]
     输出：[null,1,3,1]
     */
    blacklist = [2]
    obj = Solution(4, blacklist)
    assert(!blacklist.contains(obj.pick()))
    assert(!blacklist.contains(obj.pick()))
    assert(!blacklist.contains(obj.pick()))
}
