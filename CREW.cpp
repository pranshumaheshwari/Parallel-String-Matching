#include<bits/stdc++.h>
#include<omp.h>

#define NUM_THREADS 4

using namespace std;

vector<int> v;

int main() {
    ifstream fin;
    string a, t;
    fin.open("1.txt");
    getline(fin, t);
    fin.close();

    cin>>a;
    omp_set_num_threads(omp_get_max_threads());

    int n = t.size(), m = a.size();
    vector<vector<int> > check(m, vector<int>(n, 0));
    int *SUM = new int[n];

    double start = omp_get_wtime();

    #pragma omp parallel for shared(a,t,check)
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

    #pragma omp parallel for shared(m)
    for(int i=0;i<n;i++) {
        if(SUM[i] == m) {
            #pragma omp critical
                v.push_back(i);
        }
    }

    double end = omp_get_wtime();
    
    for(auto it : v) {
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<"Time: "<<end-start<<"\n";

    return 0;
}