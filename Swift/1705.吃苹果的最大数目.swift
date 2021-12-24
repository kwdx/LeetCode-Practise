/*
 * @lc app=leetcode.cn id=1705 lang=swift
 *
 * [1705] 吃苹果的最大数目
 */

// @lc code=start
class Solution {
    func eatenApples(_ apples: [Int], _ days: [Int]) -> Int {
        typealias P = (Int, Int)
        var q = PriorityQueue<P>( { $0.0 > $1.0 } )
        var time = 0, ans = 0
        while time < apples.count || !q.isEmpty {
            if time < apples.count && apples[time] > 0 {
                // 添加新的苹果
                q.push((time + days[time] - 1, apples[time]))
            }
            while let apple = q.top, apple.0 < time {
                // 清除已过期的苹果
                q.pop()
            }
            if var apple = q.pop() {
                apple.1 -= 1
                if apple.1 > 0 && apple.0 > time {
                    q.push(apple)
                }
                ans += 1
            }
            time += 1
        }
        return ans
    }
}
// @lc code=end

func main() {
    var apples: [Int]
    var days: [Int]
    var res: Int
    
//    /**
//     输入：apples = [1,2,3,5,2], days = [3,2,1,4,2]
//     输出：7
//     解释：你可以吃掉 7 个苹果：
//     - 第一天，你吃掉第一天长出来的苹果。
//     - 第二天，你吃掉一个第二天长出来的苹果。
//     - 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
//     - 第四天到第七天，你吃的都是第四天长出来的苹果。
//     */
//    apples = [1,2,3,5,2]
//    days = [3,2,1,4,2]
//    res = 7
//    assert(res == Solution().eatenApples(apples, days))
//
//    /**
//     输入：apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
//     输出：5
//     解释：你可以吃掉 5 个苹果：
//     - 第一天到第三天，你吃的都是第一天长出来的苹果。
//     - 第四天和第五天不吃苹果。
//     - 第六天和第七天，你吃的都是第六天长出来的苹果。
//     */
//    apples = [3,0,0,0,0,2]
//    days = [3,0,0,0,0,2]
//    res = 5
//    assert(res == Solution().eatenApples(apples, days))
    
    /**
     输入：apples = [2,1,10], days = [2,10,1]
     输出：4
     */
    apples = [2,1,10]
    days = [2,10,1]
    res = 4
    assert(res == Solution().eatenApples(apples, days))
}
