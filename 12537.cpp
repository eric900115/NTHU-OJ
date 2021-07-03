#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    int num;
    cin>>num;

    set <pair<int,int>> s;
    vector <int>v;

    for(int i=0;i<num;i++){

        string str;
        cin>>str;

        if(str=="max"&&v.size()>0)
            cout<<(*(s.rbegin())).first<<" "<<(*(s.rbegin())).second<<endl;

        else if(str=="find"){
            int tmp;
            cin>>tmp;
            if(tmp<=v.size())
            /*    auto it=find_if(s.begin(), s.end(), [=](const pair<int,int>& p){ return p.second == tmp; });
            //auto it=find(s.begin(),s.end(),tmp);
                if(it!=s.end())
                    cout<<(*it).first<<endl;}*/
                cout<<v[tmp-1]<<endl;

        }
        else if(str=="min"&&v.size()>0)
            cout<<(*(s.begin())).first<<" "<<(*(s.begin())).second<<endl;
        else if(str=="push_back"){
            int tmp;
            cin>>tmp;
            s.insert({tmp,v.size()+1});
            v.push_back(tmp);
        }
        else if(str=="pop_back"&&v.size()>0){
            int tmp=v[v.size()-1];
            s.erase({tmp,v.size()});
            v.pop_back();
            //auto it = find_if(s.begin(), s.end(), [=](const pair<int,int>& p){ return p.first == tmp; });
        }


    }


}
