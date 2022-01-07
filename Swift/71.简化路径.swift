/*
 * @lc app=leetcode.cn id=71 lang=swift
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
    func simplifyPath(_ path: String) -> String {
        let paths = path.map { $0 }
        var cpns: [String] = []
        var i = 1   // "/a//b////c/d//././/.."
        while i < paths.count {
            if paths[i] == "/" {
                i += 1
                continue
            }
            var j = i + 1
            while j < paths.count && paths[j] != "/" {
                j += 1
            }
            let item = String(paths[i..<j])
            if item == ".." {
                if !cpns.isEmpty {
                    cpns.removeLast()
                }
            } else if item != "." {
                cpns.append(item)
            }
            i = j
        }
        var ans = ""
        while !cpns.isEmpty {
            ans += "/" + cpns.removeFirst()
        }
        return ans.isEmpty ? "/" : ans
    }
}
// @lc code=end

func main() {
    var path: String
    var res: String
    
    /**
     输入：path = "/home/"
     输出："/home"
     解释：注意，最后一个目录名后面没有斜杠。
     */
    path = "/home/"
    res = "/home"
    assert(res == Solution().simplifyPath(path))

    /**
     输入：path = "/../"
     输出："/"
     解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。
     */
    path = "/../"
    res = "/"
    assert(res == Solution().simplifyPath(path))

    /**
     输入：path = "/home//foo/"
     输出："/home/foo"
     解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
     */
    path = "/home//foo/"
    res = "/home/foo"
    assert(res == Solution().simplifyPath(path))

    /**
     输入：path = "/a/./b/../../c/"
     输出："/c"
     */
    path = "/a/./b/../../c/"
    res = "/c"
    assert(res == Solution().simplifyPath(path))
    
    /**
     输入：path = "/a//b////c/d//././/.."
     输出："/a/b/c"
     */
    path = "/a//b////c/d//././/.."
    res = "/a/b/c"
    assert(res == Solution().simplifyPath(path))
}
