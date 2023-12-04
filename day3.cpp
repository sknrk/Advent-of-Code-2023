#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int total = 0;
ofstream output("output.txt");
ifstream input("input.txt");
string s; 
vector<string> engine_map;
int deltas[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<vector<bool> > visited(10000, vector<bool>(10000, false));

bool checksymbol(int i, int j){
    if(i<0 || j<0 || i>=engine_map.size() || j>=engine_map[0].size()){
        return true;
    }

    int value = engine_map[i][j];
    if((value >= 33 && value <= 47 && value != 46) || (value >= 58 && value <= 64)) {
        return false;
    }

    return true;
}

void first_part(){
    string line;
    while (getline(input, line)) {
        engine_map.push_back(line);
    }

    int n = engine_map.size();
    int m = n > 0 ? engine_map[0].size() : 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int number = 0;
            bool isClean = true;
            while(engine_map[i][j]<=57 && engine_map[i][j]>=48){
                for (int k = 0; k < 8; ++k) {
                    int new_i = i + deltas[k][0];
                    int new_j = j + deltas[k][1];

                    if (!checksymbol(new_i, new_j)) {
                        isClean = false;
                        break;
                    }
                }

                number = number*10 + (engine_map[i][j] - '0');
                if(j+1<m && engine_map[i][j+1]<=57 && engine_map[i][j+1]>=48){
                    j++;
                }
                else{
                    break;
                }
            }
            if(number!=0 && !isClean){
                total += number;
                output << number << endl;
            }
        }
    }
    cout << total << endl;

}

int multiply_numbers(int i, int j){
    if(i<0 || j<0 || i>=engine_map.size() || j>=engine_map[0].size()){
        return 0;
    }

    if(engine_map[i][j]<=57 && engine_map[i][j]>=48){
        int number = engine_map[i][j] - '0';    
        int j1=j,j2=j;
        int multiplier = 10;
        visited[i][j] = true;

        while(engine_map[i][j1+1]<=57 && engine_map[i][j1+1]>=48){
            number = number*10 + (engine_map[i][j1+1] - '0');
            multiplier *= 10;
            visited[i][j1+1] = true;
            if(j1+1<engine_map[i].size())
                j1++;
            else
                break;
        }
        while(engine_map[i][j2-1]<=57 && engine_map[i][j2-1]>=48){
            number += (engine_map[i][j2 - 1] - '0') * multiplier;
            multiplier *= 10;
            visited[i][j2-1] = true;
            if(j2-1>=0)
                j2--;
            else
                break;
        }
        return number;
    }   


    return 0;
}


void second_part(){
    string line;
    while (getline(input, line)) {
        engine_map.push_back(line);
    }

    int n = engine_map.size();
    int m = n > 0 ? engine_map[0].size() : 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int number = 0;
            bool isClean = true;

            if(engine_map[i][j]==42){
                int multiplier = 1; int counter = 0;
                int value = 0;
                for (int k = 0; k < 8; ++k) {
                    int new_i = i + deltas[k][0];
                    int new_j = j + deltas[k][1];
                    if (!visited[new_i][new_j]) {
                        visited[new_i][new_j] = true;
                        value = multiply_numbers(new_i, new_j);
                        if(value!=0){
                            counter++;
                            multiplier *= value;
                        }
                        cout << value << endl;
                        value = 0;
                    }
                }
                if(counter==2){
                    total += multiplier;
                    output << multiplier << endl;
                }
            }
        }
    }
    cout << total << endl;

}

int main(){
    second_part();
}