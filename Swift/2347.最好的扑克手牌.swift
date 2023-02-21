/*
 * @lc app=leetcode.cn id=2347 lang=swift
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
class Solution {
    func bestHand(_ ranks: [Int], _ suits: [Character]) -> String {
        var colors = Set<Character>()
        for suit in suits {
            colors.insert(suit)
        }
        if colors.count == 1 {
            return "Flush"
        }
        var nums = [Int: Int]()
        for rank in ranks {
            nums[rank] = 1 + (nums[rank] ?? 0)
        }
        if nums.count == 5 {
            return "High Card"
        }
        for (_, val) in nums {
            if val > 2 {
                return "Three of a Kind"
            }
        }
        return "Pair"
    }
}
// @lc code=end

func main() {
    var ranks: [Int]
    var suits: [Character]
    var res: String
    
    /**
     输入：ranks = [13,2,3,1,9], suits = ["a","a","a","a","a"]
     输出："Flush"
     解释：5 张扑克牌的花色相同，所以返回 "Flush" 。
     */
    ranks = [13,2,3,1,9]
    suits = ["a","a","a","a","a"]
    res = "Flush"
    assert(res == Solution().bestHand(ranks, suits))
    
    /**
     输入：ranks = [4,4,2,4,4], suits = ["d","a","a","b","c"]
     输出："Three of a Kind"
     解释：第一、二和四张牌组成三张相同大小的扑克牌，所以得到 "Three of a Kind" 。
     注意我们也可以得到 "Pair" ，但是 "Three of a Kind" 是更好的手牌类型。
     有其他的 3 张牌也可以组成 "Three of a Kind" 手牌类型。
     */
    ranks = [4,4,2,4,4]
    suits = ["d","a","a","b","c"]
    res = "Three of a Kind"
    assert(res == Solution().bestHand(ranks, suits))
    
    /**
     输入：ranks = [10,10,2,12,9], suits = ["a","b","c","a","d"]
     输出："Pair"
     解释：第一和第二张牌大小相同，所以得到 "Pair" 。
     我们无法得到 "Flush" 或者 "Three of a Kind" 。
     */
    ranks = [10,10,2,12,9]
    suits = ["a","b","c","a","d"]
    res = "Pair"
    assert(res == Solution().bestHand(ranks, suits))
}
