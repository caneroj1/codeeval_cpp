//
//  main.cpp
//  CycleDetection
//
//  Created by Joseph Canero on 7/26/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int smallestPattern(string origStr) {
    if (origStr.length() == 1) return 1;
    else {
        string str(origStr + origStr);
        string::iterator tortoise = str.begin() + 1, hare = str.begin() + 2;
        while (*tortoise != *hare) {
            tortoise += 1;
            if (hare != str.end())
                hare++;
            if (hare != str.end())
                hare++;
            else return origStr.length();
        }
        
        int pos = 0;
        tortoise = str.begin();
        while (*tortoise != *hare) {
            tortoise++;
            hare++;
            pos++;
        }
        
        int length = 1;
        hare++;
        while (*tortoise != *hare) {
            hare++;
            length++;
        }
        return length;
    }
}

int main(int argc, const char * argv[]) {
    fstream f(argv[1]);
    string line;
    
    while (getline(f, line))
        cout << smallestPattern(line) << endl;
    
    return 0;
}
