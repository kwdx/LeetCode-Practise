//
//  _509_斐波那契数.cpp
//  LeetCode-C++
//
//  Created by warden on 2019/11/25.
//  Copyright © 2019 warden. All rights reserved.
//

#include "_509_斐波那契数.hpp"

int _509_斐波那契数::fib(int N) {    
    if (N == 0) {
        return 0;
    }
    int f0 = 0;
    int f1 = 1;
    for (int i = 1; i < N; i++) {
        int tmp = f1;
        f1 = f1 + f0;
        f0 = tmp;
    }
    return f1;
}
