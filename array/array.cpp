#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int *a=new int[n];
    int i;
    for(i=0 ; i<n ; i++){
        cin>>a[i];
    }
    int sum=0;
    for(i=0 ; i<n ; i++){
        sum+=a[i];
    }
    cout<<(double)sum/n;
    return 0;
}