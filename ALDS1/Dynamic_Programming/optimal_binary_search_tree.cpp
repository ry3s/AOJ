#include <bits/stdc++.h>

using namespace std;
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007
#define INF (1<<28)
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
#define floot10 cout<<fixed<<setprecision(10);
#define int long long int
double p[5000],q[5000],sump[5000],sumq[5000];
double memo[5000][5000];

int main(){
    floot10;
    int n;
    cin>>n;
    lp(i,n) cin>>p[i+1];
    lp(i,n+1) cin>>q[i];
    sumq[0]=q[0];
    lp(i,n){
        sump[i+1]=sump[i]+p[i+1];
        sumq[i+1]=sumq[i]+q[i+1];
    }
    lps(i,1,n+1){
        lps(j,1,n+1){
            if(j>=i)memo[i][j]=INF;
            else memo[i][j]=0;
        }
    }
    lps(l,1,n+1){
        lps(i,1,n+2-l){
            int j=i+l-1;
            lps(k,i,j+1){
                double sum=sump[j]-sump[i-1];
                if(i==1) sum+=sumq[j];
                else{
                    sum+=sumq[j]-sumq[i-2];
                }
                memo[i][j]=min(memo[i][j],sum-p[k]+memo[i][k-1]+memo[k+1][j]);
            }
        }
    }
    cout<<memo[1][n]+sump[n]+sumq[n]<<endl;
    return 0;
}
