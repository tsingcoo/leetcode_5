//
//  Header.h
//  leetcode_5
//
//  Created by 王青龙 on 6/30/16.
//  Copyright © 2016 王青龙. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include<string>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        if (s.size()<2) {
            return s;
        }
        int len=(int)s.size(),max_left=0,max_len=1,left,right;
        for (int start=0; start<len&&len-start>max_len/2; ) {
            left=right=start;
            while (right<len-1&&s[right+1]==s[right]) {
                ++right;
            }
            start=right+1;
            while (right<len-1&&left>0&&s[right+1]==s[left-1]) {
                ++right;
                --left;
            }
            if (max_len<right-left+1) {
                max_left=left;
                max_len=right-left+1;
            }
        }
        return s.substr(max_left,max_len);
    }
};

#endif /* Header_h */
