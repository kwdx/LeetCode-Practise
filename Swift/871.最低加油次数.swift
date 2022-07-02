/*
 * @lc app=leetcode.cn id=871 lang=swift
 *
 * [871] 最低加油次数
 */

// @lc code=start
class Solution {
    func minRefuelStops(_ target: Int, _ startFuel: Int, _ stations: [[Int]]) -> Int {
        var ans = 0
        var q = PriorityQueue<Int>()
        var idx = 0
        var remain = startFuel
        var loc = 0
        while loc < target {
            if remain == 0 {
                if !q.isEmpty {
                    ans += 1
                    remain += q.pop()!
                } else {
                    return -1
                }
            }
            loc += remain
            remain = 0
            while idx < stations.count && stations[idx][0] <= loc {
                q.push(stations[idx][1])
                idx += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var target: Int
    var startFuel: Int
    var stations: [[Int]]
    var res: Int
    
    /**
     输入：target = 1, startFuel = 1, stations = []
     输出：0
     解释：我们可以在不加油的情况下到达目的地。
     */
    target = 1
    startFuel = 1
    stations = []
    res = 0
    assert(res == Solution().minRefuelStops(target, startFuel, stations))
    
    /**
     输入：target = 100, startFuel = 1, stations = [[10,100]]
     输出：-1
     解释：我们无法抵达目的地，甚至无法到达第一个加油站。
     */
    target = 100
    startFuel = 1
    stations = [[10,100]]
    res = -1
    assert(res == Solution().minRefuelStops(target, startFuel, stations))
    
    /**
     输入：target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
     输出：2
     解释：
     我们出发时有 10 升燃料。
     我们开车来到距起点 10 英里处的加油站，消耗 10 升燃料。将汽油从 0 升加到 60 升。
     然后，我们从 10 英里处的加油站开到 60 英里处的加油站（消耗 50 升燃料），
     并将汽油从 10 升加到 50 升。然后我们开车抵达目的地。
     我们沿途在1两个加油站停靠，所以返回 2 。
     */
    target = 100
    startFuel = 10
    stations = [[10,60],[20,30],[30,30],[60,40]]
    res = 2
    assert(res == Solution().minRefuelStops(target, startFuel, stations))
}
