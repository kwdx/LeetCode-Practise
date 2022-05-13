//
//  A.面试题-01.05-一次编辑.swift
//  swift_
//
//  Created by kingsoft on 2022/5/13.
//

import Foundation

// @lc code=start
class Solution {
    func oneEditAway(_ first: String, _ second: String) -> Bool {
        guard abs(first.count - second.count) <= 1 else {
            return false
        }
        var ans = 0
        let chars1 = Array(first)
        let chars2 = Array(second)
        if first.count == second.count {
            var i = 0
            while i < first.count && ans <= 1 {
                if chars1[i] != chars2[i] {
                    ans += 1
                }
                i += 1
            }
        } else {
            var i = 0, j = 0
            while i < first.count && j < second.count && ans <= 1{
                if chars1[i] == chars2[j] {
                    i += 1
                    j += 1
                } else {
                    if chars1.count < chars2.count {
                        j += 1
                    } else {
                        i += 1
                    }
                    ans += 1
                }
            }
        }
        
        return ans <= 1
    }
}
// @lc code=end

func main() {
    // insert code here...
    
    var first: String
    var second: String
    var res: Bool
    
    /**
     输入:
     first = "pale"
     second = "ple"
     输出: True
     */
    first = "pale"
    second = "ple"
    res = true
    assert(res == Solution().oneEditAway(first, second))
    
    /**
     输入：
     first = "pales"
     second = "pal"
     输出: False
     */
    first = "pales"
    second = "pal"
    res = false
    assert(res == Solution().oneEditAway(first, second))
    
    /**
     输入：
     first = "islander"
     second = "slander"
     输出: False
     */
    first = "islander"
    second = "slander"
    res = true
    assert(res == Solution().oneEditAway(first, second))
}
