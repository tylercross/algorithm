#include <iostream>
#include <string>
using namespace std;
void PrintNumber(string number);
void Print1toMaxofNDigitsRecursively(string num,int index);
void Print1toMaxofNDigits(int n)
{
    if(n<=0) return ;
    string num(n,'0');
    for(int i=0;i<10;++i)
    {
        num[0] = i + '0';
        Print1toMaxofNDigitsRecursively(num,0);

    }
}
void Print1toMaxofNDigitsRecursively(string num,int index)
{
    if(index==num.size()-1)
    {
        PrintNumber(num);
        return ;
    }
    for(int i=0;i<10;++i)
    {
        num[index+1] = i + '0';
        Print1toMaxofNDigitsRecursively(num, index+1);

    }

}
void PrintNumber(string number)
{
    for(int i=0;i<number.size();i++)
    {
        if(number[i]!='0'){
            cout<<number.substr(i)<<endl;
            return ;
        }
    }
}

int main()
{
    Print1toMaxofNDigits(2);

    return 0;
}
