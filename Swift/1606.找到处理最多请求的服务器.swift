/*
 * @lc app=leetcode.cn id=1606 lang=swift
 *
 * [1606] 找到处理最多请求的服务器
 */

// @lc code=start
class Solution {
    func busiestServers(_ k: Int, _ arrival: [Int], _ load: [Int]) -> [Int] {
        // 当前空余的服务器
        var available = PriorityQueue<Int>(>)
        for i in 0..<k {
            available.push(i)
        }
        // 当前忙碌的服务器（结束时间，服务器id）
        var busy = PriorityQueue<(Int, Int)> {
            $0.0 == $1.0 ? ($0.1 < $1.1) : ($0.0 > $1.0)
        }
        // 每台服务器处理的请求数
        var requests = [Int](repeating: 0, count: k)
        for i in 0..<arrival.count {
            while let (endTime, id) = busy.top, endTime <= arrival[i] {
                busy.pop()
                // 保证得到的是一个不小于 i 的且与 id 同余的数
                available.push(i + ((id - i) % k + k) % k)
            }
            if var id = available.pop() {
                id %= k
                requests[id] += 1
                busy.push((arrival[i] + load[i], id))
            }
        }
        let maxReq = requests.max()!
        return (0..<k).filter { requests[$0] == maxReq }
    }
}
// @lc code=end

func main() {
    var k: Int
    var arrival: [Int]
    var load: [Int]
    var res: [Int]
    
    /**
     输入：k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3]
     输出：[1]
     解释：
     所有服务器一开始都是空闲的。
     前 3 个请求分别由前 3 台服务器依次处理。
     请求 3 进来的时候，服务器 0 被占据，所以它呗安排到下一台空闲的服务器，也就是服务器 1 。
     请求 4 进来的时候，由于所有服务器都被占据，该请求被舍弃。
     服务器 0 和 2 分别都处理了一个请求，服务器 1 处理了两个请求。所以服务器 1 是最忙的服务器。
     */
    k = 3
    arrival = [1,2,3,4,5]
    load = [5,2,3,3,3]
    res = [1]
    assert(res == Solution().busiestServers(k, arrival, load))
    
    /**
     输入：k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
     输出：[0]
     解释：
     前 3 个请求分别被前 3 个服务器处理。
     请求 3 进来，由于服务器 0 空闲，它被服务器 0 处理。
     服务器 0 处理了两个请求，服务器 1 和 2 分别处理了一个请求。所以服务器 0 是最忙的服务器。
     */
    k = 3
    arrival = [1,2,3,4]
    load = [1,2,1,2]
    res = [0]
    assert(res == Solution().busiestServers(k, arrival, load))
    
    /**
     输入：k = 3, arrival = [1,2,3], load = [10,12,11]
     输出：[0,1,2]
     解释：每个服务器分别处理了一个请求，所以它们都是最忙的服务器。
     */
    k = 3
    arrival = [1,2,3]
    load = [10,12,11]
    res = [0,1,2]
    assert(res == Solution().busiestServers(k, arrival, load))
    
    /**
     输入：k = 3, arrival = [1,2,3,4,8,9,10], load = [5,2,10,3,1,2,2]
     输出：[1]
     */
    k = 3
    arrival = [1,2,3,4,8,9,10]
    load = [5,2,10,3,1,2,2]
    res = [1]
    assert(res == Solution().busiestServers(k, arrival, load))
    
    /**
     输入：k = 1, arrival = [1], load = [1]
     输出：[0]
     */
    k = 1
    arrival = [1]
    load = [1]
    res = [0]
    assert(res == Solution().busiestServers(k, arrival, load))
}
