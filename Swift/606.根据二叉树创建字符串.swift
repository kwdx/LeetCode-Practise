/*
 * @lc app=leetcode.cn id=606 lang=swift
 *
 * [606] 根据二叉树创建字符串
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
    private var ans: String = ""
    func tree2str(_ root: TreeNode?) -> String {
        guard let node = root else { return "" }
        dfs(node)
        ans.removeFirst()
        ans.removeLast()
        return ans
    }
    
    private func dfs(_ node: TreeNode) {
        ans += "(\(node.val)"
        if node.left != nil {
            dfs(node.left!)
        } else if node.right != nil {
            ans += "()"
        }
        if node.right != nil {
            dfs(node.right!)
        }
        ans += ")"
    }
}
// @lc code=end

func main() {
    var root: TreeNode?
    var res: String
    
    /**
     输入: 二叉树: [1,2,3,4]
            1
          /   \
         2     3
        /
       4

     输出: "1(2(4))(3)"

     解释: 原本将是“1(2(4)())(3())”，
     在你省略所有不必要的空括号对之后，
     它将是“1(2(4))(3)”。
     */
    root = generateTreeByLevel([1,2,3,4])
    res = "1(2(4))(3)"
    assert(res == Solution().tree2str(root))
    
    /**
     输入: 二叉树: [1,2,3,null,4]
            1
          /   \
         2     3
          \
           4

     输出: "1(2()(4))(3)"

     解释: 和第一个示例相似，
     除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
     */
    root = generateTreeByLevel([1,2,3,nil,4])
    res = "1(2()(4))(3)"
    assert(res == Solution().tree2str(root))
}
