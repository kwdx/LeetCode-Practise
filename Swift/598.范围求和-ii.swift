/*
 * @lc app=leetcode.cn id=598 lang=swift
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
    func maxCount(_ m: Int, _ n: Int, _ ops: [[Int]]) -> Int {
        var minM = m
        var minN = n
        for op in ops {
            minM = min(minM, op[0])
            minN = min(minN, op[1])
        }
        return minM * minN
    }
}
// @lc code=end

func main() {
    var m: Int
    var n: Int
    var ops: [[Int]]
    var res: Int
    
    /**
     输入:
     m = 3, n = 3
     operations = [[2,2],[3,3]]
     输出: 4
     解释:
     初始状态, M =
     [[0, 0, 0],
      [0, 0, 0],
      [0, 0, 0]]

     执行完操作 [2,2] 后, M =
     [[1, 1, 0],
      [1, 1, 0],
      [0, 0, 0]]

     执行完操作 [3,3] 后, M =
     [[2, 2, 1],
      [2, 2, 1],
      [1, 1, 1]]

     M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4。
     */
    m = 3
    n = 3
    ops = [[2,2],[3,3]]
    res = 4
    assert(res == Solution().maxCount(m,n,ops))
}
