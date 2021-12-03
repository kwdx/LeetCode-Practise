/*
 * @lc app=leetcode.cn id=786 lang=swift
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
    func kthSmallestPrimeFraction(_ arr: [Int], _ k: Int) -> [Int] {
        let n = arr.count
        var left: Double = 0
        var right: Double = 1
        
        while true {
            let mid = (left + right) / 2
            var i = -1
            var count = 0
            var x = 0
            var y = 1
            
            for j in 1..<n {
                while Double(arr[i + 1]) / Double(arr[j]) < mid {
                    i += 1
                    if arr[i] * y > arr[j] * x {
                        x = arr[i]
                        y = arr[j]
                    }
                }
                count += i + 1
            }
            
            if (count == k) {
                return [x, y]
            } else if (count < k) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }
}
// @lc code=end

func main() {
    var arr: [Int]
    var k: Int
    var res: [Int]
    
    /**
     输入：arr = [1,2,3,5], k = 3
     输出：[2,5]
     解释：已构造好的分数,排序后如下所示:
     1/5, 1/3, 2/5, 1/2, 3/5, 2/3
     很明显第三个最小的分数是 2/5
     */
    arr = [1,2,3,5]
    k = 3
    res = [2,5]
    assert(res == Solution().kthSmallestPrimeFraction(arr, k))
    
    /**
     输入：arr = [1,7], k = 1
     输出：[1,7]
     */
    arr = [1,7]
    k = 1
    res = [1,7]
    assert(res == Solution().kthSmallestPrimeFraction(arr, k))
}
