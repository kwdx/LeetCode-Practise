/*
 * @lc app=leetcode.cn id=715 lang=swift
 *
 * [715] Range 模块
 */

// @lc code=start

class RangeModule {
    
    var ranges: [(begin: Int, end: Int)] = []

    init() {
        
    }
    
    func addRange(_ left: Int, _ right: Int) {
        var newRanges: [(begin: Int, end: Int)] = []
        var inserted = false
        var begin = left
        var end = right
        for range in ranges {
            if range.begin > end, !inserted {
                newRanges.append((begin, end))
                inserted = true
            }
            
            if range.end < begin || range.begin > end {
                newRanges.append(range)
            } else {
                begin = min(range.begin, begin)
                end = max(range.end, end)
            }
        }
        
        if !inserted {
            newRanges.append((begin, end))
        }
        
        ranges = newRanges
    }
    
    func queryRange(_ left: Int, _ right: Int) -> Bool {
        var l = 0
        var r = ranges.count
        
        while l < r {
            let mid = (l + r) / 2
            let range = ranges[mid]
            
            if range.begin > right {
                r = mid
            } else if range.end < left {
                l = mid + 1
            } else {
                return range.begin <= left && range.end >= right
            }
        }
        
        return false
    }
    
    func removeRange(_ left: Int, _ right: Int) {
        var newRanges: [(begin: Int, end: Int)] = []
        for range in ranges {
            if range.begin >= right || range.end <= left {
                newRanges.append(range)
            } else {
                if range.begin < left {
                    newRanges.append((range.begin, left))
                }
                
                if range.end > right {
                    newRanges.append((right, range.end))
                }
            }
        }
        
        ranges = newRanges
    }
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * let obj = RangeModule()
 * obj.addRange(left, right)
 * let ret_2: Bool = obj.queryRange(left, right)
 * obj.removeRange(left, right)
 */
// @lc code=end

func main() {
    /**
     输入
     ["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
     [[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
     输出
     [null, null, null, true, false, true]

     解释
     RangeModule rangeModule = new RangeModule();
     rangeModule.addRange(10, 20);
     rangeModule.removeRange(14, 16);
     rangeModule.queryRange(10, 14); 返回 true （区间 [10, 14) 中的每个数都正在被跟踪）
     rangeModule.queryRange(13, 15); 返回 false（未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
     rangeModule.queryRange(16, 17); 返回 true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）
     */
    let rangeModule = RangeModule()
    rangeModule.addRange(10, 20)
    rangeModule.removeRange(14, 16)
    assert(rangeModule.queryRange(10, 14))  // 返回 true （区间 [10, 14) 中的每个数都正在被跟踪）
    assert(!rangeModule.queryRange(13, 15)) // 返回 false（未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
    assert(rangeModule.queryRange(16, 17))  // 返回 true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）
}
