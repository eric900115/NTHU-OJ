#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

 bool comp( int a,  int b){
     return a < b;
 }

int main()
{
    set <int> myset;

    int num;
    cin>>num;
    //int min_num=65536;
    for(int i=0;i<num;i++){

        string op;
        cin>>op;

        if(op=="print"&&myset.size()>0)
        {
            //auto s=myset.rbegin;
            //sort(myset.begin(),myset.end(),comp);
            for(auto i=myset.begin();i!=--myset.end();i++)
            {
                //auto s=myset.begin()+myset.size()-1;
                //cout<<distance(i,myset.end());
                //if(distance(i,myset.end())!=1)
                    cout<<*i<<" ";
                //else
                  //  cout<<*i;
            }
            cout<<*(myset.rbegin());
            cout<<endl;
        }
        else if(op=="range_erase")
        {
           // sort(myset.begin(),myset.end(),comp);

            int l,r;
            cin>>l>>r;

            //std::vector<int>::iterator low,up;
           // auto low=lower_bound (myset.begin(), myset.end(),l);
            //auto up=upper_bound (low, myset.end(),r);
            //std::vector<int>::iterator ,up;
            //low=low-myset.begin();
            //up=up-myset.begin();
            //cout<<up-myset.begin();
            myset.erase(myset.lower_bound(l),myset.upper_bound(r));
            //if(myset.size()==0)min_num=65536;
        }
        else if(op=="min"&&myset.size()>0)
        {
            cout<<*(myset.begin())<<endl;
        }
        else if(op=="insert")
        {
            int l;
            cin>>l;
            myset.insert(l);

        }
    }

    return 0;
}
