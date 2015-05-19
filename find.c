#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

void findelement(int a[],int n){
		int * first=a;
		int * last=a+n;
		int *mid=0;
		int value;
		if(n==0) return;
		if(a[n-1]==(a[0]+n-1)) return;// missing something
		if(a[n-1]!=(a[0]+n)) return; //mising more than one;
		last--;
		
		while(first!=last){
			
			mid=first+(last-first)/2;
			value=(last-a+first-a+a[0]+a[0])/2;
//			printf("the mid value is :%d, the value is :%d\n",*mid,value);
//			system("read");
			if(value>=*mid) first=++mid;
			else last=mid;
				
		}


		printf("the first missing value should be %d\n",(*first-1));
}

void findduplicate(int a[], int n){
		int * first=a;
		int * last=a+n;
		int * mid=0;
		int value;
		if (n==0) return;
		if(a[n-1]==(a[0]+n-1)) return;
		last--;
		while(first!=last){
			mid=first+(last-first)/2;
			value=(last-a+first-a+a[0]+a[0])/2;

			if(value<=*mid) first=mid+1;
			else   last=mid;
		}
		printf("the first duplicate is %d\n",*first);

}
int main(){
		int pass[]={1,2,3,5,6,7};
		findelement(pass,6);
		int duplicate[]={1,2,3,3,4,5};
		findduplicate(duplicate,6);


}

