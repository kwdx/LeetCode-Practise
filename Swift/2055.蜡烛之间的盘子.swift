/*
 * @lc app=leetcode.cn id=2055 lang=swift
 *
 * [2055] 蜡烛之间的盘子
 */

import Darwin

// @lc code=start
class Solution {
    func platesBetweenCandles(_ s: String, _ queries: [[Int]]) -> [Int] {
        let chars = Array(s)
        let n = s.count
        var left = [Int](repeating: 0, count: n)
        var right = left
        var sum = [Int](repeating: 0, count: n + 1)
        var i = 0, j = n - 1, p = -1, q = -1
        while i < n {
            if chars[i] == "|" {
                p = i
            }
            if chars[j] == "|" {
                q = j
            }
            left[i] = p
            right[j] = q
            sum[i + 1] = sum[i] + (chars[i] == "*" ? 1 : 0)
            i += 1
            j -= 1
        }
        
        return queries.map { query in
            let a = right[query[0]]
            let b = left[query[1]]
            if a != -1 && a <= b {
                return sum[b + 1] - sum[a]
            } else {
                return 0
            }
        }
        
//        char[] cs = s.toCharArray();
//        int n = cs.length, m = qs.length;
//        int[] l = new int[n], r = new int[n];
//        int[] sum = new int[n + 1];
//        for (int i = 0, j = n - 1, p = -1, q = -1; i < n; i++, j--) {
//            if (cs[i] == '|') p = i;
//            if (cs[j] == '|') q = j;
//            l[i] = p; r[j] = q;
//            sum[i + 1] = sum[i] + (cs[i] == '*' ? 1 : 0);
//        }
//        int[] ans = new int[m];
//        for (int i = 0; i < m; i++) {
//            int a = qs[i][0], b = qs[i][1];
//            int c = r[a], d = l[b];
//            if (c != -1 && c <= d) ans[i] = sum[d + 1] - sum[c];
//        }
//        return ans;
    }
}
// @lc code=end


func main() {
    var s: String
    var queries: [[Int]]
    var res: [Int]
    
    /**
     输入：s = "**|**|***|", queries = [[2,5],[5,9]]
     输出：[2,3]
     解释：
     - queries[0] 有两个盘子在蜡烛之间。
     - queries[1] 有三个盘子在蜡烛之间。
     */
    s = "**|**|***|"
    queries = [[2,5],[5,9]]
    res = [2,3]
    assert(res == Solution().platesBetweenCandles(s, queries));
    
    /**
     输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
     输出：[9,0,0,0,0]
     解释：
     - queries[0] 有 9 个盘子在蜡烛之间。
     - 另一个查询没有盘子在蜡烛之间。
     */
    s = "***|**|*****|**||**|*"
    queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
    res = [9,0,0,0,0]
    assert(res == Solution().platesBetweenCandles(s, queries))
}
