/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> toSet;
        for (string& email : emails) {
            string name = "";
            int i = 0;
            bool ok = true;
            while (i < email.size()) {
                if (email[i] == '@') break;
                if (email[i] == '.' && ++i >= 0) continue;
                if (email[i] == '+') ok = false;
                if (ok) name.push_back(email[i]);
                ++i;
            }
            toSet.insert(name + email.substr(i));
        }
        return (int)toSet.size();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> emails;
    int res;
    
    /**
     输入：emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
     输出：2
     解释：实际收到邮件的是 "testemail@leetcode.com" 和 "testemail@lee.tcode.com"。
     */
    emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    res = 2;
    assert(res == Solution().numUniqueEmails(emails));
    
    /**
     输入：emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
     输出：3
     */
    emails = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
    res = 3;
    assert(res == Solution().numUniqueEmails(emails));

    cout << "OK~" << endl;
    
    return 0;
}

