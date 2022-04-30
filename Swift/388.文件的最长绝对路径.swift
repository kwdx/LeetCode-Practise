/*
 * @lc app=leetcode.cn id=388 lang=swift
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
    func lengthLongestPath(_ input: String) -> Int {
        var ans = 0
        var pos = 0
        var st: [Int] = []
        let chars = Array(input)
        let n = chars.count
        
        while pos < input.count {
            var depth = 1
            
            while pos < n && chars[pos] == "\t" {
                pos += 1
                depth += 1
            }
            
            var len = 0
            var isFile = false
            while pos < n && chars[pos] != "\n" {
                if chars[pos] == "." {
                    isFile = true
                }
                len += 1
                pos += 1
            }
            
            //
            pos += 1
            
            while st.count >= depth {
                st.removeLast()
            }
            
            if let last = st.last {
                len += last + 1
            }
            
            if isFile {
                ans = max(ans, len)
            } else {
                st.append(len)
            }
        }
        
        return ans
    }
}
// @lc code=end

func main() {
    var input: String
    var res: Int
    
    /**
     输入：input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
     输出：20
     解释：只有一个文件，绝对路径为 "dir/subdir2/file.ext" ，路径长度 20
     */
    input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
    res = 20
    assert(res == Solution().lengthLongestPath(input))
    
    /**
     输入：input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
     输出：32
     解释：存在两个文件：
     "dir/subdir1/file1.ext" ，路径长度 21
     "dir/subdir2/subsubdir2/file2.ext" ，路径长度 32
     返回 32 ，因为这是最长的路径
     */
    input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
    res = 32
    assert(res == Solution().lengthLongestPath(input))
    
    /**
     输入：input = "a"
     输出：0
     解释：不存在任何文件
     */
    input = "a"
    res = 0
    assert(res == Solution().lengthLongestPath(input))
    
    /**
     输入：input = "file1.txt\nfile2.txt\nlongfile.txt"
     输出：12
     解释：根目录下有 3 个文件。
     因为根目录中任何东西的绝对路径只是名称本身，所以答案是 "longfile.txt" ，路径长度为 12
     */
    input = "file1.txt\nfile2.txt\nlongfile.txt"
    res = 12
    assert(res == Solution().lengthLongestPath(input))
}
