/*
 * @lc app=leetcode.cn id=451 lang=swift
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
    func frequencySort(_ s: String) -> String {
        typealias Pair = (Character, Int)
        var m = [Character: Int]()
        for ch in s {
            m[ch] = 1 + (m[ch] ?? 0);
        }
        var pq = [Pair]()
        for item in m {
            pq.append((item.key, item.value))
        }
        pq.sort { (item1, item2) -> Bool in
            return item1.1 > item2.1
        }
        var res = String()
        for item in pq {
            res += String(repeating: item.0, count: item.1)
        }
        return res
    }
}
// @lc code=end

func main() {
    var s: String
    var res: String
    
    /**
     输入:
     "tree"

     输出:
     "eert"

     解释:
     'e'出现两次，'r'和't'都只出现一次。
     因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
     */
    s = "tree"
    res = "eert"
    assert(res == Solution().frequencySort(s) || "eetr" == Solution().frequencySort(s))
    
    /**
     输入:
     "cccaaa"

     输出:
     "cccaaa"

     解释:
     'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
     注意"cacaca"是不正确的，因为相同的字母必须放在一起。
     */
    s = "cccaaa"
    res = "cccaaa"
    assert(res == Solution().frequencySort(s) || "aaaccc" == Solution().frequencySort(s))
    
    /**
     输入:
     "Aabb"

     输出:
     "bbAa"

     解释:
     此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
     注意'A'和'a'被认为是两种不同的字符。
     */
    s = "Aabb"
    res = "bbAa"
    assert(res == Solution().frequencySort(s) || "bbaA" == Solution().frequencySort(s))
}
