/*
 * @lc app=leetcode.cn id=952 lang=swift
 *
 * [952] 按公因数计算最大组件大小
 */

// @lc code=start
class Solution {
    private var p: [Int] = []
    private var sz: [Int] = []
    private var ans = 0

    func find(_ x: Int) -> Int {
        if p[x] != x {
            p[x] = find(p[x])
        }
        return p[x]
    }
    
    func union(_ a: Int, _ b: Int) {
        let a1 = find(a)
        let b1 = find(b)
        if a1 == b1 {
            return
        }
        sz[a1] += sz[b1]
        p[b1] = p[a1]
        ans = max(ans, sz[a1])
    }
    
    func largestComponentSize(_ nums: [Int]) -> Int {
        let n = nums.count
        p = [Int](repeating: 0, count: n)
        sz = [Int](repeating: 0, count: n)
        
        var map: [Int: [Int]] = [:]
        
        for i in 0..<n {
            var cur = nums[i]
            var j = 2
            while j * j <= cur {
                if cur % j == 0 {
                    var arr = map[j] ?? []
                    arr.append(i)
                    map[j] = arr
                }
                while cur % j == 0 {
                    cur /= j
                }
                j += 1
            }
            if cur > 1 {
                var arr = map[cur] ?? []
                arr.append(i)
                map[cur] = arr
            }
        }
        
        for i in 0..<n {
            p[i] = i
            sz[i] = 1
        }
        ans = 1
        for (_, arr) in map {
            for i in 1..<arr.count {
                union(arr[0], arr[i])
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var nums: [Int]
    var res: Int
    
    /**
     输入：nums = [4,6,15,35]
     输出：4
     */
    nums = [4,6,15,35]
    res = 4
    assert(res == Solution().largestComponentSize(nums))
    
    /**
     输入：nums = [20,50,9,63]
     输出：2
     */
    nums = [20,50,9,63]
    res = 2
    assert(res == Solution().largestComponentSize(nums))
    
    /**
     输入：nums = [2,3,6,7,4,12,21,39]
     输出：8
     */
    nums = [2,3,6,7,4,12,21,39]
    res = 8
    assert(res == Solution().largestComponentSize(nums))
}
