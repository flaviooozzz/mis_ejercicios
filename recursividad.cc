#include <iostream>

int par(int x);
int impar(int x);

int main(){
    std::cout<<factorial(5);
    return 0;
}

int par(int x){
    if(x%2==0){
        return true;
    }
    else{
        return impar(x); 
    }
    

}
int impar(int x){
    if(x%2==1){
        return
    }
    else{
        return par(x);
    }
    
    
}