//
//  5838.检查字符串是否为数组前缀.cpp
//  Cpp
//
//  Created by warden on 2021/8/8.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0;
        for (string word : words) {
            if (s.length() - i < word.size()) return false;
            for (int j = 0; j < word.size(); j++) {
                if (word[j] != s[i]) return false;
                i++;
                
             }
            if (i == s.length()) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    Solution solution;
    
    words = {"i", "love", "leetcode", "apples"};
    // true
    cout << solution.isPrefixString("iloveleetcode", words) << endl;
    
    words = {"apples","i","love","leetcode"};
    // false
    cout << solution.isPrefixString("iloveleetcode", words) << endl;
    
    words = {"aa","aaaa","banana"};
    // false
    cout << solution.isPrefixString("a", words) << endl;
    
    words = {"c","cc"};
    // false
    cout << solution.isPrefixString("cccccc", words) << endl;
    
    return 0;
}
