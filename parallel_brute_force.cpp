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

    int n = t.size(), m = a.size();
    int tid, start, end;

    int partSize = n / NUM_THREADS;
    int remainder = n % NUM_THREADS;

    omp_set_num_threads(NUM_THREADS);

    double ts = omp_get_wtime();

    #pragma omp parallel num_threads(NUM_THREADS) private(tid,start,end) shared(t,a,remainder,partSize,m)
    {
        tid=omp_get_thread_num();
        long long j;

        if(tid == 0) {
            start = tid;
            end = partSize - 1;
        } else {
            start = (tid * partSize) - m;
            end = (tid * partSize) + partSize - 1;
        }
        for(long long i=start;i<=end-m;i++) {
            for(j=0;j<m;j++)
                if(t[i+j] != a[j])
                    break;
            if(j == m) {
                #pragma omp critical
                    v.push_back(i);
            }
        }
    }
    if(remainder != 0) {
        long long j;
        start = (NUM_THREADS+1) * partSize;
        end = n;
        for(long long i=start;i<=end-m;i++) {
            for(j=0;j<m;j++)
                if(t[i+j] != a[j])
                    break;
            if(j == m) {
                #pragma omp critical
                    v.push_back(i);
            }
        }
    }

    double te = omp_get_wtime();

    for(auto it : v) {
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<"Time: "<<te-ts<<"\n";

    return 0;
}