#include<bits/stdc++.h>
using namespace std;
int findExtra(int a[],int b[],int n);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n],b[n-1];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			cin>>b[i];
		}
		cout<<findExtra(a,b,n)<<endl;
	}
}

int compare(const void* ab, const void* bb)
{
  int* a = (int *)ab;
  int *b = (int *)bb;

  if(*a < *b)
    return -1;
  else if(*b < *a)
    return 1;
  else
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below*/
int findExtra(int a[],int b[],int n)
{
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++)
        sum1 += a[i];
        
    for(int i = 0; i < n-1; i++)
        sum2 += b[i];
    
    int x = sum1 - sum2;
    int *p = (int *)bsearch(&x, a, n, sizeof(a[0]), compare);
    return (p - a);
}