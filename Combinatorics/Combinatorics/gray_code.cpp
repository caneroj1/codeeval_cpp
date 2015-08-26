//
//  gray_code.cpp
//  Combinatorics
//
//  Created by Joseph Canero on 7/25/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include "gray_code.h"
#include <string>
using namespace std;

vector<string> generateGrayCode(size_t n) {
    vector<string> grayCode = { "0", "1" };
    if (n == 1) return grayCode;
    else {
        for (int i = 1; i < n; i++) {
            vector<string> nextLevel;
            for (vector<string>::reverse_iterator i = grayCode.rbegin(); i != grayCode.rend(); i++)
                nextLevel.push_back("0" + *i);
            for (vector<string>::iterator i = grayCode.begin(); i != grayCode.end(); i++)
                nextLevel.push_back("1" + *i);
            grayCode = nextLevel;
        }
    }
    return grayCode;
}