#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int i, j, k;
int total = 0;
ofstream output("output.txt");
ifstream input("input.txt");
string s; 

void first_part(){
    while(getline(input, s)){
        int firstEncounter = -1, lastEncounter = -1;
        for(i = 0, j=s.length()-1; i < s.length(); i++, j--){
            if(s[i]<=57 && s[i]>=48 && firstEncounter == -1){
                firstEncounter = i;
            }
            if(s[j]<=57 && s[j]>=48 && lastEncounter == -1){
                lastEncounter = j;
            }
        }
        total += (s[firstEncounter] - '0')*10 + (s[lastEncounter] - '0');
        output << s[firstEncounter] << s[lastEncounter] << endl;
    }
    cout << total << endl;
}

string clear_string(string s) {
    const string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const string numbers[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (int i = 0; i < 10; i++) {
        size_t pos = s.find(words[i]);
        while (pos != string::npos) {
            s.replace(pos, words[i].length(), numbers[i]);
            pos = s.find(words[i], pos + numbers[i].length());
        }
    }

    return s;
}

void second_part(){
    while(getline(input, s)){
        s = clear_string(s);
        int firstEncounter = -1, lastEncounter = -1;
        for(i = 0, j=s.length()-1; i < s.length(); i++, j--){
            if(s[i]<=57 && s[i]>=48 && firstEncounter == -1){
                firstEncounter = i;
            }
            if(s[j]<=57 && s[j]>=48 && lastEncounter == -1){
                lastEncounter = j;
            }
        }
        total += (s[firstEncounter] - '0')*10 + (s[lastEncounter] - '0');
        output << s[firstEncounter] << s[lastEncounter] << endl;
    }
    cout << total << endl;
}

int main(){
    first_part();
}