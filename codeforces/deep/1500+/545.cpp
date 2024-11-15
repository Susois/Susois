#include <bits/stdc++.h>
using namespace std;
#define PII pair <long long, long long>
long long a; 
int main()
{cin >> a; 
    vector <PII> trees;
    for (int g=0; g<a; g++)
    {
        long long b,c; cin >> b >> c;
        trees.push_back(PII(b, c));     
    } 
    long long maxd=-3e9, ans=0; 
    for (int g=0; g<trees.size(); g++)
    {
        if (trees[g].first-trees[g].second>maxd)
        {
            maxd=trees[g].first; ans++; continue; 
        }
        if (g==trees.size()-1)
        {
            ans++; continue; 
        }
        if (trees[g].first+trees[g].second<trees[g+1].first)
        {
            maxd=trees[g].first+trees[g].second; ans++; continue; 
        }
        maxd=trees[g].first; 
    }
    cout << ans; 
    return 0; 
}