/*
 * @lc app=leetcode.cn id=318 lang=swift
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
    func maxProduct(_ words: [String]) -> Int {
        var maskToLen: [Int: Int] = [:]
        var flag = 0
        for word in words {
            flag = 0
            word.forEach { c in
                if let val = c.asciiValue, val - 97 >= 0 {
                    flag |= 1 << (val - 97)
                }
            }
            maskToLen[flag] = max(maskToLen[flag] ?? 0, word.count)
        }
        
        var ans = 0
        for a in maskToLen {
            for b in maskToLen {
                if (a.key & b.key) == 0 {
                    ans = max(ans, a.value * b.value)
                }
            }
        }
        return ans
    }
}
// @lc code=end

func main() {
    var words: [String]
    var res: Int
    
    /**
     输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
     输出: 16
     解释: 这两个单词为 "abcw", "xtfn"。
     */
    words = ["abcw","baz","foo","bar","xtfn","abcdef"]
    res = 16
    assert(res == Solution().maxProduct(words))

    /**
     输入: ["a","ab","abc","d","cd","bcd","abcd"]
     输出: 4
     解释: 这两个单词为 "ab", "cd"。
     */
    words = ["a","ab","abc","d","cd","bcd","abcd"]
    res = 4
    assert(res == Solution().maxProduct(words))

    /**
     输入: ["a","aa","aaa","aaaa"]
     输出: 0
     解释: 不存在这样的两个单词。
     */
    words = ["a","aa","aaa","aaaa"]
    res = 0
    assert(res == Solution().maxProduct(words))
    
    /**
     输入: ["bdcecbcadca","caafd","bcadc","eaedfcd","fcdecf","dee","bfedd","ffafd","eceaffa","caabe","fbdb","acafbccaa","cdc","ecfdebaafde","cddbabf","adc","cccce","cbbe","beedf","fafbfdcb","ceecfabedbd","aadbedeaf","cffdcfde","fbbdfdccce","ccada","fb","fa","ec","dddafded","accdda","acaad","ba","dabe","cdfcaa","caadfedd","dcdcab","fadbabace","edfdb","dbaaffdfa","efdffceeeb","aefdf","fbadcfcc","dcaeddd","baeb","beddeed","fbfdffa","eecacbbd","fcde","fcdb","eac","aceffea","ebabfffdaab","eedbd","fdeed","aeb","fbb","ad","bcafdabfbdc","cfcdf","deadfed","acdadbdcdb","fcbdbeeb","cbeb","acbcafca","abbcbcbaef","aadcafddf","bd","edcebadec","cdcbabbdacc","adabaea","dcebf","ffacdaeaeeb","afedfcadbb","aecccdfbaff","dfcfda","febb","bfffcaa","dffdbcbeacf","cfa","eedeadfafd","fcaa","addbcad","eeaaa","af","fafc","bedbbbdfae","adfecadcabe","efffdaa","bafbcbcbe","fcafabcc","ec","dbddd","edfaeabecee","fcbedad","abcddfbc","afdafb","afe","cdad","abdffbc","dbdbebdbb"]
     输出: 45
     */
    words = ["bdcecbcadca","caafd","bcadc","eaedfcd","fcdecf","dee","bfedd","ffafd","eceaffa","caabe","fbdb","acafbccaa","cdc","ecfdebaafde","cddbabf","adc","cccce","cbbe","beedf","fafbfdcb","ceecfabedbd","aadbedeaf","cffdcfde","fbbdfdccce","ccada","fb","fa","ec","dddafded","accdda","acaad","ba","dabe","cdfcaa","caadfedd","dcdcab","fadbabace","edfdb","dbaaffdfa","efdffceeeb","aefdf","fbadcfcc","dcaeddd","baeb","beddeed","fbfdffa","eecacbbd","fcde","fcdb","eac","aceffea","ebabfffdaab","eedbd","fdeed","aeb","fbb","ad","bcafdabfbdc","cfcdf","deadfed","acdadbdcdb","fcbdbeeb","cbeb","acbcafca","abbcbcbaef","aadcafddf","bd","edcebadec","cdcbabbdacc","adabaea","dcebf","ffacdaeaeeb","afedfcadbb","aecccdfbaff","dfcfda","febb","bfffcaa","dffdbcbeacf","cfa","eedeadfafd","fcaa","addbcad","eeaaa","af","fafc","bedbbbdfae","adfecadcabe","efffdaa","bafbcbcbe","fcafabcc","ec","dbddd","edfaeabecee","fcbedad","abcddfbc","afdafb","afe","cdad","abdffbc","dbdbebdbb"]
    res = 45
    assert(res == Solution().maxProduct(words))
}
