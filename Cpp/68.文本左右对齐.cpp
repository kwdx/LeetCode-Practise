/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        queue<string> q;
        int cap = 0;
        for (int i = 0; i < words.size();) {
            cap = maxWidth;
            while (i < words.size() && (int)words[i].size() <= cap) {
                q.push(words[i]);
                cap -= words[i].size() + 1;
                i += 1;
            }
            int spaces = cap + (int)q.size();
            int space;
            if (q.size() > 1) {
                space = spaces / ((int)q.size() - 1);
                spaces -= space * ((int)q.size() - 1);
            } else {
                space = spaces;
                spaces = 0;
            }
            if (i == words.size()) {
                // 最后一行
                space = 1;
                spaces = 0;
            }
            string s;
            while (!q.empty()) {
                s += q.front();
                q.pop();
                for (int j = 0; j < space && s.size() < maxWidth; j++) {
                    s.push_back(' ');
                }
                if (spaces > 0) {
                    s.push_back(' ');
                    spaces -= 1;
                }
            }
            while (s.size() < maxWidth) {
                s.push_back(' ');
            }
            res.push_back(s);
        }
        return res;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {

    vector<string> words, res;
    int maxWidth;

    /**
     输入:
     words = ["This", "is", "an", "example", "of", "text", "justification."]
     maxWidth = 16
     输出:
     [
        "This    is    an",
        "example  of text",
        "justification.  "
     ]
     */
    words = {"This", "is", "an", "example", "of", "text", "justification."};
    maxWidth = 16;
    res = {
        "This    is    an",
        "example  of text",
        "justification.  "
    };
    assert(res == Solution().fullJustify(words, maxWidth));

    /**
     输入:
     words = ["What","must","be","acknowledgment","shall","be"]
     maxWidth = 16
     输出:
     [
       "What   must   be",
       "acknowledgment  ",
       "shall be        "
     ]
     解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
          因为最后一行应为左对齐，而不是左右两端对齐。
          第二行同样为左对齐，这是因为这行只包含一个单词。
     */
    words = {"What","must","be","acknowledgment","shall","be"};
    maxWidth = 16;
    res = {
        "What   must   be",
        "acknowledgment  ",
        "shall be        "
    };
    assert(res == Solution().fullJustify(words, maxWidth));

    /**
     输入:
     words = ["Science","is","what","we","understand","well","enough","to","explain",
              "to","a","computer.","Art","is","everything","else","we","do"]
     maxWidth = 20
     输出:
     [
       "Science  is  what we",
       "understand      well",
       "enough to explain to",
       "a  computer.  Art is",
       "everything  else  we",
       "do                  "
     ]
     */
    words = {"Science","is","what","we","understand","well","enough","to","explain",
        "to","a","computer.","Art","is","everything","else","we","do"};
    maxWidth = 20;
    res = {
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  "
    };
    assert(res == Solution().fullJustify(words, maxWidth));

    /**
     输入:
     words = ["ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"]
     maxWidth = 16
     输出:
     ["ask   not   what","your country can","do  for  you ask","what  you can do","for your country"]
     */
    words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    maxWidth = 16;
    res = {
        "ask   not   what",
        "your country can",
        "do  for  you ask",
        "what  you can do",
        "for your country"
    };
    assert(res == Solution().fullJustify(words, maxWidth));
    
    /**
     输入:
     words = ["My","momma","always","said,","\"Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."]
     maxWidth = 20
     输出:
     ["My    momma   always","said, \"Life was like","a box of chocolates.","You  never know what","you're gonna get.   "]
     */
    words = {"My","momma","always","said,","\"Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."};
    maxWidth = 20;
    res = {
        "My    momma   always",
        "said, \"Life was like",
        "a box of chocolates.",
        "You  never know what",
        "you're gonna get.   "
    };
    assert(res == Solution().fullJustify(words, maxWidth));

    cout << "OK~" << endl;
    
    return 0;
}
