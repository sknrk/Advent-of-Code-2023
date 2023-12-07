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

using namespace std;

int total = 0, n, multiplier = 1;
ofstream output("output.txt");
ifstream input("input.txt");
string s, temp; 
string cards[10000];
int scores[10000];
double hand_values[10000];

int map_card_value(char card) {
    if (card >= '2' && card <= '9') {
        return card - '0';
    }
    map<char, int> high_cards = {{'T', 10}, {'J', 1}, {'Q', 12}, {'K', 13}, {'A', 14}};
    return high_cards[card];
}

double check_cards(string card){
    int cards_value[15] = {0};
    int max_value = 0; 
    for(int i=0;i<=4;i++){
        int value = map_card_value(card[i]);
        cards_value[value]++;
        if (value > max_value) {
            max_value = value;
        }
    }
    double double_card=0.01*map_card_value(card[0]) + 0.0001*map_card_value(card[1]) + 0.000001*map_card_value(card[2]) + 0.00000001*map_card_value(card[3]) + 0.0000000001*map_card_value(card[4]);
    // printf("%.10f\n", double_card);
    for(int i=2;i<=14;i++){
        if(cards_value[i] == 5){
            return 7+double_card;
        }
        if(cards_value[i] == 4){
            return 6+double_card;
        }
        if(cards_value[i] == 3){
            for(int j=2;j<=14;j++){
                if(cards_value[j] == 2){
                    return 5+double_card;
                }
            }
            return 4+double_card;
        }
        if(cards_value[i] == 2){
            for(int j=2;j<=14;j++){
                if(cards_value[j] == 3){
                    return 5+double_card;
                }
            }
            for(int j=2;j<=14;j++){
                if(cards_value[j] == 2 && j!=i){
                    return 3+double_card;
                }
            }
            return 2+double_card;
        }
    }
    return 1 + double_card;
}

void first_part(){
    int i=0,j,m,n=0;
    while (getline(input,s))
    {
        stringstream ss(s);
        ss >> cards[n];
        ss >> scores[n];
        hand_values[n++] = check_cards(cards[n]);   
        // output << std::fixed << std::setprecision(10) << cards[n-1] << ": " << hand_values[n-1] << endl;
    }
    n=n-1;
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(hand_values[i] > hand_values[j]){
                swap(hand_values[i], hand_values[j]);
                swap(cards[i], cards[j]);
                swap(scores[i], scores[j]);
            }
        }
    }
    for(i=0;i<=n;i++){
        output << std::fixed << std::setprecision(10) << cards[i] << ": " << hand_values[i] << ": " << i << ": " << scores[i] << endl;
        total += (i+1)*scores[i];
    }
    cout << total << endl;
}

double check_cards2(string card){
    int i;
    int cards_value[15] = {0};
    int max_value = 0; 
    for(int i=0;i<=4;i++){
        int value = map_card_value(card[i]);
        cards_value[value]++;
        if (value > max_value) {
            max_value = value;
        }
    }
    double double_card=0.01*map_card_value(card[0]) + 0.0001*map_card_value(card[1]) + 0.000001*map_card_value(card[2]) + 0.00000001*map_card_value(card[3]) + 0.0000000001*map_card_value(card[4]);
    for(int i=1;i<=14;i++){
        if(cards_value[i] == 5 || (cards_value[1]+cards_value[i]==5 && i!=1)){
            return 7+double_card;
        }
    }
    for(int i=1;i<=14;i++){
        if(cards_value[i] == 4 || (cards_value[1]+cards_value[i]==4 && i!=1)){
            return 6+double_card;
        }
    }
    for(int i=1;i<=14;i++){
        if(cards_value[i] == 3){
            for(int j=1;j<=14;j++){
                if((cards_value[j] == 2 || (cards_value[1]+cards_value[j]==2 && i!=1)) && j!=i){
                    return 5+double_card;
                }
            }
            return 4+double_card;
        }
        if(cards_value[1]+cards_value[i]==3 && i!=1){
            for(int j=2;j<=14;j++){
                if(cards_value[j] == 2 && j!=i){
                    return 5+double_card;
                }
            }
            return 4+double_card;
        }
    }

    for(int i=1;i<=14;i++){
        if(cards_value[i] == 2){
            for(int j=1;j<=14;j++){
                if((cards_value[j] == 2 || (cards_value[1]+cards_value[j]==2 && j!=1)) && j!=i){
                    return 3+double_card;
                }
            }
            return 2+double_card;
        }
        if(cards_value[1]+cards_value[i]==2 && i!=1){
            for(int j=2;j<=14;j++){
                if(cards_value[j] == 2 && j!=i){
                    return 3+double_card;
                }
            }
            return 2+double_card;
        }
    }
    return 1 + double_card;
}


void second_part(){
        int i=0,j,m,n=0;
    while (getline(input,s))
    {
        stringstream ss(s);
        ss >> cards[n];
        ss >> scores[n];
        hand_values[n++] = check_cards2(cards[n]);   
        // output << std::fixed << std::setprecision(10) << cards[n-1] << ": " << hand_values[n-1] << endl;
    }
    n=n-1;
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(hand_values[i] > hand_values[j]){
                swap(hand_values[i], hand_values[j]);
                swap(cards[i], cards[j]);
                swap(scores[i], scores[j]);
            }
        }
    }
    for(i=0;i<=n;i++){
        output << std::fixed << std::setprecision(10) << cards[i] << ": " << hand_values[i] << ": " << i << ": " << scores[i] << endl;
        total += (i+1)*scores[i];
    }
    cout << total << endl;
}

int main(){
    second_part();
}





