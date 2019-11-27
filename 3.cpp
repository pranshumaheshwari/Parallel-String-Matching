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
    vector<int> index;

    double start = omp_get_wtime();

    for(long long i=0;i<=n-m;i++) {
        int j;
        for(j=0;j<m;j++)
            if(t[i+j]!=a[j])
                break;
        if(j == m)
            index.push_back(i);
    }

    double end = omp_get_wtime();
    
    for(auto it : index) {
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<"Time: "<<end-start<<"\n";

    return 0;
}