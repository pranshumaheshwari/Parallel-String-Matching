#include<bits/stdc++.h>

using namespace std;

int main() {

    ofstream fout;
    fout.open("3.txt");

    for(long long i=0;i<1E3;i++) fout<<(char)('a' + rand() % 26);

    fout.close();

    return 0;
}