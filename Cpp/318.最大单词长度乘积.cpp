/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> maskToLen;
        for (string& word : words) {
            int flag = 0;
            for (auto c : word) {
                flag |= 1 << (c - 'a');
            }
            maskToLen[flag] = max(maskToLen[flag], (int)word.length());
        }
        int ans = 0;
        for (auto a : maskToLen) {
            for (auto b : maskToLen) {
                if ((a.first & b.first) == 0) {
                    ans = max(ans, a.second * b.second);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    int res;
    
    /**
     输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
     输出: 16
     解释: 这两个单词为 "abcw", "xtfn"。
     */
    words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    res = 16;
    assert(res == Solution().maxProduct(words));

    /**
     输入: ["a","ab","abc","d","cd","bcd","abcd"]
     输出: 4
     解释: 这两个单词为 "ab", "cd"。
     */
    words = {"a","ab","abc","d","cd","bcd","abcd"};
    res = 4;
    assert(res == Solution().maxProduct(words));

    /**
     输入: ["a","aa","aaa","aaaa"]
     输出: 0
     解释: 不存在这样的两个单词。
     */
    words = {"a","aa","aaa","aaaa"};
    res = 0;
    assert(res == Solution().maxProduct(words));
    
    /**
     输入: ["bdcecbcadca","caafd","bcadc","eaedfcd","fcdecf","dee","bfedd","ffafd","eceaffa","caabe","fbdb","acafbccaa","cdc","ecfdebaafde","cddbabf","adc","cccce","cbbe","beedf","fafbfdcb","ceecfabedbd","aadbedeaf","cffdcfde","fbbdfdccce","ccada","fb","fa","ec","dddafded","accdda","acaad","ba","dabe","cdfcaa","caadfedd","dcdcab","fadbabace","edfdb","dbaaffdfa","efdffceeeb","aefdf","fbadcfcc","dcaeddd","baeb","beddeed","fbfdffa","eecacbbd","fcde","fcdb","eac","aceffea","ebabfffdaab","eedbd","fdeed","aeb","fbb","ad","bcafdabfbdc","cfcdf","deadfed","acdadbdcdb","fcbdbeeb","cbeb","acbcafca","abbcbcbaef","aadcafddf","bd","edcebadec","cdcbabbdacc","adabaea","dcebf","ffacdaeaeeb","afedfcadbb","aecccdfbaff","dfcfda","febb","bfffcaa","dffdbcbeacf","cfa","eedeadfafd","fcaa","addbcad","eeaaa","af","fafc","bedbbbdfae","adfecadcabe","efffdaa","bafbcbcbe","fcafabcc","ec","dbddd","edfaeabecee","fcbedad","abcddfbc","afdafb","afe","cdad","abdffbc","dbdbebdbb"]
     输出: 45
     */
    words = {"bdcecbcadca","caafd","bcadc","eaedfcd","fcdecf","dee","bfedd","ffafd","eceaffa","caabe","fbdb","acafbccaa","cdc","ecfdebaafde","cddbabf","adc","cccce","cbbe","beedf","fafbfdcb","ceecfabedbd","aadbedeaf","cffdcfde","fbbdfdccce","ccada","fb","fa","ec","dddafded","accdda","acaad","ba","dabe","cdfcaa","caadfedd","dcdcab","fadbabace","edfdb","dbaaffdfa","efdffceeeb","aefdf","fbadcfcc","dcaeddd","baeb","beddeed","fbfdffa","eecacbbd","fcde","fcdb","eac","aceffea","ebabfffdaab","eedbd","fdeed","aeb","fbb","ad","bcafdabfbdc","cfcdf","deadfed","acdadbdcdb","fcbdbeeb","cbeb","acbcafca","abbcbcbaef","aadcafddf","bd","edcebadec","cdcbabbdacc","adabaea","dcebf","ffacdaeaeeb","afedfcadbb","aecccdfbaff","dfcfda","febb","bfffcaa","dffdbcbeacf","cfa","eedeadfafd","fcaa","addbcad","eeaaa","af","fafc","bedbbbdfae","adfecadcabe","efffdaa","bafbcbcbe","fcafabcc","ec","dbddd","edfaeabecee","fcbedad","abcddfbc","afdafb","afe","cdad","abdffbc","dbdbebdbb"};
    res = 45;
    assert(res == Solution().maxProduct(words));

    cout << "OK~" << endl;

    return 0;
}
