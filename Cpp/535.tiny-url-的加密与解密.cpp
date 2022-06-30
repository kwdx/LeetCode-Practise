/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
private:
    unordered_map<int, string> dataBase;
public:

    Solution() {
        srand((unsigned int)time(0));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int key;
        while (true) {
            key = rand();
            if (dataBase.count(key) == 0) {
                dataBase[key] = longUrl;
                break;
            }
        }
        return "http://tinyurl.com/" + to_string(key);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int p = (int)shortUrl.rfind("/") + 1;
        if (p == -1) {
            return "";
        }
        int key = stoi(shortUrl.substr(p, (int)shortUrl.length() - p));
        return dataBase[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：url = "https://leetcode.com/problems/design-tinyurl"
     输出："https://leetcode.com/problems/design-tinyurl"

     解释：
     Solution obj = new Solution();
     string tiny = obj.encode(url); // 返回加密后得到的 TinyURL 。
     string ans = obj.decode(tiny); // 返回解密后得到的原本的 URL 。
     */
    string url = "https://leetcode.com/problems/design-tinyurl";
    Solution obj;
    string tiny = obj.encode(url);  // 返回加密后得到的 TinyURL 。
    string ans = obj.decode(tiny);  // 返回解密后得到的原本的 URL 。
    assert(url == ans);
    
    cout << "OK~" << endl;
    
    return 0;
}
