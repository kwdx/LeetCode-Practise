//
//  041.滑动窗口的平均值.swift
//  Swift_
//
//  Created by warden on 2022/7/17.
//

// @lc code=start
class MovingAverage {

    let n: Int
    private var arr: [Double] = []
    private var sum: Double = 0
    
    /** Initialize your data structure here. */
    init(_ size: Int) {
        self.n = size
    }
    
    func next(_ val: Int) -> Double {
        arr.append(Double(val))
        sum += Double(val)
        if arr.count > n {
            sum -= arr.removeFirst()
        }
        return sum / Double(arr.count)
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * let obj = MovingAverage(size)
 * let ret_1: Double = obj.next(val)
 */
// @lc code=end

func main() {
    /**
     输入：
     inputs = ["MovingAverage", "next", "next", "next", "next"]
     inputs = [[3], [1], [10], [3], [5]]
     输出：
     [null, 1.0, 5.5, 4.66667, 6.0]

     解释：
     MovingAverage movingAverage = new MovingAverage(3);
     movingAverage.next(1); // 返回 1.0 = 1 / 1
     movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
     movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
     movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
     */
    let movingAverage = MovingAverage(3)
    assert(1 == movingAverage.next(1))
    assert(5.5 == movingAverage.next(10))
    assert(14 / 3.0 == movingAverage.next(3))
    assert(6 == movingAverage.next(5))
}
