#include <cstdio>

int sleep(int a, int b){
    return printf("%d sleep %d hours\n", a, b);
}

int learn(int a, int b){
    return printf("%d learn %d hours\n", a, b);
}


int eval(int (*visit)(int a, int b)){
    return visit(1, 2);
}

int main(){
    eval(sleep);
    eval(learn);
    return 0;
}