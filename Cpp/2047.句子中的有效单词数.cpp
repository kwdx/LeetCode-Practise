/*
 * @lc app=leetcode.cn id=2047 lang=cpp
 *
 * [2047] 句子中的有效单词数
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int countValidWords(string sentence) {
        int ans = 0;
        string token;
        for (char c : sentence) {
            if (c == ' ') {
                ans += check(token) ? 1 : 0;
                token = "";
            } else {
                token += c;
            }
        }
        ans += check(token) ? 1 : 0;
        return ans;
    }
    
    bool check(const string& work) {
        int n = (int)work.size();
        if (n == 0) return false;
        bool flag = false;
        unordered_set<char> masks = {'!', ',', '.'};
        for (int i = 0; i < n; ++i) {
            char c = work[i];
            if ('0' <= c && c <= '9') return false;
            switch (c) {
                case ' ':
                    return false;
                case '!':
                case '.':
                case ',':
                    return i == n - 1;
                case '-':
                    if (flag || i == 0 || i == n - 1 || masks.count(work[i - 1]) || masks.count(work[i + 1])) {
                        return false;
                    } else {
                        flag = true;
                    }
                    break;
                default:
                    break;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string sentence;
    int res;
    
    /**
     输入：sentence = "cat and  dog"
     输出：3
     解释：句子中的有效单词是 "cat"、"and" 和 "dog"
     */
    sentence = "cat and  dog";
    res = 3;
    assert(res == Solution().countValidWords(sentence));

    /**
     输入：sentence = "!this  1-s b8d!"
     输出：0
     解释：句子中没有有效单词
     "!this" 不是有效单词，因为它以一个标点开头
     "1-s" 和 "b8d" 也不是有效单词，因为它们都包含数字
     */
    sentence = "!this  1-s b8d!";
    res = 0;
    assert(res == Solution().countValidWords(sentence));

    /**
     输入：sentence = "alice and  bob are playing stone-game10"
     输出：5
     解释：句子中的有效单词是 "alice"、"and"、"bob"、"are" 和 "playing"
     "stone-game10" 不是有效单词，因为它含有数字
     */
    sentence = "alice and  bob are playing stone-game10";
    res = 5;
    assert(res == Solution().countValidWords(sentence));

    /**
     输入：sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."
     输出：6
     解释：句子中的有效单词是 "he"、"bought"、"pencils,"、"erasers,"、"and" 和 "pencil-sharpener."
     */
    sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.";
    res = 6;
    assert(res == Solution().countValidWords(sentence));
    
    sentence = " 62   nvtk0wr4f  8 qt3r! w1ph 1l ,e0d 0n 2v 7c.  n06huu2n9 s9   ui4 nsr!d7olr  q-, vqdo!btpmtmui.bb83lf g .!v9-lg 2fyoykex uy5a 8v whvu8 .y sc5 -0n4 zo pfgju 5u 4 3x,3!wl  fv4   s  aig cf j1 a i  8m5o1  !u n!.1tz87d3 .9    n a3  .xb1p9f  b1i a j8s2 cugf l494cx1! hisceovf3 8d93 sg 4r.f1z9w   4- cb r97jo hln3s h2 o .  8dx08as7l!mcmc isa49afk i1 fk,s e !1 ln rt2vhu 4ks4zq c w  o- 6  5!.n8ten0 6mk 2k2y3e335,yj  h p3 5 -0  5g1c  tr49, ,qp9 -v p  7p4v110926wwr h x wklq u zo 16. !8  u63n0c l3 yckifu 1cgz t.i   lh w xa l,jt   hpi ng-gvtk8 9 j u9qfcd!2  kyu42v dmv.cst6i5fo rxhw4wvp2 1 okc8!  z aribcam0  cp-zp,!e x  agj-gb3 !om3934 k vnuo056h g7 t-6j! 8w8fncebuj-lq    inzqhw v39,  f e 9. 50 , ru3r  mbuab  6  wz dw79.av2xp . gbmy gc s6pi pra4fo9fwq k   j-ppy -3vpf   o k4hy3 -!..5s ,2 k5 j p38dtd   !i   b!fgj,nx qgif ";
    res = 49;
    assert(res == Solution().countValidWords(sentence));

    cout << "OK~" << endl;

    return 0;
}
