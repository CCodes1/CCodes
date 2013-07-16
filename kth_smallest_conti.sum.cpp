#include<iostream>
#include<cstdio>
using namespace std;
long long int sum[60000];
int n;
long long int lss(long long int reqs,int n){
	long long int ways[n+1];
	ways[0]=0;
	if(sum[1]<=reqs){
		ways[1]=1;
	}
	else{
		ways[1]=0;
	}
	int i;
	int j=0;
	for(i=2;i<=n;i++){
		while(j<i){
			if((sum[i]-sum[j]) <= reqs){
				break;
			}
			j++;
		}
		ways[i]=ways[i-1]+(i-j);
	}
	return ways[n];
}
long long int equal(long long int reqs,int n){
	long long int ways[n+1];
	ways[0]=0;
	if(sum[1]==reqs){
		ways[1]=1;
	}
	else{
		ways[1]=0;
	}
	int i;
	int j=0;
	int k;
	int c;
	for(i=2;i<=n;i++){
		while(j<i){
			if(sum[i]-sum[j] == reqs){
				break;
			}
			j++;
		}
		k=j;
		c=0;
		while(k<i){
			if(sum[i]-sum[k]==reqs){
				c++;
			}
			else{
				break;
			}
			k++;
		}
		ways[i]=ways[i-1]+c;
	}
	return ways[n];
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	long long int a[n+1];
	scanf("%lld",&a[1]);
	sum[0]=0;
	sum[1]=a[1];
	int i;
	for(i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	/*for(i=1;i<=n;i++){
	  printf("%lld ",sum[i]);
	  }
	  printf("\n");
	 */



	long long int lo=0,hi=sum[n],mid;
	long long int x,y,ans;
	/*
	   x=lss(3,n);
	   y=equal(3,n);
	   printf("less=%lld eq=%lld\n",x,y);
	 */

	while(lo <= hi){
		mid=(lo+(hi-lo)/2);
		x=lss(mid,n);
		//y=equal(mid,n);
		if(x>=k){
			//if(y>=1){
			ans=mid;
		//	}
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	/*//	printf("sum=%lld less=%lld eq=%lld\n",mid,x,y);
	  if(y>=1){
	  if(x < k && x+y >=k){
	  ans=mid;
	  break;
	  }
	  else{
	  lo=mid+1;
	  }
	  }
	  else{
			if(x<=k){
				lo=mid+1;
			}
			else{
				hi=mid-1;
			}
		}
	}*/
	printf("%lld\n",ans);
	return 0;
}
