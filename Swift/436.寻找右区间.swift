/*
 * @lc app=leetcode.cn id=436 lang=swift
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
    func findRightInterval(_ intervals: [[Int]]) -> [Int] {
        var arr: [(Int, Int)] = []
        for i in 0..<intervals.count {
            arr.append((intervals[i][0], i))
        }
        arr.sort(by: <)
        var ans: [Int] = []
        
        for i in 0..<intervals.count {
            if let it = arr.first(where: { $0.0 >= intervals[i][1] }) {
                ans.append(it.1)
            } else {
                ans.append(-1)
            }
        }
        
        return ans
    }
}
// @lc code=end

func main() {
    var intervals: [[Int]]
    var res: [Int]
    
    /**
     输入：intervals = [[1,2]]
     输出：[-1]
     解释：集合中只有一个区间，所以输出-1。
     */
    intervals = [[1,2]]
    res = [-1]
    assert(res == Solution().findRightInterval(intervals))
    
    /**
     输入：intervals = [[3,4],[2,3],[1,2]]
     输出：[-1,0,1]
     解释：对于 [3,4] ，没有满足条件的“右侧”区间。
     对于 [2,3] ，区间[3,4]具有最小的“右”起点;
     对于 [1,2] ，区间[2,3]具有最小的“右”起点。
     */
    intervals = [[3,4],[2,3],[1,2]]
    res = [-1,0,1]
    assert(res == Solution().findRightInterval(intervals))
    
    /**
     输入：intervals = [[1,4],[2,3],[3,4]]
     输出：[-1,2,-1]
     解释：对于区间 [1,4] 和 [3,4] ，没有满足条件的“右侧”区间。
     对于 [2,3] ，区间 [3,4] 有最小的“右”起点。
     */
    intervals = [[1,4],[2,3],[3,4]]
    res = [-1,2,-1]
    assert(res == Solution().findRightInterval(intervals))
}
