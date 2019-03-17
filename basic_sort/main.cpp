//#include <iostream>
#include "bubble.h"
//using namespace std;
//function count the number of count variable
#include "select.h"
#include "insert.h"
#include "merge.h"
#include "quick.h"
#include<limits.h>
#include<vector>
using namespace std;

int main()
{
    vector<int> data ={6, 5, 4, 3, 2, 1};//initialize data[]
    int n = data.size();
    cout<<"input size of numbers:"<<endl;
    //cin>>n;
    //int nums[n];
    //int num;
    //cout<<"input numbers"<<endl;
    //int i=0;
    //while(cin>>num&&i<n)
     //   nums[i++] = num;

   // int data[]={4,5,1,6,2,7,3,8};
   //   BubbleSort(data, n);
    //SimpleSeletionSort(data,6);
    // InsertSort(data,6);
    //ShellSort(data,n);
      //Merge_Sort(data,8);
      Merge_Sort_pass(data,8);
    // Quick_sort(data,n);
    cout<<"The sort result:"<<endl;
     printf(data, n);


   // before

    return 0;
}
