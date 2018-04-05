#include<unistd.h>
#include<stdio.h>


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
