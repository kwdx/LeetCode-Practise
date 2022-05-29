/*
 * @lc app=leetcode.cn id=468 lang=swift
 *
 * [468] 验证IP地址
 */

import Darwin

// @lc code=start
class Solution {
    func validIPAddress(_ queryIP: String) -> String {
        let numChars: Set<Character> = .init("0123456789")
        let hexChars: Set<Character> = .init("0123456789abcdefABCDEF")
        var values = queryIP.components(separatedBy: ".")
        if values.count == 4 {
            // 可能是IPv4
            for value in values {
                if value.isEmpty { return "Neither" }
                let chars = Array(value)
                if chars.count > 3 { return "Neither" }
                if chars.count > 1, chars[0] == "0" { return "Neither" }
                for char in chars where !numChars.contains(char) { return "Neither" }
                if Int(value)! > 255 { return "Neither" }
            }
            return "IPv4"
        }
        
        values = queryIP.components(separatedBy: ":")
        if values.count == 8 {
            // 可能是IPv6
            for value in values {
                if value.isEmpty { return "Neither" }
                let chars = Array(value)
                if chars.count > 4 { return "Neither" }
                for char in chars where !hexChars.contains(char) {
                    return "Neither"
                }
            }
            return "IPv6"
        }
        return "Neither"
    }
}
// @lc code=end

func main() {
    var queryIP: String
    var res: String
    
    /**
     输入：queryIP = "172.16.254.1"
     输出："IPv4"
     解释：有效的 IPv4 地址，返回 "IPv4"
     */
    queryIP = "172.16.254.1"
    res = "IPv4"
    assert(res == Solution().validIPAddress(queryIP))
    
    /**
     输入：queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
     输出："IPv6"
     解释：有效的 IPv6 地址，返回 "IPv6"
     */
    queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
    res = "IPv6"
    assert(res == Solution().validIPAddress(queryIP))
    
    /**
     输入：queryIP = "256.256.256.256"
     输出："Neither"
     解释：既不是 IPv4 地址，又不是 IPv6 地址
     */
    queryIP = "256.256.256.256"
    res = "Neither"
    assert(res == Solution().validIPAddress(queryIP))
}
