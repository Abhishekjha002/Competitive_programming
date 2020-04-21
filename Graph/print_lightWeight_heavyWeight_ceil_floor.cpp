#include<cstdio>
#include<algorithm>
#include<map>
#include<cstdlib>
#define pii pair<int,int>
using namespace std;
int n, P[60];
char p[5]="EWNS";
void Solve(){
    long long x,y;
    for(int z1=-4;z1<=4;z1++)
    {
        for(int z2=-4;z2<=4;z2++)
        {
            x = z1;
            y = z2;
            int i, j;
    for(i=1;i<=50;i++){
        long long tx=x,ty=y;
        for(j=i-1;j>=0;j--){
            if(abs(tx)>=abs(ty)){
                if(tx>0){
                    P[j]=0;
                    tx-=(1ll<<j);
                }
                else{
                    P[j]=1;
                    tx+=(1ll<<j);
                }
            }
            else{
                if(ty>0){
                    P[j]=2;
                    ty-=(1ll<<j);
                }
                else{
                    P[j]=3;
                    ty+=(1ll<<j);
                }
            }
        }
        if(tx==0&&ty==0){
            for(j=0;j<i;j++){
                printf("%c",p[P[j]]);
            }
            puts("");
            return;
        }
    }
    puts("IMPOSSIBLE");
        }
    }
    
}
int main(){
    Solve();
}