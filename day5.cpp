#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <stdint.h>
#include <climits>

using namespace std;

int total = 0;
ofstream output("output.txt");
ifstream input("input.txt");
string s, temp; 
int seed[10000];
int seed_to_map[8][10000];

vector<vector<int>> seed_to_map(9);

void first_part(){
    int i,j,m,n,minConverter=1000;
    getline(input,s);
    stringstream ss(s);
    ss >> temp;
    for(i=1;1;i++){
        int temp_int;
        if(ss >> temp_int){
            seed[i] = temp_int;
        }
        else{
            break;
        }
        cout << seed[i] << " "; 
    }
    getline(input,s); getline(input,s); cout << endl;
    int counter = 1;
    while(getline(input,s)){
        if(s[0]==13){
            counter++;
            getline(input,s);
            getline(input,s);
        }
        stringstream ss(s);
        int destination,source,length;
        ss >> destination >> source >> length;  
        for(i=1;i<=length;i++){
            seed_to_map[counter][source+i-1] = destination+i-1;
            output << counter << ":" << source+i-1 << ":" << seed_to_map[counter][source+i-1] << endl;
        }
        output << counter << endl;
    }
    for(i=1;i<=4;i++){
        int converter = seed[i];
        for(j=1;j<=counter;j++){
            if(seed_to_map[j][converter]!=0)
                converter = seed_to_map[j][converter];
            cout << converter << " ";
        }
        if(converter < minConverter){
            minConverter = converter;
        }
        cout << endl;
    }
    cout << minConverter << endl;
}

void alternative_part_1(){
        int i,j,m,n,minConverter=1000;
    getline(input,s);
    stringstream ss(s);
    ss >> temp;
    for(i=1;1;i++){
        int temp_int;
        if(ss >> temp_int){
            seed[i] = temp_int;
        }
        else{
            break;
        }
        cout << seed[i] << " "; 
    }
    getline(input,s); getline(input,s); cout << endl;
    int counter = 1;
    while(getline(input,s)){
        if(s[0]==13){
            counter++;
            getline(input,s);
            getline(input,s);
        }
        stringstream ss(s);
        int destination,source,length;
        ss >> destination >> source >> length;  
        for(i=1;i<=length;i++){
            seed_to_map[counter][source+i-1] = destination+i-1;
            output << counter << ":" << source+i-1 << ":" << seed_to_map[counter][source+i-1] << endl;
        }
        output << counter << endl;
    }
}

void second_part(){

}

int main(){
    first_part();
}