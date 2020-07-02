#include <iostream>
#include <vector>
#include <string>
using namespace std;

void allSubsequence(string s1, string s2)
{
    if(s1.length() == 0 || s2.length() == 0)
    {
        if(s1.length() == 0 && s2.length() != 0)
            cout<<"NULL , "<<s2<<"\n";
        if(s2.length() == 0 && s1.length() != 0)
            cout<<"NULL , "<<s1<<"\n";
        if(s1.length() == 0 && s2.length() == 0)
            cout<<"NULL , NULL\n";
        return;
    }

    cout<< s1 <<" , "<<s2<<"\n";
    
    allSubsequence(s1.substr(1), s2.substr(1));
    
    allSubsequence(s1.substr(1),s2);
    allSubsequence(s1,s2.substr(1));
    

}

void solve()
{
    string str1 = "123";
    string str2 = "456";
    allSubsequence(str1, str2);
}

int main()
{
    solve();
    return 0;
}