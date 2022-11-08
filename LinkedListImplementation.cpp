#include<iostream>
using namespace std;

struct node
{
	int row, col;
	int val;
	node *next;
};

node *sparse[100];

int main()
{

	int r,c,i,j,count=0,k=0;
    cout<<"Enter the number of rows and columns of the matrix\n";
    cin>>r>>c;
    int a[r][c];
    cout<<"Enter the elements of the matrix\n";
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
                count++;
        }
    }
    if(count>r*c/2)
    {
        cout<<"Not a sparse matrix\n";
        return 0;
    }
	if(count<=(r*c)/2)
	{
		node *temp;
		node *last;
		int k=0;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(a[i][j]!=0)
				{
					temp=new node;
					temp->row=i;
					temp->col=j;
					temp->val=a[i][j];
					temp->next=NULL;
					if(sparse[k]==NULL)
					{
						sparse[k]=temp;
						last=temp;
					}
					else
					{
						last->next=temp;
						last=temp;
					}
				}
			}
			k++;
		}

		k=0;
		cout<<"The sparse matrix is: \n";
		while(sparse[k]!=NULL)
		{
			temp=sparse[k];
			while(temp!=NULL)
			{
				cout<<temp->row<<" "<<temp->col<<" "<<temp->val<<"\n";
				temp=temp->next;
			}
			k++;
		}
	}
	else
	{
		cout<<"The matrix is not a sparse matrix";
	}
	return 0;
}
