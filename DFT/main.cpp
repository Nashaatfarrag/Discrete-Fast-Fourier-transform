#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define pi  3.14159265
Sleep (  __in DWORD dwMilliseconds   );
class Mycomplex {
  public:
    float MyReal = 0 , MyImg = 0 ;
    float Mag () {return sqrt(MyReal*MyReal +MyImg*MyImg);}
    float Phase(){ return (atan(MyImg/MyReal) * 180 ) / 3.14159265 ;}
    //void MyPrint(){cout<<MyReal<<"i"<<MyImg;}
} ;
int main()
{
    int n  ;
    cout<<"Enter N of N-points : ";
    cin>>n;
    float x[n];
    Mycomplex widdle_Mat[n][n] , a[n]  , Result[n];
    for(int i = 0 ; i < n ;i++){
        cout<<"Enter x["<<i<<"]: ";
        cin>>x[i];
    }
puts(" ");

    for(int i = 0 ; i < n ; i ++){
            a[i].MyReal = cos((2*pi*i)/n);
            a[i].MyImg = -1 *( sin((2*pi*i)/n));    }
    /* for(int i = 0 ; i < n ; i ++){
            printf("%lf\n",a[i].MyReal );
           printf("%lf\n",a[i].MyImg ); }*/

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            widdle_Mat[i][j].MyReal = a[(i*j)%n].MyReal;
            widdle_Mat[i][j].MyImg =  a[(i*j)%n].MyImg;    }  }
    cout<<"The widdle Matrix : \n";
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
           printf("%.2lf ",widdle_Mat[i][j].MyReal );
           printf("%.2lfi\t",widdle_Mat[i][j].MyImg );
        }    cout<<"\n";   }
    puts(" ");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j ++ ){
            Result[i].MyReal += x[j]*widdle_Mat[i][j].MyReal;
            Result[i].MyImg += x[j]*widdle_Mat[i][j].MyImg;        }    }
    puts("X(k)\tReal   Img\tMag\t\tPhase");
    puts("-------------------------------------------------");
    for(int i = 0 ; i < n ; i++)
        printf("X[%d]\t%.2lf   %.2lfi\t%f\t%lf\n",i,((Result[i].MyReal == 0 )? 0 : Result[i].MyReal),((Result[i].MyImg == 0 )? 0 : Result[i].MyImg),Result[i].Mag(),Result[i].Phase() );
   sleep(20);
    return 0;}
