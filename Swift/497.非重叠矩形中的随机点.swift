/*
 * @lc app=leetcode.cn id=497 lang=swift
 *
 * [497] 非重叠矩形中的随机点
 */

// @lc code=start

class Solution {
    
    private let arr: [Int]
    private let rects: [[Int]]

    init(_ rects: [[Int]]) {
        self.rects = rects
        var arr = [0]
        for rect in rects {
            arr.append(arr.last! + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1))
        }
        self.arr = arr
    }
    
    func pick() -> [Int] {
        var num = Int.random(in: 0..<arr.last!)
        let rectIdx = arr.firstIndex(where: { $0 > num })! - 1
        num -= arr[rectIdx]
        
        let a = rects[rectIdx][0], b = rects[rectIdx][1]
        let x = rects[rectIdx][2]
        let cols = x - a + 1
        let row = num / cols
        let col = num - cols * row
        return [a + col, b + row]
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution(rects)
 * let ret_1: [Int] = obj.pick()
 */
// @lc code=end

func main() {
    /**
     输入:
     ["Solution", "pick", "pick", "pick", "pick", "pick"]
     [[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
     输出:
     [null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]

     解释：
     Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
     solution.pick(); // 返回 [1, -2]
     solution.pick(); // 返回 [1, -1]
     solution.pick(); // 返回 [-1, -2]
     solution.pick(); // 返回 [-2, -2]
     solution.pick(); // 返回 [0, 0]
     */
    let solution = Solution([[-2, -2, 1, 1], [2, 2, 4, 6]])
    print(solution.pick())
    print(solution.pick())
    print(solution.pick())
    print(solution.pick())
    print(solution.pick())
}
