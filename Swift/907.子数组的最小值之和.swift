/*
 * @lc app=leetcode.cn id=907 lang=swift
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
    func sumSubarrayMins(_ arr: [Int]) -> Int {
        let n = arr.count
        var st = [Int]()
        var left = [Int](repeating: 0, count: n)
        var right = [Int](repeating: 0, count: n)
        for i in 0..<n {
            while !st.isEmpty && arr[i] <= arr[st.last!] {
                st.removeLast()
            }
            left[i] = i - (st.isEmpty ? -1 : st.last!)
            st.append(i)
        }
        st.removeAll()
        for i in (0..<n).reversed() {
            while !st.isEmpty && arr[i] < arr[st.last!] {
                st.removeLast()
            }
            right[i] = (st.isEmpty ? n : st.last!) - i
            st.append(i)
        }
        var ans = 0
        let mod = 1000_000_007
        for i in 0..<n {
            ans = (ans + left[i] * right[i] * arr[i]) % mod
        }
        return ans
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var res: Int
    
    /**
     输入：arr = [3,1,2,4]
     输出：17
     解释：
     子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
     最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。
     */
    arr = [3,1,2,4]
    res = 17
    assert(res == Solution().sumSubarrayMins(arr))
    
    /**
     输入：arr = [11,81,94,43,3]
     输出：444
     */
    arr = [11,81,94,43,3]
    res = 444
    assert(res == Solution().sumSubarrayMins(arr))
}
