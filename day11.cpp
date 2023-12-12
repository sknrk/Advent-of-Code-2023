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
#include <queue>

using namespace std;

int n, multiplier = 1, stack_counter = 0, max_counter = 0, starter_i, starter_j;
long long int total = 0;
ofstream output("output.txt");
ifstream input("input.txt");
string s, temp, directions; 
string space[1000];
int columns[1000], rows[1000];

vector<pair<int,int> > galaxy_collector;
vector<pair<string, int> > targets;

void first_part(){
    int i,j,m;
   while(getline(input,s)){
        stringstream ss(s);
        while(1){
            if(ss>>temp){
                space[n++]=temp;
                space[n-1].find('#')!=string::npos ? rows[n-1] : rows[n-1]++;
            }
            else{
                break;
            }
        }
    }
    // horizontal scan
    for(i=0;i<space[0].size();i++){
        bool empty = true;
        for(j=0;j<n;j++){
            if(space[j][i]=='#'){
                galaxy_collector.push_back(make_pair(j,i));
                empty=false;
            }
        }
        if(empty==true){
            columns[i]++;
        }
    }
    for(i=0;i<galaxy_collector.size();i++){
        for(j=i+1;j<galaxy_collector.size();j++){
            int distance=0;
            for(int k=galaxy_collector[i].first; k!=galaxy_collector[j].first; galaxy_collector[i].first<galaxy_collector[j].first ? k++ : k--){
                distance+=rows[k]+1;
            }
            for(int k=galaxy_collector[i].second; k!=galaxy_collector[j].second; galaxy_collector[i].second<galaxy_collector[j].second ? k++ : k--){
                distance+=columns[k]+1;
            }
            total+=distance;
        }
    }
    cout << total << endl;
}

void second_part(){
    int i,j,m;
   while(getline(input,s)){
        stringstream ss(s);
        while(1){
            if(ss>>temp){
                space[n++]=temp;
                space[n-1].find('#')!=string::npos ? rows[n-1] : rows[n-1]=999999;
            }
            else{
                break;
            }
        }
    }
    // horizontal scan
    for(i=0;i<space[0].size();i++){
        bool empty = true;
        for(j=0;j<n;j++){
            if(space[j][i]=='#'){
                galaxy_collector.push_back(make_pair(j,i));
                empty=false;
            }
        }
        if(empty==true){
            columns[i]=9999999;
        }
    }
    for(i=0;i<galaxy_collector.size();i++){
        for(j=i+1;j<galaxy_collector.size();j++){
            int distance=0;
            for(int k=galaxy_collector[i].first; k!=galaxy_collector[j].first; galaxy_collector[i].first<galaxy_collector[j].first ? k++ : k--){
                distance+=rows[k]+1;
            }
            for(int k=galaxy_collector[i].second; k!=galaxy_collector[j].second; galaxy_collector[i].second<galaxy_collector[j].second ? k++ : k--){
                distance+=columns[k]+1;
            }
            total+=distance;
        }
    }
    cout << total << endl;
}

int main(){
    first_part();
}