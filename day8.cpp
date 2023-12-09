#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <stdint.h>
#include <climits>
#include <map>
#include <iomanip>
#include <numeric>
#include <numeric> 
#include <utility> 

using namespace std;

int total = 0, n, multiplier = 1;
ofstream output("output.txt");
ifstream input("input.txt");
string s, temp, directions; 
int road[2000000][2];
map<string, pair<string, string> > nodeMap;
vector<pair<string, int> > targets;

void second_part(){
    int i,j,m,n=1;
    getline(input,s); stringstream  ss(s);
    ss >> directions; getline(input,s);
    int first_counter=0;
    string target;
    while(getline(input,s)){
        stringstream ss(s);
        string node,left,right;

        ss >> node >> temp >> left >> right;

        stringstream ssleft;
        ssleft << left[1] << left[2] << left[3];
        stringstream ssright;
        ssright << right[0] << right[1] << right[2];

        if(node[2]=='A'){
            targets.push_back(make_pair(node, 0));
        }

        nodeMap[node] = make_pair(ssleft.str(),ssright.str());
        n++;
    }
    n--;
    
    for(i=0;i<targets.size();i++){
        int counter = 0;
        target=targets[i].first;
        while(target[2]!='Z'){
            for(int i=0;i<directions.length();i++){
                if(directions[i]=='L'){
                    output << target <<endl;
                    if (nodeMap.find(target) != nodeMap.end()) {
                        target = nodeMap[target].first;
                    }
                }
                else if(directions[i]=='R'){
                    output << target <<endl;
                    if (nodeMap.find(target) != nodeMap.end()) {
                        target = nodeMap[target].second;
                    }
                }
                counter++;
                if(target[2]=='Z') break;
            }
        }
        targets[i].second = counter;
    }
    long long int multiplier = 1;
    for(i=0;i<targets.size();i++){
        output << targets[i].first << " " << targets[i].second << endl;
        multiplier = lcm(multiplier, targets[i].second);
    }
    cout << multiplier << endl;
}

void first_part(){
    int i,j,m,n=1;
    getline(input,s); stringstream  ss(s);
    ss >> directions; getline(input,s);
    int first_counter=0;
    string target;
    while(getline(input,s)){
        stringstream ss(s);
        string node,left,right;

        ss >> node >> temp >> left >> right;

        stringstream ssleft;
        ssleft << left[1] << left[2] << left[3];
        stringstream ssright;
        ssright << right[0] << right[1] << right[2];

        nodeMap[node] = make_pair(ssleft.str(),ssright.str());
        n++;
    }
    n--;
    int counter = 0;
    target = "AAA";
    cout << target << endl;
    while(target!="ZZZ"){
        for(int i=0;i<directions.length();i++){
            if(directions[i]=='L'){
                output << target <<endl;
                if (nodeMap.find(target) != nodeMap.end()) {
                    target = nodeMap[target].first;
                }
            }
            else if(directions[i]=='R'){
                output << target <<endl;
                if (nodeMap.find(target) != nodeMap.end()) {
                    target = nodeMap[target].second;
                }
            }
            counter++;
            if(target=="ZZZ") break;
        }
    }

    cout << target << " " << counter << endl;
}

int main(){
    second_part();
}