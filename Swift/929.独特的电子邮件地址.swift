/*
 * @lc app=leetcode.cn id=929 lang=swift
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
    func numUniqueEmails(_ emails: [String]) -> Int {
        var toSet: Set<String> = []
        for email in emails {
            var name = ""
            let chars = Array(email)
            var i = 0
            var ok = true
            while i < chars.count {
                if chars[i] == "@" {
                    break
                } else if chars[i] == "." {
                    i += 1
                    continue
                }
                if chars[i] == "+" {
                    ok = false
                }
                if ok {
                    name.append(chars[i])
                }
                i += 1
            }
            toSet.insert(name + String(chars[i...]))
        }
        return toSet.count
    }
}
// @lc code=end

func main() {
    var emails: [String]
    var res: Int
    
    /**
     输入：emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
     输出：2
     解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。
     */
    emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    res = 2
    assert(res == Solution().numUniqueEmails(emails))
    
    /**
     输入：emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
     输出：3
     */
    emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
    res = 3
    assert(res == Solution().numUniqueEmails(emails))
}
