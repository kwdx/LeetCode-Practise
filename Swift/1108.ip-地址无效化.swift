/*
 * @lc app=leetcode.cn id=1108 lang=swift
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
    func defangIPaddr(_ address: String) -> String {
        var ans = ""
        for c in address {
            if c == "." {
                ans.append("[.]")
            } else {
                ans.append(c)
            }
        }
        return ans
//        address.replacingOccurrences(of: ".", with: "[.]")
    }
}
// @lc code=end

func main() {
    var address: String
    var res: String
    
    /**
     输入：address = "1.1.1.1"
     输出："1[.]1[.]1[.]1"
     */
    address = "1.1.1.1"
    res = "1[.]1[.]1[.]1"
    assert(res == Solution().defangIPaddr(address))
    
    /**
     输入：address = "255.100.50.0"
     输出："255[.]100[.]50[.]0"
     */
    address = "255.100.50.0"
    res = "255[.]100[.]50[.]0"
    assert(res == Solution().defangIPaddr(address))
}
