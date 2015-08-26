//
//  permutations
//  Combinatorics
//
//  Created by Joseph Canero on 7/25/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include "permutations.h"
#include "vector_utils.h"

template <class T>
void permute(vector<T> items, vector<T> subgroup, vector<vector<T>> &permutations) {
    if (items.empty()) permutations.push_back(subgroup);
    else {
        for (int i = 0; i < items.size(); i++) {
            subgroup.push_back(items[i]);
            permute(deleteAt(items, i), subgroup, permutations);
            subgroup.pop_back();
        }
    }
}

template <class T>
vector<vector<T>> permutations(vector<T> items) {
    if (items.empty()) return vector<vector<T>>();
    
    vector<vector<T>> permutations;
    permute(items, vector<T>(), permutations);
    return permutations;
}