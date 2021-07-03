#include <iostream>
#include <vector>
using namespace std;

const int MAX_N=1e3+3;

int n;
int marked[MAX_N]={0};
int group=1;

class Data{
    public:
        Data(){
            marked=0;}
        int x,y;
        int marked;
};


vector <Data> arr;
vector <int> counter;
int r;
void dfs(int parent,int now)
{
    arr[now].marked=group;
    for(int i=0;i<n;i++)
    {
        if(i==parent) continue;
        if(arr[i].marked!=0) continue;
        int tmp=((arr[i].x-arr[now].x)*(arr[i].x-arr[now].x)+(arr[i].y-arr[now].y)*(arr[i].y-arr[now].y));
        //cout<<arr[i].marked<<" "<<i<<" "<<now<<endl;
        if(tmp<=(r*r))
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
        cin>>n>>r>>k;

        for(int i=0;i<n;i++)
        {
            int x,y;
            Data s;
            cin>>s.x>>s.y;
            arr.push_back(s);
        }




        for(int i=0;i<n;i++)
        {
            if(arr[i].marked==0)
            {
                //cout<<group;
                dfs(-1,i);
                group++;

            }
        }

        for(int i=1;i<group;i++)
            counter.push_back(0);

        for(auto i:arr)
            counter[i.marked-1]++;
        //cout<<endl;
        int c1=0,c2=0;
        for(auto i:counter)
        {
            // cout<<i;
            if(i<k)
                c2++;
            else c1++;
        }

        cout<<c2<<" "<<c1<<endl;
        arr.clear();
        counter.clear();
        group=1;
        marked[MAX_N]={0};
    }
    return 0;
}
