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

//dp ============================
int wordBreak_(string word, string ans, int idx, vector<int>& dp)
{
    // cout << idx << "\n";
    if(word.size() == idx)
    {
        cout << ans << "\n";
        return dp[idx] = 1;
    }
    // cout << "hi\n";

    if(dp[idx] != -1)
        return dp[idx];

    int count = 0;

    for(int i=1;i<=word.size() - idx;i++)
    {
        string temp = word.substr(idx, i);
        if(map.find(temp) != map.end())
        {
            count += wordBreak_(word, ans + temp + " ", idx + i, dp);
        }
    }

    return dp[idx] = count;
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