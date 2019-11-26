#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

int main() {
    ifstream fin;
    string a = "fgh", t;
    fin.open("1.txt");
    getline(fin, t);
    fin.close();
    
    int n = t.size(), m = a.size();
    vector<int> index;

    for(long long i=0;i<=n-m;i++) {
        int j;
        for(j=0;j<m;j++)
            if(t[i+j]!=a[j])
                break;
        if(j == m)
            index.push_back(i);
    }

    for(auto it : index) {
        cout<<it<<" ";
    }
    cout<<"\n";

    return 0;
}