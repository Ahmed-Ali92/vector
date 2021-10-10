#include <iostream>
#include<cassert>
using namespace std;
class Vector{
 private:
     int size{0};
     int *arr{nullptr}; //user size
     int capacity {};   //actual size
     void expand_capacity();
 public:
    Vector(int size);
    ~Vector();
    int get_size();
    int get_front();
    int get_back();
    int get(int index);
    int find(int value);

    void insert(int index,int value);
    void push_back(int value);
    void set(int index,int value);
    void print();

    void right_rotate();
    void right_rotate(int times);
    void left_rotate();
    int pop(int index);
    int find_transposition(int value);
};

void Vector::expand_capacity()
{
    capacity*=2;
    int *arr2=new int[capacity];
    for(int i=0;i<size;i++)
        arr2[i]=arr[i];
    swap(arr,arr2);
    delete []arr2;
    arr2=nullptr;
}
Vector::Vector(int size):
    size(size){
    if (size<0) size=1;
    capacity=size+10;
    arr=new int [capacity];
    }
Vector::~Vector(){
 delete []arr;
 arr=nullptr;
}
int Vector::get_size()
{
    return size;
}
int Vector::get_front()
{
    return arr[0];
}
int Vector::get_back()
{
    return arr[size-1];
}
int Vector::find(int value)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==value) return i;
    }
    return -1;
}
void Vector::print(){
  for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
  cout<<endl;

}

int Vector::get(int index){
 assert(index>=0 &&index<size);
 return arr[index];

}
void Vector::set(int index,int value)
{
     assert(index>=0 &&index<size);
     arr[index]=value;

}
void Vector::push_back(int value)
{
    if (capacity==size) expand_capacity();
    arr[size++]=value;
}
void Vector::right_rotate()
{
    int last_element=arr[size-1];
    for(int i=size-2;i>=0;i--)
        arr[i+1]=arr[i];
    arr[0]=last_element;
}
void Vector::left_rotate()
{
    int first_element=arr[0];
    for(int i=1;i<size;i++)
        arr[i-1]=arr[i];
    arr[size-1]=first_element;
}
void Vector::right_rotate(int times)
{
    times%=size;
    while(times--) right_rotate();
}
int Vector::pop(int index)
{
    assert(0<=index&&index<size);
    int value=arr[index];
    for(int i=index+1;i<size;i++)
        arr[i-1]=arr[i];
    size--;
    return value;
}
int Vector::find_transposition(int value)
{
  for(int i=0;i<size;i++)
  {
      if(arr[i]==value)
      {
          if (i==0) return 0;
          swap(arr[i],arr[i-1]);
          return i-1;
      }
  }
  return -1;
}
void Vector::insert(int index,int value)
{
    assert(0<=index&&index<=size);
    if (size==capacity) expand_capacity();
    for(int i=size-1;i>=index;i--)
        arr[i+1]=arr[i];
    arr[index]=value;
    size++;
}
int main()
{

    return 0;
}
