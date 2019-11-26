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
    vector<int> check(n, 1);

    #pragma omp parallel for
    for(long long i=0;i<n*m;i++) {
        int id = i / m;
        int j = i % m;
        if(a[j] != t[id+j]) {
            check[id] = 0;
        }
    }

    #pragma omp parallel for
    for(int i=0;i<n;i++) {
        if(check[i]) {
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