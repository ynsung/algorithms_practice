#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _node{
    int idx;
    struct _node* nx[26];
} node;

node* createNode(){
    node* np = (node*)malloc(sizeof(node));
    for(int i=0; i<26; i++) np->nx[i] = NULL;
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

void deleteNode(node* np){
    for(int i = 0; i < 26; i++) {
        if(np->nx[i]) deleteNode(np->nx[i]);
    }
    free(np);
}

int findIdx(node* root, char* str){
    node* np = root;
    while(*str){
        int i = *str++ - 'a';
        np = np->nx[i];
    }
    return np->idx;
}

// id_list_len은 배열 id_list의 길이입니다.
// report_len은 배열 report의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(id_list_len*sizeof(int));
    int** matrix = (int**)malloc(id_list_len*sizeof(int*));
    node* root = createNode();
    
    char user[20], player[20]; // 신고자, 피신고자
    
    for(int i=0; i<id_list_len; i++){
        matrix[i] = (int*)malloc(id_list_len*sizeof(int));
        addNode(root, id_list[i], i);
    }
    
    for(int i=0; i<id_list_len; i++){
        for(int j=0; j<id_list_len; j++)
            matrix[i][j] = 0;
    }
    
    for(int i=0; i<id_list_len; i++)
        answer[i] = 0;
    
    for(int i=0; i<report_len; i++){
        int j = 0, u = 0, p = 0;
        while(!(report[i][j] == ' ')){
            user[u++] = report[i][j++];
        }
        user[u] = '\0';
        while(!(report[i][++j] == '\0')){
            player[p++] = report[i][j];
        }
        player[p] = '\0';
        
        u = findIdx(root, user);
        p = findIdx(root, player);
        
        matrix[u][p] = 1;
    }
    
    for(int j=0; j<id_list_len; j++){
        int sum = 0;
        for(int i=0; i<id_list_len; i++)
            sum += matrix[i][j];
        if(sum >= k){
            for(int i=0; i<id_list_len; i++){
                if(matrix[i][j])
                    answer[i]++;
            }
        }
    }
    deleteNode(root);
    return answer;
}