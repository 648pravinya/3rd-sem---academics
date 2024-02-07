#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    char data;
    unsigned frequency;
    struct Node*left,*right;
};
struct Node*createNode(char data,unsigned frequency) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->frequency=frequency;
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct node*buildHuffmanTree(char data signed frequency int size) {
    struct Node*left,*right,*top;
    struct Node*priorityQueue[size];
    int rear=0;
    for(int i=0;i<size;++i) {
        priorityQueue[rear++]=createNode(data[i] frequency[i]);
        for(int j=rear-1;j>0;j--) {
            if(priorityQueue[j]->frequency < priorityQueue[j-1]->frequency) {
                struct Node*temp=prorityQueue[j];
                priorityQueue[j]=priorityQueue[j-1];
                priorityQueue[j-1]=temp;
            } else {
                break;
            }
        }
    }
    while (rear>1) {
        left=priorityQueue[0];
        right=priorityQueue[1];
        for(int i=0;i<rear-2;++i) {
            priorityQueue[i]=priorityQueue[i+2];
        }
        rear-=2;
        top=createNode('$',left->frequency+right->frequency);
        top->left=left;
        top->right=right;
        int i;
        for(i=rear-1;i>=0;--i) {
            if(top->frequency>=priorityQueue[i]->frequency) {
                break;
            }
            priorityQueue[i+1]=priorityQueue[i];
            }
            priorityQueue[i+1]=top;
            rear++;
        }
        return prorityQueue[0];
}
void printHuffmanCodes(struct Node*root,int arr[],int top) {
    if(root->left) {
        arr[top]=0;
        printHuffmanCodes(root->left,arr,top+1);
    }
    if(root->right) {
        arr[top]=1;
        printHuffmancodes(root->right,arr,top+1);
    }
    if(!(root->left)&&(root->right)) {
        printf("%c:",root->data);
        for(int i=0;i<top;++i) {
            printf("%d",arr[i]);
        }
        printf("\n");
    }
}
int main() {
    char inputstring[]="blackboard";
    int frequencies[256]={0};
    int len=strlen(inputstring);
    for(int i=0;i<len;i++) {
        frequencies[(int)inputstring[i]]++;
    }
    int vaildcharacters=0;
    for(int i=0;i<256;i++) {
        if(frequencies[i]>0) {
            validcharaters++;
        }
    }
    char data[validcharacters];
    int freq[validcharacters];
    int index=0;
    for(int i-0;i<256;i++) {
        if(frequencies[i]>0) {
            data[index]=(char)i;
            freq[index]=frequencies[i];
            index++;
        }
    }
    struct Node*root=buildHuffmanTree(data,freq,validcharacters);
    int arr[100],top=0;
    printf("Huffman codes:\n");
    printHuffmancodes(root,arr,top);
    return 0;
}
