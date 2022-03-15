/*
 * @lc app=leetcode.cn id=393 lang=cpp
 *
 * [393] UTF-8 编码验证
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = (int)data.size();
        for (int i = 0; i < n; ) {
            int val = data[i];
            int j = 7;
            while (j >= 0 and ((val >> j) & 1) == 1) --j;
            int cnt = 7 - j;
            if (cnt == 1 || cnt > 4) return false;
            if (i + cnt > n) return false;
            for (j = i + 1; j < i + cnt; ++j) {
                if (((data[j] >> 7 & 1) == 1) and (((data[j] >> 6) & 1) == 0)) continue;
                return false;
            }
            if (cnt == 0) ++i;
            else i += cnt;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> data;
    bool res;
    
    /**
     输入：data = [197,130,1]
     输出：true
     解释：数据表示字节序列:11000101 10000010 00000001。
     这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。
     */
    data = {197,130,1};
    res = true;
    assert(res == Solution().validUtf8(data));
    
    /**
     输入：data = [235,140,4]
     输出：false
     解释：数据表示 8 位的序列: 11101011 10001100 00000100.
     前 3 位都是 1 ，第 4 位为 0 表示它是一个 3 字节字符。
     下一个字节是开头为 10 的延续字节，这是正确的。
     但第二个延续字节不以 10 开头，所以是不符合规则的。
     */
    data = {235,140,4};
    res = false;
    assert(res == Solution().validUtf8(data));

    cout << "OK~" << endl;

    return 0;
}
