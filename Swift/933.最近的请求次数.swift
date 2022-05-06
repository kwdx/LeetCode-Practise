/*
 * @lc app=leetcode.cn id=933 lang=swift
 *
 * [933] 最近的请求次数
 */

// @lc code=start

class RecentCounter {

    var dq: [Int] = []
    
    init() {

    }
    
    func ping(_ t: Int) -> Int {
        dq.append(t)
        while dq[0] < t - 3000 {
            dq.removeFirst()
        }
        return dq.count
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * let obj = RecentCounter()
 * let ret_1: Int = obj.ping(t)
 */
// @lc code=end

func main() {
    /**
     输入：
     ["RecentCounter", "ping", "ping", "ping", "ping"]
     [[], [1], [100], [3001], [3002]]
     输出：
     [null, 1, 2, 3, 3]

     解释：
     RecentCounter recentCounter = new RecentCounter();
     recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
     recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
     recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
     recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3
     */
    let recentCounter = RecentCounter()
    assert(1 == recentCounter.ping(1))
    assert(2 == recentCounter.ping(100))
    assert(3 == recentCounter.ping(3001))
    assert(3 == recentCounter.ping(3002))
}
