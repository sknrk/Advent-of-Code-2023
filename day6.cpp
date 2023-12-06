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

int total = 0, n, multiplier = 1;
ofstream output("output.txt");
ifstream input("input.txt");
string s, temp; 

long long int race[100];
long long int record[100];
void first_part(){
    int i,j,m,n;
    int race1,race2,race3;
    getline(input,s);
    stringstream ss(s);
    ss >> temp;
    for(i=1;;i++){
        long long int temp_int;
        if(ss >> temp_int){
            race[i] = temp_int;
        }
        else{
            n=i-1;
            break;
        }
    }
    getline(input,s);
    stringstream ss2(s);
    ss2 >> temp;
    for(i=1;;i++){
        long long int temp_int;
        if(ss2 >> temp_int){
            record[i] = temp_int;
        }
        else{
            break;
        }
    }
    for(i=1;i<=n;i++){
        output << race[i] << ":" << record[i] << endl;
        int counter = 0;
        for(j=0;j<=race[i];j++){
            long long int score = (race[i] - j)*j;
            if(score > record[i]){
                counter++;
            }
            output << score << " ";
        }
        multiplier *= counter;
        output << endl;
    }
    for(i=1;i<=n;i++){
        cout << race[i] << ":" << record[i] << endl;
    }
    cout << multiplier << endl;
}

void second_part(){
}

int main(){
    first_part();
}