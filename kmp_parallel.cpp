#include<bits/stdc++.h>
#include<omp.h>

#define NUM_THREADS 4

using namespace std;

int* kmp_init(string v, int m) {

    int *f = new int[m+1];
    f[0]=0; f[1]=0;
    int i=2, j=0;

    while (i<=m) {

        if (v[j]==v[i-1]) {
            j++;
            f[i]=j;
            i++;
        }
        else if (j==0) {
            f[i]=0;
            i++;
        }
        else {
            j=f[j];
        }
    }

    return f;
}

void kmp_search(string v, string b, char r[], int m, int n, int* f) {
    int i=0, j=0;

    while (i<n) {
    
        if (v[j]==b[i]) {
            j++;
            i++;
            if (j==m) { 
                j=f[j]; 
                r[i-m]=1; 
            }
        } else if (j==0) { 
            i++; 
        }
        else { 
            j=f[j]; 
        }
    }
}

void kmp_parallel(int p, string v, string b, char r[], int m, int n) {
    
    omp_set_num_threads(p);
    int *f = kmp_init(v,m);
    int pos=n-m+1;
    
    #pragma omp parallel for
    for (int proc=0;proc<p;proc++) {
        int start=proc*pos/p;
        int end=(proc+1)*pos/p;
        kmp_search(v,b.substr(start, end-start+m),r+start,m,end-start+m-1,f);
    }
}

int main() {

    ifstream fin;
    string a, t;
    fin.open("2.txt");
    getline(fin, t);
    fin.close();

    cin>>a;

    int n = t.size(), m = a.size();
    char *r = new char[n];
    
    clock_t ct = clock();
    kmp_parallel(NUM_THREADS,a,t,r,m,n);
    ct = clock() - ct;
    cout << (double)(((double)ct)/CLOCKS_PER_SEC) << endl;
    return 0;
}