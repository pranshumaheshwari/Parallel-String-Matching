#include<bits/stdc++.h>
#include<omp.h>

#define NUM_THREADS 4

using namespace std;

int main() {

    ifstream fin;
    string a, t;
    fin.open("1.txt");
    getline(fin, t);
    fin.close();

    cin>>a;
    
    omp_set_num_threads(NUM_THREADS);
    int n = t.size(), m = a.size();
    int **D = new int*[m];
    for(long long i=0;i<m;i++) {
        D[i] = new int[n];
    }
    vector<int> index;

    double start = omp_get_wtime();

    #pragma omp parallel for
    for(int i=0;i<m;i++) {
        D[i][0] = 0;
    }

    #pragma omp parallel for
    for(int i=0;i<n;i++) {
        D[0][i] = (t[i] == a[0]) ? 1 : 0;
    }

    for(int i=1;i<m;i++) {
        #pragma omp parallel for
        for(int l=i;l<n;l++) {
            D[i][l] = (a[i] == t[l] && D[i-1][l-1]) ? 1 : 0;
        }
    }

    double end = omp_get_wtime();

    for(int l=0;l<n;l++) {
        if(D[m-1][l])        
            index.push_back(l);
    }


    for(auto it : index) {
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<"Time: "<<end-start<<"\n";

    return 0;
}