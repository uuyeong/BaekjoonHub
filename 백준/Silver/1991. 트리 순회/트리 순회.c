#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct tagNode {
    struct tagNode* left;
    struct tagNode* right;
    char data;
} Node;

// 노드 생성
Node* CreatNode(char NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->data = NewData;
    return NewNode;
}

// 노드 소멸
void DestroyTree(Node* Tree) {
    if (Tree == NULL) return;

    DestroyTree(Tree->left);
    DestroyTree(Tree->right);
    free(Tree);
}

// 노드 찾기
Node* FindNode(Node* Tree, char x) {
    if (Tree == NULL) return NULL;
    if (Tree->data == x) return Tree;

    Node* LeftFind = FindNode(Tree->left, x);
    if (LeftFind != NULL) return LeftFind;

    return FindNode(Tree->right, x);
}

// 전위 순회
void Pre_Traversal(Node* Tree) {
    if (Tree == NULL) return;

    printf("%c", Tree->data);
    Pre_Traversal(Tree->left);
    Pre_Traversal(Tree->right);
}

// 중위 순회
void In_Traversal(Node* Tree) {
    if (Tree == NULL) return;

    In_Traversal(Tree->left);
    printf("%c", Tree->data);
    In_Traversal(Tree->right);
}

// 후위 순회
void Post_Traversal(Node* Tree) {
    if (Tree == NULL) return;

    Post_Traversal(Tree->left);
    Post_Traversal(Tree->right);
    printf("%c", Tree->data);
}

int main(void) {
    int n;
    scanf("%d", &n);
    getchar(); // 개행 문자 제거

    Node* Tree = CreatNode('A'); // 루트 노드 생성

    char arr[4];
    for (int i = 0; i < n; i++) {
        scanf(" %c %c %c", &arr[0], &arr[1], &arr[2]);

        Node* CurrentNode = FindNode(Tree, arr[0]);
        if (CurrentNode == NULL) {
            printf("Node not found: %c\n", arr[0]);
            continue;
        }

        if (arr[1] != '.') CurrentNode->left = CreatNode(arr[1]);
        if (arr[2] != '.') CurrentNode->right = CreatNode(arr[2]);
    }
    
    Pre_Traversal(Tree);
    printf("\n");

    In_Traversal(Tree);
    printf("\n");

    Post_Traversal(Tree);
    printf("\n");

    DestroyTree(Tree); // 메모리 해제

    return 0;
}
