/*
 * @lc app=leetcode.cn id=1345 lang=swift
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
class Solution {
    private var arr: [Int] = []
    private let INF = 0x3f3f3f3f
    private var map: [Int: [Int]] = [:]
    private var n: Int = 0
    func minJumps(_ arr: [Int]) -> Int {
        n = arr.count
        if n == 1 {
            return 0
        }
        self.arr = arr
        for i in (0..<n).reversed() {
            var list = map[arr[i]] ?? []
            list.append(i)
            map[arr[i]] = list
        }
        var dist1 = [Int](repeating: INF, count: n)
        var dist2 = [Int](repeating: INF, count: n)
        dist1[0] = 0
        dist2[n - 1] = 0
        var d1: [Int] = [0]
        var d2: [Int] = [n - 1]
        
        while !d1.isEmpty && !d2.isEmpty {
            var t = -1
            if d1.count < d2.count {
                t = update(&d1, &d2, &dist1, &dist2)
            } else {
                t = update(&d2, &d1, &dist2, &dist1)
            }
            if t != -1 {
                return t
            }
        }
        return -1
    }
    
    func update(_ d1: inout [Int], _ d2: inout [Int], _ dist1: inout [Int], _ dist2: inout [Int]) -> Int {
        let t = d1.removeFirst()
        let step = dist1[t]
        if t + 1 < n {
            if dist2[t + 1] != INF {
                return step + 1 + dist2[t + 1]
            }
            if dist1[t + 1] == INF  {
                d1.append(t + 1)
                dist1[t + 1] = step + 1
            }
        }
        if t - 1 >= 0 {
            if dist2[t - 1] != INF {
                return step + 1 + dist2[t - 1]
            }
            if dist1[t - 1] == INF {
                d1.append(t - 1)
                dist1[t - 1] = step + 1
            }
        }
        let list = map[arr[t]] ?? []
        for ne in list {
            if dist2[ne] != INF {
                return step + 1 + dist2[ne]
            }
            if dist1[ne] == INF {
                d1.append(ne)
                dist1[ne] = step + 1
            }
        }
        return -1
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: Int
    
    /**
     输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
     输出：3
     解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
     */
    arr = [100,-23,-23,404,100,23,23,23,3,404]
    res = 3
    assert(res == Solution().minJumps(arr))
    
    /**
     输入：arr = [7]
     输出：0
     解释：一开始就在最后一个元素处，所以你不需要跳跃。
     */
    arr = [7]
    res = 0
    assert(res == Solution().minJumps(arr))
    
    /**
     输入：arr = [7,6,9,6,9,6,9,7]
     输出：1
     解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
     */
    arr = [7,6,9,6,9,6,9,7]
    res = 1
    assert(res == Solution().minJumps(arr))
    
    /**
     输入：arr = [6,1,9]
     输出：2
     */
    arr = [6,1,9]
    res = 2
    assert(res == Solution().minJumps(arr))
    
    /**
     输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
     输出：3
     */
    arr = [11,22,7,7,7,7,7,7,7,22,13]
    res = 3
    assert(res == Solution().minJumps(arr))
}
