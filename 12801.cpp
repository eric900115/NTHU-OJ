#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int day,line;
        cin>>day>>line;

        //vector <long long int> arr(day,0);
        int coffee[day];


        for(int i=0;i<day;i++)
            cin>>coffee[i];

        int L=0,R=day,ans=day,M;
        while(L<R)
        {
            M=(L+R)/2;
            long long int tmp=0;
            for(int j=0;j<day;j++)
            {
                int decrease=0;
                decrease=j/(M+1);
                //cout<<decrease<<" ";
                if(coffee[j]-decrease>0)
                    tmp+=coffee[j]-decrease;
            }
            //cout<<M<<" ";
            if(tmp>=line){
                cout<<tmp<<"   "<<M<<endl;
                ans=M;
                R=M;
            }
            else L=M+1;
            //cout<<arr[i]<<endl;
        }
        //auto it=lower_bound(arr.begin(),arr.end(),line);
        if(ans!=day)
            cout<<ans+1<<endl;
        else cout<<"-1"<<endl;
    }
}
