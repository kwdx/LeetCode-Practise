/*
 * @lc app=leetcode.cn id=688 lang=swift
 *
 * [688] “马”在棋盘上的概率
 */

// @lc code=start
class Solution {
    private let dirs: [(Int, Int)] = [(-1,-2),(-1,2),(1,-2),(1,2),(-2,1),(-2,-1),(2,1),(2,-1)]
    
    func knightProbability(_ n: Int, _ k: Int, _ row: Int, _ column: Int) -> Double {
        guard k > 0  else {
            return 1
        }
        var f: [[[Double]]] = .init(repeating: .init(repeating: .init(repeating: 0, count: k + 1), count: n), count: n)
        for i in 0..<n {
            for j in 0..<n {
                f[i][j][0] = 1
            }
        }
        
        for p in 1...k {
            for i in 0..<n {
                for j in 0..<n {
                    for dir in dirs {
                        let nx = i + dir.0, ny = j + dir.1
                        if nx < 0 || nx >= n || ny < 0 || ny >= n {
                            continue
                        }
                        f[i][j][p] += f[nx][ny][p - 1] / 8
                    }
                }
            }
        }
        return f[row][column][k]
    }
}
// @lc code=end

func main() {
    var n: Int
    var k: Int
    var row: Int
    var column: Int
    var res: Double
    
    /**
     输入: n = 3, k = 2, row = 0, column = 0
     输出: 0.0625
     解释: 有两步(到(1,2)，(2,1))可以让骑士留在棋盘上。
     在每一个位置上，也有两种移动可以让骑士留在棋盘上。
     骑士留在棋盘上的总概率是0.0625。
     */
    n = 3
    k = 2
    row = 0
    column = 0
    res = 0.0625
    assert(res == Solution().knightProbability(n, k, row, column))
    
    /**
     输入: n = 1, k = 0, row = 0, column = 0
     输出: 1.00000
     */
    n = 1
    k = 0
    row = 0
    column = 0
    res = 1.00000
    assert(res == Solution().knightProbability(n, k, row, column))
}
