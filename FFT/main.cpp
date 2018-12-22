#include<bits/stdc++.h>
using namespace std;
#define pi  3.14159265
vector<int>  xn;
bool isinteger(float x){
if(floor(x) == x )
return 1 ;
else
    return 0 ;
}

void myprintf(complex<double> x){
    printf("%.2f",x.real());
    if(x.imag() > 0)  printf("+%.2fi",x.imag());
    else if(x.imag() < 0)  cout<<x.imag()<<"i";
    else  printf("\t");
}

complex<double> omega(int n , int power){
   float x = cos((2*pi*power)/n);
    float y = -1 *( sin((2*pi*power)/n));
    complex<double> z ;
    z.real() = x ;
    z.imag() = y ;
    return z ; }

complex<double> out (int n , int index , int start = 0 ){
if(n == 2){
    if(index == 0) return xn[start +0] + xn[start +1];
    else   return xn[start + 0] - xn[start + 1] ; }
else {
    if(index >= n/2)   return out(n/2,index-n/2,start) - omega(n,index-n/2) * out(n/2,index-n/2,start + n/2);
    else               return out(n/2,index , start) + out(n/2,index , start +n/2);}
}

//ifstream fin("mytext.txt");
int main()
{
    //freopen("mytext.txt", "r", stdin);
    int n , temp;
    cout<<"Please enter number of N-Points : ";
    cin>>n;
    if( !isinteger(log2(n)) || n < 2 ){
        puts("No you Cant");
        return 0 ;    }

    for(int i = 0 ; i < n ;i ++){
        cout<<"Enter x["<<i<<"] of X[n] : ";
        cin>>temp;
        xn.push_back(temp);
    }
    for(int i = 1 ; i < n/2 ; i++)  swap( xn[ i+ (n/2- 1)] , xn[i] );
    //for(int i = 0 ; i < n ;i++)  cout<<xn[i]<<"\t";   puts(" ");
    puts(" ");
    puts("X(k)\tValue\t\tMag\t\tPhase");
    puts("-------------------------------------------------");
    for(int i = 0 ; i < n ; i++)    {
            complex<double> y = out(n,i);
            cout<<"X["<<i<<"]"<<"\t";
            myprintf(y);
            cout<<"   \t"<<abs(y)<<"\t\t"<<arg(y)*180/pi<<"\n";
    }    return 0;
}
