#include<bits/stdc++.h>
#include<omp.h>

#define NUM_THREADS 4

using namespace std;

vector<int> v;

int main() {
    ifstream fin;
    string a = "fgh", t;
    fin.open("1.txt");
    getline(fin, t);
    fin.close();

    int n = t.size(), m = a.size();
    vector<vector<int> > check(m, vector<int>(n, 0));
    int SUM[n];

    #pragma omp parallel for
    for(long long i=0;i<n*m;i++) {
        int id = i / m;
        int j = i % m;
        if(a[j] == t[id+j]) {
            check[j][id] = 1;
        }
    }

    #pragma omp parallel for
    for(int i=0;i<n;i++) {
        SUM[i] = 0;
        #pragma omp parallel for reduction(+:SUM[i])
        for(int j=0;j<m;j++) {
            SUM[i] += check[j][i];
        }
    }

    #pragma omp parallel for
    for(int i=0;i<n;i++) {
        if(SUM[i] == m) {
            #pragma omp critical
                v.push_back(i);
        }
    }

    for(auto it : v) {
        cout<<it<<" ";
    }
    cout<<"\n";

    return 0;
}