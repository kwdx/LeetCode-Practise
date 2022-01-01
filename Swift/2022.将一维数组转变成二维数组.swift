/*
 * @lc app=leetcode.cn id=2022 lang=swift
 *
 * [2022] 将一维数组转变成二维数组
 */

// @lc code=start
class Solution {
    func construct2DArray(_ original: [Int], _ m: Int, _ n: Int) -> [[Int]] {
        guard original.count == m * n else {
            return []
        }
        var ans: [[Int]] = .init(repeating: .init(repeating: 0, count: n), count: m)
        for row in 0..<m {
            for col in 0..<n {
                ans[row][col] = original[row * n + col]
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var original: [Int]
    var m: Int
    var n: Int
    var res: [[Int]]
    
    /**
     输入：original = [1,2,3,4], m = 2, n = 2
     输出：[[1,2],[3,4]]
     解释：
     构造出的二维数组应该包含 2 行 2 列。
     original 中第一个 n=2 的部分为 [1,2] ，构成二维数组的第一行。
     original 中第二个 n=2 的部分为 [3,4] ，构成二维数组的第二行。
     */
    original = [1,2,3,4]
    m = 2
    n = 2
    res = [[1,2],[3,4]]
    assert(res == Solution().construct2DArray(original, m, n))
    
    /**
     输入：original = [1,2,3], m = 1, n = 3
     输出：[[1,2,3]]
     解释：
     构造出的二维数组应该包含 1 行 3 列。
     将 original 中所有三个元素放入第一行中，构成要求的二维数组。
     */
    original = [1,2,3]
    m = 1
    n = 3
    res = [[1,2,3]]
    assert(res == Solution().construct2DArray(original, m, n))
    
    /**
     输入：original = [1,2], m = 1, n = 1
     输出：[]
     解释：
     original 中有 2 个元素。
     无法将 2 个元素放入到一个 1x1 的二维数组中，所以返回一个空的二维数组。
     */
    original = [1,2]
    m = 1
    n = 1
    res = []
    assert(res == Solution().construct2DArray(original, m, n))
    
    /**
     输入：original = [3], m = 1, n = 2
     输出：[]
     解释：
     original 中只有 1 个元素。
     无法将 1 个元素放满一个 1x2 的二维数组，所以返回一个空的二维数组。
     */
    original = [3]
    m = 1
    n = 2
    res = []
    assert(res == Solution().construct2DArray(original, m, n))
}
