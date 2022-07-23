/*
 * @lc app=leetcode.cn id=757 lang=swift
 *
 * [757] 设置交集大小至少为2
 */

// @lc code=start
class Solution {
    func intersectionSizeTwo(_ intervals: [[Int]]) -> Int {
        let intervals = intervals.sorted {
            return $0[1] == $1[1] ? $0[0] > $1[0] : $0[1] < $1[1]
        }
        var ans = [Int]()
        for interval in intervals {
            let (a, b) = (interval[0], interval[1])
            if ans.isEmpty {
                ans = [b - 1, b]
            } else {
                let cnt = ans.count
                if ans[cnt - 1] < a {
                    ans.append(b - 1)
                }
                if ans[cnt - 2] < a {
                    ans.append(b)
                }
            }
        }
        return ans.count;
    }
}
// @lc code=end

func main() {
    var intervals: [[Int]]
    var res: Int
    
    /**
     输入: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
     输出: 3
     解释:
     考虑集合 S = {2, 3, 4}. S与intervals中的四个区间都有至少2个相交的元素。
     且这是S最小的情况，故我们输出3。
     */
    intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
    res = 3
    assert(res == Solution().intersectionSizeTwo(intervals))
    
    /**
     输入: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
     输出: 5
     解释:
     最小的集合S = {1, 2, 3, 4, 5}.
     */
    intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
    res = 5
    assert(res == Solution().intersectionSizeTwo(intervals))
}
