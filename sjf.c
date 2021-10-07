#include <stdio.h>
int p[30], bt[30], tot_tat = 0, wt[30], n, tot_wt = 0, tat[30], SJF_wt = 0, SJF_tat = 0;

int swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
	return 0;
}
int sort()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (bt[i] > bt[j])// ~bt~ pr
			{
				swap(&bt[j], &bt[i]);
				//swap pr j pr i 
				swap(&p[j], &p[i]);
			}
		}
	}-
	return 0;
}
int WT_TAT(int *a, int *b)
{
        int i;
        for(i=0;i<n;i++)
        {
                if(i==0)
                  tat[i] = bt[i];
                else
                  tat[i] = tat[i-1] + bt[i];
                tot_tat=tot_tat+tat[i];
        }
        *a = tot_tat;
        wt[0]=0;
        for(i=1;i<n;i++)
        {
                wt[i]=tat[i]-bt[i];
                tot_wt = tot_wt+wt[i];
        }
        *b = tot_wt;
        printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME"); for(i=0; i<n; i++)
        printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
        return 0;
}

int main() 
{ 
	int i;  
	printf("\nEnter the no.of processes \n"); 
	scanf("%d",&n); 
	printf("Enter burst time for each process\n");
 	for(i=0;i<n;i++) 
	{		 
		scanf("%d",&bt[i]); 
		p[i] = i; 
	} 
	sort();
	printf("\n SJF Algorithm \n"); 
	WT_TAT(&SJF_tat,&SJF_wt); 
	printf("\n\nTotal Turn around Time:%d",SJF_tat); 
	printf("\nAverage Turn around Time :%d ", SJF_tat/n);
	printf("\nTotal Waiting Time:%d",SJF_wt); 
	printf("\nTotal avg. Waiting Time:%d",SJF_wt/n); 
	return 0; 
}	