#include<iostream>
#include <fstream>
#include <list>
#include <stdlib.h>
#include <cmath>
//[a,b] with equal boundary
void swap(int* input,int a,int b){
   int temp;
   temp=input[a];
   input[a]=input[b];
   input[b]=temp;
}
void quicksort(int* input,int start,int end){
   if(end-start==0){
   }
   else{
     srand(time(NULL));
    int irand=rand();
    double temp=irand/(RAND_MAX+1.0);
    temp=start+(end-start)*temp;
    int pivot=floor(temp);
    swap(input,start,pivot);
    std::cout<<"Partition Element is: "<<input[start]<<std::endl;
    int i=start+1;
    int j=start;
    for(j=start+1;j<=end;j++){
      if(input[j]<input[start]){
         swap(input,j,i+1);
         i++;
      }
    }
    swap(input,i,start);
   }
}
int main(){
   std::fstream fs;
   fs.open("QuickSort.txt",std::fstream::in);
   std::list<int> input;
   int temp;
   do{
      fs>>temp;
      input.push_back(temp);
   }while(!fs.eof());
   int size=input.size();
   int* data=new int [size];
   size_t count=0;
   for(std::list<int>::iterator a=input.begin();a!=input.end();a++){
      data[count]=*a;
      count++;
   }
   int a[10]={10,9,8,7,6,5,4,3,2,1};
   quicksort(a,0,9);
   for(size_t i=0;i<10;i++){
      std::cout<<a[i]<<std::endl;
   }
}
