#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){

    set < pair < int , string > >s;

    int n;
    cin>>n;

    while(n--)
    {
        string str;
        cin>>str;

        if(str=="born"){
            string name;
            int age;
            cin>>name>>age;
            s.insert({age,name});
        }
        else if(str=="find"&&s.size()>0){
            string name;
            int age;
            cin>>name>>age;
            auto it=s.find({age,name});

            if(it!=s.end()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(str=="kill"&&s.size()>0){
            string name;
            int age;
            cin>>name>>age;
            s.erase({age,name});
        }
        else if(str=="young"&&s.size()>0){

            cout<<(s.begin())->second<<" "<<(s.begin())->first<<endl;

        }

    }

}
