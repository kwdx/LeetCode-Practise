/*
 * @lc app=leetcode.cn id=661 lang=swift
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution {
    func imageSmoother(_ img: [[Int]]) -> [[Int]] {
        let m = img.count, n = img[0].count
        var sum: [[Int]] = .init(repeating: .init(repeating: 0, count: n + 3), count: m + 3)
        for i in 1...m {
            for j in 1...n {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + img[i - 1][j - 1]
            }
        }
        var ans: [[Int]] = .init(repeating: .init(repeating: 0, count: n), count: m)
        for i in 0..<m {
            for j in 0..<n {
                let a = max(0, i - 1), b = max(0, j - 1)
                let c = min(m - 1, i + 1), d = min(n - 1, j + 1)
                let cnt = (c - a + 1) * (d - b + 1)
                let total = sum[c + 1][d + 1] - sum[a][d + 1] - sum[c + 1][b] + sum[a][b]
                ans[i][j] = total / cnt
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var img: [[Int]]
    var res: [[Int]]
    
    /**
     输入:img = [[1,1,1],[1,0,1],[1,1,1]]
     输出:[[0, 0, 0],[0, 0, 0], [0, 0, 0]]
     解释:
     对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
     对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
     对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
     */
    img = [[1,1,1],[1,0,1],[1,1,1]]
    res = [[0, 0, 0],[0, 0, 0], [0, 0, 0]]
    assert(res == Solution().imageSmoother(img))
    
    /**
     输入: img = [[100,200,100],[200,50,200],[100,200,100]]
     输出: [[137,141,137],[141,138,141],[137,141,137]]
     解释:
     对于点 (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
     对于点 (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
     对于点 (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
     */
    img = [[100,200,100],[200,50,200],[100,200,100]]
    res = [[137,141,137],[141,138,141],[137,141,137]]
    assert(res == Solution().imageSmoother(img))
}
