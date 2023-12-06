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

int total = 0, n;
ofstream output("output.txt");
ifstream input("input.txt");
string s, temp; 
long long int seed[100000000];
vector<long long int> seed_point;
vector<bool> checker;

void clear_checker(){
    for(int i=0;i<n;i++){
        checker[i]=0;
    }
}

void first_part_alternative(){
    int i,j,m;
    long long int minConverter=INT64_MAX;
    getline(input,s);
    stringstream ss(s);
    ss >> temp;
    for(i=1;1;i++){
        long long int temp_int;
        if(ss >> temp_int){
            seed[i] = temp_int;
        }
        else{
            n=i-1;
            break;
        }
        cout << seed[i] << " "; 
    }
    getline(input,s); getline(input,s); cout << endl;
    int counter = 1;
    while(getline(input,s)){
        if(s[0]==13){
            counter++;
            clear_checker();
            getline(input,s);
            getline(input,s);
        }
        stringstream ss(s);
        long long int destination,source,length;
        ss >> destination >> source >> length;
        for(i=1;i<=n;i++){
            if(seed[i] <= source + length && seed[i] >= source && checker[i]==0){
                output << "seed:" << i << " counter:" << counter << " " << seed[i] << " -> "  << destination + seed[i] - source << endl;
                seed[i] = destination + seed[i] - source;
                checker[i]=1;
            } 
        }
    }
    for(i=1;i<=n;i++){
        if(seed[i] < minConverter){
            minConverter = seed[i];
        }
    }
    cout << minConverter << endl;
}

void second_part(){
    long long int i,j,m;
    long long int minConverter=INT64_MAX;
    getline(input,s);
    stringstream ss(s);
    ss >> temp;

    for(i=1,m=1;1;i++){
        long long int temp_int;
        long long int temp_int2;
        if(ss >> temp_int){
            ss >> temp_int2;
            long long int range = temp_int2 + temp_int;
            for(long long int k=temp_int;k<range;k++){
                seed_point.push_back(k);
                checker.push_back(0);
            }
            seed[i] = temp_int;
        }
        else{
            n=seed_point.size();
            break;
        }
    }
    cout << "hey" << endl;
    getline(input,s); getline(input,s); cout << endl;
    int counter = 1;
    while(getline(input,s)){
        if(s[0]==13){
            counter++;
            clear_checker();
            getline(input,s);
            getline(input,s);
            cout << counter << endl;
        }
        cout << s << endl;
        stringstream ss(s);
        long long int destination,source,length;
        ss >> destination >> source >> length;
        for(i=0;i<n;i++){
            if(seed[i] <= source + length && seed[i] >= source && checker[i]==0){
                output << "seed:" << i << " counter:" << counter << " " << seed[i] << " -> "  << destination + seed[i] - source << endl;
                seed[i] = destination + seed[i] - source;
                checker[i]=1;
            }
        }
    }
    for(i=0;i<n;i++){
        if(seed[i] < minConverter){
            minConverter = seed[i];
        }
    }
    cout << minConverter << endl;
}


int main(){
    second_part();
}