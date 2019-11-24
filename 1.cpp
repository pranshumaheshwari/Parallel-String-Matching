#include<bits/stdc++.h>

using namespace std;

int main() {

    string a = "GTTC", t = "GGGTTCTA";
    int n = t.size(), m = a.size();
    int D[m+1][n+1];
    for(int i=0;i<=n;i++) D[0][i] = 0;
    for(int i=0;i<=m;i++) D[i][0] = i;

    for(int i=1;i<=m;i++) {
        for(int l=1;l<=n;l++) {
            int temp = (a[i-1] == t[l-1]) ? D[i-1][l-1] : D[i-1][l-1] + 1;
            D[i][l] = min({ D[i-1][l] + 1, D[i][l-1] + 1, temp });
        }
    }

    for(int i=0;i<=m;i++) {
        for(int l=0;l<=n;l++) {
            cout<<D[i][l]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}