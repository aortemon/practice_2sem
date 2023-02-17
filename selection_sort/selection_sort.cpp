#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 10

struct lnode {
    int data;
    struct lnode* next;
} *head, * visit;

void list_add(struct lnode** q, int num);
void list_selection_sort(void);
void list_print(void);

int main(void) {
    struct lnode* newnode = NULL;
    int i = 0;

    for (int i = 0; i < MAX; i++) {
        list_add(&newnode, (rand() % 100));
    }
    head = newnode;
    cout << "Before sort: \n";
    list_print();
    cout << "After sort: \n";
    list_selection_sort();
    list_print();
    return 0;
}
void list_add(struct lnode** q, int num) {
    struct lnode* temp;
    temp = *q;
    if (*q == NULL) {
        *q = (lnode*)malloc(sizeof(struct lnode));
        temp = *q;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = (lnode*)malloc(sizeof(struct lnode));
        temp = temp->next;
    }
    temp->data = num;
    temp->next = NULL;
}

void list_print(void) {
    visit = head;
    while (visit != NULL) {
        cout << visit->data << " ";
        visit = visit->next;
    }
    printf("\n");
}

void list_selection_sort(void) {
    lnode* a, * b, * c, * d, * r;

    a = b = head;

    while (b->next) {

        c = d = b->next;
        while (d) {
            if (b->data > d->data) {
                if (b->next == d) {
                    if (b == head) {
                        b->next = d->next;
                        d->next = b;
                        r = b;
                        b = d;
                        d = r;
                        c = d;
                        head = b;
                        d = d->next;
                    }
                    else {
                        b->next = d->next;
                        d->next = b;
                        a->next = d;
                        r = b;
                        b = d;
                        d = r;
                        c = d;
                        d = d->next;
                    }
                }
                else {
                    if (b == head) {
                        r = b->next;
                        b->next = d->next;
                        d->next = r;
                        c->next = b;
                        r = b;
                        b = d;
                        d = r;
                        c = d;
                        d = d->next;
                        head = b;
                    }
                    else {
                        r = b->next;
                        b->next = d->next;
                        d->next = r;
                        c->next = b;
                        a->next = d;
                        r = b;
                        b = d;
                        d = r;
                        c = d;
                        d = d->next;
                    }
                }
            }
            else {
                c = d;
                d = d->next;
            }
        }
        a = b;
        b = b->next;
    }

}