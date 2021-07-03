#include <iostream>
#include <queue>

using namespace std;
queue <pair<int,int>>q;
int toBeDestroyed=0;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
int n,m;
char **str=nullptr;
int bfs(){
    int dist;
    while(!q.empty())
    {
        int now_x,now_y;
        now_x=q.front().first;
        now_y=q.front().second;
        q.pop();
        dist=q.front().first;
        q.pop();
        //for(int i=0;i<n;i++){
       // for(int j=0;j<m;j++)
          //  cout<<str[i][j];
        //cout<<endl;}
        //cout<<now_x<<" "<<now_y<<" "<<dist<<endl;

        for(int s=0;s<4;s++)
        {
            int next_x,next_y;
            next_x=now_x+x[s];
            next_y=now_y+y[s];

            if(next_x>=n||next_x<0||next_y>=n||next_y<0)
                continue;

            if(str[next_x][next_y]=='C')
                continue;

            if(str[next_x][next_y]=='T'){
                toBeDestroyed--;
                if(toBeDestroyed==0)return dist+1;
            }

            str[next_x][next_y]='C';

            q.push({next_x,next_y});
            //dist++;
            q.push({dist+1,0});
        }
    }
    return -1;

}

int main()
{


    cin>>n>>m;

    str=new char*[n];

    for(int i=0;i<n;i++)
        str[i]=new char[m];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>str[i][j];
            if(str[i][j]=='I'){
                q.push({i,j});
                q.push({0,0});
            }
            else if(str[i][j]=='T')
                toBeDestroyed++;
        }
    //now_x=q.front().first;
    //now_y=q.front().second;


        cout<<bfs()<<endl;



    for(int i=0;i<n;i++)
        delete [] str[i];

    delete [] str;


    return 0;
}
