#include<bits/stdc++.h>

using namespace std;

int main() {

    ifstream fin;
    string a = "fgh", t;
    fin.open("1.txt");
    getline(fin, t);
    fin.close();
    
    int n = t.size(), m = a.size();

    int D[m][n];
    for(int i=0;i<m;i++) D[i][0] = 0;
    for(int i=0;i<n;i++) D[0][i] = (t[i] == a[0]) ? 1 : 0;

    for(int i=1;i<m;i++) {
        for(int l=1;l<n;l++) {
            D[i][l] = (a[i] == t[l] && D[i-1][l-1]) ? 1 : 0;
        }
    }

    for(int l=0;l<n;l++) {
        if(D[m-1][l])        
            cout<<l<<" ";
    }
    cout<<"\n";

    return 0;
}