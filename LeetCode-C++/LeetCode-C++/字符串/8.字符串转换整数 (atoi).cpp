//
//  8.字符串转换整数 (atoi).cpp
//  LeetCode-C++
//
//  Created by warden on 2021/7/30.
//  Copyright © 2021 warden. All rights reserved.
//
// https://leetcode-cn.com/problems/string-to-integer-atoi/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int num = 0;

        bool isPositiveFlag = true;
        bool parseNum = false;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ') {
                if (!parseNum) {
                    continue;
                } else {
                    break;
                }
            } else if (ch == '-') {
                if (parseNum) break;;
                isPositiveFlag = false;
                parseNum = true;
            } else if (ch == '+') {
                if (parseNum) break;
                parseNum = true;
            } else if (ch >= '0' && ch <= '9') {
                int addNum = ch - '0';

                if (num > (INT32_MAX - addNum) / 10) {
                    return isPositiveFlag ? INT32_MAX : INT32_MIN;
                }
                num = num * 10 + addNum;
                parseNum = true;
            } else {
                break;
            }
        }
        return isPositiveFlag ? num : -num;
    }
};

//int main(int argc, const char * argv[]) {
//    // insert code here...
//
////    cout << (42 == Solution().myAtoi("42")) << endl;
////
////    cout << (-42 == Solution().myAtoi("   -42")) << endl;
////
////    cout << (4193 == Solution().myAtoi("4193 with words")) << endl;
////
////    cout << (0 == Solution().myAtoi("words and 987")) << endl;
////
////    cout << ((-2147483648) == Solution().myAtoi("-91283472332")) << endl;
//    cout << (0 == Solution().myAtoi("00000-42a1234")) << endl;
//
//    return 0;
//}
