#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<iomanip>
#define MAX_N 1000
#define MAX_Bit 5
#define MAX 100000
using namespace std;
class BigInt{
	public:
		int sign; // 正負號
		long long m[MAX_N];
		int l; //長度
		long long operator [](int i) const { return m[i]; }
		long long &operator [](int i) { return m[i]; }
		BigInt(){ l=1, m[0]=0; sign=1; }
		BigInt(int x){ (*this)=x; }
		BigInt(const char *s){ (*this)=s; }
        friend std::istream& operator>>(istream&, BigInt&);
        friend std::ostream& operator<<(ostream&, BigInt);
        BigInt operator +( const BigInt &y );
        BigInt operator -( const BigInt &y );
};
istream& operator>>(istream& os, BigInt& np)
{

    string ch;
	os>>ch;
    //memset(np.m,0,MAX_N);
	for(int i=0;i<MAX_N;i++)
        np.m[i]=0;

	if(ch[0]=='-')
    {
        ch=ch.substr(1,ch.length()-1);
        np.sign=-1;
	}
	else np.sign=1;

	reverse(ch.begin(), ch.end());
	int id=0;
	for(int i = 0 ; i < ch.length() ; i += MAX_Bit)
	{
		string sub = ch.substr(i,5);
		reverse(sub.begin(),sub.end());//reverse substring
		np.m[id++]=atoi(sub.c_str());//change str->num
        //.c_str() change type string into char*
	}
	np.l = id;

	return os;
}

//out.width(MAX_BIT)
//out.fill(0)
ostream& operator<<(ostream& os, BigInt np)
{
    if(np.sign==-1)os<<'-';

    os<<np[np.l-1];

    for(auto i=np.l-2;i>=0;i--)
        os<<setfill('0')<<setw(5)<<np[i];

    return os;
}
BigInt BigInt::operator +( const BigInt &y )
{

    BigInt np(*this);

    int len;
    int i=0;
    int carry=0;

    //for(int k=0;k<y.l;k++) cout<<y[k];
    //cout<<endl;
    //for(int k=0;k<np.l;k++)cout<<np[k];
    //cout<<endl;
    for(;i<np.l||i<y.l||carry;i++)
    {
        carry+=np[i]*np.sign+y[i]*y.sign;
        bool flag=false;
        np[i]=carry%100000;
        carry/=100000;
    }

    np.l=i;

    if(np[i-1]<0)
    {
        bool flag=false;
        for(int j=0;j<i;j++)
        {
            if(np[j]>0)
            {
                np[j]=100000-np[j];
                if(flag==true)
                    np[j]--;
                flag=true;
            }
            else
            {
                np[j]=abs(np[j]);
                if(flag==true)
                {
                    np[j]--;
                    flag=false;
                }
            }
        }
        np.sign=-1;
    }
    else
    {
        bool flag=false;
        for(int j=0;j<i;j++)
        {
            //cout<<np[j]<<endl;
            if(np[j]<0){
                np[j]=100000+np[j];
                if(flag==true){
                    np[j]--;}

                flag=true;}
            else
            {
                if(flag==true)
                {
                    np[j]--;
                    flag=false;
                }
            }
        }
        np.sign=1;

    }

    for(int k=np.l-1;k>=0;k--)
    {
        if(np[k]!=0)break;
        if(np[k]==0)np.l--;
    }

    if(np.l==0&&np[0]==0)
    {
        np.sign=1;
        np.l=1;
    }

    return np;

}
BigInt BigInt::operator -( const BigInt &y ){

   BigInt np(*this);

    int len;
    int i=0;
    int carry=0;

    //for(int k=0;k<y.l;k++) cout<<y[k];
    //cout<<endl;
    //for(int k=0;k<np.l;k++)cout<<np[k];
    //cout<<endl;


    for(;i<np.l||i<y.l||carry;i++)
    {

        //cout<<np[i]<<" "<<y[i]<<" "<<carry<<endl;
        carry+=np[i]*np.sign-y[i]*y.sign;
        bool flag=false;
    //    if(carry<0){
    //        flag=true;

        np[i]=carry%100000;

        carry/=100000;
        //cout<<np[i]<<" "<<carry<<endl;
    }
    np.l=i;

    if(np[i-1]<0){
        bool flag=false;
        for(int j=0;j<i;j++)
        {

            if(np[j]>0){
                np[j]=100000-np[j];
                if(flag==true) {
                np[j]--;}
                flag=true;}
            else {
                np[j]=abs(np[j]);
                if(flag==true) {
                np[j]--;
                flag=false;}
            }


        }
        np.sign=-1;
    }
    else{
        bool flag=false;
        for(int j=0;j<i;j++)
        {

            //cout<<np[j]<<endl;
            if(np[j]<0)
            {
                np[j]=100000+np[j];
                if(flag==true)
                    np[j]--;

                flag=true;
            }
            else
            {
                if(flag==true)
                {
                    np[j]--;
                    flag=false;
                }

            }
        }
        np.sign=1;

    }


    for(int k=np.l-1;k>=0;k--)
    {
        if(np[k]!=0)break;
        if(np[k]==0)np.l--;
    }

    if(np.l==0&&np[0]==0)
    {
        np.sign=1;
        np.l=1;
    }

    return np;

}


