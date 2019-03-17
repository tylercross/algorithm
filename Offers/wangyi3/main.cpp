#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
double distance(double x1,double y1,double x2,double y2 );
void aoe(const vector<vector<double>>& datas,int nums,vector<int>&res)
{


    int head=0;
    int max_aoe=1;
     cout<<"up_bounnd:"<<datas[head][0]<<endl;
    for(int i=0;i<nums;i++)
    {
        cout<<"up_bounnd:"<<datas[head][0]<<endl;
        for(int j=head+1;j<(1+head+(int)(datas[head][0]));j++)//select center
        {
            max_aoe = 1;
           /* for(int k = j+1;k<=head+datas[head][0];k++)
            {
                if(distance(datas[j][0],datas[j][1],datas[k][0],datas[k][1])
                    > 2*datas[head][1]) continue;
                else
                {
                double center_x = datas[j][0] + datas[k][0];
                double center_y = datas[j][1] + datas[k][1];
                int counter =2;
                for(int l=head+1;l<=head+datas[head][0];l++)
                {
                    if(l==j||l==k) continue;
                    if(distance(datas[l][0],datas[l][1],center_x,center_y)< datas[head][1])
                        counter ++;
                }
                max_aoe = max(max_aoe,counter);
                }
            }*/
        }
        res.push_back(max_aoe);
        //if(head=head+datas[head][0]+1<datas.size());
    }




    //vector<int> ress{1,2,3,4,5,56,6};

}

double distance(double x1,double y1,double x2,double y2 )
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));


}




int main()
{
    int nums;
    cin>>nums;
    vector<vector<double>> datas(nums,vector<double>());
    int point_num;
    double r,x,y;
    vector<double> temp(2,0);
    for(int i=0;i<nums;i++)
    {
        cin>>point_num;
        cin>>r;
        temp[0] = point_num;
        temp[1] = r;
        datas.push_back(temp);
        for(int j=0;j<point_num;j++)
        {
            cin>>x;
            cin>>y;
            temp[0] = x;
            temp[1] = y;

            datas.push_back(temp);

        }

    }

    cout<<nums<<endl;
    for(int i=0;i<datas.size();i++)
    {


        for(int j=0;j<datas[i].size();j++)
            cout<<datas[i][j]<<" ";
        cout<<endl;
}

   vector<int> res;
   aoe(datas,nums,res);
   for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;

   return 0;
}
