#include<iostream>
using namespace std;
int main()
{
	int fifo[3]={-1};
	int n;
	cout<<"enter the number of inputs\n";
	cin>>n;
	int input[n];
	cout<<"enter inputs";
	for(int i=0;i<n;i++)
	cin>>input[i];
	
	int hit =0;
	int fault =0,j=0;
	int flag;
	for(int i=0;i<n;i++){
		flag=0;
		for(int k=0;k<3;k++)
		{
			if(fifo[k]==input[i])
			{flag=1;hit++;}
			}
		if(flag==0){
			fifo[j]=input[i];	
			j++;
			if(j>=3)
			j=0;
			fault++;
			}
	}
	cout<<"hits is"<<hit<<endl;
	cout<<"fault is"<<fault<<endl;
	return 0;
	}
