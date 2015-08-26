//
//  vector_utils.cpp
//  Combinatorics
//
//  Created by Joseph Canero on 7/25/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include "vector_utils.h"
#include <vector>
#include <iostream>

template <class T>
vector<T> slice(vector<T> v, size_t begin, size_t length) {
    vector<T> nv;
    size_t stop = (begin + length > v.size()) ? v.size() : (begin + length);
    
    for (typename vector<T>::iterator i = v.begin() + begin; i != v.begin() + stop; i++)
        nv.push_back(*i);
    return nv;
}

template <class T>
vector<T> deleteAt(vector<T> v, size_t position) {
    vector<T> nv(v);
    position = position >= v.size() ? v.size() - 1 : position;
    nv.erase(nv.begin() + position);
    return nv;
}

template <class T>
vector<T> deleteBetween(vector<T> v, size_t begin, size_t length) {
    vector<T> nv(v);
    size_t stop = (begin + length > v.size()) ? v.size() : (begin + length);
    nv.erase(nv.begin() + begin, nv.begin() + stop);
    return nv;
}
