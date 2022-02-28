/*
 * @lc app=leetcode.cn id=1601 lang=swift
 *
 * [1601] 最多可达成的换楼请求数目
 */

// @lc code=start
class Solution {
    func maximumRequests(_ n: Int, _ requests: [[Int]]) -> Int {
        var ans = 0
        let m = requests.count
        let check: (Int) -> Bool = { s in
            var cnt: [Int] = .init(repeating: 0, count: 20)
            var sum = 0
            for i in 0..<16 {
                if (s >> i) & 1 != 1 {
                    continue
                }
                let request = requests[i]
                cnt[request[0]] += 1
                if cnt[request[0]] == 1 {
                    sum += 1
                }
                cnt[request[1]] -= 1
                if cnt[request[1]] == 0 {
                    sum -= 1
                }
            }
            return sum == 0
        }
        for i in 0..<(1<<m) {
            if i.nonzeroBitCount <= ans {
                continue
            }
            if check(i) {
                ans = max(ans, i.nonzeroBitCount)
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var n: Int
    var requests: [[Int]]
    var res: Int
    
    /**
     输入：n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
     输出：5
     解释：请求列表如下：
     从楼 0 离开的员工为 x 和 y ，且他们都想要搬到楼 1 。
     从楼 1 离开的员工为 a 和 b ，且他们分别想要搬到楼 2 和 0 。
     从楼 2 离开的员工为 z ，且他想要搬到楼 0 。
     从楼 3 离开的员工为 c ，且他想要搬到楼 4 。
     没有员工从楼 4 离开。
     我们可以让 x 和 b 交换他们的楼，以满足他们的请求。
     我们可以让 y，a 和 z 三人在三栋楼间交换位置，满足他们的要求。
     所以最多可以满足 5 个请求。
     */
    n = 5
    requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
    res = 5
    assert(res == Solution().maximumRequests(n, requests))

    /**
     输入：n = 3, requests = [[0,0],[1,2],[2,1]]
     输出：3
     解释：请求列表如下：
     从楼 0 离开的员工为 x ，且他想要回到原来的楼 0 。
     从楼 1 离开的员工为 y ，且他想要搬到楼 2 。
     从楼 2 离开的员工为 z ，且他想要搬到楼 1 。
     我们可以满足所有的请求。
     */
    n = 3
    requests = [[0,0],[1,2],[2,1]]
    res = 3
    assert(res == Solution().maximumRequests(n, requests))
    
    /**
     输入：n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
     输出：4
     */
    n = 4
    requests = [[0,3],[3,1],[1,2],[2,0]]
    res = 4
    assert(res == Solution().maximumRequests(n, requests))
}
