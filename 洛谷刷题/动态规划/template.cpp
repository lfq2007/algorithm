#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
bool cmp(int p,int q){
    return p>q;
}//尽量选大的才能保证答案最小
int main()
{
    int X,n,ans=0,SUM=0;
    cin>>X>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(a[n]!=1){//我们说过了，无解的情况
        cout<<-1<<endl;
        return 0;
    }
    while(SUM<X){//如果我们现在还不能凑出1~X的所有面值，那就要再选
        for(int i=1;i<=n;i++)
            if(a[i]<=SUM+1){
                SUM+=a[i];
                break;
            }
        ans++;//又选了一张
    }
    cout<<ans<<endl;
    return 0;
}
