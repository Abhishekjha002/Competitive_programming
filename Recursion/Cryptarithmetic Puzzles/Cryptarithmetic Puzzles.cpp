#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//Cryptarithmetic Puzzles
string s1 = "send";
string s2 = "more";
string s3 = "money";
vector<int> mapping(26,0);
int numused = 0;
int stringtoNumber(string& s)
{
    int res = 0;
    for(int i=0;i<s.size();i++)
    {
        int idx = s[i] - 'a';
        res = res*10 + mapping[idx];
    }
    return res;
} 
int crypto_(string str,int idx)
{
    if(idx == str.size())
    {
        int n1 = stringtoNumber(s1);
        int n2 = stringtoNumber(s2);
        int n3 = stringtoNumber(s3);
        if((n1 + n2 == n3) && ( mapping[s1[0] - 'a'] != 0 && mapping[s2[0] - 'a'] != 0 && mapping[s3[0] - 'a'] != 0))
        {
            cout<<n1<<" "<<n2<<" "<<n3<<"\n";
            return 1;
        }
        return 0;
    }

    int count = 0;
    int index = str[idx] - 'a';
    
    for(int num=0;num<=9;num++)
    {
        int mask = (1 << num);
        if(!(numused & mask))
        {
            numused ^= mask;
            mapping[index] = num;
            count += crypto_(str,idx+1);
            numused ^= mask;
            mapping[index] = 0;
        }
    }
    return count;
}
void crypto()
{
    string s = s1 + s2 + s3;
    int freq = 0;
    for(int i=0;i<s.size();i++)
    {
        int idx = s[i] - 'a';
        int k = (1 << idx);
        if(!(freq & k))
        {
            freq |= k;
        }
    }

    string str = "";
    for(int i=0;i<26;i++)
    {
        int k = (1 << i);
        if((freq & k))
        {
            str += (char)(i + 'a');
        }
    }
    //cout<<str<<"\n";
    int c = crypto_(str,0);
    cout<<c;
}
void solve()
{
    crypto();
}
int main()
{
    solve();
}