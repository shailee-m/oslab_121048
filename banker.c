#include<stdio.h>
int res_vec[4]={10,10,10,10};
void main()
{

int num_p;

printf("\nEnter total number of processes\n");
scanf("%d",&num_p);

int alloc[num_p][4];
int claim[num_p][4];

int i,j,count,N,N_prev,m;
N=num_p;
N_prev=0;
int flag[N];
for(m=0;m<N;m++)
	flag[m]=0;
for(i=0;i<4;i++)
{
	("\t %d of total resource %d,",res_vec[i], i);
}
	printf("\n");
for(i=0;i<num_p;i++)
{
	printf("\nEnter claim for process %d : ",i+1);
	scanf("%d%d%d%d",&claim[i][0],&claim[i][1],&claim[i][2],&claim[i][3]);
	printf("\nEnter Allocation for process %d: ",i+1);
	scanf("%d%d%d%d",&alloc[i][0],&alloc[i][1],&alloc[i][2],&alloc[i][3]);
	res_vec[0]-=alloc[i][0];
	res_vec[1]-=alloc[i][1];
	res_vec[2]-=alloc[i][2];
	res_vec[3]-=alloc[i][3];
	
}
	printf("\n");
for(i=0;i<4;i++)
{
	printf("\t %d is Available resource of %d,",res_vec[i], i);
	
}
	printf("\n");
while(N)
{

	for(i=0;i<num_p;i++)
	{
//	printf("\n%d for %d",flag[i],i+1);
		if(flag[i]==0)
		{
			for(j=0,count=0;j<4;j++)
			{
				if(res_vec[j]>= (claim[i][j]-alloc[i][j]))
				{
	//				printf("process %d, resource no %d, value %d\n",i+1,j+1,claim[i][j]-alloc[i][j]);
					count++;
				}
			}
			if(count==4)
			{
				res_vec[0]+=alloc[i][0];
				res_vec[1]+=alloc[i][1];
				res_vec[2]+=alloc[i][2];
				res_vec[3]+=alloc[i][3];
				alloc[i][0]=0;	
				alloc[i][1]=0;	
				alloc[i][2]=0;	
				alloc[i][3]=0;	
				claim[i][0]=0;	
				claim[i][1]=0;	
				claim[i][2]=0;	
				claim[i][3]=0;	
				N--;	
				flag[i]=1;	
			}
		}
		printf("\n");				
	for(m=0;m<4;m++)
	{
	printf("\n %d is Available resource of %d",res_vec[m], m);
	}
		printf("\n");	
	
	}
	
	if(N==N_prev && N!=0)
			{
				printf("\nIn unsafe state\n");
				break;
			}
	N_prev=N;
	
	

}
if(N==0)
{
printf("\nNo deadlock will occur\n");
for(i=0;i<num_p;i++)
	{
			for(j=0,count=0;j<4;j++)
			{
				printf("%d\t",alloc[i][j]);
			}
			printf("\n");
	}

}
else
{
printf("\nYour last allocation that will lead to deadlock is: \n");
for(i=0;i<num_p;i++)
	{
			for(j=0,count=0;j<4;j++)
			{
				printf("%d\t",alloc[i][j]);
			}
			if(flag[i]==0)
				printf("\t Process %d will starve", i+1);
			printf("\n");
	}
}
scanf("%d", m);
}
