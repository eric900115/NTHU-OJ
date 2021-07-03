#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define Max(a,b) (a>b ?a :b)
#define Min(a,b) (a<b ?a :b)
using namespace std;
int main(){

int t;
cin>>t;
while(t--){
    vector <int> s(3);
    cin>>s[0]>>s[1]>>s[2];

    sort(s.begin(),s.end());

    if(s[1]<(s[1]+s[2]-s[0])/2) cout<<s[0]+s[1]<<"\n";
    else cout<<(s[1]+s[2]-s[0])/2+s[0]<<"\n";
}
}
