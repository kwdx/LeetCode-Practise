/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string reorderSpaces(string text) {
        int n = (int)text.size();
        vector<string> words;
        int spaces = n;
        string word;
        for (char &c : text) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.emplace_back(word);
                    word.clear();
                }
            } else {
                word.push_back(c);
                --spaces;
            }
        }
        if (!word.empty()) {
            words.emplace_back(word);
        }
        int cnt;
        if (words.size() == 1) {
            cnt = spaces;
        } else {
            cnt = spaces / (words.size() - 1);
        }
        string ans = words[0];
        string spaceStr = string(cnt, ' ');
        for (int i = 1; i < words.size(); ++i) {
            ans += spaceStr + words[i];
        }
        while (ans.size() < n) {
            ans.push_back(' ');
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string text;
    string res;
    
    /**
     输入：text = "  this   is  a sentence "
     输出："this   is   a   sentence"
     解释：总共有 9 个空格和 4 个单词。可以将 9 个空格平均分配到相邻单词之间，相邻单词间空格数为：9 / (4-1) = 3 个。
     */
    text = "  this   is  a sentence ";
    res = "this   is   a   sentence";
    assert(res == Solution().reorderSpaces(text));
    
    /**
     输入：text = " practice   makes   perfect"
     输出："practice   makes   perfect "
     解释：总共有 7 个空格和 3 个单词。7 / (3-1) = 3 个空格加上 1 个多余的空格。多余的空格需要放在字符串的末尾。
     */
    text = " practice   makes   perfect";
    res = "practice   makes   perfect ";
    assert(res == Solution().reorderSpaces(text));
    
    /**
     输入：text = "hello   world"
     输出："hello   world"
     */
    text = "hello   world";
    res = "hello   world";
    assert(res == Solution().reorderSpaces(text));
    
    /**
     输入：text = "  walks  udp package   into  bar a"
     输出："walks  udp  package  into  bar  a "

     */
    text = "  walks  udp package   into  bar a";
    res = "walks  udp  package  into  bar  a ";
    assert(res == Solution().reorderSpaces(text));
    
    /**
     输入：text = "a"
     输出："a"
     */
    text = "a";
    res = "a";
    assert(res == Solution().reorderSpaces(text));

    cout << "OK~" << endl;
    
    return 0;
}
