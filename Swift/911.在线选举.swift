/*
 * @lc app=leetcode.cn id=911 lang=swift
 *
 * [911] 在线选举
 */

// @lc code=start

class TopVotedCandidate {
    
    private var list: [(Int, Int)] = []

    init(_ persons: [Int], _ times: [Int]) {
        var votes: [Int: Int] = [:]
        var cur: Int = persons[0]
        for i in 0..<times.count {
            let vote = (votes[persons[i]] ?? 0) + 1
            votes[persons[i]] = vote
            if vote >= votes[cur]! {
                cur = persons[i]
            }
            list.append((times[i], cur))
        }
    }
    
    func q(_ t: Int) -> Int {
        var l = 0, r = list.count - 1
        while l < r {
            let mid = (l + r + 1) >> 1
            if list[mid].0 <= t {
                l = mid
            } else {
                r = mid - 1
            }
        }
        return list[r].0 <= t ? list[r].1 : 0
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * let obj = TopVotedCandidate(persons, times)
 * let ret_1: Int = obj.q(t)
 */
// @lc code=end

func main() {
    /**
     输入：
     ["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
     [[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
     输出：
     [null, 0, 1, 1, 0, 0, 1]

     解释：
     TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
     topVotedCandidate.q(3); // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
     topVotedCandidate.q(12); // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
     topVotedCandidate.q(25); // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
     topVotedCandidate.q(15); // 返回 0
     topVotedCandidate.q(24); // 返回 0
     topVotedCandidate.q(8); // 返回 1
     */
    let topVotedCandidate = TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30])
    // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
    assert(topVotedCandidate.q(3) == 0)
    // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
    assert(topVotedCandidate.q(12) == 1)
    // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
    assert(topVotedCandidate.q(25) == 1)
    // 返回 0
    assert(topVotedCandidate.q(15) == 0)
    // 返回 0
    assert(topVotedCandidate.q(24) == 0)
    // 返回 1
    assert(topVotedCandidate.q(8) == 1)
}
