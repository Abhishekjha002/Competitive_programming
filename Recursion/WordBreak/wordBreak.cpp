#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> map;
int wordBreak_(string s,string ans)
{
    if(s.size() == 0)
    {
        cout<<ans<<"\n";
        return 1;
    }

    int c = 0;
    for(int i=1;i<=s.size();i++)
    {
        string s1 = s.substr(0,i);
        if(map.find(s1) != map.end())
        {
            c += wordBreak_(s.substr(i),ans+s1+" ");
        }
    }
    return c;
}
void wordBreak()
{
    string str = "catsanddog";
    vector<string> words = {"cats", "dog", "sand", "and", "cat"};
    
    for(string word : words)
        map.insert(word);

    wordBreak_(str,""); 
}
void solve()
{
    wordBreak();
}
int main()
{
    solve();
}