/*
 * @lc app=leetcode.cn id=591 lang=cpp
 *
 * [591] 标签验证器
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
private:
    const string CDATA1 = "<![CDATA[", CDATA2 = "]]>";
public:
    bool isValid(string code) {
        int n = (int)code.size();
        int i = 0;
        deque<string> dq;
        while (i < n) {
            if (i + 8 < n && code.substr(i, 9) == CDATA1) {
                // 尝试解析 CDATA
                if (i == 0) return false;
                int j = i + 9;
                bool isOK = false;
                while (j < n && !isOK) {
                    if (j + 2 < n && code.substr(j, 3) == CDATA2) {
                        j = j + 3;
                        isOK = true;
                    } else {
                        ++j;
                    }
                }
                if (!isOK) return false;
                i = j;
            } else if (code[i] == '<') {
                if (i == n - 1) return false;
                bool isEnd = code[i + 1] == '/';
                int p = isEnd ? i + 2 : i + 1;
                int j = p;
                while (j < n && code[j] != '>') {
                    if (!isupper(code[j])) return false;
                    ++j;
                }
                if (j == n) return false;
                int len = j - p;
                if (len < 1 || len > 9) return false;
                string tag = code.substr(p, j - p);
                i = j + 1;
                if (!isEnd) {
                    dq.push_back(tag);
                } else {
                    if (dq.empty()) return false;
                    if (dq.back() != tag) return false;
                    dq.pop_back();
                    if (dq.empty() && i < n) return false;
                }
            } else {
                if (i == 0) return false;
                ++i;
            }
        }
        return dq.empty();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string code;
    bool res;
    
    /**'
     输入: "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
     输出: True
     解释:
     代码被包含在了闭合的标签内： <DIV> 和 </DIV> 。
     TAG_NAME 是合法的，TAG_CONTENT 包含了一些字符和 cdata 。
     即使 CDATA_CONTENT 含有不匹配的起始标签和不合法的 TAG_NAME，它应该被视为普通的文本，而不是标签。
     所以 TAG_CONTENT 是合法的，因此代码是合法的。最终返回True。
     */
    code = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    res = true;
    assert(res == Solution().isValid(code));

    /**
     输入: "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"
     输出: True
     解释:
     我们首先将代码分割为： start_tag|tag_content|end_tag 。
     start_tag -> "<DIV>"
     end_tag -> "</DIV>"
     tag_content 也可被分割为： text1|cdata|text2 。
     text1 -> ">>  ![cdata[]] "
     cdata -> "<![CDATA[<div>]>]]>" ，其中 CDATA_CONTENT 为 "<div>]>"
     text2 -> "]]>>]"

     start_tag 不是 "<DIV>>>" 的原因参照规则 6 。
     cdata 不是 "<![CDATA[<div>]>]]>]]>" 的原因参照规则 7 。
     */
    code = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
    res = true;
    assert(res == Solution().isValid(code));
    
    /**'
     输入: "<A>  <B> </A>   </B>"
     输出: False
     解释: 不合法。如果 "<A>" 是闭合的，那么 "<B>" 一定是不匹配的，反之亦然。
     */
    code = "<A>  <B> </A>   </B>";
    res = false;
    assert(res == Solution().isValid(code));
    
    /**
     输入: "<DIV>  div tag is not closed  <DIV>"
     输出: False
     */
    code = "<DIV>  div tag is not closed  <DIV>";
    res = false;
    assert(res == Solution().isValid(code));
    
    /**
     输入: "<DIV>  unmatched <  </DIV>"
     输出: False
     */
    code = "<DIV>  unmatched <  </DIV>";
    res = false;
    assert(res == Solution().isValid(code));
    
    /**
     输入: "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>"
     输出: False
     */
    code =  "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>";
    res = false;
    assert(res == Solution().isValid(code));
    
    /**
     输入: "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>"
     输出: False
     */
    code = "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>";
    res = false;
    assert(res == Solution().isValid(code));
    
    /**
     输入: "<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>"
     输出: False
     */
    code = "<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>";
    res = false;
    assert(res == Solution().isValid(code));
    
    cout << "OK~" << endl;
    
    return 0;
}
