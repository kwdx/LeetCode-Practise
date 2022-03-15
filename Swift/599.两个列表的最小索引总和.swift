/*
 * @lc app=leetcode.cn id=599 lang=swift
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
    func findRestaurant(_ list1: [String], _ list2: [String]) -> [String] {
        var rests: [String: Int] = [:]
        for (idx, element) in list1.enumerated() {
            rests[element] = idx
        }
        var ans: [String] = []
        var minIdx = 2000
        for i in 0..<list2.count {
            let rest  = list2[i]
            if i > minIdx {
                break
            }
            if let idx = rests[rest] {
                if idx + i < minIdx {
                    minIdx = idx + i
                    ans = [rest]
                } else if idx + i == minIdx {
                    ans.append(rest)
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var list1: [String]
    var list2: [String]
    var res: [String]
    
    /**
     输入: list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
     输出: ["Shogun"]
     解释: 他们唯一共同喜爱的餐厅是“Shogun”。
     */
    list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]
    list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
    res = ["Shogun"]
    assert(res == Solution().findRestaurant(list1, list2))
    
    /**
     输入:list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]，list2 = ["KFC", "Shogun", "Burger King"]
     输出: ["Shogun"]
     解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
     */
    list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]
    list2 = ["KFC", "Shogun", "Burger King"]
    res = ["Shogun"]
    assert(res == Solution().findRestaurant(list1, list2))
}
