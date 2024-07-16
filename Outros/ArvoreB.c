#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float data;
    struct Node* right;
    struct Node* left;
};
struct Node* CriarNode(float data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("[ERROR] Nao foi possivel alocar memoria para esse node");
        return NULL;
    }
    else
    {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

}
void InserirNodeNaArvore(struct Node* node,float newNode)
{
    struct Node* proximo = newNode > node->data ? node->right: node->left;
    while(proximo != NULL)
    {
        node = proximo;
        if(newNode > proximo->data)
        {
            proximo = proximo->right;
        }
        else
        {
            proximo = proximo->left;
        }
    }
     if(newNode > node->data)
        {
            node->right = CriarNode(newNode);
        }
        else
        {
            node->left = CriarNode(newNode);
        }
}
void FreeNodes(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        FreeNodes(node->right);
        FreeNodes(node->left);
        free(node);
        return;
    }
}
int CountTreeNodes(struct Node *node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + CountTreeNodes(node->left) + CountTreeNodes(node->right);
}
int SearchInBinary(float data,struct Node* node, int count)
{
    if(node == NULL)
    {
        return -1;
    }
    if(data == node->data)
    {
        return count;
    }
    else if(data > node->data)
    {
        count ++;
        return SearchInBinary(data,node->right,count);
    }
    else
    {
        return SearchInBinary(data,node->left,count);
    }
}
void main(void)
{
    FILE *file = fopen("data50M.txt", "r");
    
    if (file == NULL) {
        perror("Erro");
        return;
    }
    
    char line[100];
    fgets(line, sizeof(line), file);
    struct Node* node = CriarNode(atof(line));
    while (fgets(line, sizeof(line), file)) {
        float value = atof(line);
        if(SearchInBinary(value,node,0) == -1)
        {
            InserirNodeNaArvore(node,value);
        }
    }
    fclose(file);
    printf("O arquivo apresenta %d elementos diferentes",CountTreeNodes(node));
    FreeNodes(node);
}