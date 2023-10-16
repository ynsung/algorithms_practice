#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    int idx;
    struct _node* nx[26];
} node;

node* createNode() {
    node* np = (node*)malloc(sizeof(node));
    for (int i=0; i<26; i++) np->nx[i] = NULL;
    return np;
}

void addNode(node* root, char* str, int idx){
    node* np = root;
    while(*str){
        int i = *str++ - 'a';
        if(!np->nx[i]) np->nx[i] = createNode();
        np = np->nx[i];
    }
    np->idx = idx;
}

int findIdx(node* root, char* str){
    node* np = root;
    while(*str){
        int i = *str++ - 'a';
        np = np->nx[i];
    }
    return np->idx;
}

void deleteNode(node* np){
    for(int i = 0; i < 26; i++) {
        if(np->nx[i]) deleteNode(np->nx[i]);
    }
    free(np);
}

void swap(char** a, char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// players_len은 배열 players의 길이입니다.
// callings_len은 배열 callings의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(players_len*sizeof(char*));
    node* root = createNode();
    
    for(int i=0; i<players_len; i++){
        answer[i] = (char*)malloc((strlen(players[i])+1)*sizeof(char));
        strcpy(answer[i], players[i]);
        addNode(root, players[i], i);
    }
    
    for(int i=0; i<callings_len; i++){
        int idx = findIdx(root, callings[i]);
        addNode(root, answer[idx-1], idx);
        addNode(root, answer[idx], idx-1);
        swap(&answer[idx], &answer[idx-1]);
    }
    deleteNode(root);
    return answer;
}