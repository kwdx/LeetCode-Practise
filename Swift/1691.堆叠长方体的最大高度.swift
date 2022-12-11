/*
 * @lc app=leetcode.cn id=1691 lang=swift
 *
 * [1691] 堆叠长方体的最大高度
 */

// @lc code=start
class Solution {
    func maxHeight(_ cuboids: [[Int]]) -> Int {
        let cuboids: [[Int]] = cuboids
            .map { $0.sorted() }
            .sorted {
                $0[0] + $0[1] + $0[2] < $1[0] + $1[1] + $1[2]
            }
        var ans = 0
        var dp = [Int](repeating: 0, count: cuboids.count)
        for i in 0..<cuboids.count {
            dp[i] = cuboids[i][2]
            var j = 0
            while j < i {
                if cuboids[i][0] >= cuboids[j][0] &&
                    cuboids[i][1] >= cuboids[j][1] &&
                    cuboids[i][2] >= cuboids[j][2] {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2])
                }
                j += 1
            }
            ans = max(ans, dp[i])
        }
        return ans
    }
}
// @lc code=end

func main() {
    var cuboids: [[Int]]
    var res: Int
    
    /**
     输入：cuboids = [[50,45,20],[95,37,53],[45,23,12]]
     输出：190
     解释：
     第 1 个长方体放在底部，53x37 的一面朝下，高度为 95 。
     第 0 个长方体放在中间，45x20 的一面朝下，高度为 50 。
     第 2 个长方体放在上面，23x12 的一面朝下，高度为 45 。
     总高度是 95 + 50 + 45 = 190 。
     */
    cuboids = [[50,45,20],[95,37,53],[45,23,12]]
    res = 190
    assert(res == Solution().maxHeight(cuboids))
    
    /**
     输入：cuboids = [[38,25,45],[76,35,3]]
     输出：76
     解释：
     无法将任何长方体放在另一个上面。
     选择第 1 个长方体然后旋转它，使 35x3 的一面朝下，其高度为 76 。
     */
    cuboids = [[38,25,45],[76,35,3]]
    res = 76
    assert(res == Solution().maxHeight(cuboids))
    
    /**
     输入：cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
     输出：102
     解释：
     重新排列长方体后，可以看到所有长方体的尺寸都相同。
     你可以把 11x7 的一面朝下，这样它们的高度就是 17 。
     堆叠长方体的最大高度为 6 * 17 = 102 。
     */
    cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
    res = 102
    assert(res == Solution().maxHeight(cuboids))
}
