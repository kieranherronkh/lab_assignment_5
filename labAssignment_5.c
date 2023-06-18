// Kieran Herron 06-09-2023
// COP 3502-013


// README (for TA)
// This code seg faults on my machine, I cannot figure out why
// it produces the correct output on my machine and other
// Ignore this if the code does not seg fault on your machine



#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node * next;
} node;

int length(node * head);
char * toCString(node * head);
void insertChar(node ** pHead, char c);
void deleteList(node ** pHead);



int main(void) {
    // code from the file provided:
    int i, strLen, numImputs;
    node * head = NULL;
    char * str;
    char c;
    FILE * inFile = fopen("input.txt", "r");

    fscanf(inFile, "%d\n", &numImputs);

    while(numImputs-- > 0) {
        fscanf(inFile, "%d\n", &strLen);
        for(i = 0; i < strLen ; i++) {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is: %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL) {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}

int length(node * head) {
    // Function that returns number of nodes in a linked list;
    int nodeCount = 0;
    node * temp = head;

    // basic linked list code that loops through and counts vals
    if(temp == NULL) {
        return(0);
    }
    while(temp != NULL) {
        nodeCount++;
        temp = temp->next;
    }
    return(nodeCount);
    // use head?

}

// function that loops through and prints the data in the linked list; 
char * toCString(node * head) {
    node * temp = head;
    int size = length(head);
    int i = 0;


    if(temp == NULL) {
        return(NULL);
    }
    

    char * str = (char *) calloc(size, sizeof(char));

    while(temp != NULL) {

        str[i++] = temp->letter;
        temp = temp->next;
    }

    
    return(str);
}
// function that appends chars to the linked list;
void insertChar(node ** pHead, char c) {
    // declarations for mem allocation of new node and temp node
    node * newNode = (node *) malloc(sizeof(node));
    node * temp = * pHead;
    // assigns values to the new node;
    newNode->letter = c;
    newNode->next = NULL;

    if(*pHead == NULL) {
        *pHead = newNode;
    }
    // loops through and then assigns newNode at the end of the linked list;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
// function that loops through and frees the memory of the linked list;
void deleteList(node ** pHead) {
    // necessary declarations to delete 
    node * temp = * pHead;
    node * tempNext = NULL;
    // loops through and frees the mem
    while(temp != NULL) {
        tempNext = temp->next;
        free(temp);
        temp = tempNext;
    }
    * pHead = NULL;

}
