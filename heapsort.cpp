#include<bits/stdc++.h>

using namespace std;
/**
    Array implementation of min-heap
    Calculations:

        parent(i)  =  (i-1)/2                           where i is the index of a child (either left or right)

        child(i)   =    left : 2*i+1 , right : 2*i+2    where i is the index of parent
**/


class Heap{
    vector<int> arr;            //using vector<int> for flexible array

    public :
    Heap(){}                    //constructor
    ~Heap(){}                   //destructor

    void insertion(int k){      //inserting a key k in the heap
        arr.push_back(k);
        bubbleUp();
    }

    void deletion(){            //deleting root key
        cout<<arr[0]<<" ";
        arr[0]=arr[arr.size()-1];
        arr.pop_back();
        bubbleDown();
    }

    void bubbleUp(){            //process bubbleUp to remove any min-heap property violation after insertion
       int i= arr.size()-1;     //last index of array

        while(i > 0  && arr[i]<arr[(i-1)/2])       //while  :  i must be greater than 0  and key at index i is less  than its parent key
        {
            int temp=arr[(i-1)/2];      //swapping key at index i and its parent key
            arr[(i-1)/2]=arr[i];
            arr[i]=temp;

            i=(i-1)/2;                  //setting i to its parent index
        }
    }
    void bubbleDown(){              //process bubble down to remove any min-heap violation after deletion
        int parent=0;               //start with root node
        int left=1;                 //left child is at index 1
        int right=2;                //right child is at index 2

        //while  : left index must be less than array size and parent key is grater than either left or right child's key
        while(left<arr.size() && (arr[parent]>arr[left] || arr[parent]>arr[right]))
        {

            if(arr[left]<arr[right]){       //if left key is less than right key of  parent
                int temp=arr[left];         //then swap the parent with left child
                arr[left]=arr[parent];
                arr[parent]=temp;

                parent=left;                //set the parent to left
            }
            else{
                int temp=arr[right];        //if right key is less than left key of parent
                arr[right]=arr[parent];     //then swap the parent with right child
                arr[parent]=temp;

                parent=right;               //set the parent to right
            }

                left=parent*2+1;            //re-calculate left and right child's index for new parent
                right=parent*2+2;
        }
    }
    void sorting()
    {
        cout<<"Unsorted elements in min-heap : ";
        for(int i:arr)
            cout<<i<<" ";

        cout<<"\nSorted elements are : ";
        while(arr.size()!=0)
        {
            deletion();
        }
        cout<<endl;
    }
    void inputElement(){
            int n;
            cout<<"\nEnter the no elements to be sorted : ";
            cin>>n;
            for(int i=0;i<n;i++){
                int k;
                cout<<"\nEnter key "<<i<<" : ";
                cin>>k;
                insertion(k);
            }
    }
};
int main(){
    Heap heap;
    heap.inputElement();
    heap.sorting();

}
