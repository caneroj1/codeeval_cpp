//
//  permutations
//  Combinatorics
//
//  Created by Joseph Canero on 7/25/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#ifndef __Combinatorics__permutations__
#define __Combinatorics__permutations__

#include <stdio.h>
#include <vector>

using namespace std;

template <class T>
void permute(vector<T>, vector<T>, vector<vector<T>>&);

template <class T>
vector<vector<T>> permutations(vector<T>);

#endif /* defined(__Combinatorics__permutations__) */
