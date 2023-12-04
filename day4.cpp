#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>

using namespace std;

int total = 0;
ofstream output("output.txt");
ifstream input("input.txt");
string s; 
int copies[1010];

void first_part(){
    string line;
    while(getline(input,line)){
        vector<int> winning_numbers, matches;
        // cout << line << endl;
        stringstream ss(line);
        int game_number;
        string temp;
        ss >> temp >> game_number >> temp;
        for(int i=1;i<=10;i++){
            int number;
            ss >> number;
            winning_numbers.push_back(number);
            output << number << " ";
        };
        ss >> temp;
        output << "| ";
        int points = 0;
        for(int i=1,j=0;i<=25;i++){
            int number;
            ss >> number;
            if(find(winning_numbers.begin(), winning_numbers.end(), number) != winning_numbers.end()){
                points=pow(2,j);
                cout << "found " << number << " at " << j << " " << points << endl;
                j++;
            }
            matches.push_back(number);
            output << number << " ";
        };
        total+=points;
        output << endl;
    }
    cout << total << endl;
}

void second_part(){
    string line;
    int game_number;
    while(getline(input,line)){
        vector<int> winning_numbers, matches;
        stringstream ss(line);
        string temp;
        ss >> temp >> game_number >> temp;
        for(int i=1;i<=10;i++){
            int number;
            ss >> number;
            winning_numbers.push_back(number);
            output << number << " ";
        };
        ss >> temp;
        output << "| ";
        int points = 0;
        for(int i=1,j=0;i<=25;i++){
            int number;
            ss >> number;
            if(find(winning_numbers.begin(), winning_numbers.end(), number) != winning_numbers.end()){
                points+=1;
                j++;
            }
            matches.push_back(number);
            output << number << " ";
        }; 
        for(int i=1;i<=points;i++){
            copies[game_number+i]+=copies[game_number]+1;
            cout << game_number <<" "<< game_number+i << " " << copies[game_number]+1 << endl;  
        }
        output << endl;
    }
    for(int i=1;i<=game_number;i++){
        total+=copies[i]+1;
    }
    cout << total << endl;
}

int main(){
    second_part();
}