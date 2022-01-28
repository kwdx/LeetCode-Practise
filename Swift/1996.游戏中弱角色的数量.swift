/*
 * @lc app=leetcode.cn id=1996 lang=swift
 *
 * [1996] 游戏中弱角色的数量
 */

// @lc code=start
class Solution {
    func numberOfWeakCharacters(_ properties: [[Int]]) -> Int {
        let properties1 = properties.sorted {
            $0[0] == $1[0] ? $0[1] < $1[1] : $0[0] > $1[0]
        }
        var maxDefines = properties1[0][1]
        var ans = 0
        for i in 1..<properties1.count {
            if properties1[i][1] >= maxDefines {
                maxDefines = properties1[i][1]
            } else {
                ans += 1
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var properties: [[Int]]
    var res: Int
    
    /**
     输入：properties = [[5,5],[6,3],[3,6]]
     输出：0
     解释：不存在攻击和防御都严格高于其他角色的角色。
     */
    properties = [[5,5],[6,3],[3,6]]
    res = 0
    assert(res == Solution().numberOfWeakCharacters(properties))

    /**
     输入：properties = [[2,2],[3,3]]
     输出：1
     解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
     */
    properties = [[2,2],[3,3]]
    res = 1
    assert(res == Solution().numberOfWeakCharacters(properties))
    
    /**
     输入：properties = [[1,5],[10,4],[4,3]]
     输出：1
     解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
     */
    properties = [[1,5],[10,4],[4,3]]
    res = 1
    assert(res == Solution().numberOfWeakCharacters(properties))
}
