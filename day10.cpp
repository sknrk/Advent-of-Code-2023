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

int total = 0, n, multiplier = 1, stack_counter = 0, max_counter = 0, starter_i, starter_j;
ofstream output("output.txt");
ifstream input("input.txt");
string s, temp, directions; 
string tunnel_map[1000];
int counter_map[1000][1000];
// map <string, pair(int,int)> test[10]={{'|',{1,0},},{'-',{0,1}},{'L',{1,1}},{'J',{1,-1}}};
multimap<char, pair<int, int>> test;

struct QueueItem {
    int i;
    int j;
    int counter;
};

queue<QueueItem> direction_queue;

void recursive_travel(int i,int j,int counter){
    if(i<0 && i>=n && j<0 && j>=tunnel_map[i].size()){
        return;
    }
    counter_map[i][j]=counter;
    if(counter > max_counter){
        max_counter = counter;
    }

    for (const auto& pair : test) {
        if(pair.first == tunnel_map[i][j]){
            int new_i=i+pair.second.first;
            int new_j=j+pair.second.second;
            if(new_i>=0 && new_i<n && new_j>=0 && new_j<tunnel_map[i].size() && tunnel_map[new_i][new_j]!='.' && counter_map[new_i][new_j]==0){

                counter_map[new_i][new_j]=counter+1;
                QueueItem item = {new_i, new_j, counter+1};
                direction_queue.push(item);
            }
        }
    }

    while (!direction_queue.empty()) {
        QueueItem front = direction_queue.front();
        direction_queue.pop();
        recursive_travel(front.i, front.j, front.counter);
    }
}

void recursive_travel_dfs(int i,int j,int counter){
    if(i<0 && i>=n && j<0 && j>=tunnel_map[i].size()){
        return;
    }
    counter_map[i][j]=counter;
    if(counter > max_counter){
        max_counter = counter;
    }

    for (const auto& pair : test) {
        if(pair.first == tunnel_map[i][j]){
            int new_i=i+pair.second.first;
            int new_j=j+pair.second.second;
            if(new_i>=0 && new_i<n && new_j>=0 && new_j<tunnel_map[i].size() && tunnel_map[new_i][new_j]!='.' && counter_map[new_i][new_j]==0){

                counter_map[new_i][new_j]=counter+1;
                // QueueItem item = {new_i, new_j, counter+1};
                // direction_queue.push(item);
                recursive_travel_dfs(new_i, new_j, counter+1);
            }
        }
    }

}


void first_part(){
    test.insert({'|', {-1, 0}});
    test.insert({'|', {1, 0}});
    test.insert({'-', {0, 1}});
    test.insert({'-', {0, -1}});
    test.insert({'L', {0, 1}});
    test.insert({'L', {-1, 0}});
    test.insert({'J', {-1, 0}});
    test.insert({'J', {0, -1}});
    test.insert({'7', {1, 0}});
    test.insert({'7', {0, -1}});
    test.insert({'F', {1, 0}});
    test.insert({'F', {0, 1}});

    int i,j,m;
    while(getline(input,s)){
        stringstream ss(s);
        while(1){
            if(ss>>temp){
                tunnel_map[n++]=temp;
            }
            else{
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<tunnel_map[i].size();j++){
            output << tunnel_map[i][j] << " ";
            if(tunnel_map[i][j]=='S'){
                counter_map[i][j]=1;
                if(tunnel_map[i][j-1]=='-' || tunnel_map[i][j-1]=='F' || tunnel_map[i][j-1]=='L'){
                    QueueItem item = {i, j-1, 2};
                    direction_queue.push(item);
                    starter_i=i; starter_j=j;
                    return recursive_travel_dfs(i,j-1,2);
                }
                if(tunnel_map[i][j+1]=='-' || tunnel_map[i][j+1]=='7' || tunnel_map[i][j+1]=='J'){
                    QueueItem item = {i, j+1, 2};
                    direction_queue.push(item);
                    starter_i=i; starter_j=j;
                    return recursive_travel_dfs(i,j+1,2);
                }
                if(tunnel_map[i+1][j]=='|' || tunnel_map[i+1][j]=='L' || tunnel_map[i+1][j]=='J'){
                    QueueItem item = {i+1, j, 2};
                    direction_queue.push(item);
                    starter_i=i; starter_j=j;
                    return recursive_travel_dfs(i+1,j,2);
                }
                if(tunnel_map[i-1][j]=='|' || tunnel_map[i-1][j]=='F' || tunnel_map[i-1][j]=='7'){
                    QueueItem item = {i-1, j, 2};
                    direction_queue.push(item);
                    starter_i=i; starter_j=j;
                    return recursive_travel_dfs(i-1,j,2);
                }

                starter_i=i; starter_j=j;
                recursive_travel_dfs(i,j,1);
            }
        }
        output << endl;
    }
    for(i=0;i<n;i++){
        for(j=0;j<tunnel_map[i].size();j++){
            output << counter_map[i][j] << "     ";
        }
        output << endl;
    }
    cout << max_counter << endl;
}

int void_counter=0;
int deltas[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


void count_void(int i,int j){
    if(counter_map[i][j]==0){
        void_counter++;
        counter_map[i][j]=-1;
    }
    for(int k=0;k<4;k++){
        int new_i=i+deltas[k][0];
        int new_j=j+deltas[k][1];
        if(new_i>=0 && new_i<n && new_j>=0 && new_j<tunnel_map[i].size() && counter_map[new_i][new_j]==0){
            count_void(new_i,new_j);
        }
    }
}

// 0 - down
// 1 - left
// 2 - up
// 3 - right


// down
// left right

// left
// up down

// up
// right left

// right
// down up



void print_counter_map(){
    for(int i=0;i<n;i++){
        for(int j=0;j<tunnel_map[i].size();j++){
            cout << counter_map[i][j] << "     ";
        }
        cout << endl;
    }   
}

int finish=1;
int directioni, directionj;
int clockwise[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int clockwise_counter=0;
int direction = 0; 


void travel_and_count(int i,int j){
    // if(counter_map[i][j]==max_counter){
    //     finish=-1;
    // }  
    int new_i = i+clockwise[clockwise_counter][0];
    int new_j = j+clockwise[clockwise_counter][1];
    if(new_i>=0 && new_i<n && new_j>=0 && new_j<tunnel_map[i].size() && counter_map[new_i][new_j]==0){
        cout << "count void activated" << endl;
        // print_counter_map();
        count_void(new_i,new_j);
    }

    // print_counter_map();
    // cout << endl << i << " " << j << endl;
    // cout << counter_map[i][j] << endl;
    // cout << "clockwise_counter: " << clockwise_counter << endl;
    // cout << "direction: " << direction << endl;

    // cin >> temp;
    // system("clear");
    int goi,goj;
    for(int k=0;k<4;k++){
        int new_i=i+deltas[k][0];
        int new_j=j+deltas[k][1];
        if(new_i>=0 && new_i<n && new_j>=0 && new_j<tunnel_map[i].size() && counter_map[new_i][new_j]==counter_map[i][j]+1){
            if(direction==0){
                if(new_j>j){
                    clockwise_counter++;
                    direction=1;
                }
                else if(new_j<j){
                    clockwise_counter--;
                    direction=3;
                }
            }
            if(direction==1){
                if(new_i>i){
                    clockwise_counter--;
                    direction=0;
                }
                else if(new_i<i){
                    clockwise_counter++;
                    direction=2;
                }
            }
            if(direction==2){
                if(new_j>j){
                    clockwise_counter--;
                    direction=1;
                }
                else if(new_j<j){
                    clockwise_counter++;
                    direction=3;
                }
            }
            if(direction==3){
                if(new_i>i){
                    clockwise_counter++;
                    direction=0;
                }
                else if(new_i<i){
                    clockwise_counter--;
                    direction=2;
                }
            }
            if(clockwise_counter==4) clockwise_counter=0;
            if(clockwise_counter==-1) clockwise_counter=3;
            
            travel_and_count(new_i,new_j);
        }
    }

}   

void second_part(){
    first_part();
    travel_and_count(starter_i, starter_j);
    for(int i=0;i<n;i++){
        for(int j=0;j<tunnel_map[i].size();j++){
            output << counter_map[i][j] << "     ";
        }
        output << endl;
    }   
    cout << void_counter << endl;
}

int main(){
    second_part();
}