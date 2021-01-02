#include <bits/stdc++.h>
using namespace std;

struct treenode
{
    char character;
    int  value;
    treenode* left;
    treenode* right;
    treenode(char c,int v)
    {
        character=c;
        value=v;
        left=NULL;
        right=NULL;

    }

};
struct compare
{

    bool operator()(treenode *a,treenode *b)
    {
        return (a->value > b->value);
    }
};
void print(treenode *root,int arr[],int top)
{
    if(root->left)
    {
        arr[top]=0;
        print(root->left,arr,top+1);


    }
    if(root->right)
    {
        arr[top]=1;
        print(root->right,arr,top+1);
    }
    if (!root->left && !root->right) {
        cout << root->character << " ";
        for (int i = 0; i < top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }

}

void huffmancode(char arr[],int freq[],int size)
{
    treenode *left;
    treenode *right;
    treenode *node;
    priority_queue<treenode*,vector<treenode*>,compare> pq;
    for(int i=0; i<size; i++)
    {
        treenode* newnode=new treenode(arr[i],freq[i]);
        pq.push(newnode);
    }
    while(pq.size()!=1)
    {
        left=pq.top();
        pq.pop();
        right=pq.top();
        pq.pop();
        node=new treenode('*',left->value+right->value);
        node->left=left;
        node->right=right;
        pq.push(node);
    }
    treenode *root=pq.top();
    int newarray[100];
    int top=0;
    print(root, newarray, top);

}
int stringseperation(string s,char *c,int *b)
{
    map <char,int> a;
    for(int i=0; s[i]; i++)
    {
        if(a.find(s[i])==a.end())
        {
            a.insert(make_pair(s[i],1));
        }
        else
        {
            a[s[i]]++;
        }
    }
    cout<<"The frequency of character:"<<endl;
    int i=0;
    for(auto &el :a)
    {

        c[i]=el.first;
        b[i]=el.second;
        cout<<el.first<<" "<<el.second<<endl;
        i++;
    }
    return a.size();



}

int main()
{
    string str;
    char character[100]= {0};
    int value[100]= {0};
    unsigned int si=0;
    ifstream inp;
    inp.open("input.txt");
    inp>>str;
    cout<<"Input-" <<str<<endl;
    inp.close();
    si= stringseperation(str,character,value);
    cout<<"Total Unique Characters:"<<si<<endl;
    huffmancode(character,value,si);


}
