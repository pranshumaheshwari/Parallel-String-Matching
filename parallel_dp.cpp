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
    vector<int> index;


    double start = omp_get_wtime();

    #pragma omp parallel for
    for(int i=0;i<=n;i++) {
        D[0][i] = 0;
    }

    #pragma omp parallel for
    for(int i=0;i<=m;i++) {
        D[i][0] = i;
    }

    for(int i=1;i<=m;i++) {
        #pragma omp parallel for
        for(int l=1;l<=n;l++) {
            int temp = (a[i-1] == t[l-1]) ? D[i-1][l-1] : D[i-1][l-1] + 1;
            D[i][l] = min({ D[i-1][l] + 1, temp });
        }
    }

    for(int l=1;l<=n;l++) {
        #pragma omp parallel for
        for(int i=1;i<=m;i++) {
            int temp = (a[i-1] == t[l-1]) ? D[i-1][l-1] : D[i-1][l-1] + 1;
            D[i][l] = min({ D[i][l-1] + 1, D[i][l], temp });
        }
    }

    double end = omp_get_wtime();

    #pragma omp parallel for
    for(int i=m;i<=n;i++) {
        if(!D[m][i]) {
            #pragma omp critical
                index.push_back(i);
        }
    }

    for(auto it : index) {
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<"Time: "<<end-start<<"\n";

    return 0;
}