#include<bits/stdc++.h>
#include<time.h>

using namespace std;

void computeLPSArray(string pat, int M, int* lps) 
{ 
    int len = 0; 
    lps[0] = 0; 
    int i = 1; 

    while (i < M) {
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else  
        {  
            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else  { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

void KMPSearch(string pat, string txt) 
{ 
    int M = pat.size(); 
    int N = txt.size(); 
    int lps[M]; 
  
    computeLPSArray(pat, M, lps); 
  
    int i = 0;  
    int j = 0;  

    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
        if (j == M) { 
            printf("Found pattern at index %d \n", i - j); 
            j = lps[j - 1]; 
        } 
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
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

    clock_t ct = clock();
    KMPSearch(a,t);
    ct = clock() - ct;
    cout <<"Time: " <<(double)(((double)ct)/CLOCKS_PER_SEC) << endl;
    return 0;
}