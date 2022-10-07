/*
 * @lc app=leetcode.cn id=811 lang=swift
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution {
    func subdomainVisits(_ cpdomains: [String]) -> [String] {
        var map: [String: Int] = [:]
        for cpdomain in cpdomains {
            let cmps = cpdomain.components(separatedBy: " ")
            let cnt = Int(cmps[0])!
            let domain = Array(cmps[1])
            var idx = domain.count - 1
            while (idx >= 0) {
                while idx >= 0 && domain[idx] != "." {
                    idx -= 1
                }
                let cur = String(domain[(idx + 1)...])
                map[cur] = cnt + (map[cur] ?? 0)
                idx -= 1
            }
            
        }
        return map.map { "\($0.value) \($0.key)" }.sorted { $0.count > $1.count }
    }
}
// @lc code=end

func main() {
    var cpdomains: [String]
    var res: [String]
    
    /**
     输入：cpdomains = ["9001 discuss.leetcode.com"]
     输出：["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
     解释：例子中仅包含一个网站域名："discuss.leetcode.com"。
     按照前文描述，子域名 "leetcode.com" 和 "com" 都会被访问，所以它们都被访问了 9001 次。
     */
    cpdomains = ["9001 discuss.leetcode.com"]
    res = ["9001 discuss.leetcode.com","9001 leetcode.com","9001 com"].sorted { $0.count > $1.count }
    assert(res == Solution().subdomainVisits(cpdomains))
    
    /**
     输入：cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
     输出：["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
     解释：按照前文描述，会访问 "google.mail.com" 900 次，"yahoo.com" 50 次，"intel.mail.com" 1 次，"wiki.org" 5 次。
     而对于父域名，会访问 "mail.com" 900 + 1 = 901 次，"com" 900 + 50 + 1 = 951 次，和 "org" 5 次。
     */
    cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
    res = ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"].sorted { $0.count > $1.count }
    assert(res == Solution().subdomainVisits(cpdomains))
}
