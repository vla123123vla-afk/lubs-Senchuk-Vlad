#include <iostream> 
#include <cmath> 
#include <iomanip>
using namespace std; 

int main() {
    cout<<"vvedite kol-vo elementov n"<<endl;
    int n;
    cin >> n;
int*mas =new int[n];
for (int i=0; i<=n-1; i++)
{
    cout<<"vvedite element number "<<i+1<<endl;
  cin >> mas[i];
}                                         //для ввода массива

for (int i=0; i<n; i++)
{
    cout << mas[i]<< " ";
}
cout<< endl;                           //для вывода массива 

int s=0;
for(int i=0;i<n-1;i++){
    if(mas[i]>=0 && mas[i+1]<0)
s++;
    if(mas[i]<0 && mas[i+1]>=0)
s++;
}
cout<<"kol-vo smen znaka -- "<<s<<endl;    //количество смен знака

int z1=-1, z2=-1;
int pr=1;
for (int i=0; i<n; i++){
    if(mas[i] == 0 ){
        if(z1 == -1)
        z1=i;
    else{
        z2=i;
        break;
    }
    }
}

if(z1==-1 || z2==-1){
cout<<"net dvux nulei"<<endl;
}
else{
if(z1+1==z2){
cout<<"net elementov mezhdy nyliami"<<endl;
}
else{
    for(int i=z1;i<z2-1;i++){
    pr=pr*(mas[i+1]);
    }
cout<<"proizvedenie -- "<<pr<<endl;
} }                                   //произведение между 2 нулевыми элементами

int a=0;
int*mas1 =new int[n];
for (int i=0; i<n; i++)
mas1[i]=0;

for (int i=0; i<n; i++){
if( mas[i] %2==0){
    mas1[a]=mas[i];
    a++;
}
}
for (int i=0; i<n; i++){
if(mas[i] %2!=0){
    mas1[a]=mas[i];
    a++;
}
} 
cout<<"novi massiv -- ";
for(int i=0; i<n; i++){
    mas[i]=mas1[i];
    cout<<mas[i]<<"  ";
}

delete[] mas;
delete[] mas1;

return 0;
}