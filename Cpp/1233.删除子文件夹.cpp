/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 *
 * [1233] 删除子文件夹
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};
        for (int i = 1; i < folder.size(); ++i) {
            string pre = ans.end()[-1];
            int preSize = (int)pre.size();
            if (!(preSize < folder[i].size() && pre == folder[i].substr(0, preSize) && folder[i][preSize] == '/')) {
                ans.push_back(folder[i]);
            }
        }
        return ans;
        
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> folder;
    vector<string> res;
    
    /**
     输入：folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
     输出：["/a","/c/d","/c/f"]
     解释："/a/b/" 是 "/a" 的子文件夹，而 "/c/d/e" 是 "/c/d" 的子文件夹。
     */
    folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    res = {"/a","/c/d","/c/f"};
    assert(res == Solution().removeSubfolders(folder));
    
    /**
     输入：folder = ["/a","/a/b/c","/a/b/d"]
     输出：["/a"]
     解释：文件夹 "/a/b/c" 和 "/a/b/d/" 都会被删除，因为它们都是 "/a" 的子文件夹。
     */
    folder = {"/a","/a/b/c","/a/b/d"};
    res = {"/a"};
    assert(res == Solution().removeSubfolders(folder));
    
    /**
     输入: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
     输出: ["/a/b/c","/a/b/ca","/a/b/d"]
     */
    folder = {"/a/b/c","/a/b/ca","/a/b/d"};
    res = {"/a/b/c","/a/b/ca","/a/b/d"};
    assert(res == Solution().removeSubfolders(folder));

    cout << "OK~" << endl;
    
    return 0;
}
