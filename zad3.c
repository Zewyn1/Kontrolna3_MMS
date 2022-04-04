#include <stdio.h>
#include <stdlib.h>
#include <string.h>
     struct node{
        int *data;
        struct node *next;
     };
void print(struct node *cll){
    struct node *temp = cll;
    while(temp != NULL){
        printf("%d ", *(temp->data));
        temp = temp->next;
    }
    printf("\n");
}
struct node* insertAfter(struct node *cll, int skipCount, int newElem){
    struct node *temp = cll;
    int i = 0;
    while(i < skipCount){
        temp = temp->next;
        i++;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = (int*)malloc(sizeof(int));
    *(newNode->data) = newElem;
    newNode->next = temp->next;
    temp->next = newNode;
    return cll;
}
     int main() {
        int n;
        scanf("%d", &n);
        struct node *head = NULL;
        struct node *tail = NULL;
        struct node *temp = NULL;
        int *data = (int *)malloc(sizeof(int));
        int i;
        for (i = 0; i < n; i++) {
            scanf("%d", data);
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = data;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }
        tail->next = head;
        while (head != tail) {
            printf("%d ", *(head->data));
            head = head->next;
        }
        printf("%d\n", *(head->data));
        free(head);
        print(head);
        int skipCount, newElem;
        scanf("%d %d", &skipCount, &newElem);
        head = insertAfter(head, skipCount, newElem);
        print(head);
        return 0;
    }
