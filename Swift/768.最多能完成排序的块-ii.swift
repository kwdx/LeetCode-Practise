/*
 * @lc app=leetcode.cn id=768 lang=swift
 *
 * [768] 最多能完成排序的块 II
 */

// @lc code=start
class Solution {
    func maxChunksToSorted(_ arr: [Int]) -> Int {
        var st: [Int] = []
        for num in arr {
            if st.isEmpty || num >= st.last! {
                st.append(num)
            } else {
                let mx = st.removeLast()
                while !st.isEmpty && st.last! > num {
                    st.removeLast()
                }
                st.append(mx)
            }
        }
        return st.count
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: Int
    
    /**
     输入: arr = [5,4,3,2,1]
     输出: 1
     解释:
     将数组分成2块或者更多块，都无法得到所需的结果。
     例如，分成 [5, 4], [3, 2, 1] 的结果是 [4, 5, 1, 2, 3]，这不是有序的数组。
     */
    arr = [5,4,3,2,1]
    res = 1
    assert(res == Solution().maxChunksToSorted(arr))
    
    /**
     输入: arr = [2,1,3,4,4]
     输出: 4
     解释:
     我们可以把它分成两块，例如 [2, 1], [3, 4, 4]。
     然而，分成 [2, 1], [3], [4], [4] 可以得到最多的块数。
     */
    arr = [2,1,3,4,4]
    res = 4
    assert(res == Solution().maxChunksToSorted(arr))
}
