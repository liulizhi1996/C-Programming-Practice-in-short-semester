#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUCT_NO_SIZE     15
#define PRODUCT_NAME_SIZE   50

struct Product
{
    char no[PRODUCT_NO_SIZE];
    char name[PRODUCT_NAME_SIZE];
    int quantity;
};

struct ListNode
{
    struct Product product;
    struct ListNode *next;
};

struct ListNode *list;

int Create();
int Destroy();
int Sell(char *no, int quantity);
void Stock(char *no, int quantity);
void List();
void interface();

int Create()
{
    printf("*** CREATE ***\n");
    static int call_times = 0;
    call_times++;
    if (call_times > 1)
    {
        printf("!!! Warning: Before creation, system will destroy the existed records !!!\n");
        if (!Destroy())
        {
            printf("Exit creation.\n");
            return 0;
        }
        getchar();
    }

    char no[PRODUCT_NO_SIZE];
    char name[PRODUCT_NAME_SIZE];
    struct ListNode *p;

    list = (struct ListNode *)malloc(sizeof(struct ListNode));
    list->next = NULL;

    while (1)
    {
        printf("Please enter the no (quit if no input): ");
        fgets(no, PRODUCT_NO_SIZE, stdin);
        no[strlen(no) - 1] = 0;
        if (strlen(no) == 0)
        {
            printf("Finish creating!\n");
            break;
        }
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        strcpy(p->product.no, no);

        printf("Please enter the name: ");
        fgets(name, PRODUCT_NAME_SIZE, stdin);
        name[strlen(name) - 1] = 0;
        strcpy(p->product.name, name);

        p->product.quantity = 0;

        p->next = list->next;
        list->next = p;
    }

    return 1;
}

int Destroy()
{
    printf("*** DESTROY ***\n");
    int choice;
    printf("Do you want to destroy existed records? (1 - Yes, 0 - No): ");
    scanf("%d", &choice);
    if (!choice)
        return 0;

    struct ListNode *p = list, *q;
    while (p)
    {
        q = p->next;
        free(q);
        p = q;
    }
    list = NULL;
    printf("Finish destroying!\n");
    return 1;
}

int Sell(char *no, int quantity)
{
    struct ListNode *p = list->next, *q = list;

    while (p)
    {
        if (strcmp(p->product.no, no) == 0)
        {
            if (p->product.quantity >= quantity)
            {
                p->product.quantity -= quantity;
                if (p->product.quantity == 0)
                {
                    q->next = p->next;
                    free(p);
                    p = q->next;
                    continue;
                }
                printf("Finish to selling!\n");
                return 1;
            }
            else
            {
                printf("No sufficient stock! Failed to sell!\n");
                return 0;
            }
        }
        q = p;
        p = p->next;
    }
    printf("No such record! Failed to sell!\n");
    return 0;
}

void Stock(char *no, int quantity)
{
    struct ListNode *p = list->next, *q;

    while (p)
    {
        if (strcmp(p->product.no, no) == 0)
        {
            p->product.quantity += quantity;
            printf("Finish stocking!\n");
            return;
        }
        p = p->next;
    }

    char name[PRODUCT_NAME_SIZE] = { 0 };
    q = (struct ListNode *)malloc(sizeof(struct ListNode));
    strcpy(q->product.no, no);
    printf("Please enter the name: ");
    fgets(name, PRODUCT_NAME_SIZE, stdin);
    name[strlen(name) - 1] = 0;
    strcpy(q->product.name, name);
    q->product.quantity = quantity;
    q->next = list->next;
    list->next = q;
}

void List()
{
    if (!list)
    {
        printf("Please create list first!\n");
        return;
    }

    printf("*** LIST ***\n");
    struct ListNode *p = list->next;

    if (p)
    {
        int i = 0;
        while (p)
        {
            ++i;
            printf("%-3d - No: %s\t\tName: %s\t\tQuantity: %d\n", i, p->product.no, p->product.name, p->product.quantity);
            p = p->next;
        }
    }
    else
    {
        printf("No products info!\n");
    }
}

void interface()
{
    int choice;
    char no[PRODUCT_NO_SIZE] = { 0 };
    int quantity;

    while (1)
    {
        printf("-------- Products Management System --------\n");
        printf("1. Create\n");
        printf("2. Sell\n");
        printf("3. Stock\n");
        printf("4. List\n");
        printf("5. Destroy\n");
        printf("6. Exit\n");
        printf("--------------------------------------------\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
            case 1:
                Create(); break;
            case 2:
                printf("*** SELL ***\n");
                if (!list)
                {
                    printf("Please create list first!\n");
                    break;
                }
                printf("Please enter the no: ");
                fgets(no, PRODUCT_NO_SIZE, stdin);
                no[strlen(no) - 1] = 0;
                printf("Please enter the quantity: ");
                scanf("%d", &quantity);
                Sell(no, quantity);
                break;
            case 3:
                printf("*** STOCK ***\n");
                if (!list)
                {
                    printf("Please create list first!\n");
                    break;
                }
                printf("Please enter the no: ");
                fgets(no, PRODUCT_NO_SIZE, stdin);
                no[strlen(no) - 1] = 0;
                printf("Please enter the quantity: ");
                scanf("%d", &quantity);
                getchar();
                Stock(no, quantity);
                break;
            case 4:
                List();
                break;
            case 5:
                Destroy();
                break;
            case 6:
                printf("Thank you for your using!\n");
                return;
            default:
                printf("Unrecognized command.\n");
        }
    }
}

int main()
{
    list = NULL;
    interface();
    return 0;
}
