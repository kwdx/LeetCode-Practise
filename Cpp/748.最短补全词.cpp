/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> getCnts(string word) {
        vector<int> cnts(26);
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                ++cnts[c - 97];
            } else if (c >= 'A' && c <= 'Z') {
                ++cnts[c - 65];
            }
        }
        return cnts;
    }
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string ans;
        vector<int> cnts = getCnts(licensePlate);
        for (string word : words) {
            vector<int> cur = getCnts(word);
            bool isContains = true;
            for (int i = 0; i < 26; ++i) {
                if (cnts[i] > cur[i]) {
                    isContains = false;
                    break;
                }
            }
            if (isContains && (ans.length() == 0 || word.length() < ans.length())) {
                ans = word;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string licensePlate;
    vector<string> words;
    string res;
    
    /**
     输入：licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
     输出："steps"
     解释：最短补全词应该包括 "s"、"p"、"s"（忽略大小写） 以及 "t"。
     "step" 包含 "t"、"p"，但只包含一个 "s"，所以它不符合条件。
     "steps" 包含 "t"、"p" 和两个 "s"。
     "stripe" 缺一个 "s"。
     "stepple" 缺一个 "s"。
     因此，"steps" 是唯一一个包含所有字母的单词，也是本例的答案。
     */
    licensePlate = "1s3 PSt";
    words = {"step", "steps", "stripe", "stepple"};
    res = "steps";
    assert(res == Solution().shortestCompletingWord(licensePlate, words));
    
    /**
     输入：licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
     输出："pest"
     解释：licensePlate 只包含字母 "s" 。所有的单词都包含字母 "s" ，其中 "pest"、"stew"、和 "show" 三者最短。答案是 "pest" ，因为它是三个单词中在 words 里最靠前的那个。
     */
    licensePlate = "1s3 456";
    words = {"looks", "pest", "stew", "show"};
    res = "pest";
    assert(res == Solution().shortestCompletingWord(licensePlate, words));
    
    /**
     输入：licensePlate = "Ah71752", words = ["suggest","letter","of","husband","easy","education","drug","prevent","writer","old"]
     输出："husband"
     */
    licensePlate = "Ah71752";
    words = {"suggest","letter","of","husband","easy","education","drug","prevent","writer","old"};
    res = "husband";
    assert(res == Solution().shortestCompletingWord(licensePlate, words));
    
    /**
     输入：licensePlate = "OgEu755", words = ["enough","these","play","wide","wonder","box","arrive","money","tax","thus"]
     输出："enough"
     */
    licensePlate = "OgEu755";
    words = {"enough","these","play","wide","wonder","box","arrive","money","tax","thus"};
    res = "enough";
    assert(res == Solution().shortestCompletingWord(licensePlate, words));
    
    /**
     输入：licensePlate = "iMSlpe4", words = ["claim","consumer","student","camera","public","never","wonder","simple","thought","use"]
     输出："simple"
     */
    licensePlate = "iMSlpe4";
    words = {"claim","consumer","student","camera","public","never","wonder","simple","thought","use"};
    res = "simple";
    assert(res == Solution().shortestCompletingWord(licensePlate, words));

    cout << "OK~" << endl;

    return 0;
}
