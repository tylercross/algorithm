#include <iostream>
#include <vector>

using namespace std;

int GetTranslationCounter(const string & number)
{
    int length=number.length();
    vector<int> counter(length,0);
    int count=0;

    for(int i=length-1;i>=0;--i)
    {
        count=0;
        if(i<length-1)
            count=counter[i+1];
        else count=1;
        if(i<length-1)
        {
            int digit1=number[i]-'0';
            int digit2=number[i+1]-'0';
            int bigger=digit1*10+digit2;
            if(bigger>=10&&bigger<=25)
            {
                if(i<length-2)
                    count+=counter[i+2];
                else
                    count+=1;
            }
        }
        counter[i]=count;

    }
    count=counter[0];
    return count;
}
int GetTranslationCounter(int number)
{
    if(number<0) return 0;
    string numberInString=to_string(number);
    return GetTranslationCounter(numberInString);
}


int main()
{
    int num;
    while(cin>>num)
    cout<<GetTranslationCounter(num);


    return 0;
}
