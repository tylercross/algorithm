#include <iostream>


using namespace std;
     int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
     int width,height;
     int left=(A-E>0)?A:E;
     int right=(C-G>0)?G:C;
     width=(right-left)>0?right-left:0;
     int down=(B-F>0)?B:F;
     int up=(D-H>0)?H:D;
     height=(up-down)>0?up-down:0;
     int A_plus_B = (C-A)*(D-B)+(G-E)*(H-F);
     int A_overlap_B = width*height;
     return A_plus_B-A_overlap_B ;
     }

int main()
{
    int A,B,C,D,E,F,G,H;
    cin>>A>>B>>C>>D>>E>>F>>G>>H;

    cout<<computeArea(A,B,C,D,E,F,G,H)<<endl;
    return 0;
}
