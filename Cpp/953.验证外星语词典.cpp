/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> ord(26, 0);
        for (int i = 0; i < 26; ++i) {
            ord[order[i] - 'a'] = i;
        }
        vector<string> clone = words;
        sort(clone.begin(), clone.end(), [ord](const string& a, const string& b) {
            int m = (int)a.size(), n = (int)b.size();
            int i = 0, j = 0;
            while (i < m && j < n) {
                int c1 = a[i] - 'a', c2 = b[j] - 'a';
                if (c1 != c2) return ord[c1] < ord[c2];
                ++i; ++j;
            }
            if (i < n) return true;
            return false;
        });
        for (int i = 0; i < words.size(); ++i) {
            if (clone[i] != words[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    string order;
    bool res;
    
    /**
     输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
     输出：true
     解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
     */
    words = {"hello","leetcode"};
    order = "hlabcdefgijkmnopqrstuvwxyz";
    res = true;
    assert(res == Solution().isAlienSorted(words, order));
    
    /**
     输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
     输出：false
     解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
     */
    words = {"word","world","row"};
    order = "worldabcefghijkmnpqstuvxyz";
    res = false;
    assert(res == Solution().isAlienSorted(words, order));
    
    /**
     输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
     输出：false
     解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
     */
    words = {"apple","app"};
    order = "abcdefghijklmnopqrstuvwxyz";
    res = false;
    assert(res == Solution().isAlienSorted(words, order));
    
    cout << "OK~" << endl;
    
    return 0;
}
