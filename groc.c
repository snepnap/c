// #include<stdio.h>
// #include<string.h>
// struct groc{
//     char itm_name[100];
//     int itm_qu;
//     float price;
// };
// int max=100
// groc product[max];
// int itm_countt=0;

// void itm_add(void){
//     if(max==100){
//         printf("sorry cant add more item ");
//     }
//     else{
//         groc it;
//         printf("enter the product name");
//         scanf("%s",&it.itm_name[]);
//         printf("enter the quantity of the item ");
//         scanf("%d",it.itm_qu);
//         printf("enter the price");
//         scanf("%f",&it.price);
//     }
// }





#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    int id;
    char name[30];
    double price;
    int qty;
} Item;

Item items[MAX_ITEMS];
int item_count = 0;

int find_index(int id) {
    for (int i = 0; i < item_count; i++) if (items[i].id == id) return i;
    return -1;
}

void add_item(void) {
    if (item_count >= MAX_ITEMS) { printf("Inventory full\n"); return; }
    Item it;
    printf("Enter id: ");
    if (scanf("%d", &it.id) != 1) { while (getchar()!='\n'); printf("Bad input\n"); return; }
    if (find_index(it.id) != -1) { printf("ID exists\n"); return; }
    printf("Enter name (no spaces): ");
    if (scanf("%29s", it.name) != 1) { printf("Bad input\n"); return; }
    printf("Enter price: ");
    if (scanf("%lf", &it.price) != 1) { while (getchar()!='\n'); printf("Bad input\n"); return; }
    printf("Enter quantity: ");
    if (scanf("%d", &it.qty) != 1) { while (getchar()!='\n'); printf("Bad input\n"); return; }
    items[item_count++] = it;
    printf("Added\n");
}

void list_items(void) {
    if (item_count == 0) { printf("No items\n"); return; }
    printf("ID\tName\tPrice\tQty\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].qty);
    }
}

void sell_item(void) {
    int id, q;
    printf("Enter id: ");
    if (scanf("%d", &id) != 1) { while (getchar()!='\n'); printf("Bad input\n"); return; }
    int idx = find_index(id);
    if (idx == -1) { printf("Not found\n"); return; }
    printf("Enter quantity to sell: ");
    if (scanf("%d", &q) != 1) { while (getchar()!='\n'); printf("Bad input\n"); return; }
    if (q <= 0 || q > items[idx].qty) { printf("Invalid qty\n"); return; }
    items[idx].qty -= q;
    printf("Sold: %.2f\n", q * items[idx].price);
}

int main(void) {
    int choice = -1;
    while (1) {
        printf("\n1 Add 2 List 3 Sell 0 Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) { while (getchar()!='\n'); continue; }
        if (choice == 1) add_item();
        else if (choice == 2) list_items();
        else if (choice == 3) sell_item();
        else if (choice == 0) break;
        else printf("Bad choice\n");
    }
    return 0;
}














