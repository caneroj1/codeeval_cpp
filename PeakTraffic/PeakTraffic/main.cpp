//
//  main.cpp
//  PeakTraffic
//
//  Created by Joseph Canero on 7/25/15.
//  Copyright (c) 2015 Joseph Canero. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

const int UNDEFINED = -1;
stack<int> graphStack;
int globalIndex;

vector<string> inputComponents(string line) {
    vector<string> components;
    string target = "    ";
    
    size_t i = line.find(target);
    
    while (i != string::npos) {
        components.push_back(line.substr(0, i));
        line.replace(0, i + target.length(), "");
        i = line.find(target);
    }
    
    components.push_back(line);
    return components;
}

map<int, string> constructGraph(string filename, vector<vector<int>> &graph) {
    map<int, string> emails;
    map<string, int> myMap;
    fstream f(filename);
    string line;
    int id = 0;
    
    while (getline(f, line)) {
        vector<string> lineData = inputComponents(line);
        if (myMap.find(lineData[1]) == myMap.end())
            myMap.insert(pair<string, int>(lineData[1], id++));
        
        if (myMap.find(lineData[2]) == myMap.end())
            myMap.insert(pair<string, int>(lineData[2], id++));
        
        
        int first_index = myMap.find(lineData[1])->second,
        second_index = myMap.find(lineData[2])->second;
        
        
        if (first_index >= graph.size())
            graph.push_back(vector<int>());
        
        if (second_index >= graph.size())
            graph.push_back(vector<int>());
        
        graph[first_index].push_back(second_index);
    }
    
    for (map<string, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++)
        emails.insert(pair<int, string>(iter->second, iter->first));
    
    return emails;
}

vector<string> strongConnect(int vertex, vector<vector<int>> &graph, vector<int> &indices, vector<int> &lowlink, vector<bool> &onStack, map<int, string> &emailMap) {
    vector<string> components;
    
    indices[vertex] = globalIndex;
    lowlink[vertex] = globalIndex++;
    graphStack.push(vertex);
    onStack[vertex] = true;
    
    for (int edge : graph[vertex]) {
        if (indices[edge] == UNDEFINED) {
            strongConnect(edge, graph, indices, lowlink, onStack, emailMap);
            lowlink[vertex] = min(lowlink[vertex], lowlink[edge]);
        }
        else if (onStack[edge])
            lowlink[vertex] = min(lowlink[vertex], indices[edge]);
    }
    
    int edge;
    if (lowlink[vertex] == indices[vertex]) {
        do {
            edge = graphStack.top();
            graphStack.pop();
            onStack[edge] = false;
            components.push_back(emailMap.find(edge)->second);
        } while (edge != vertex);
    }
    return components;
}

vector<vector<string>> tarjanStronglyConnectedComponents(vector<vector<int>> &graph, map<int, string> &emailMap) {
    globalIndex = 0;
    vector<int> indices(graph.size(), -1), lowlink(graph.size(), -1);
    vector<bool> onStack(graph.size(), false);
    vector<vector<string>> components;
    
    for (int vertex = 0; vertex < graph.size(); vertex++)
        if (indices[vertex] == UNDEFINED) {
            vector<string> component = strongConnect(vertex, graph, indices, lowlink, onStack, emailMap);
            if (!component.empty() && component.size() >= 3) components.push_back(component);
        }
    
    return components;
}

int main(int argc, const char * argv[]) {
    
    vector<string> listOfComponents;
    vector<vector<int>> graph;
    string comp = "";
    
    map<int, string> userMap = constructGraph(argv[1], graph);
    vector<vector<string>> components = tarjanStronglyConnectedComponents(graph, userMap);
    vector<vector<string>> sortedComponents;
    
    for (vector<string> component : components) {
        sort(component.begin(), component.end());
        sortedComponents.push_back(component);
    }
    
    int index;
    for (vector<string> component : sortedComponents) {
        comp = "";
        index = 0;
        for (string item : component) {
            if (index++ < component.size() - 1) comp += item + ", ";
            else comp += item;
        }
        listOfComponents.push_back(comp);
    }
    
    sort(listOfComponents.begin(), listOfComponents.end());
    
    for (string component : listOfComponents)
        cout << component << endl;
    
    return 0;
}
