/*
 * @lc app=leetcode.cn id=851 lang=swift
 *
 * [851] 喧闹和富有
 */

// @lc code=start
class Solution {
    func loudAndRich(_ richer: [[Int]], _ quiet: [Int]) -> [Int] {
        var ans: [Int] = .init(repeating: -1, count: quiet.count)
                
        var poorers: [Int: [Int]] = [:]
        var ins: [Int] = .init(repeating: 0, count: quiet.count)
        for rich in richer {
            var poorer = poorers[rich[0]] ?? []
            poorer.append(rich[1])
            poorers[rich[0]] = poorer
            ins[rich[1]] += 1
        }
        
        var queue: [Int] = []
        for i in 0..<quiet.count {
            if ins[i] == 0 {
                queue.append(i)
                ans[i] = i
            }
        }
        while !queue.isEmpty {
            let i = queue.removeFirst()
            poorers[i]?.forEach { p in
                if ans[p] == -1 {
                    ans[p] = quiet[p] < quiet[ans[i]] ? p : ans[i]
                } else {
                    ans[p] = quiet[ans[p]] < quiet[ans[i]] ? ans[p] : ans[i]
                }
                ins[p] -= 1
                if (ins[p] == 0) {
                    queue.append(p);
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var richer: [[Int]]
    var quiet: [Int]
    var res: [Int]
    
    /**
     输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
     输出：[5,5,2,5,4,5,6,7]
     解释：
     answer[0] = 5，
     person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0 有更多的钱。
     唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
     但是目前还不清楚他是否比 person 0 更有钱。
     answer[7] = 7，
     在所有拥有的钱肯定不少于 person 7 的人中（这可能包括 person 3，4，5，6 以及 7），
     最安静（有较低安静值 quiet[x]）的人是 person 7。
     其他的答案也可以用类似的推理来解释。
     */
    richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
    quiet = [3,2,5,4,6,1,7,0]
    res = [5,5,2,5,4,5,6,7]
    assert(res == Solution().loudAndRich(richer, quiet))
    
    /**
     输入：richer = [], quiet = [0]
     输出：[0]
     */
    richer = []
    quiet = [0]
    res = [0]
    assert(res == Solution().loudAndRich(richer, quiet))
}
