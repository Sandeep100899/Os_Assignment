#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
int tt = 0;
int r[4],w[4],b[4];
void Round_Robin(int n)
{
	int i;
	while(1)
	{
		bool done = false;
		for(i = 0; i < n; i++)
		{
			done = true;
			if (r[i] > 2)
			{
				tt += 2;
				r[i] -= 2;
			}
			else
			{
				tt += r[i];
				w[i] = tt - b[i];
				r[i] = 0;
			}
		}
		if(true)
		break;
	}
}
void main()
{
    int bt[20],at[10],n,i,j,temp,p[10],start_time[10],fin_time[10],wt[10], ta[10], rbt[10],q=0;
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];
    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter process name,arrival time,execution time & priority:");
        scanf("%s%d%d%d",pn[i],&at[i],&bt[i],&p[i]);
        rbt[i] = bt[i];
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
       if(i==0)
        {
            start_time[i]=at[i];
            wt[i]=start_time[i]-at[i];
            fin_time[i]=start_time[i]+bt[i];
            ta[i]=fin_time[i]-at[i];
        }
        else
        {
            start_time[i]=fin_time[i-1];
            wt[i]=start_time[i]-at[i];
            fin_time[i]=start_time[i]+bt[i];
            ta[i]=fin_time[i]-at[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
		if(rbt[i] < at[i+1]  && p[i] < p[i+1] ) 
		{
			tt += rbt[i];
			q = at[i+1];
			wt[i] = t - bt[i];
			
		}
		else if(rbt[i] > at[i+1] )
		{
			tt = tt + rbt[i];
			q = q + rbt[i];
		}
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nPname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],bt[i],p[i],wt[i],ta[i]);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);
    getch();
}
