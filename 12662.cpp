#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,p,k;
        cin>>n>>p>>k;

        vector <int> a(n+1);
        vector <int> prefix(n+1,0);
        for(int i=1;i<=n;i++) cin>>a[i];

        sort(a.begin()+1,a.end());

        prefix[0]=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<prefix[i];
            if(i<k) prefix[i]=prefix[i-1]+a[i];
            else prefix[i]=prefix[i-k]+a[i];
        }
        int tmp=0;
        for(int i=1;i<=n;i++){
            //cout<<prefix[i]<<" ";
            if(prefix[i]<=p) tmp=i;//***/
        }
        cout<<tmp<<"\n";
    }
}
