#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node 
{
    int data;
    node *left,*right;
};
typedef struct node *Tree;

void InitTree(Tree &T)
{
    T=NULL;
}

void TreeInsert(Tree &T,int k)
{
    if(T==NULL)
    {
        T=new node;
        T->data=k;
        T->left=NULL;
        T->right=NULL;
    }
    else if(k<T->data) 
        TreeInsert(T->left, k);
    else if(k>T->data) 
        TreeInsert(T->right, k);
}

void CreateTree(Tree &T,int &n)
{
    cout<<"Nhap vao so luong phan tu:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cout<<"Nhap vao gia tri:";
        cin>>k;
        TreeInsert(T,k);
    }
}

void InorderTreeWalk(Tree T)//LNR
{
    if(T!=NULL)
    {
        InorderTreeWalk(T->left);
        cout<<T->data<<" ";
        InorderTreeWalk(T->right);
    }
}

void PreorderTreeWalk(Tree T)//NLR
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        PreorderTreeWalk(T->left);
        PreorderTreeWalk(T->right);
    }
}

void PostorderTreeWalk(Tree T)//LRN
{
    if(T!=NULL)
    {
        PostorderTreeWalk(T->left);
        PostorderTreeWalk(T->right);
        cout<<T->data<<" ";
    }
}

Tree TreeSearch(Tree T,int k)
{
    if(T==NULL||T->data==k)
        return T;
    else if(k<T->data)
        return TreeSearch(T->left,k);
    else
        return TreeSearch(T->right,k);
}

int DeleteMin(Tree &T)
{ 
    int min;
    if(T->left==NULL)
    {
        min=T->data;
        T=T->right;
        return min;
    }
    else return DeleteMin(T->left);
}

void TreeDelete(Tree &T, int k)
{ 
    if(T!=NULL)
    {
        if(k<T->data) 
            TreeDelete(T->left,k);
        else if(k>T->data) 
            TreeDelete(T->right,k);
        else if(T->right==NULL) 
            T=T->left;
        else if(T->left==NULL) 
            T=T->right; 
        else T->data=DeleteMin(T->right);
    } 
}

void EvenTree(Tree T)
{
    if(T!=NULL)
    {
        EvenTree(T->right);
        if(T->data%2==0)
            cout<<T->data<<" ";
        EvenTree(T->left);
    }
}

void Multiplesof3(Tree T)
{
    if(T!=NULL)
    {
        Multiplesof3(T->right);
        if(T->data%3==0)
            cout<<T->data<<" ";
        Multiplesof3(T->left);
    }
}

int TotalTree(Tree T)
{
    if(T!=NULL)
        return TotalTree(T->left)+TotalTree(T->right)+1;
    else
        return 0;
}

int SumTree(Tree T)
{
    if(T!=NULL)
        return SumTree(T->left)+SumTree(T->right)+T->data;
    else
        return 0;
}

int SumOddTree(Tree T)
{
    if(T!=NULL)
    {
        if(T->data%2!=0)
            return SumOddTree(T->left)+SumOddTree(T->right)+T->data;
        else
            return SumOddTree(T->left)+SumOddTree(T->right);
    }
    else
        return 0;
}

int LevelTree(Tree T,int k)
{
    if(T!=NULL)
    {
        if(T->data==k)
            return 1;
        else if(T->data<k)
            return LevelTree(T->right,k)+1;
        else if(T->data>k)
            return LevelTree(T->left,k)+1;
        else 
            return 0;
    }
    else
        return 0;
}

int CountLeaf(Tree T)
{
    if(T!=NULL)
    {
        if(T->left==NULL&&T->right==NULL)
            return 1;   
        else
            return CountLeaf(T->left)+CountLeaf(T->right);
    }
    else
        return 0;
}

int Max(int a,int b)
{
    if(a<b)
    return b;
    else
    return a;
}

int MaxHeight(Tree T)
{
    if(T!=NULL)
        return Max(MaxHeight(T->left),MaxHeight(T->right))+1;
    else
        return 0;
}

void Print(Tree T,int k)
{
    if(T!=NULL)
    {
        if(T->data==k)
            cout<<T->data<<" ";
        else if(k<T->data)
        {
            cout<<T->data<<" ";
            Print(T->left,k);
        }
        else
        {
            cout<<T->data<<" ";
            Print(T->right,k);
        }
    }
}

void SumLevelExpected(Tree T,int k,int expected,int &count)
{
    if(T!=NULL)
    {
        k++;
        SumLevelExpected(T->left,k,expected,count);
        if(k==expected)
        {
            count++;
        }
        SumLevelExpected(T->right,k,expected,count);    
    }
}

int SumEven(Tree T)
{
    if(T!=NULL)
    {
        if(T->data%2==0)
            return SumEven(T->left)+SumEven(T->right)+T->data;
        else
            return SumEven(T->left)+SumEven(T->right);
    }
    else
        return 0;
}

int Counter(Tree T)
{
    if(T!=NULL)
    {
        if(T->left==NULL&&T->right!=NULL || T->right==NULL&&T->left!=NULL)
            return Counter(T->left)+Counter(T->right)+1;
        else
            return Counter(T->left)+Counter(T->right);
    }
    else 
        return 0;
}

void PrintLevelExpected(Tree T,int k,int expected)
{
    if(T!=NULL)
    {
        k++;
        PrintLevelExpected(T->left,k,expected);
        if(k==expected)
            cout<<T->data<<" ";
        PrintLevelExpected(T->right,k,expected);
    }
}

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head,*tail;
};

void InitList(List &L)
{
    L.head=L.tail=NULL;
}

Node *CreateNode(int data)
{
    Node *x=new Node;
    x->data=data;
    x->next=NULL;
    return x;
}

void AddTail(List &L,Node *x)
{
    if(L.head==NULL)
        L.head=L.tail=x;
    else
    {
        L.tail->next=x;
        L.tail=x;
    }
}

void CreateList(Tree T,List &L)
{
    if(T!=NULL)
    {
        CreateList(T->left,L);
        AddTail(L,CreateNode(T->data));
        CreateList(T->right,L);
    }
}

void PrintList(List L)
{
    if(L.head==NULL)
        return;
    Node *x=L.head;
    while(x!=NULL)
    {
        cout<<x->data<<" ";
        x=x->next;
    }
    cout<<"\n";
}

struct MatHang
{
    string code;
    string name;
    int amount;
    double price;
    MatHang *left,*right;
};
typedef struct MatHang *CayMatHang;

void KhoiTaoCayMatHang(CayMatHang &T)
{
    T=NULL;
}

void ChenMatHang(CayMatHang &T,string code,string name,int amount,double price)
{
    if(T==NULL)
    {
        T=new MatHang;
        T->code=code;
        T->name=name;
        T->amount=amount;
        T->price=price;
        T->left=NULL;
        T->right=NULL;
    }
    else if(price > T->price)
        ChenMatHang(T->right,code,name,amount,price);
    else
        ChenMatHang(T->left,code,name,amount,price);
}

void TaoDanhSachMatHang(CayMatHang &T,int &n)
{
    cout<<"Nhap vao so luong danh sach mat hang:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string code,name;
        int amount;
        double price;
        cout<<"Nhap vao thong tin san pham thu "<<i<<":\n";
        fflush(stdin);
        cout<<"Nhap vao ma code:";
        getline(cin,code);
        fflush(stdin);
        cout<<"Nhap vao ten mat hang:";
        getline(cin,name);
        cout<<"Nhap vao so luong mat hang:";
        cin>>amount;
        cout<<"Nhap vao gia mat hang:";
        cin>>price;
        ChenMatHang(T,code,name,amount,price);
    }
}

void InDanhSachMatHang(CayMatHang &T)//trung vị LNR
{
    if(T!=NULL)
    {
        InDanhSachMatHang(T->left);
        cout<<"Thong tin san pham:\n";
        cout<<"Ma code:"<<T->code<<"\n";
        cout<<"Ten mat hang:"<<T->name<<"\n";
        cout<<"So luong mat hang:"<<T->amount<<"\n";
        cout<<"Gia mat hang:"<<T->price<<"\n\n";
        InDanhSachMatHang(T->right);
    }
}

void CacMatHangCoGiaTienBangP(CayMatHang T,double p)
{
    if(T!=NULL)
    {
        CacMatHangCoGiaTienBangP(T->left,p);
        if(T->price==p)
        {
            cout<<"\nThong tin san pham:\n";
            cout<<"Ma code:"<<T->code<<"\n";
            cout<<"Ten mat hang:"<<T->name<<"\n";
            cout<<"So luong mat hang:"<<T->amount<<"\n";
            cout<<"Gia mat hang:"<<T->price<<"\n\n";
        }
        CacMatHangCoGiaTienBangP(T->right,p);
    }
}

double TongGiaTienCacMatHang(CayMatHang T)
{
    if(T!=NULL)
    {
        return TongGiaTienCacMatHang(T->left)+TongGiaTienCacMatHang(T->right)+T->price*T->amount;
    }
    else
        return 0;
}

int main()
{
    system("cls");
    Tree T;
    int n;
    InitTree(T);
    TreeInsert(T,30);
    TreeInsert(T,20);
    TreeInsert(T,15);
    TreeInsert(T,25);
    TreeInsert(T,50);
    TreeInsert(T,40);
    TreeInsert(T,60);
    TreeInsert(T,33);
    TreeInsert(T,45);
    TreeInsert(T,42);
    TreeInsert(T,48);
    InorderTreeWalk(T);
    //PreorderTreeWalk(T);
    //PostorderTreeWalk(T);
    goto menu;
    menu:
    {
        cout<<"\n========== Menu ==========\n";
        cout<<"1.Bai 1\n";
        cout<<"2.Bai 2\n";
        cout<<"3.Bai 3\n";
        cout<<"4.Bai 4\n";
        cout<<"5.Bai 5\n";
        cout<<"5.Bai 6\n";
        cout<<"5.Bai 7\n";
        cout<<"5.Bai 8\n";
        cout<<"5.Bai 9\n";
        cout<<"5.Bai 10\n";
        cout<<"5.Bai 11\n";
        cout<<"5.Bai 12\n";
        cout<<"5.Bai 13\n";
        cout<<"5.Bai 14\n";
        cout<<"5.Bai 15\n";
        cout<<"5.Bai 16\n";
        cout<<"5.Bai 17\n";
        cout<<"5.Bai 18\n";
        cout<<"5.Bai 19\n";
        cout<<"5.Bai 20\n";
        cout<<"5.Bai 21\n";
        cout<<"Nhap vao bai ban muon in:";
        int chon;
        cin>>chon;
        switch(chon)
        {
            case 1:
                goto bai1;
            case 3:
                goto bai3;
            case 4:
                goto bai4;
            case 5:
                goto bai5;
            case 6:
                goto bai6;
            case 7:
                goto bai7;
            case 8:
                goto bai8;
            case 9:
                goto bai9;
            case 13:
                goto bai13;
            case 14:
                goto bai14;
            case 15:
                goto bai15;
            case 16:
                goto bai16;
            case 17:
                goto bai17;
            case 18:
                goto bai18;
            case 19:
                goto bai19;
            case 20:
                goto bai20;
            case 21:
                goto bai21;
            default:
                cout<<"Nhap vao ko hop le!!!\n";
                break;
        }
    }

    yesno:
    {
        char v;
        cout<<"Nhan y de tiep tuc nhan bat ky de thoat:";
        cin>>v;
        if(v=='y')
            goto menu;
        else
            return 0;
    }

    bai1:
    {
        int k;
        cout<<"Nhap vao gia tri can tim:";
        cin>>k;
        cout<<TreeSearch(T,k)->data<<"\n";
        cout<<"Nhap vao gia tri can xoa:";
        cin>>k;
        TreeDelete(T,k);
        InorderTreeWalk(T);
        cout<<"\n";
        goto yesno;
    }

    bai3:
    {
        List L;
        InitList(L);
        CreateList(T,L);
        PrintList(L);
        goto yesno;
    }

    bai4:
    {
        InorderTreeWalk(T);
        cout<<"\n";
        goto yesno;
    }

    bai5:
    {
        cout<<"Cac so chan trong cay la:\n";
        EvenTree(T);
        cout<<"\n";
        goto yesno;
    }

    bai6:
    {
        cout<<"Cac boi so cua 3 trong cay la:\n";
        Multiplesof3(T);
        cout<<"\n";
        goto yesno;
    }

    bai7:
    {
        cout<<"Tong cac nut trong cay la:"<<TotalTree(T)<<"\n";
        goto yesno;
    }

    bai8:
    {
        cout<<"Tong gia tri trong cay la:"<<SumTree(T)<<"\n";
        goto yesno;
    }
    
    bai9:
    {
        cout<<"Tong cac gia tri le trong cay la:"<<SumOddTree(T)<<"\n";
        goto yesno;
    }

    bai13:
    {
        CayMatHang CMH;
        KhoiTaoCayMatHang(CMH);
        int n;
        TaoDanhSachMatHang(CMH,n);
        InDanhSachMatHang(CMH);
        double p;
        cout<<"Nhap vao gia tien:";
        cin>>p;
        cout<<"Danh sach san pham co gia tien bang p la:\n";
        CacMatHangCoGiaTienBangP(CMH,p);
        cout<<"Tong gia tien cac mat hang trong danh sach la:"<<TongGiaTienCacMatHang(CMH)<<"\n";
        goto yesno;
    }

    bai14:
    {
        int k;
        cout<<"Nhap vao gia tri ban muon xac dinh muc:";
        cin>>k;
        cout<<"Muc cua k la:"<<LevelTree(T,k)<<"\n";
        goto yesno;
    }

    bai15:
    {
        cout<<"So nut la cua cay nhi phan la:"<<CountLeaf(T)<<"\n";
        goto yesno;
    }

    bai16:
    {
        cout<<"Chieu cao cua cay nhi phan la:"<<MaxHeight(T)<<endl;
        goto yesno;
    }

    bai17:
    {
        int k;
        cout<<"Nhap vao gia tri can tim kiem:";
        cin>>k;
        cout<<"Cac nut tren duong di tu goc den nut co khoa k trong cay nhi phan la:\n";
        Print(T,k);
        cout<<"\n";
        goto yesno;
    }

    bai18:
    {
        int i,count=0;
        cout<<"Nhap vao muc i:";
        cin>>i;
        SumLevelExpected(T,0,i,count);
        cout<<"Tong so nut o muc i la:"<<count<<"\n";
        goto yesno;
    }

    bai19:
    {
        cout<<"Tong so nut co khoa chan trong cay la:"<<SumEven(T)<<"\n";
        goto yesno;
    }

    bai20:
    {
        cout<<"So nut co 1 con trong cay nhi phan la:"<<Counter(T)<<"\n";
        goto yesno;
    }

    bai21:
    {
        int i;
        cout<<"Nhap vao muc i:";
        cin>>i;
        cout<<"Cac nut o muc i la:\n";
        PrintLevelExpected(T,0,i);
        cout<<"\n";
        goto yesno;
    }
}