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
        cout<<"Root is : "<<arr[0];
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
    void printHeap()
    {
        cout<<"Heap : ";

        for(int i:arr)              //for each implementation
            cout<<i<<" ";
        cout<<endl;
    }
};
int main(){
    Heap heap;
    int choice,key;

    do{

        cout<<"\nHeap Implementation : "
            <<"\n1.Insertion "
            <<"\n2.deletion "
            <<"\n3.print heap"
            <<"\n4.exit"
            <<"\nEnter Your Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                    int n;
                    cout<<"Enter no of elements to be inserted : ";
                    cin>>n;
                    for(int i=0;i<n;i++){
                    cout<<"\nEnter key : ";
                    cin>>key;
                    heap.insertion(key);
                    }
                    break;
            case 2: heap.deletion();
                    break;
            case 3: heap.printHeap();
                    break;
            case 4: cout<<"Exiting...!!!";
                    exit(0);

            default: cout<<"\nInvalid choice ! Try Again.";

        }
    }while(true);

}
