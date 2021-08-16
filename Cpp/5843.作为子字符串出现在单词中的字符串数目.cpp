//
//  5843.作为子字符串出现在单词中的字符串数目.cpp
//  Cpp
//
//  Created by warden on 2021/8/15.
//
// https://leetcode-cn.com/problems/number-of-strings-that-appear-as-substrings-in-word/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int num = 0;
        map<char, vector<int>> indexMaps;
        
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            vector<int> indexes;
            if (indexMaps.find(ch) != indexMaps.end()) {
                indexes = indexMaps[ch];
            }
            indexes.push_back(i);
            indexMaps[ch] = indexes;
        }
        
        for (string pattern : patterns) {
            if (indexMaps.find(pattern[0]) != indexMaps.end()) {
                vector<int> indexes = indexMaps[pattern[0]];
                for (int i = 0; i < indexes.size(); i++) {
                    int startIndex = indexes[i];
                    int j = 0;
                    for (j = 0; j < pattern.size(); j++) {
                        if (pattern[j] != word[j + startIndex]) {
                            break;
                        }
                    }
                    if (j == pattern.size()) {
                        num ++;
                        break;;
                    }
                }
            }
            
        }
        
        return num;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
    vector<string> patterns;
    string word;
    
    patterns = {"a","abc","bc","d"};
    word = "abc";
    // 3
    cout << Solution().numOfStrings(patterns, word) << endl;
    
    patterns = {"a","b","c"};
    word = "aaaaabbbbb";
    // 2
    cout << Solution().numOfStrings(patterns, word) << endl;
    
    patterns = {"a","a","a"};
    word = "ab";
    // 3
    cout << Solution().numOfStrings(patterns, word) << endl;
    
    return 0;
}
