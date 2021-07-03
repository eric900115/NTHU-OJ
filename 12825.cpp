#include <iostream>
#include <vector>
#include <set>
using namespace std;

//const int MAX_N=1e3+3;



class Data{
    public:
        Data(){
            marked=0;}
        string str;
        int marked;
};
vector <Data> arr;
int n;
vector <vector<int>> ar;
int group=1;
int r;

void dfs(int parent,int now)
{
    arr[now].marked=group;

    for(auto i : arr[now].str){
        int tmp=i-'a';
        ar[group-1][tmp]++;}
        //ar[group-1].insert(i);

    for(int i=0;i<n;i++)
    {
        if(i==parent) continue;
        if(arr[i].marked!=0) continue;
        bool found=false;
        for (auto i:arr[i].str)
        {
            int tmp=i-'a';
            if(ar[group-1][tmp]!=0){
                found=true;
                break;}
        }
        if(found==true)
           dfs(now,i);
    }

}

int main()
{
    int num;
    cin>>num;

    for(int i=0;i<num;i++)
    {
        int k;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            int x,y;
            Data s;
            cin>>s.str;
            arr.push_back(s);
        }

        vector < int > ss(26,0);
        for(int i=0;i<n;i++)
        {
            if(arr[i].marked==0)
            {
                ar.push_back(ss);
                dfs(-1,i);
                group++;

            }
        }

        cout<<group-1<<endl;
        arr.clear();
        ar.clear();
        group=1;
    }
    return 0;
}
