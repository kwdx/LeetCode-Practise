/*
 * @lc app=leetcode.cn id=901 lang=swift
 *
 * [901] 股票价格跨度
 */

// @lc code=start

class StockSpanner {
    private var st = [(-1, Int.max)]
    private var idx = -1
    
    init() {

    }
    
    func next(_ price: Int) -> Int {
        idx += 1
        while st.last!.1 <= price {
            st.removeLast()
        }
        let ans = idx - st.last!.0
        st.append((idx, price))
        return ans
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * let obj = StockSpanner()
 * let ret_1: Int = obj.next(price)
 */
// @lc code=end

func main() {
    /**
     输入：["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
     输出：[null,1,1,1,2,1,4,6]
     解释：
     首先，初始化 S = StockSpanner()，然后：
     S.next(100) 被调用并返回 1，
     S.next(80) 被调用并返回 1，
     S.next(60) 被调用并返回 1，
     S.next(70) 被调用并返回 2，
     S.next(60) 被调用并返回 1，
     S.next(75) 被调用并返回 4，
     S.next(85) 被调用并返回 6。

     注意 (例如) S.next(75) 返回 4，因为截至今天的最后 4 个价格
     (包括今天的价格 75) 小于或等于今天的价格。
     */
    let S = StockSpanner()
    assert(1 == S.next(100))
    assert(1 == S.next(80))
    assert(1 == S.next(60))
    assert(2 == S.next(70))
    assert(1 == S.next(60))
    assert(4 == S.next(75))
    assert(6 == S.next(85))
}
