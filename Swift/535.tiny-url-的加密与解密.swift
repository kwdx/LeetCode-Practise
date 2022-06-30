/*
 * @lc app=leetcode.cn id=535 lang=swift
 *
 * [535] TinyURL 的加密与解密
 */

// @lc code=start
class Codec {
    private var database: [String: String] = [:]
    private let letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    private let prefix = "http://tinyurl.com/"
    
    // Encodes a URL to a shortened URL.
    func encode(_ longUrl: String) -> String {
        var key: String = ""
        while true {
            key = (0..<4).reduce("", { s, _ in s + "\(letters.randomElement()!)" })
            if database[key] == nil {
                database[key] = longUrl
                break
            }
        }
        return prefix + key
    }
    
    // Decodes a shortened URL to its original URL.
    func decode(_ shortUrl: String) -> String {
        guard shortUrl.hasPrefix(prefix) else {
            return ""
        }
        let key = shortUrl.dropFirst(prefix.count)
        return database[String(key)] ?? ""
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec()
 * val s = obj.encode(longUrl)
 * let ans = obj.decode(s)
*/
// @lc code=end

func main() {
    /**
     输入：url = "https://leetcode.com/problems/design-tinyurl"
     输出："https://leetcode.com/problems/design-tinyurl"

     解释：
     Solution obj = new Solution();
     string tiny = obj.encode(url); // 返回加密后得到的 TinyURL 。
     string ans = obj.decode(tiny); // 返回解密后得到的原本的 URL 。
     */
    let url = ""
    let obj = Codec()
    let tiny = obj.encode(url)  // 返回加密后得到的 TinyURL 。
    let ans = obj.decode(tiny)  // 返回解密后得到的原本的 URL 。
    assert(url == ans)
}
