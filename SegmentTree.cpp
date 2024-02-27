#include <bits/stdc++.h>
using namespace std;
int arr[10005],seg[4*10005];
void build(int index,int low,int high)
{
   if(low == high)
   {
   	seg[index] = arr[low];
   	return;
  }
  int mid = low + high >> 1;
  build(2*index+1,low,mid);
  build(2*index+2,mid+1,high);
  seg[index] = min(seg[2*index+1],seg[2*index+2]);
}
int query(int index,int low,int high,int l,int r)
{
  if(r < low || high < l) return INT_MAX;
  if(low >= l && high <= r) return seg[index];
  int mid = low + high >> 1;
  int left = query(2*index+1,low,mid,l,r);
  int right = query(2*index+2,mid+1,high,l,r);
  return left+right;
}
int main()
{
	int n,l,r;
	cin>>n;
	for(int i = 0;i < n; i++) cin>>arr[i];
	cin>>l>>r;
    build(0,0,n-1);
	return 0;
}