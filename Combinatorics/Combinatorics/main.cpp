//
//  main.cpp
//  Combinatorics
//
//  Created by Joseph Canero on 7/25/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include <iostream>
#include <vector>
#include "vector_utils.h"
#include "vector_utils.cpp"
#include "permutations.h"
#include "permutations.cpp"
#include "combinations.h"
#include "combinations.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> set = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (vector<int> permutation: permutations(slice(set, 0, 4))) {
        for (int i : permutation) cout << i << " ";
        cout << endl;
    }
    
    for (vector<int> combo : chooseN(set, 3)) {
        for (int i : combo) cout << i << " ";
        cout << endl;
    }
    
    return 0;
}
