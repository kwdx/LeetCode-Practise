/*
 * @lc app=leetcode.cn id=508 lang=swift
 *
 * [508] 出现次数最多的子树元素和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    private var numToFreq: [Int: Int] = [:]
    private var maxNum = 0
    
    private func dfs(_ root: TreeNode?) -> Int {
        guard let node = root else {
            return 0
        }
        let cur = node.val + dfs(node.left) + dfs(node.right)
        numToFreq[cur] = 1 + (numToFreq[cur] ?? 0)
        maxNum = max(maxNum, numToFreq[cur]!)
        return cur
    }
    
    func findFrequentTreeSum(_ root: TreeNode?) -> [Int] {
        _ = dfs(root)
        return numToFreq.compactMap { (key, val) in
            val == maxNum ? key : nil
        }
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var ans: [Int]
    
    /**
     输入: root = [5,2,-3]
     输出: [2,-3,4]
     */
    root = generateTreeByLevel([5,2,-3])
    ans = [2,-3,4]
    print(Solution().findFrequentTreeSum(root))
//    assert(ans == Solution().findFrequentTreeSum(root));
    
    /**
     输入: root = [5,2,-5]
     输出: [2]
     */
    root = generateTreeByLevel([5,2,-5])
    ans = [2]
    assert(ans == Solution().findFrequentTreeSum(root));
}
