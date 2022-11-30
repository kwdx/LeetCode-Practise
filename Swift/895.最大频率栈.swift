/*
 * @lc app=leetcode.cn id=895 lang=swift
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack {

    private var maxFreq: Int = 0
    private var valToFreqs: [Int: Int] = [:]
    private var freqToStacks: [Int: [Int]] = [:]
    
    init() {

    }
    
    func push(_ val: Int) {
        let freq = 1 + (valToFreqs[val] ?? 0)
        valToFreqs[val] = freq
        var nums = freqToStacks[freq] ?? []
        nums.append(val)
        freqToStacks[freq] = nums
        maxFreq = max(maxFreq, freq)
    }
    
    func pop() -> Int {
        let val = freqToStacks[maxFreq]!.popLast()!
        if freqToStacks[maxFreq]!.isEmpty {
            maxFreq -= 1
        }
        valToFreqs[val] = valToFreqs[val]! - 1
        return val
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * let obj = FreqStack()
 * obj.push(val)
 * let ret_2: Int = obj.pop()
 */
// @lc code=end

func main() {
    /**
     输入：
     ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
     [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
     输出：[null,null,null,null,null,null,null,5,7,5,4]
     解释：
     FreqStack = new FreqStack();
     freqStack.push (5);//堆栈为 [5]
     freqStack.push (7);//堆栈是 [5,7]
     freqStack.push (5);//堆栈是 [5,7,5]
     freqStack.push (7);//堆栈是 [5,7,5,7]
     freqStack.push (4);//堆栈是 [5,7,5,7,4]
     freqStack.push (5);//堆栈是 [5,7,5,7,4,5]
     freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,5,7,4]。
     freqStack.pop ();//返回 7 ，因为 5 和 7 出现频率最高，但7最接近顶部。堆栈变成 [5,7,5,4]。
     freqStack.pop ();//返回 5 ，因为 5 出现频率最高。堆栈变成 [5,7,4]。
     freqStack.pop ();//返回 4 ，因为 4, 5 和 7 出现频率最高，但 4 是最接近顶部的。堆栈变成 [5,7]。
     */
    let freqStack = FreqStack()
    freqStack.push(5)
    freqStack.push(7)
    freqStack.push(5)
    freqStack.push(7)
    freqStack.push(4)
    freqStack.push(5)
    assert(5 == freqStack.pop())
    assert(7 == freqStack.pop())
    assert(5 == freqStack.pop())
    assert(4 == freqStack.pop())
}
