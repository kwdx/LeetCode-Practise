/*
 * @lc app=leetcode.cn id=1184 lang=swift
 *
 * [1184] 公交站间的距离
 */

// @lc code=start
class Solution {
    func distanceBetweenBusStops(_ distance: [Int], _ start: Int, _ destination: Int) -> Int {
        let sum = distance.reduce(0, +)
        var clockwise: Int
        if start < destination {
            clockwise = distance[start..<destination].reduce(0, +)
        } else {
            clockwise = distance[destination..<start].reduce(0, +)
        }
        return min(sum - clockwise, clockwise)
    }
}
// @lc code=end

func main() {
    var distance: [Int]
    var start: Int
    var destination: Int
    var res: Int
    
    /**
     输入：distance = [1,2,3,4], start = 0, destination = 1
     输出：1
     解释：公交站 0 和 1 之间的距离是 1 或 9，最小值是 1。
     */
    distance = [1,2,3,4]
    start = 0
    destination = 1
    res = 1
    assert(res == Solution().distanceBetweenBusStops(distance, start, destination))

    /**
     输入：distance = [1,2,3,4], start = 0, destination = 2
     输出：3
     解释：公交站 0 和 2 之间的距离是 3 或 7，最小值是 3。
     */
    distance = [1,2,3,4]
    start = 0
    destination = 2
    res = 3
    assert(res == Solution().distanceBetweenBusStops(distance, start, destination))
    
    /**
     输入：distance = [1,2,3,4], start = 0, destination = 3
     输出：4
     解释：公交站 0 和 3 之间的距离是 6 或 4，最小值是 4。
     */
    distance = [1,2,3,4]
    start = 0
    destination = 3
    res = 4
    assert(res == Solution().distanceBetweenBusStops(distance, start, destination))
}
