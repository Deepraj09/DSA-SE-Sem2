#include<iostream>
#include<stdlib.h>
//#include<stdio.h>

using namespace std;

typedef struct node
{
    int a;
    struct node *left,*right;

}node;

struct node *root = NULL;

class BST 
{
    int count;
    struct node *temp = NULL,*t1 = NULL, *s = NULL, *t = NULL;
    
    public:
        BST()
        {
            count = 0;
        }
        struct node *create();
        void insert();
        int height(struct node *,int c);
        int findmin(struct node *);
        void swap(struct node*);
        void search(struct node *, int m);
        void display(struct node*);
};

struct node *BST::create()
{
    node *p = new(struct node);

    p->left = NULL;
    p->right = NULL;

    cout<<"Enter the data: \n";
    cin>>p->a;

    return p;
}

void BST::insert()
{
    temp = create();
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        t1 = root;
        while(t1 != NULL)
        {
            s = t1;
            if((temp->a) > (t1->a))
            {
                t1 = t1->right;
            }
            else
            {
                t1 = t1->left;
            }

            if((temp->a) > (s->a))
            {
                s->right = temp;
            }
            else
            {
                s->left = temp;
            }
        }
    }
}

int BST::height(struct node *q, int c)
{
    if(root == NULL)
    {
        cout<<"Tree does not exist \n";
    }
    else
    {
        c++;
        if(q->left != NULL)
        {
            height(q->left, c);
        }
        else
        {
            height(q->right, c);
        }
        if(count < c)
        {
            count = c;
        }
    }
    return count;
}

int BST::findmin(node *T)
{
    while(T->left != NULL)
    {
        T = T->left;
    }
    return T->a;
}

void BST::swap(struct node *q)
{
    if(q == NULL)
    {
        cout<<"tree does not exist";

    }
    else
    {
        if(q->left != NULL)
        {
            swap(q->left);
        }
        if(q->right != NULL)
        {
            swap(q->right);
        }
        t = q->left;
        q->left = q->right;
        q->right = t;
    }
}

void BST::search(struct node * root, int m)
{
    int f;
    if(root != NULL)
    {
        if(root->a == m)
        {
            f = 1;
        }

        if(m > root->a)
        {
            search(root->right,m);
        }
        else
        {
            search(root->left,m);
        }

        if(f == 1)
        {
            cout<<"\n FOUND!!";
        }
    }
}

void BST::display(struct node *q)
{
    if(q == NULL)
    {
        cout<<"\n tree does not exist";
    }
    else
    {
        cout<<"\n*"<<q->a;
        if(q->left != NULL)
        {
            display(q->left);
        }
        if(q->right != NULL)
        {
            display(q->right);
        }
    }
}

int main()
{
    BST b;
    int x,m,c=0,cnt,min,f1;

    do
    {
        cout<<"\n Enter your choice: ";
        cout<<"\n 1.insert: ";
        cout<<"\n 2.No of nodes in longest path: ";
        cout<<"\n 3.Minimum value is: ";
        cout<<"\n 4.Swap";
        cout<<"\n 5.search";
        cout<<"\n 6.display";
        cout<<"\n 7.Quit";
        cin>>x;
        switch(x)
        {
            case 1:
                b.insert();
                break;
            case 2: 
                cnt = b.height(root,c);
                cout<<"\n Number of nodes in logest path is = "<<cnt;
                break;
            case 3:
                min = b.findmin(root);
                cout<<"Minimum value is = "<<min;
                break;
            case 4:
                b.swap(root);
                break;
            case 5:
                cout<<"\n Enter data to be searched: ";
                cin>>m;
                b.search(root, m);
                break;
            case 6:
                b.display(root);
                break;
            case 7:
                exit(0);
        }
    }while(x != 7);
    return 0;
    
}