#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int length = 0;

void insert(Node **main_head, char *color, int dest)
{

    Node *head = *main_head;

    Node *np;
    np = (Node *)malloc(sizeof(Node));

    strcpy(np->color, color);
    np->next = NULL;

    if (dest == 0)
    {
        np->next = head->next;
        head->next = np;
    }
    else if (dest < length)
    {
        Node *cur, *pre;
        cur = head->next;
        pre = NULL;

        for (int counter = 1; counter <= dest; counter++)
            /
            {
                pre = cur;
                cur = cur->next;
            }
        np->next = cur;
        pre->next = np;
    }
    else if (dest >= length)
    {
        Node *cur = head;
        while ((cur->next) != NULL)
            cur = cur->next;
        cur->next = np;
    }

    length++;
}
void erase1(Node **main_head, int dest)
{

    Node *head = *main_head;
    Node *cur = head->next;
    Node *pre = head;

    int counter = 1;
    if (cur != NULL && dest > 0)
    {
        if (dest < length)
        {
            while (counter < dest)
            {
                counter++;
                pre = cur;
                cur = cur->next;
            }

            pre->next = cur->next;
            free(cur);
        }
        else
        {
            while (cur->next != NULL)
            {
                pre = cur;
                cur = cur->next;
            }
            pre->next = NULL;
            free(cur);
        }
        length--;
    }
}
void erase2(Node **main_head, char *color)
{

    Node *head = *main_head;
    Node *np = head->next;
    if (np != NULL)
    {
        Node *pre = head;
        while (np != NULL)
        {

            if (strcmp(color, np->color) == 0)
            {
                Node *np1 = np->next;
                pre->next = np1;
                free(np);
                np = np1;
                length--;
            }
            else
            {
                pre = np;
                np = np->next;
            }
        }
    }
}
void reverse(Node **main_head, int dest1, int dest2)
{
    Node *head = *main_head;
    Node *cur, *pre, *cur1, *pre1;

    cur1 = cur = head->next;
    pre1 = pre = head;

    int counter;

    if (dest2 > length)
        dest2 = length;

    if (dest1 > length)
        dest1 = length;

    if (dest1 != dest2 && dest1 > 0 && dest2 > 0)
    {
        if (dest1 > dest2)
        {
            int tmp;
            tmp = dest2;
            dest2 = dest1;
            dest1 = tmp;
        }

        for (counter = 1; counter < dest1; counter++)
        {
            pre = cur;
            cur = cur->next;
        }

        for (counter = 1; counter <= dest2; counter++)
        {
            pre1 = cur1;
            cur1 = cur1->next;
        }

        Node *np, *np1, *np2;
        np = cur->next;
        np1 = cur;

        cur->next = cur1;
        pre->next = pre1;

        while (np != pre1)
        {
            np2 = np->next;
            np->next = np1;
            np1 = np;
            np = np2;
        }
        np->next = np1;
    }
}
