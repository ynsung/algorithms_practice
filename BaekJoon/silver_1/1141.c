/*

접두사X 집합이란 집합의 어떤 한 단어가, 다른 단어의 접두어가 되지 않는 집합이다. 

예를 들어, {hello}, {hello, goodbye, giant, hi}, 비어있는 집합은 모두 접두사X 집합이다. 

하지만, {hello, hell}, {giant, gig, g}는 접두사X 집합이 아니다.

단어 N개로 이루어진 집합이 주어질 때, 접두사X 집합인 부분집합의 최대 크기를 출력하시오.

------------입력------------
6
hello
hi
h
run
rerun
running

------------출력------------
4

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node{
    int ing;
    struct _node* nx[26];
}node;

node* createNode(){
    node* np = (node*)malloc(sizeof(node));
    for(int i=0; i<26; i++)
        np->nx[i] = NULL;    
    np->ing = 0;
    return np;
}

void addNode(node* root, char *str){
    node* np = root;
    while(*str){
        int i = *str++ - 'a';
        if(!np->nx[i]) np->nx[i] = createNode();
        np->ing++;
        np = np->nx[i];
    }
    np->ing++;
}

bool isIndependent(node* root, char* str){
    node* np = root;
    while(*str){
        int i = *str++ - 'a';
        np = np->nx[i];
    }
    if(np->ing > 1){
        np->ing--;
        return false;
    }
    else return true;
}

void deleteNode(node* np){
    for(int i = 0; i < 26; i++) {
        if(np->nx[i]) deleteNode(np->nx[i]);
    }
    free(np);
}

int main(){
    int n, answer = 0;
    char str[50][51];
    node* root = createNode();
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", str[i]);
        addNode(root, str[i]);
    }
    for(int i=0; i<n; i++)
        if(isIndependent(root, str[i])) answer++;
    
    printf("%d", answer);
}