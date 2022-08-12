/*
 * @lc app=leetcode.cn id=1282 lang=swift
 *
 * [1282] 用户分组
 */

// @lc code=start
class Solution {
    func groupThePeople(_ groupSizes: [Int]) -> [[Int]] {
        var groups: [Int: [Int]] = [:]
        for i in 0..<groupSizes.count {
            let size = groupSizes[i]
            groups[size] = groups[size] ?? []
            groups[size]!.append(i)
        }
        var ans: [[Int]] = []
        for (size, people) in groups {
            let groupCnt = people.count / size
            for i in 0..<groupCnt {
                var group: [Int] = []
                let start = i * size
                for j in 0..<size {
                    group.append(people[start + j])
                }
                ans.append(group)
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var groupSizes: [Int]
    var res: [[Int]]
    
    /**
     输入：groupSizes = [3,3,3,3,3,1,3]
     输出：[[5],[0,1,2],[3,4,6]]
     解释：
     第一组是 [5]，大小为 1，groupSizes[5] = 1。
     第二组是 [0,1,2]，大小为 3，groupSizes[0] = groupSizes[1] = groupSizes[2] = 3。
     第三组是 [3,4,6]，大小为 3，groupSizes[3] = groupSizes[4] = groupSizes[6] = 3。
     其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
     */
    groupSizes = [3,3,3,3,3,1,3]
    res = [[5],[0,1,2],[3,4,6]]
    print(Solution().groupThePeople(groupSizes))
    
    /**
     输入：groupSizes = [2,1,3,3,3,2]
     输出：[[1],[0,5],[2,3,4]]
     */
    groupSizes = [2,1,3,3,3,2]
    res = [[1],[0,5],[2,3,4]]
    print(Solution().groupThePeople(groupSizes))
}
