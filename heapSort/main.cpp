#include <iostream>
#include <vector>
//#include <cstdlib>
#include <utility>
#include "permutation.h"

template<typename Comparable>
void percDown(std::vector<Comparable> &a, int i, int n);

template<typename Comparable>
void heapsort(std::vector<Comparable> &a) {
    //建立最大堆，类似于删除操作依次从下往上进行下滤。
    for(int i=a.size()/2-1;i>=0;--i)
    {
        percDown(a,i,a.size());
    }
    //依次从后面到前面依次从大往小排，个数-1。
    for(int j=a.size()-1;j>0;--j)
    {
        std::swap(a[0],a[j]);
        percDown(a,0,j);
    }

}

inline int leftChild(int i) {
    return i * 2 + 1;
}

template<typename Comparable>
void percDown(std::vector<Comparable> &a, int root, int n) {


   Comparable temp=a[root];
   int child;
   for(;leftChild(root)<n ;root=child)
   {
       child=leftChild(root);
       if(child+1<n&&a[child]<a[child+1]) child++;
       if(temp<a[child])
          a[root]=a[child];
        else
        break;

   }
   a[root]=temp;

}

int main() {

    std::srand(std::time(0));

    const int SIZE = 20;//常量不可修改
    int i;

    int *nums = Permutation3(SIZE);//生成数组
    std::vector<int> nums_vec;
    nums_vec.reserve(SIZE);//增加vector的容量到SIze

    for (i = 0; i < SIZE; ++i)
        nums_vec.push_back(nums[i]);
    delete[] nums;
    //用vector存放数组

    heapsort(nums_vec);

    for (i = 0; i < nums_vec.size(); i++)
        std::cout << nums_vec[i] << " ";
    std::cout << "\n";

    return 0;
}
