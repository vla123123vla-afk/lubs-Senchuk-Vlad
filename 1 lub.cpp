#include <iostream> 
#include <cmath> 
#include <iomanip>
using namespace std; 

int main() { 
    cout << "Vvedite kol-vo znakov k" << endl; 
    int k; 
    cin >> k; 
    cout << "Vvedite x (-1;1]" << endl; 
    double x; 
    cin >> x; 
    double l = 0; 
    if (x>1){
        cout<<"incorrect value";
    }
    else {
    for (int i = 1; i <= k*10; i++) { 
        l += pow(-1, i + 1) * pow(x, i) / i; 
    } 
    cout << "ln(1+x)=";  
 cout << fixed << setprecision(k) << l << endl;}
    return 0; 
}