//
//  main.cpp
//  PredictSequence
//
//  Created by Joseph Canero on 7/28/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//
//  https://www.codeeval.com/open_challenges/125/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int predict(long index) {
    long rank = 0, swap = 0;
    while (true) {
        if (index == 0)
            return swap % 3;
        else {
            rank = long(log2(index));
            index -= long(exp2(rank));
            swap++;
        }
    }
}

int main(int argc, const char * argv[]) {
    fstream f(argv[1]);
    string line;
    
    while (getline(f, line))
        cout << predict(stol(line)) << endl;
    return 0;
}
