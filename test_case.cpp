#include<bits/stdc++.h>

using namespace std;

int main() {

    ofstream fout;
    fout.open("1.txt");

    for(long long i=0;i<1E5;i++) fout<<(char)('a' + rand() % 26);

    fout.close();

    return 0;
}