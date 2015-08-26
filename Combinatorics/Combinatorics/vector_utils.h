//
//  vector_utils.h
//  Combinatorics
//
//  Created by Joseph Canero on 7/25/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#ifndef __Combinatorics__vector_utils__
#define __Combinatorics__vector_utils__

#include <vector>

using namespace std;

template <class T>
vector<T> slice(vector<T> v, size_t begin, size_t length);

template <class T>
vector<T> deleteAt(vector<T> v, size_t position);

template <class T>
vector<T> deleteBetween(vector<T> v, size_t begin, size_t end);

#endif /* defined(__Combinatorics__vector_utils__) */
