#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main(){

    map <int,map<char,vector<string>>> bucket;
    queue < int > q;
    int num;
    cin>>num;

    for(int i=0;i<num;i++)
    {
        string str;
        cin>>str;
        int counter=0;
        char lastvowel;
        for(auto i: str)
        {
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u')
            {
                counter++;
                lastvowel=i;
            }
        }
        bucket[counter][lastvowel].push_back(str);
    }

    int comp=0,uc=0;
    for(auto i : bucket)
    {
        for (auto v : i.second )
        {
            comp+=(v.second.size())/2;
            uc+=(v.second.size())%2;
        }
        q.push(uc);
        uc=0;
    }

    uc=q.front();
    q.pop();
    int counter=0;

    for(int i=comp;i>0;i--)
    {
        if(uc>1){
            uc-=2;
            counter++;
        }
        else{
            if(!q.empty())
            {
                uc=q.front();
                q.pop();
                i++;
            }
            else{
                uc+=2;
            }
        }

    }
    cout<<counter<<endl;

}
