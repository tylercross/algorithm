 #include <iostream>


using namespace std;
 int addDigits(int num) {
        int copy=num;


            int temp=0;
        while(copy||temp>9)
        {
          while(copy>0)
          {   temp+=copy%10;
              copy/=10;
          }
            if(temp>9) {copy=temp; temp=0;}
            else break;

        }


        return temp;
 }
int main()
{
    int num;
    cin>>num;
    cout<<addDigits(num)<<endl;
    return 0;
}
