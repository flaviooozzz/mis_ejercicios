#include <iostream>

int suma(int x);
int potencia(int a,int b);
int factorial(int x);

int main(){

    std::cout<<potencia(4,2);

    return 0;
}

int factorial(int x){
    if(x <=1){
        return 1;
    }
    else{
        return x * factorial(x-1);
    }
}

int suma(int x){
    if(x==1){
        return 1;
    }
    else{
        return x+suma(x-1);
    }
}

int potencia(int a, int b){
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }
    else{
        return a*potencia(a,b-1);
    }

}