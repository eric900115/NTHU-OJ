#include <iostream>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int a,b,c,d;
        cin>>a>>b>>c>>d;

        int prefix[100001]={0},arr[100001]={0},prefix_ans[100001]={0};

        for(int i=a;i<=b;i++){
            arr[i+b]++;
            arr[i+c+1]--;
        }


        for(int i=1;i<=100001;i++)prefix[i]=prefix[i-1]+arr[i];

        for(int i=c;i<=b+c;i++)
                prefix_ans[i]=prefix_ans[i-1]+prefix[i];
                //cout<<prefix_ans[i];}

        long long int ans=0;
        for(int i=c;i<=d;i++)
            if(i<b+c) ans=ans+prefix_ans[b+c]-prefix_ans[i];
            //cout<<ans;}
        cout<<ans<<"\n";
    }

}
