#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct game{
    int gameNumber;
    int set1[3];
    int set2[3];
    int set3[3];
    int red=0;
    int green=0;
    int blue=0;
    int possible = 1;
    int maxRed = 0;
    int maxGreen = 0;
    int maxBlue = 0;
};

int i, j, k;
int total = 0;
ofstream output("output.txt");
ifstream input("input.txt");
string s;


game parser(string s) {
    game current;
    size_t start = s.find("Game ") + 5;
    size_t end = s.find(":", start);
    current.gameNumber = stoi(s.substr(start, end - start));
    start = s.find(":", end) + 2;
    for(int i=start;i<=s.length();i++){
        if(s[i]<=57 && s[i]>=48){
            int number;
            if(s[i+1]<=57 && s[i+1]>=48){
                number = (s[i] - '0')*10 + (s[i+1] - '0');
                i++;
            } else {
                number = (s[i] - '0');
            }
            i+=2;
            if(s[i] == 'r'){
                current.red += number;
            } else if(s[i] == 'g'){
                current.green += number;
            } else if(s[i] == 'b'){
                current.blue += number;
            }
        }
        if(s[i] == ';' || i+1 == s.length()){
            if(current.red>current.maxRed){
                current.maxRed = current.red;  
            }
            if(current.blue>current.maxBlue){
                current.maxBlue = current.blue;
            }
            if(current.green>current.maxGreen){
                current.maxGreen = current.green;
            }
            current.red = 0;
            current.green = 0;
            current.blue = 0;
        }
    }
    return current;
}

void second_part(){
    while(getline(input, s)){
        game current = parser(s);
        total += current.maxRed*current.maxGreen*current.maxBlue;    
        output << current.gameNumber << endl;
        output << current.gameNumber << " " << current.red << " " << current.green << " " << current.blue << endl;
    }
}

void first_part(){
    while(getline(input, s)){
        game current = parser(s);
        if(current.possible==1){
            total += current.gameNumber;
            output << current.gameNumber << endl;
        }   
        output << current.gameNumber << " " << current.red << " " << current.green << " " << current.blue << endl;
    }
}

int main(){
    first_part();
    cout << total << endl;
}