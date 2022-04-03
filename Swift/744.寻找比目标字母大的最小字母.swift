/*
 * @lc app=leetcode.cn id=744 lang=swift
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
    func nextGreatestLetter(_ letters: [Character], _ target: Character) -> Character {
        var l = 0, r = letters.count - 1
        while l < r {
            let mid = (l + r) >> 1
            if letters[mid] > target {
                r = mid
            } else {
                l = mid + 1
            }
        }
        return letters[r] > target ? letters[r] : letters[0]
    }
}
// @lc code=end

func main() {
    var letters: [Character]
    var target: Character
    var res: Character
    
    /**
     输入: letters = ["c", "f", "j"]，target = "a"
     输出: "c"
     */
    letters = ["c", "f", "j"]
    target = "a"
    res = "c"
    assert(res == Solution().nextGreatestLetter(letters, target));
    
    /**
     输入: letters = ["c","f","j"], target = "c"
     输出: "f"
     */
    letters = ["c","f","j"]
    target = "c"
    res = "f"
    assert(res == Solution().nextGreatestLetter(letters, target));
    
    /**
     输入: letters = ["c","f","j"], target = "d"
     输出: "f"
     */
    letters = ["c","f","j"]
    target = "d"
    res = "f"
    assert(res == Solution().nextGreatestLetter(letters, target))
}
