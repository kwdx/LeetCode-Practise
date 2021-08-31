//
//  Google_1.cpp
//  Cpp
//
//  Created by warden on 2021/8/24.
//

/**
 谷歌笔试题--给定一个集合A=[0,1,3,8](该集合中的元素都是在0，9之间的数字，但未必全部包含)， 指定任意一个正整数K，请用A中的元素组成一个大于K的最小正整数。

 Google2009华南地区笔试题

 给定一个集合A=[0,1,3,8](该集合中的元素都是在0，9之间的数字，但未必全部包含)，指定任意一个正整数K，请用A中的元素组成一个大于K的最小正整数。比如，A=[1,0] K=21 那么输出结构应该为100。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Google2009华南地区笔试题
// 给定一个集合A=[0,1,3,8](该集合中的元素都是在0，9之间的数字，但未必全部包含)，
// 指定任意一个正整数K，请用A中的元素组成一个大于K的最小正整数。
// 比如，A=[1,0] K=21 那么输出结构应该为100。

int generate_min_int_greater_than_k_1(vector<int> A, int K) {
    sort(A.begin(), A.end());
            
    stack<int> st;
    bool needBigger = true;
    
    int k = K;
    
    while (k > 0) {
        int k_num = k % 10;
        k /= 10;
        int i = 0;
        for (; i < A.size(); i++) {
            if (k_num <= A[i]) {
                break;
            }
        }
        if (i == A.size()) {
            // 没找到相等或大于的，后续需要更大一点的
            st.push(A[0]);
            needBigger = true;
        } else {
            // 找到了
            if (needBigger && k_num == A[i]) {
                if (i + 1 == A.size()) {
                    needBigger = true;
                    st.push(A[0]);
                    continue;
                } else {
                    i += 1;
                }
            }
            if (A[i] > k_num) {
                // 当前位更大，把之前生成的数字改成最小
                int genSize = (int)st.size();
                while (!st.empty()) {
                    st.pop();
                }
                while (genSize-- > 0) {
                    st.push(A[0]);
                }
            }
            needBigger = false;
            st.push(A[i]);
        }
    }
    
    int res = 0;

    if (needBigger) {
        // 需要更大的，直接生成多一位的数字
        if (A[0] == 0) {
            res = A[1];
        } else {
            res = A[0];
        }
        while (res <= K) {
            res = res * 10 + A[0];
        }
    } else {
        while (!st.empty()) {
            res = res * 10 + st.top();
            st.pop();
        }
    }
    return res;
}


int generate_min_int_greater_than_k(vector<int> A, int K) {
    sort(A.begin(), A.end());
    
    vector<int> k_nums;
    while (K > 0) {
        k_nums.push_back(K % 10);
        K /= 10;
    }
        
    stack<int> st;
    bool needBigger = true;
    
    for (int k_num : k_nums) {
        int i = 0;
        for (; i < A.size(); i++) {
            if (k_num <= A[i]) {
                break;
            }
        }
        if (i == A.size()) {
            // 没找到相等或大于的，后续需要更大一点的
            st.push(A[0]);
            needBigger = true;
        } else {
            // 找到了
            if (needBigger && k_num == A[i]) {
                if (i + 1 == A.size()) {
                    needBigger = true;
                    st.push(A[0]);
                    continue;
                } else {
                    i += 1;
                }
            }
            if (A[i] > k_num) {
                // 当前位更大，把之前生成的数字改成最小
                int genSize = (int)st.size();
                while (!st.empty()) {
                    st.pop();
                }
                while (genSize-- > 0) {
                    st.push(A[0]);
                }
            }
            needBigger = false;
            st.push(A[i]);
        }
    }
    
    int res = 0;

    if (needBigger) {
        // 需要更大的，直接生成多一位的数字
        if (A[0] == 0) {
            res = A[1];
        } else {
            res = A[0];
        }
        for (int i = 0; i < k_nums.size(); i++)
            res = res * 10 + A[0];
    } else {
        while (!st.empty()) {
            res = res * 10 + st.top();
            st.pop();
        }
    }
    return res;
}


int main(int argc, const char * argv[]) {
    vector<int> A;
    int K = 0;
    
    A = {1,2};
    K = 23;
    assert(111 == generate_min_int_greater_than_k_1(A, K));
    
    A = {1,0};
    K = 21;
    assert(100 == generate_min_int_greater_than_k_1(A, K));
    
    
    A = {2,3};
    K = 35;
    assert(222 == generate_min_int_greater_than_k_1(A, K));
    
    
    A = {0,1,3,8};
    K = 82;
    assert(83 == generate_min_int_greater_than_k_1(A, K));
    
    A = {0,1,3,8};
    K = 843;
    assert(880 == generate_min_int_greater_than_k_1(A, K));
    
    A = {0,1,3,7};
    K = 843;
    assert(1000 == generate_min_int_greater_than_k_1(A, K));
    
    cout << "OK~" << endl;
    
    return 0;
};
