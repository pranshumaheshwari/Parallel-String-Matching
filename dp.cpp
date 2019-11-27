#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

int main() {

    ifstream fin;
    string a, t;
    fin.open("1.txt");
    getline(fin, t);
    fin.close();
    
    cin>>a;

    int n = t.size(), m = a.size();
    int D[m+1][n+1];
    vector<int> v;

    double start = omp_get_wtime();

    for(int i=0;i<=n;i++) D[0][i] = 0;
    for(int i=0;i<=m;i++) D[i][0] = i;

    for(int i=1;i<=m;i++) {
        for(int l=1;l<=n;l++) {
            int temp = (a[i-1] == t[l-1]) ? D[i-1][l-1] : D[i-1][l-1] + 1;
            D[i][l] = min({ D[i-1][l] + 1, D[i][l-1] + 1, temp });
        }
    }

    double end = omp_get_wtime();

    for(int l=0;l<=n;l++) {
        if(!D[m][l]) {
            v.push_back(l);
        }
    }

    for(auto it : v) {
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<"Time: "<<end-start<<"\n";

    return 0;
}