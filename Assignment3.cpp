#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

struct node
{
    char label[20];
    int ch_count;
    struct node *child[10];

}*root;

class GT
{
    public:
        void Create_tree();
        void display(node * r1);

        GT()
        {
            root = NULL;
        }
};


void GT::Create_tree()
{
    int tbooks,tchapters,i,j,k;

    root = new node;

    cout<<"Enter the name of Book: \n";
    cin>>root->label;

    cout<<"Enter the no of sections: \n";
    cin>>tchapters;
    root->ch_count = tchapters;

    for(i = 0; i < tchapters; i++)
    {
        root->child[i] = new node;

        cout<<"Enter the name of chapter: \n";
        cin>>root->child[i]->label;

        cout<<"Enter the no of sections in the chapters: "<<root->child[i]->label;
        cin>>root->child[i]->ch_count;

        for(j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;

            cout<<"Enter the Section: "<<j+1<<"name\n";
            cin>>root->child[i]->child[j]->label;

        }
    }
}

void GT::display(node * r1)
{
    if(r1 != NULL)
    {
        int i,j,k,tchapters;

        cout<<"\n -------- BOOK Hirearchy -----------";

        cout<<"\n Book title: "<<r1->label;
        tchapters = r1->ch_count;

        for(i = 0; i < tchapters; i++)
        {
            cout<<"\n chapters: "<<i+1;
            cout<<" "<<r1->child[i]->label;
            cout<<"\n Sections: ";

            for(j = 0; j < r1->child[i]->ch_count; j++)
            {
                cout<<"\n "<<r1->child[i]->child[j]->label;
            }
        }
    }
}

int main()
{
    int choice;

    GT gt;

    while(1)
    {
        cout<<"----------------------\n";
        cout<<" BOOK TREE CREATION \n";
        cout<<"----------------------\n";
        
        cout<<"1.Create_tree"<<endl;
        cout<<"2.Display_Tree"<<endl;
        cout<<"3.Ouit"<<endl;

        cout<<"Enter your choice: \n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            gt.Create_tree();
            break;
        case 2: 
            gt.display(root);
            break;
        case 3:
            exit(1);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}