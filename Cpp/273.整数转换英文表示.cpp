/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<string> singles = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> tens = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tenZeroes = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string thousandNumToWords(int num) {
        stack<string> st;
        int single = num % 10;
        int ten = num / 10 % 10;
        int hundred = num / 100;
        if (single == 0 && ten == 0) {
            
        } else if (single == 0) {
            st.push(tenZeroes[ten - 1]);
        } else if (ten == 0) {
            st.push(singles[single - 1]);
        } else if (ten == 1) {
            st.push(tens[single - 1]);
        } else {
            st.push(singles[single - 1]);
            st.push(tenZeroes[ten - 1]);
        }
        if (hundred > 0) {
            st.push(singles[hundred - 1] + " Hundred");
        }
        string ans;
        while (!st.empty()) {
            ans += st.top() + " ";
            st.pop();
        }
        return ans;
    }
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        string ans;
        const int thousand = 1e3;
        const int million = 1e6;
        const int billion = 1e9;
        if (num >= billion) {
            ans += thousandNumToWords(num / billion) + "Billion ";
        }
        num %= billion;
        if (num >= million) {
            ans += thousandNumToWords(num / million) + "Million ";
        }
        num %= million;
        if (num >= thousand) {
            ans += thousandNumToWords(num / thousand) + "Thousand ";
        }
        num %= thousand;
        ans += thousandNumToWords(num);
        if (ans.size() > 0) {
            ans.pop_back();
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    int num;
    string res;
    string ans;

    /**
     输入：num = 123
     输出："One Hundred Twenty Three"
     */
    num = 123;
    res = "One Hundred Twenty Three";
    assert(res == Solution().numberToWords(num));
    
    /**
     输入：num = 12345
     输出："Twelve Thousand Three Hundred Forty Five"
     */
    num = 12345;
    res = "Twelve Thousand Three Hundred Forty Five";
    assert(res == Solution().numberToWords(num));
    
    /**
     输入：num = 1234567
     输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
     */
    num = 1234567;
    res = "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";
    assert(res == Solution().numberToWords(num));
    
    /**
     输入：num = 1234567891
     输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
     */
    num = 1234567891;
    res = "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One";
    assert(res == Solution().numberToWords(num));
    
    cout << "OK~" << endl;
    
    return 0;
}
