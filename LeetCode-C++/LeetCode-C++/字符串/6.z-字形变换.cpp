//
//  6.z-字形变换.cpp
//  LeetCode-C++
//
//  Created by warden on 2021/7/30.
//  Copyright © 2021 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/zigzag-conversion/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int step = 2 * (numRows - 1);
        string rStr;
        for (int i = 0; i < numRows; i ++) {
            for (int j = i; j < s.size(); j += step) {
                rStr.push_back(s[j]);
                if (i > 0 && i < numRows - 1 && j + step - i * 2 < s.size()) {
                    rStr.push_back(s[j + step - i * 2]);
                }
            }
        }
        return rStr;
    }
};

//int main(int argc, const char * argv[]) {
//    // insert code here...
//
//    cout << ("PAHNAPLSIIGYIR" == Solution().convert("PAYPALISHIRING", 3)) << endl;
//
//    cout << ("PINALSIGYAHRPI" == Solution().convert("PAYPALISHIRING", 4)) << endl;
//
//    cout << ("A" == Solution().convert("A", 1)) << endl;
//
//    return 0;
//}
