#include<iostream>
using namespace std;

void Swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void XuatMang(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

// Worst Case
//  .In the worst-case scenario, the outer loop runs O(n) times.
//  .As a result, the worst-case time complexity of Bubble Sort is O(n x n) = O(n x n)=  O(n^2).
// Best Case
//  .In the best-case scenario, the array is already sorted, but just in case, bubble sort performs O(n) comparisons.
//  .As a result, the time complexity of Bubble Sort in the best-case scenario is O(n).
// Average Case
//  .Bubble sort may require (n/2) passes and O(n) comparisons for each pass in the average case.
//  .As a result, the average case time complexity of Bubble Sort is O(n/2 x n) = O(n/2 x n) = O(n/2 x n) = O(n/2 x n) = O (n2).

void BubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool HaveSwap=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                Swap(a[j+1],a[j]);
                HaveSwap=true;
            }
        }
        if(HaveSwap==false)
            break;
    }
}
//In all three cases the time complexity of Selection Sort is O(n x n)= O(n^2)

void SelectionSort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            min=j;
        }
        Swap(a[min],a[i]);
    }
}


//In all three cases the time complexity of InsertionSort is O(n x n)= O(n^2)
void InsertionSort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j-=1;
        }
        a[j+1]=key;
    }
}
// Best Case:Time complexity of BinarySearch is O(1) element was found in the first step itself
// Average Case:Time Complexity of Binary Search is O(logN).
// Worst Case:Time Complexity of Binary Search is O(logN).
int BinarySearch(int a[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid= l+ (r-l)/2;//equivalent (l+r)/2 but avoid overflow
        
        if(a[mid]==x)//find x in the middle element
            return mid;

        if(a[mid]>x)
            return BinarySearch(a,l,mid-1,x);

        if(a[mid]<x)
            return BinarySearch(a,mid+1,r,x);
    }
    return -1;
}

//Time complexity of Tower is O(n^2)
void Tower(int n , char a, char b, char c )
{
    if(n==1){
        cout<<"\t"<<a<<"-------"<<c<<endl;
        return;
    }
    Tower(n-1,a,c,b);
    Tower(1,a,b,c);
    Tower(n-1,b,a,c);
}

void Heapify(int a[],int n,int i)
{
    int Largest = i;
    int Left = i*2+1;
    int Right = i*2+2;

    if(Left<n && a[Largest]<a[Left])// cây trái lớn hơn đầu
        Largest=Left;

    if(Right<n && a[Largest]<a[Right])// cây phải lớn hơn đầu
        Largest=Right;

    while(Largest!=i)
    {
        Swap(a[Largest],a[i]);
        Heapify(a,n,Largest);
    }

}
// Time complexity of Heapify() is O(Logn) 
// Time complexity of HeapSort() is O(n)
// Worst Case Time Complexity of HeapSort: O(n*log n)
// Best Case Time Complexity of HeapSort: O(n*log n)
// Average Time Complexity of HeapSort: O(n*log n)

void HeapSort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)//build max heap
        Heapify(a,n,i);

    for(int i=n-1;i>=0;i--)
    {
        Swap(a[0],a[i]);//bring max heap to the last element and cut it
        Heapify(a,i,0);//build max heap again :v
    }
}

void Merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];//creat temp arrays

    //copy element to temp arrays
    for(int i=0;i<n1;i++)
        L[i]=a[l+i];
    for(int j=0;j<n2;j++)
        R[j]=a[m+1+j];

    int i=0,j=0,k=l;//init index of arrays

    //Merge Array
    while(i<n1&&j<n2)
    {
        if(L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    //copy the remaining element to main array
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];

}

//In all three case time complexity of MergeSort is O(nlogn)
void MergeSort(int a[],int l,int r)
{
    if(r>l)
    {
        int m=l+(r-l)/2; //equivalent to (l+r)/2 but avoid overflow
        //Recursive call to split array
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        Merge(a,l,m,r);
    }
}


int Partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            Swap(a[i],a[j]);
        }
    }
    Swap(a[i+1],a[high]);
    return (i+1);
}

//Best case:Time complexity of QuickSort is O(nlogn)
//Average case:Time complexity of QuickSort is O(nlogn)
//Worst case:Time complexity of QuickSort is O(n^2)
void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int p=Partition(a,low,high);
        QuickSort(a,low,p-1);
        QuickSort(a,p+1,high);
    }
}

int main()
{
    int A[]={7,6,4,9,15,12,5};
    int n=7;

    // ------------------------------------------------------------------------------------ //
                                    //Các giải thuật tìm kiếm
    //BubbleSort(A,n);
    // SelectionSort(A,n);
    // InsertionSort(A,n);
    // HeapSort(A,n);
    //MergeSort(A,0,n-1);
    //QuickSort(A,0,n-1);

    // ------------------------------------------------------------------------------------ //
                                    //Thuật toán tìm kiếm nhị phân
    // int x;
    // cout<<"Nhap vao x:";//Nhập x để tìm kiếm Nhị Phân
    // cin>>x;
    // cout<<"Vi tri cua x la:"<<BinarySearch(A,0,n-1,x)<<endl;

    // ------------------------------------------------------------------------------------ //
                                   //Bài toán tháp Hà Nội
        // int soluongdia;
        // cout<<"Nhap vao so luong dia:";
        // cin>>soluongdia;
        // char a='A',b='B',c='C';
        // Tower(soluongdia,a,b,c);
    // ------------------------------------------------------------------------------------ //
    XuatMang(A,n);
    return 0;
}