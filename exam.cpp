#include<bits/stdc++.h>
#include<iostream>
using namespace std;


//0   less than  
//1   less than equal to
//2   equal to
//3   greater than
//4   greater thana nd equal to


int main()
{
	string data;
	cin>>data;  
	int sum=0;                     //  -15<-10<=0=0<5
	vector<int>v;     
	vector<int>relation;
	
	bool isNegative =false;
    int len=data.length();
    
    int i=0;
    while(i<len)
    {
        if(i+1<len && data[i]=='<' && data[i+1]!='=') // 1st case
		{
		       if(isNegative)
			   v.push_back(-sum);   
			   
			   else
			   v.push_back(sum);
			   
			   relation.push_back(0);
		    i=i+1;
		    isNegative=false;
	    }
	    
	    else if(i+1<len && data[i]=='<' && data[i+1]=='=')  //2nd case
	    {
	    	if(isNegative)
			   v.push_back(-sum);   
			   
			   else
			   v.push_back(sum);
			   
			   relation.push_back(1);
		    i=i+2;
		    isNegative=false;
		}
		else if(data[i]=='=')                 // 3rd case
		{
			if(isNegative)
			   v.push_back(-sum);   
			   
			   else
			   v.push_back(sum);
			   
			   relation.push_back(2);
			   i=i+1;
			   isNegative=false;
		}
		
		else if(i+1<len && data[i]=='>' && data[i+1]!='=') //4th case
		{
				if(isNegative)
			   v.push_back(-sum);   
			   
			   else
			   v.push_back(sum);
			   
			   relation.push_back(3);
			   i=i+1;
			   isNegative=false;
		}
		
		else if(i+1<len && data[i]=='>' && data[i+1]=='=') //5th case
		{
			if(isNegative)
			   v.push_back(-sum);   
			   
			   else
			   v.push_back(sum);
			   
			   relation.push_back(4);
			   i=i+2;
			   isNegative=false;
		}
		else if(data[i]=='-')
		{
			isNegative=true;
		}
		else
		{
			sum=sum*10+(data[i]-'0');
		}
	    
	}
	if(isNegative)
    {
        v.push_back(-sum);	
	}	
	else
	v.push_back(sum);
	
	//validating
	
	bool flag=true;
	for(int i=1;i<v.size();i++)
	{
		int diff=v[i]-v[i-1];
		int type=relation[i-1];
		 if(type==0 && diff<=0)
		 {
		 	flag=0;
		 	break;
		 }
		 if(type==1 && diff<0)
		 {
		 	flag=0;
		 	break;
		 }
		 if(type==2 && diff!=0)
		 {
		 	flag=0;
		 	break;
		 }
		 if(type==3 && diff>=0)
		 {
		 	flag=0;
		 	break;
		 }
		 if(type==4 && diff>0)
		 {
		 	flag=0;
		 	break;
		 }
	}
	if(flag)
	printf("True\n");
	else
    printf("False\n");
}
