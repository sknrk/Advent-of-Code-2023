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
string springs[1000];
vector <int> springs_map[1000];

void get_input(){
    int i,j,m;
    while(getline(input,s)){
        stringstream ss(s);
        ss >> springs[n];
        int tempint,tempint2;
        ss >> temp;
        for(i=0;i<temp.size();i+=2){
            springs_map[n].push_back(temp[i]-'0');
        }        
        for(i=0;i<springs_map[n].size();++i){
            // output << springs_map[n][i] << " ";
        }
        // output << endl;
        n++;
    }
}


void create_sub_array(string s, int n, int k){
    if(k<=s.size() && s[k]=='?'){
        string s2 = s; 
        s2[k]='#';
        create_sub_array(s2,n,k+1);
        s2[k]='.';
        create_sub_array(s2,n,k+1);
        return;
    }else if (k<s.size()-1){
        create_sub_array(s,n,k+1);
        return;
    }

    // check if its the end and if its valid
    if(k>=s.size()-1){
        vector <int> array = springs_map[n];
        int counter = 0, m=0;
        int deleted = array.size();
        output << s << endl;
        for(int j=0; j<=s.size();j++){
            if((s[j]=='.' || j==s.size()) && counter!=0){
                if(s[j]=='#'){
                    counter++;
                }
                if(array[m]==counter){
                    m++;
                    deleted--;
                }
                else{
                    return;
                }
                counter = 0;
            }
            else if(s[j]=='#'){
                counter++;
            }
        }
        if(deleted==0){
            output << s << " deleted"<< endl;        
            max_counter++;
            return;
        }
    }
    return;
}

// void partly_dynamic_recursive(string s, vector <int> sub_values[100], int k, int n, int t){
//     for()
// }

void dynamic_array(string s, int k){
    vector <int> sub_values[100];
    if(s[0]=='?'){
        sub_values[0].push_back(0);
        sub_values[0].push_back(1);
    }
    else if(s[0]=='.'){
        sub_values[0].push_back(0);
    }
    else if(s[0]=='#'){
        sub_values[0].push_back(1);
    }
    for(int i=1;i<s.size();i++){
        if(s[i]=='?'){
            if(s[i-1]=='.'){
                sub_values[i].push_back(1);
                sub_values[i].push_back(0);
            }
            else if(s[i-1]!='.'){
                for(int j=0;j<sub_values[i-1].size();j++){
                    sub_values[i].push_back(sub_values[i-1][j]);
                }
                sub_values[i].push_back(sub_values[i-1][sub_values[i-1].size()-1]+1);
            }
        }
        else if(s[i]=='.'){
            sub_values[i].push_back(0);
        }
        else if(s[i]=='#'){
            if(s[i-1]=='.'){
                sub_values[i].push_back(1);
            }
            else if(s[i-1]!='.'){
                for(int j=0;j<sub_values[i-1].size();j++){
                    sub_values[i].push_back(sub_values[i-1][j]);
                }
                sub_values[i].push_back(sub_values[i-1][sub_values[i-1].size()-1]+1);
            }
        }
        
    }
    for(int i=0;i<s.size();i++){
        for(int j=0;j<sub_values[i].size();j++){
            output << sub_values[i][j] << " ";
        }
        output << endl;
    }
    output <<endl;

    int m=0;
    // partly_dynamic_recursive(s, sub_values, k, 0);
}


void first_part(){
    get_input();
    for(int i=0;i<n;++i){
        max_counter = 0; 
        output << endl;
        // dynamic_array(springs[i], i);
        create_sub_array(springs[i], i, 0);
        // cout << max_counter << endl;
        total+=max_counter;
    }
    cout << total << endl;
}

void second_part(){
    int i,j,m;
   while(getline(input,s)){
        stringstream ss(s);
      
    }
   
}

int main(){
    first_part();
}