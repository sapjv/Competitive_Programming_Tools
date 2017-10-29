#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    cin>>n;
    long long  a[n];
    pair<long long,int>v[n],v1[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        v[i].first=a[i];
        v[i].second=i;
        v1[i].first=a[i];
        v1[i].second=i;
    }
    sort(v,v+n);
    int ans=0;
    vector<bool> visited(n,false);
    for(i=0;i<n;i++)
    {
        if(visited[i] || v[i].second==i)
            continue;
        int j=i;
        int c=0;
        while(!visited[j])
        {
            visited[j]=1;
            j=v[j].second;
            c++;
        }
        ans+=(c-1);
    }
    sort(v1,v1+n);
    reverse(v1,v1+n);
    int ans1=0;
    vector<bool> visited1(n,false);
    for(i=0;i<n;i++)
    {
        if(visited1[i] || v1[i].second==i)
            continue;
        int j=i;
        int c=0;
        while(!visited1[j])
        {
            visited1[j]=1;
            j=v1[j].second;
            c++;
        }
        ans1+=(c-1);
    }
    cout<<min(ans,ans1)<<endl;
    return 0;
}
