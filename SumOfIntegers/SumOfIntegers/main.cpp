//
//  main.cpp
//  SumOfIntegers
//
//  Created by Joseph Canero on 7/30/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> makeIntList(string line) {
    stringstream ss(line);
    vector<int> intList;
    string token;
    
    while (getline(ss, token, ','))
        intList.push_back(stoi(token));
    
    return intList;
}

int kadanesAlgorithm(vector<int> list) {
    int sumSoFar = 0,
        maxSum = 0;
    
    for (int item : list) {
        sumSoFar += item;
        if (sumSoFar < 0)
            sumSoFar = 0;
        if (maxSum < sumSoFar)
            maxSum = sumSoFar;
    }
    
    return maxSum;
}

int maxContiguousSum(vector<int> list) {
    int sumSoFar = 0,
        maxSum = 0;
    
    for (int item : list) {
        sumSoFar = max(item, sumSoFar + item);
        maxSum = max(maxSum, sumSoFar);
    }
    
    return maxSum;
}

int main(int argc, const char * argv[]) {
    fstream f(argv[1]);
    string line;
    
    while (getline(f, line))
        cout<< maxContiguousSum(makeIntList(line)) << endl;
    
    return 0;
}
