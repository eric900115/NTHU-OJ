#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool myfunction (int i,int j) { return i<j; }

int main()
{
    int num,q;
    cin>>num;
    vector <int> arr(num);

    for(int i=0;i<num;i++)
        cin>>arr[i];

    sort(arr.begin(),arr.end(),myfunction);

    cin>>q;
    for(int i=0;i<q;i++)
    {
        vector<int>::iterator low,up;
        int t;
        cin>>t;
        low=lower_bound(arr.begin(),arr.end(),t);
        up=upper_bound(arr.begin(),arr.end(),t);
        int u=(up- arr.begin()),l=(low-arr.begin());
        cout<<u-l<<endl;

    }

    return 0;
}
