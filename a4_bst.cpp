#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
};
void insert(struct node* &root, int n){
    struct node* dummy=root;
    struct node* temp = new node;
    temp->val=n;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        while(true){
            if(temp->val<root->val){
                if(root->left==NULL){
                    root->left=temp;
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right==NULL){
                    root->right=temp;
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        root=dummy;
    }
    
}
void search(struct node* root, int n){
    int count=1;
    if(root==NULL){
        cout<<"The tree is empty"<<endl;
    }else{
        while(true){
            if(root==NULL){
                cout<<"Value not found"<<endl;
                break;
            }
            else if(n<root->val){
                root=root->left;
            }
            else if(n>root->val){
                root=root->right;
            }
            else if(n==root->val){
                cout<<"Element found in "<<count<<" comparisions"<<endl;
                break;
            }
            count++;
        }
    }
}
int minimum(struct node* root){
    while(root->left){
        root=root->left;
    }
    return root->val;
}


int height(struct node* root){
    queue<struct node*> q;
    int h=0;
    if(root==NULL){
        return 0;
    }
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            struct node* top=q.front();
            q.pop();
            if(top->left){
                q.push(top->left);

            }
            if(top->right){
                q.push(top->right);
            }
        }
        h++;
    }
    return h;
}

void mirror(struct node* root){
    queue<struct node*> q;
    if(root==NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        struct node* top=q.front();
        q.pop();

        struct node* temp = top->left;
        top->left=top->right;
        top->right=temp;

        if(top->left){
           q.push(top->left);
           }
        if(top->right){
            q.push(top->right);
        }
    }
}

void display(struct node* root){
    //displays the nodes according to indorder
    stack<struct node*> st;
    struct node* curr=root;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }   
        curr=st.top();
        st.pop();
        cout<<curr->val<<", ";
        curr=curr->right;
    }
    cout<<endl;
}

int main(){
    struct node* root=NULL;
    while(true){
        cout<<"1. Insert Element"<<endl;
        cout<<"2. Search Element"<<endl;
        cout<<"3. Find Smallest Element"<<endl;
        cout<<"4. Print Height of the tree"<<endl;
        cout<<"5. Mirror tree"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        int n;
        cin>>n;                                                                                     
        if(n==1){
            cout<<"Enter the value to be added to the tree: "<<endl;
            int num;
            cin>>num;
            insert(root,num);
            cout<<" Values in the tree are: "<<endl;
            display(root);
        }
        else if(n==2){
            cout<<"Enter value to be searched: "<<endl;
            int num;
            cin>>num;
            search(root,num);
        }
        else if(n==3){
            cout<<"The smallest element in the tree is: "<<minimum(root)<<endl;
        }
        else if(n==4){
            cout<<"Height of the tree is: "<<height(root)<<endl;
        }
        else if(n==5){
            mirror(root);
            cout<<"Mirrored tree is: ";
            display(root);
        }
        else{
            break;
        }
    }

}