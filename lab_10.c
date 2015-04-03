#include<stdio.h>


void main()
{
  int N_process,i,Wait_prev;
  Wait_prev=0;
  printf("\nEnter the no of processes:");
  scanf("%d",&N_process);
  int Burst_t[N_process],Wait_t[N_process],Turnarnd[N_process];
  for(i=0;i<N_process;i++)
  	{
  		printf("\nEnter burst time for process %d:",i+1);
  		scanf("%d",&Burst_t[i]);
  
  		Wait_t[i]=Wait_prev;
  		Turnarnd[i]=Wait_t[i]+Burst_t[i];
  		Wait_prev=Wait_prev+Burst_t[i];
		 printf("\nProcess %d: Wait_Time = %d and TurnAroundTime = %d\n",i+1,Wait_t[i],Turnarnd[i]); 
  	}
 getchar();
 getchar();
  
}
