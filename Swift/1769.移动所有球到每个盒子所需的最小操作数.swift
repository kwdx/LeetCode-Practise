/*
 * @lc app=leetcode.cn id=1769 lang=swift
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution {
    func minOperations(_ boxes: String) -> [Int] {
        let boxes = Array(boxes)
        var left = boxes[0] == "1" ?  1 : 0
        var right = 0
        var operations = 0
        for i in 1..<boxes.count {
            if boxes[i] == "1" {
                right += 1
                operations += i
            }
        }
        var ans = [Int](repeating: 0, count: boxes.count)
        ans[0] = operations
        for i in 1..<boxes.count {
            operations += left - right
            if boxes[i] == "1" {
                left += 1
                right -= 1
            }
            ans[i] = operations
        }
        return ans
    }
}
// @lc code=end

func main() {
    var boxes: String
    var res: [Int]
    
    /**
     输入：boxes = "110"
     输出：[1,1,3]
     解释：每个盒子对应的最小操作数如下：
     1) 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
     2) 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
     3) 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1 步操作。共计 3 步操作。
     */
    boxes = "110"
    res = [1,1,3]
    assert(res == Solution().minOperations(boxes))
    
    /**
     输入：boxes = "001011"
     输出：[11,8,5,4,3,4]
     */
    boxes = "001011"
    res = [11,8,5,4,3,4]
    assert(res == Solution().minOperations(boxes))
}
