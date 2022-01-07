/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> paths;
        int n = (int)path.size();
        for (int i = 1; i < n;) {
            if (path[i] == '/' && ++i >= 0) continue;
            int j = i + 1;
            while (j < n && path[j] != '/') ++j;
            string item = path.substr(i, j - i);
            if (item == "..") {
                if (!paths.empty()) paths.pop_back();
            } else if (item != ".") {
                paths.push_back(item);
            }
            i = j;
        }
        string ans = "";
        while (!paths.empty()) {
            ans += "/" + paths.front();
            paths.pop_front();
        }
        return ans.size() == 0 ? "/" : ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string path;
    string res;
    
    /**
     输入：path = "/home/"
     输出："/home"
     解释：注意，最后一个目录名后面没有斜杠。
     */
    path = "/home/";
    res = "/home";
    assert(res == Solution().simplifyPath(path));
    
    /**
     输入：path = "/../"
     输出："/"
     解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。
     */
    path = "/../";
    res = "/";
    assert(res == Solution().simplifyPath(path));
    
    /**
     输入：path = "/home//foo/"
     输出："/home/foo"
     解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
     */
    path = "/home//foo/";
    res = "/home/foo";
    assert(res == Solution().simplifyPath(path));
    
    /**
     输入：path = "/a/./b/../../c/"
     输出："/c"
     */
    path = "/a/./b/../../c/";
    res = "/c";
    assert(res == Solution().simplifyPath(path));

    cout << "OK~" << endl;

    return 0;
}
