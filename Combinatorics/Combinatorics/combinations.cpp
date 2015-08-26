//
//  combinations.cpp
//  Combinatorics
//
//  Created by Joseph Canero on 7/26/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include "combinations.h"
#include "gray_code.h"
#include <string>
#include <vector>

#include <iostream>

using namespace std;

template <class T>
void combine(vector<T> items, vector<string> grayCode, vector<vector<T>> &combinations, int choose) {
    vector<T> subset;
    int index = 0;
    for (string code : grayCode) {
        for (char c : code) {
            if (c == '1')
                subset.push_back(items[index]);
            index++;
        }
        index = 0;
        if (subset.size() == choose) combinations.push_back(subset);
        subset.clear();
    }
}

template <class T>
vector<vector<T>> chooseN(vector<T> items, int choose) {
    vector<vector<T>> combinations;
    if (!items.empty() && choose >= 1)
        combine(items, generateGrayCode(items.size()), combinations, choose);
    return combinations;
}