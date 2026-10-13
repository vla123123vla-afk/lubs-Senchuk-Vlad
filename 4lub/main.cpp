#include <iostream>
using namespace std;

char*itoa1(int value, char* string, int radix){
    if(radix<2 || radix>36){
        string[0]='\0';
        return string;
    }
    int i=0;
    bool a=false;

    if(value==0){
        string[i++]='0';
        string[i]='\0';
        return string;
    }

    if (value<0 && radix==10){
        a=true;
        long long v=value; 
        v=-v;
        while(v>0){
            int ost=v % radix;
           if(ost>9){
    string[i]=(ost-10)+ 'A';
} 
else{
    string[i]=ost+ '0';
}
i++;
            v /=radix;
        }
    } 
    else{
        unsigned int value1=(unsigned int)value;
        while(value1>0){
            int ost=value1 % radix;
            if(ost>9){
                string[i++]=(ost-10)+'A';
            }
            else{
                string[i++]=ost+ '0';
            }
            value1 /=radix;
        }
    }

    
    if (a) {
        string[i++]= '-';
    }

    string[i]= '\0';
    int start= 0;
    int end=i-1;

    while(start<end){
        char temp=string[start];
        string[start]=string[end];
        string[end]=temp;
        start++;
        end--;
    }

    return string;
}                                 //вспомогательная функция А



int uniquewords(const char* word, int length){
    int uniquesimbol=0;
    
    for(int i=0; i<length; i++){
        bool b=false;
        for(int j=0; j<i; j++){
            if(word[j]==word[i]){
                b=true;
                break;
            }
        }
        if(!b){
            uniquesimbol++;
        }
    }
    return uniquesimbol; 
}

int main() {
    int n;
    int r;
    char s[100];

    cout << "A)vvedi Z chislo"<< endl;
    cin >> n;
    cout << "vvedi osnovanie sistem schislenia (ot 2 do 36)"<< endl;
    cin >> r;

    itoa1(n, s, r);
    cout << "resiltat perevoda --" << s << endl;

    
    cin.ignore(); 

   char str[301];
    cout << "B)vvedite stroky (do 300 simvolov): ";
    cin.getline(str, 301);

    int max = -1;
    int best = -1;
    int lenght = 0;
    int i = 0;

    while(str[i] != '\0'){
        while(str[i] == ' ' && str[i] != '\0') {
            i++;
        }
        
        if(str[i] == '\0'){
            break;
        }

        int start=i;
        while(str[i] !=' ' && str[i] != '\0'){
            i++;
        }
        int x = i - start;
        int uniqueword = uniquewords(&str[start], x);
        if (uniqueword >= max) {
            max = uniqueword;
            best = start;
            lenght = x;
        }
    }

    if(best != -1){
        cout<< "slovo s max razlich kol-vo simvolov -- "<< endl;
        for(int i=0; i<lenght; i++){
            cout << str[best + i];
        }
        cout << endl;
        cout << "kol-vo razlochnix simvolov v nem -- " << max << endl;
    } else{
        cout << "v stroke net slov" << endl;
    }

    return 0;
}