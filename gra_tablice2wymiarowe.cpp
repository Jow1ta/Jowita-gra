#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;
int main (){

srand(time(0));

const int w = 10;
const int k = 20;

char t[w][k];

int x = k/2;
int pkt = 0;

const int MAX = 5;

int px[MAX];
int py[MAX];
char z[MAX];

int licz = 0;

for(int i = 0; i < MAX; i++){
    px[i] = rand()%k;
    py[i] = rand()%3;
    z[i] = (rand()%2 ==0)?'+';'-';
}

while(pkt>=0){
    system("cls");

    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            t[i][j] = '';
        }
    }
}
t[w-1][x] = 'O';
int ile = 1 + pkt/5-;
if(ile > MAX){
    ile = MAX;
}
for(int i = 0; i <ile; i++){
    t[py[i][px[i] = z[i];
}
cout<<"SCORE: "<<pkt<<endl;
cout<<endl;
}

