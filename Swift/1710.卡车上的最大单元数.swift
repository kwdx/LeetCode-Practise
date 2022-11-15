/*
 * @lc app=leetcode.cn id=1710 lang=swift
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution {
    func maximumUnits(_ boxTypes: [[Int]], _ truckSize: Int) -> Int {
        var ans = 0
        let boxTypes = boxTypes.sorted { $0[1] > $1[1] }
        var truckSize = truckSize
        for boxType in boxTypes {
            let numberOfBoxes = boxType[0]
            let numberOfUnitsPerBox = boxType[1]
            if numberOfBoxes < truckSize {
                ans += numberOfBoxes * numberOfUnitsPerBox
                truckSize -= numberOfBoxes
            } else {
                ans += truckSize * numberOfUnitsPerBox
                break
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var boxTypes: [[Int]]
    var truckSize: Int
    var res: Int
    
    /**
     输入：boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
     输出：8
     解释：箱子的情况如下：
     - 1 个第一类的箱子，里面含 3 个单元。
     - 2 个第二类的箱子，每个里面含 2 个单元。
     - 3 个第三类的箱子，每个里面含 1 个单元。
     可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
     单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8
     */
    boxTypes = [[1,3],[2,2],[3,1]]
    truckSize = 4
    res = 8
    assert(res == Solution().maximumUnits(boxTypes, truckSize))
    
    /**
     输入：boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
     输出：91
     */
    boxTypes = [[5,10],[2,5],[4,7],[3,9]]
    truckSize = 10
    res = 91
    assert(res == Solution().maximumUnits(boxTypes, truckSize))
}
