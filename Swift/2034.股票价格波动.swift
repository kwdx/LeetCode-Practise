/*
 * @lc app=leetcode.cn id=2034 lang=swift
 *
 * [2034] 股票价格波动
 */

// @lc code=start

import Darwin
import Foundation

class StockPrice {
    private var cur = 0
    private var timeToPrices: [Int: Int] = [:]
    private var pqMax: PriorityQueue<(Int, Int)> = .init { $0.1 < $1.1 }
    private var pqMin: PriorityQueue<(Int, Int)> = .init { $0.1 > $1.1 }
    
    init() {
        
    }
    
    func update(_ timestamp: Int, _ price: Int) {
        cur = max(cur, timestamp)
        timeToPrices[timestamp] = price
        pqMax.push((timestamp, price))
        pqMin.push((timestamp, price))
    }
    
    func current() -> Int {
        timeToPrices[cur] ?? 0
    }
    
    func maximum() -> Int {
        while let timePrice = pqMax.top {
            if timeToPrices[timePrice.0] == timePrice.1 {
                return timePrice.1
            }
            pqMax.pop()
        }
        return 0
    }
    
    func minimum() -> Int {
        while let timePrice = pqMin.top {
            if timeToPrices[timePrice.0] == timePrice.1 {
                return timePrice.1
            }
            pqMin.pop()
        }
        return 0
    }
}

/**
 * Your StockPrice object will be instantiated and called as such:
 * let obj = StockPrice()
 * obj.update(timestamp, price)
 * let ret_2: Int = obj.current()
 * let ret_3: Int = obj.maximum()
 * let ret_4: Int = obj.minimum()
 */
// @lc code=end

func main() {
    /**
     输入：
     ["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
     [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
     输出：
     [null, null, null, 5, 10, null, 5, null, 2]

     解释：
     StockPrice stockPrice = new StockPrice();
     stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
     stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
     stockPrice.current();     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
     stockPrice.maximum();     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
     stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。
                               // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
     stockPrice.maximum();     // 返回 5 ，更正后最高价格为 5 。
     stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
     stockPrice.minimum();     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
     */
    let stockPrice = StockPrice()
    stockPrice.update(1, 10)
    stockPrice.update(2, 5)
    assert(5 == stockPrice.current())
    assert(10 == stockPrice.maximum())
    stockPrice.update(1, 3)
    assert(5 == stockPrice.maximum())
    stockPrice.update(4, 2)
    assert(2 == stockPrice.minimum())
}
