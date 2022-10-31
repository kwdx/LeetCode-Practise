/*
 * @lc app=leetcode.cn id=1773 lang=swift
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
    func countMatches(_ items: [[String]], _ ruleKey: String, _ ruleValue: String) -> Int {
        items.filter {
            switch ruleKey {
            case "type":    return $0[0] == ruleValue
            case "color":   return $0[1] == ruleValue
            case "name":    return $0[2] == ruleValue
            default:        return false
            }
        }.count
    }
}
// @lc code=end

func main() {
    var items: [[String]]
    var ruleKey: String
    var ruleValue: String
    var res: Int
    
    /**
     输入：items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
     输出：1
     解释：只有一件物品匹配检索规则，这件物品是 ["computer","silver","lenovo"] 。
     */
    items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]]
    ruleKey = "color"
    ruleValue = "silver"
    res = 1
    assert(res == Solution().countMatches(items, ruleKey, ruleValue))
    
    /**
     输入：items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]], ruleKey = "type", ruleValue = "phone"
     输出：2
     解释：只有两件物品匹配检索规则，这两件物品分别是 ["phone","blue","pixel"] 和 ["phone","gold","iphone"] 。注意，["computer","silver","phone"] 未匹配检索规则。
     */
    items = [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]]
    ruleKey = "type"
    ruleValue = "phone"
    res = 2
    assert(res == Solution().countMatches(items, ruleKey, ruleValue))
}
