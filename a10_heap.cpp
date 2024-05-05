//The process of rearragning the heap by comparing each parent with its children recursively is k.a. heapify
#include <iostream>
using namespace std;
void min_heapify(int *a,int i,int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;      //j set to left child of i
    while (j <= n)
    {
        if (j < n && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;

}
void max_heapify(int *a,int i,int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)  //Continue while j is within the bounds of the array.
    {
        if (j < n && a[j+1] > a[j])     //If the right child exists (j < n) and is greater than the left child
            j = j + 1; //increment j to point to the right child. This ensures j points to the maximum of the two children
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
void build_minheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(a,i,n);
    }
}
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a,i,n);
    }
}
int main()
{
    int n, i, x,ch;
    char choice;
    cout<<"\n Enter number of students : ";
    cin>>n;
    int a[20];
    for (i = 1; i <= n; i++)
    {
        cout<<"Enter mark of student "<<i<<" : ";
        cin>>a[i];
    }
    do
    {
        cout<<"\n 1.MIN Heap \n 2.MAX Heap \n 3. Exit";
    	cout<<"\n  Enter the choice : ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
    			   build_minheap(a, n);
  			       cout<<"Min Heap\n";
   			       for (i = 1; i <= n; i++)
   			       {
        			cout<<a[i]<<endl;
                   }
    			   break;
    		case 2:
    			   build_maxheap(a, n);
  			       cout<<"Max Heap\n";
   			       for (i = 1; i <= n; i++)
   			       {
        			cout<<a[i]<<endl;
                   }
    			   break;
            case 3:break;
    	}

    }while(ch!=3);
}