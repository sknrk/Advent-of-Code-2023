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

vector <int> sub_array_generator(vector <int> array){
    vector <int> sub_array;
    for(int i=0;i<array.size()-1;i++){
        sub_array.push_back(array[i+1]-array[i]);
    }
    return sub_array;
}

void first_part(){
    while(getline(input,s)){
        int i=0,j,m,n=0;
        vector <int> numbers[100];
        stringstream ss(s);
        int sub_array_counter=1;
        while(1){
            int temp_int;
            if(ss >> temp_int){
                numbers[0].push_back(temp_int);
                n++;
            }
            else{
                break;
            }
        }
        for(i=0;i<n;i++){
            int zero_counter = 0;
            for(j=i+1;j<n;j++){
                numbers[sub_array_counter] = sub_array_generator(numbers[sub_array_counter-1]);
                if(numbers[sub_array_counter][j-1-i] == 0){
                    zero_counter++;
                }
            }
            if(zero_counter == n-i-1){
                break;
            }
            sub_array_counter++;
        }
        for(i=sub_array_counter-1;i>=0;i--){
            int sub_array_size = numbers[i].size(); 
            numbers[i].push_back(numbers[i][sub_array_size-1]+numbers[i+1][numbers[i+1].size()-1]);
            if(i == 0){
                total += numbers[i][sub_array_size];
            }
        }
    }
    cout << total << endl;
}


void second_part(){
    while(getline(input,s)){
        int i=0,j,m,n=0;
        vector <int> numbers[100];
        stringstream ss(s);
        int sub_array_counter=1;
        while(1){
            int temp_int;
            if(ss >> temp_int){
                numbers[0].push_back(temp_int);
                n++;
            }
            else{
                break;
            }
        }
        for(i=0;i<n;i++){
            int zero_counter = 0;
            for(j=i+1;j<n;j++){
                numbers[sub_array_counter] = sub_array_generator(numbers[sub_array_counter-1]);
                if(numbers[sub_array_counter][j-1-i] == 0){
                    zero_counter++;
                }
            }
            if(zero_counter == n-i-1){
                break;
            }
            sub_array_counter++;
        }
        for(i=sub_array_counter-1;i>=0;i--){
            int sub_array_size = numbers[i].size(); 
            numbers[i].insert(numbers[i].begin(),numbers[i][0]-numbers[i+1][0]);
            if(i == 0){
                total += numbers[i][0];
            }
        }
        for(i=0;i<sub_array_counter;i++){
            for(j=0;j<numbers[i].size();j++){
                output << numbers[i][j] << " ";
            }
            output << endl;
        }
        output << endl;
    }
    cout << total << endl;
}

int main(){
    second_part();
}