/*
 * @lc app=leetcode.cn id=1475 lang=swift
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
    func finalPrices(_ prices: [Int]) -> [Int] {
        let n = prices.count
        var ans = prices
        var st = [Int]()
        for i in (0..<n).reversed() {
            while let top = st.last, prices[i] < top {
                st.removeLast()
            }
            if let top = st.last {
                ans[i] = prices[i] - top
            }
            st.append(prices[i])
        }
        return ans
    }
}
// @lc code=end

func main() {
    var prices: [Int]
    var res: [Int]
    
    /**
     输入：prices = [8,4,6,2,3]
     输出：[4,2,4,2,3]
     解释：
     商品 0 的价格为 price[0]=8 ，你将得到 prices[1]=4 的折扣，所以最终价格为 8 - 4 = 4 。
     商品 1 的价格为 price[1]=4 ，你将得到 prices[3]=2 的折扣，所以最终价格为 4 - 2 = 2 。
     商品 2 的价格为 price[2]=6 ，你将得到 prices[3]=2 的折扣，所以最终价格为 6 - 2 = 4 。
     商品 3 和 4 都没有折扣。
     */
    prices = [8,4,6,2,3]
    res = [4,2,4,2,3]
    assert(res == Solution().finalPrices(prices))
    
    /**
     输入：prices = [1,2,3,4,5]
     输出：[1,2,3,4,5]
     解释：在这个例子中，所有商品都没有折扣。
     */
    prices = [1,2,3,4,5]
    res = [1,2,3,4,5]
    assert(res == Solution().finalPrices(prices))
    
    /**
     输入：prices = [10,1,1,6]
     输出：[9,0,1,6]
     */
    prices = [10,1,1,6]
    res = [9,0,1,6]
    assert(res == Solution().finalPrices(prices))
}
