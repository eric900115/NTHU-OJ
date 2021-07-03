#include <iostream>
#include <string>
#define mod 1000000007
using namespace std;

int main(){

    int num;
    cin>>num;

    for(int i=0;i<num;i++){

        long long int x,s_len,l;
        string str;
        cin>>x>>str;

        s_len=str.length();
        l=s_len;

        for(long long int j=1;j<=x;j++){
            long long int left=str[j-1]-'0';

            long long int add =(((l-j)%mod)*((left-1)))%mod;
            l=(l+add)%mod;
            //cout<<str<<" "<<add<<" "<<l<<" "<<" "<<s_len<<endl;
            if(s_len<=x&&(left-1)>0){
                string tmp=str.substr(j,s_len-j);
                long long int t_len=tmp.length();

                for(long long int k=1;k<=left-1&&s_len<=x;k++){
                    str+=tmp;
                    s_len+=t_len;
                }
            }
            if(l<0) l+=mod;

        }
        cout<<l%mod<<endl;



    }

}
