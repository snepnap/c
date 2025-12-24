#include <stdio.h>
#include <string.h> 
#define MAX_ITEMS 100   
#define MAX_NAME_LEN 50  

int main() {
    char itemNames[MAX_ITEMS][MAX_NAME_LEN];
    int itemQuantities[MAX_ITEMS];          
    float itemPrices[MAX_ITEMS];            
    int itemCount = 0; 
    int choice;
    char searchName[MAX_NAME_LEN]; 
    int foundIndex;                
    int i;                         

    do {
        printf("\n--- Basic Grocery Management ---\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Update Item Quantity/Price\n");
        printf("4. Delete Item\n");
        printf("5. Search for Item\n");
        printf("0. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            choice = -1;
        }
        
        while (getchar() != '\n');

        switch (choice) {
            
            case 1:
                printf("\n--- Add New Item ---\n");
                if (itemCount >= MAX_ITEMS) {
                    printf("Inventory is full. Cannot add more items.\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", itemNames[itemCount]);

                    printf("Enter item quantity: ");
                    scanf("%d", &itemQuantities[itemCount]);

                    printf("Enter item price: ");
                    scanf("%f", &itemPrices[itemCount]);
                    
                    printf("\nItem '%s' added successfully!\n", itemNames[itemCount]);
                    itemCount++;
                }
                break;
            case 2:
                printf("\n--- Current Inventory (%d items) ---\n", itemCount);
                if (itemCount == 0) {
                    printf("The inventory is empty.\n");
                } else {
                    for (i = 0; i < itemCount; i++) {
                        printf("  %s: Quantity %d, Price $%.2f\n",
                               itemNames[i],
                               itemQuantities[i],
                               itemPrices[i]);
                    }
                }
                break;
            case 3:
                printf("\n--- Update Item ---\n");
                printf("Enter the name of the item to update: ");
                scanf("%s", searchName);
                foundIndex = -1; 
                for (i = 0; i < itemCount; i++) {
                    if (strcmp(itemNames[i], searchName) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                
                if (foundIndex == -1) {
                    printf("Error: Item '%s' not found.\n", searchName);
                } else {
                    printf("Enter new quantity for '%s' (current: %d): ", itemNames[foundIndex], itemQuantities[foundIndex]);
                    scanf("%d", &itemQuantities[foundIndex]);
                    
                    printf("Enter new price for '%s' (current: %.2f): ", itemNames[foundIndex], itemPrices[foundIndex]);
                    scanf("%f", &itemPrices[foundIndex]);
                    
                    printf("\nItem '%s' updated successfully!\n", itemNames[foundIndex]);
                }
                while (getchar() != '\n');
                break;
            case 4:
                printf("\n--- Delete Item ---\n");
                printf("Enter the name of the item to delete: ");
                scanf("%s", searchName);

                // 1. Find the item
                foundIndex = -1; 
                for (i = 0; i < itemCount; i++) {
                    if (strcmp(itemNames[i], searchName) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                
                if (foundIndex == -1) {
                    printf("Error: Item '%s' not found.\n", searchName);
                } else {
                    for (i = foundIndex; i < itemCount - 1; i++) {
                        strcpy(itemNames[i], itemNames[i+1]); 
                        itemQuantities[i] = itemQuantities[i+1];
                        itemPrices[i] = itemPrices[i+1];
                    }
                    itemCount--;
                    printf("\nItem '%s' deleted successfully!\n", searchName);
                }
                
                while (getchar() != '\n');
                break;
            case 5:
                printf("\n--- Search for Item ---\n");
                printf("Enter the name of the item to search for: ");
                scanf("%s", searchName);
                
                foundIndex = -1;
                for (i = 0; i < itemCount; i++) {
                    if (strcmp(itemNames[i], searchName) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                
                if (foundIndex == -1) {
                    printf("Item '%s' not found in inventory.\n", searchName);
                } else {
                    printf("\n--- Item Found ---\n");
                    printf("Name:     %s\n", itemNames[foundIndex]);
                    printf("Quantity: %d\n", itemQuantities[foundIndex]);
                    printf("Price:    $%.2f\n", itemPrices[foundIndex]);
                    printf("--------------------\n");
                }
                while (getchar() != '\n');
                break;
            case 0:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
        if (choice != 0) {
            printf("\nPress Enter to continue...");
            getchar();
        }

    } while (choice != 0); 

    return 0; 
}