/*
 * @lc app=leetcode.cn id=1233 lang=swift
 *
 * [1233] 删除子文件夹
 */

// @lc code=start
class Solution {
    func removeSubfolders(_ folder: [String]) -> [String] {
        let folder = folder.sorted()
        var ans: [String] = [folder.first!]
        for i in 1..<folder.count {
            let pre = ans.last!
            let f = folder[i]
            if !(pre.count < f.count && f.hasPrefix(pre) && f[f.index(f.startIndex, offsetBy: pre.count)] == "/") {
                ans.append(f)
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var folder: [String]
    var res: [String]
    
    /**
     输入：folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
     输出：["/a","/c/d","/c/f"]
     解释："/a/b/" 是 "/a" 的子文件夹，而 "/c/d/e" 是 "/c/d" 的子文件夹。
     */
    folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
    res = ["/a","/c/d","/c/f"]
    assert(res == Solution().removeSubfolders(folder))
    
    /**
     输入：folder = ["/a","/a/b/c","/a/b/d"]
     输出：["/a"]
     解释：文件夹 "/a/b/c" 和 "/a/b/d/" 都会被删除，因为它们都是 "/a" 的子文件夹。
     */
    folder = ["/a","/a/b/c","/a/b/d"]
    res = ["/a"]
    assert(res == Solution().removeSubfolders(folder))
    
    /**
     输入: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
     输出: ["/a/b/c","/a/b/ca","/a/b/d"]
     */
    folder = ["/a/b/c","/a/b/ca","/a/b/d"]
    res = ["/a/b/c","/a/b/ca","/a/b/d"]
    assert(res == Solution().removeSubfolders(folder))
}
