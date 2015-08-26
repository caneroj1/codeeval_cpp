//
//  combinations.h
//  Combinatorics
//
//  Created by Joseph Canero on 7/26/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#ifndef __Combinatorics__combinations__
#define __Combinatorics__combinations__

#include <vector>

using namespace std;

template <class T>
vector<vector<T>> chooseN(vector<T>, int);

template <class T>
vector<vector<T>> combine(vector<T>, vector<string>&, vector<vector<T>>&, int);

#endif /* defined(__Combinatorics__combinations__) */
