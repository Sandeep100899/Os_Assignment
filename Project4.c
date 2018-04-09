#include<unistd.h>
#include<stdio.h>

void ssort(int a[],int b[], int p[],  int n)
{
	int i, j, min, temp, mpos;
//	min = a[0];
	for(i = 0; i < n; i++ )
	{
		mpos = i;
		for(j = i+ 1; j< n; j++)
		{
			if(a[mpos] > a[j])
			{
//				min = a[j];
				mpos = j;
			}
		}
//		min = a[i];
		temp = a[mpos];
		a[mpos] = a[i];
		a[i] = temp;
		
		temp = b[mpos];
		b[mpos] = b[i];
		b[i] = temp;
		
		temp = p[mpos];
		p[mpos] = p[i];
		p[i] = temp; 
		
	}
}

int main()
{
  int n;
	printf("Enter number of process:");
	scanf("%d", &n);
	int queue1[n], queue2[n];
	int bt[n], at[n], pr[n], rbt[n];
	printf("\nEnter burst time, priority and arrival time of \n");
	for(i = 0; i<n ; i++){
		printf("process %d:" ,i+1);
		scanf("%d%d%d", &bt[i], &pr[i], &at[i]);
		printf("\n");
	}
	for(i = 0; i<n ; i++)
	{
		rbt[i] = bt[i];
	
	}
}
