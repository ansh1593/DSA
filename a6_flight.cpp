#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node
{
    string vertex;
    int time;
    node *next;
};

class adjacency
{
    int time[10][10], i, j, n;
    char ch;
    string v[20];
    node *head[20];     //head[20]: An array of pointers to nodes representing the adjacency list
    node *temp=NULL;
    public: adjacency()
            {
                for(i=0; i<20; i++)
                    head[i]=NULL;
            }
            void getgraph(), adjlist(), displaym(), displaya();
}a;

void adjacency::getgraph()
{
    cout<<"Enter no of cities (max 20)";    cin>>n;
    cout<<"Enter name of cities";
    for (i=0; i<n; i++)
        cin>>v[i];
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            cout<<"Is there any path between cities "<<v[i]<<" & "<<v[j]<<" ? (y/n)";
            cin>>ch;
            if(ch=='y')
            { cout<<"Enter time required to reach "<<v[j]<<" from "<<v[i]<<" : ";     cin>>time[i][j]; }
            else if(ch=='n')
            { time[i][j]=0; }
            else
            {  cout<<"Invalid Choice"; }
        }
    }   adjlist();
}

void adjacency::adjlist()
{
    for(i=0; i<n; i++)      // For each vertex in the graph, it creates a new node in the adjacency array
    {
        node *p = new node;
        p->next=NULL;
        p->vertex=v[i];
        p->time=time[i][j];
        head[i]=p;
        cout<<"\n "<<head[i]->vertex;
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(time[i][j] != 0)
            {
                node *p = new node;     //creation of orphan node
                p->vertex=v[i];
                p->time=time[i][j];
                p->next=NULL;
                if(head[i]->next == NULL)       //linking of node to head array 
                {   head[i]->next = p;  }
                else               //i.e. already one node exists
                {
                    temp = head[i];
                    while(temp->next != NULL)
                    {   temp=temp->next;    }
                    temp->next=p;
                }
            }
        }
    }
}

void adjacency::displaym()
{
    cout<<"\n ";
    for(j=0; j<n; j++)
    {   cout<<"\t "<<v[j];  }
    for(i=0; i<n; i++)
    {
        cout<<"\n "<<v[i];
        for(j=0; j<n; j++)
        {   cout<<"\t"<<time[i][j];     }
        cout<<"\n ";
    }
}

void adjacency::displaya()
{
    cout<<"\n adjacency list is";     
    for(i=0;i<n;i++)
    {                  
        if(head[i]==NULL)
        {   cout<<"\n adjacency list not present";  break;   }
        else
        { 
            cout<<"\n"<<head[i]->vertex;
            temp=head[i]->next;
            while(temp!=NULL)      //displaying list
            {  cout<<"-> "<<temp->vertex;
               temp=temp->next;  
            }
        }       
    }
    cout<<"Path & time required between cities is -:- ";
    for(i=0; i<n; i++)
    {
        if(head[i] == NULL)
        {    cout<<"Path not present";   break;     }
        else
        {
            temp=head[i]->next;
            while(temp != NULL)
            {
                cout<<"\n"<<head[i]->vertex;
                cout<<"->"<<temp->vertex<<"\n (time required : "<<temp->time<<" min)";
                temp=temp->next;
            }
        }
    }
}

int main()
{   int ch;
    while(1)
    {
        cout<<"\n\n Enter the choice";
        cout<<"\n 1 Enter graph";
        cout<<"\n 2 Display adjacency matrix for cities";
        cout<<"\n 3 Display adjacency list for cities";
        cout<<"\n 4 Exit \n\n";
        cin>>ch;

        switch(ch)
        {
            case 1 : a.getgraph();  break;
            case 2 : a.displaym();  break;
            case 3 : a.displaya();  break;
            case 4 : exit(0);
            default : cout<<"Invalid Choice";
        }
    }
    return 0;
}