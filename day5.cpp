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
long long int seed[100];
int seed_to_map[8][10000];
int checker[1000];

vector<vector<int> > seed_to_location(9);

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

void clear_checker(){
    for(int i=1;i<=4;i++){
        checker[i]=0;
    }
}

void first_part_alternative(){
    int i,j,m,n;
    long long int minConverter=INT64_MAX;
    getline(input,s);
    stringstream ss(s);
    ss >> temp;
    for(i=1;i<=20;i++){
        long long int temp_int;
        // if(ss >> temp_int){
            ss>> temp_int;
            seed[i] = temp_int;
        // }
        // else{
        //     break;
        // }
        cout << seed[i] << " "; 
    }
    getline(input,s); getline(input,s); cout << endl;
    int counter = 1;
    while(getline(input,s)){
        if(s.empty()){
            counter++;
            clear_checker();
            getline(input,s);
            getline(input,s);
        }
        stringstream ss(s);
        long long int destination,source,length;
        ss >> destination >> source >> length;
        for(i=1;i<=20;i++){
            if(seed[i] <= source + length && seed[i] >= source && checker[i]==0){
                output << "seed:" << i << " counter:" << counter << " " << seed[i] << " -> "  << destination + seed[i] - source << endl;
                output << destination << " " << source << " " << length << endl;
                seed[i] = destination + seed[i] - source;
                checker[i]=1;
            } 
        }
    }
    // minConverter = seed[1];
    for(i=1;i<=20;i++){
        if(seed[i] < minConverter){
            cout << minConverter << " " << seed[i] << endl; 
            minConverter = seed[i];
        }
        // cout << seed[i] << " " << endl;
    }
    cout << minConverter << endl;
}

void second_part(){

}

int main(){
    first_part_alternative();
}