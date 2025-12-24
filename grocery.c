#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100   
#define MAX_NAME_LEN 50    
typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
}
GroceryItem;
GroceryItem inventory[MAX_ITEMS];
int itemCount = 0;                
void printMenu(void);
void addItem(void);
void displayItems(void);
int findItem(const char* name);
void updateItem(void);
void deleteItem(void);
void searchItem(void);
void clearInputBuffer(void);

int main(void) {
    int choice;

    do {
        printMenu();
        
        // Get user choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer(); // Clear the invalid input
            choice = -1; // Set to an invalid choice to loop again
            continue;
        }
        clearInputBuffer(); // Clear the newline character after scanf

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                updateItem();
                break;
            case 4:
                deleteItem();
                break;
            case 5:
                searchItem();
                break;
            case 0:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
        if (choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); // Wait for user to press Enter
        }

    } while (choice != 0);

    return 0;
}

// --- Function Definitions ---

/**
 * @brief Clears the standard input buffer.
 *
 * This function reads and discards all characters from the standard input
 * buffer until a newline character or EOF is encountered. This is
 * useful for cleaning up after `scanf` to prevent issues with `fgets`.
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Displays the main menu options to the user.
 */
void printMenu(void) {
    printf("\n--- Grocery Management System ---\n");
    printf("1. Add New Item\n");
    printf("2. Display All Items\n");
    printf("3. Update Item Quantity/Price\n");
    printf("4. Delete Item\n");
    printf("5. Search for Item\n");
    printf("0. Exit\n");
    printf("----------------------------------\n");
    printf("Enter your choice: ");
}

/**
 * @brief Adds a new grocery item to the inventory.
 *
 * Prompts the user for the item's name, quantity, and price.
 * Checks for inventory limits and duplicate items.
 */
void addItem(void) {
    char name[MAX_NAME_LEN];

    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    printf("\n--- Add New Item ---\n");
    
    // Get Item Name
    printf("Enter item name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    // Check for duplicate
    if (findItem(name) != -1) {
        printf("Error: An item with this name already exists.\n");
        return;
    }

    // Add new item
    strcpy(inventory[itemCount].name, name);

    // Get Item Quantity
    printf("Enter item quantity: ");
    while (scanf("%d", &inventory[itemCount].quantity) != 1 || inventory[itemCount].quantity < 0) {
        printf("Invalid input. Please enter a non-negative number: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    // Get Item Price
    printf("Enter item price: ");
    while (scanf("%f", &inventory[itemCount].price) != 1 || inventory[itemCount].price < 0) {
        printf("Invalid input. Please enter a non-negative price: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    itemCount++;
    printf("\nItem '%s' added successfully!\n", name);
}

/**
 * @brief Displays all grocery items currently in the inventory.
 *
 * Lists items in a formatted table. If the inventory is empty,
 * it prints a message.
 */
void displayItems(void) {
    printf("\n--- Current Inventory (%d items) ---\n", itemCount);

    if (itemCount == 0) {
        printf("The inventory is empty.\n");
        return;
    }

    // Print table header
    printf("----------------------------------------------------------\n");
    printf("| %-30s | %-10s | %-10s |\n", "Item Name", "Quantity", "Price ($)");
    printf("----------------------------------------------------------\n");

    // Print each item
    for (int i = 0; i < itemCount; i++) {
        printf("| %-30s | %-10d | %-10.2f |\n",
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price);
    }
    printf("----------------------------------------------------------\n");
}

/**
 * @brief Finds an item in the inventory by its name.
 *
 * @param name The name of the item to search for (case-sensitive).
 * @return The index of the item if found, otherwise -1.
 */
int findItem(const char* name) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i; // Item found, return index
        }
    }
    return -1; // Item not found
}

/**
 * @brief Updates the quantity and/or price of an existing item.
 *
 * Prompts the user for the item name, then for the new quantity
 * and price.
 */
void updateItem(void) {
    char name[MAX_NAME_LEN];
    int index;
    int newQuantity;
    float newPrice;

    printf("\n--- Update Item ---\n");
    printf("Enter the name of the item to update: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    index = findItem(name);

    if (index == -1) {
        printf("Error: Item '%s' not found in inventory.\n", name);
        return;
    }

    // Get new quantity
    printf("Enter new quantity for '%s' (current: %d): ", name, inventory[index].quantity);
    while (scanf("%d", &newQuantity) != 1 || newQuantity < 0) {
        printf("Invalid input. Please enter a non-negative number: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    // Get new price
    printf("Enter new price for '%s' (current: %.2f): ", name, inventory[index].price);
    while (scanf("%f", &newPrice) != 1 || newPrice < 0) {
        printf("Invalid input. Please enter a non-negative price: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    // Update the item
    inventory[index].quantity = newQuantity;
    inventory[index].price = newPrice;

    printf("\nItem '%s' updated successfully!\n", name);
}

/**
 * @brief Deletes an item from the inventory.
 *
 * Prompts the user for the name of the item to delete. If found,
 * it removes the item by shifting all subsequent items one
 * position to the left in the array.
 */
void deleteItem(void) {
    char name[MAX_NAME_LEN];
    int index;

    printf("\n--- Delete Item ---\n");
    printf("Enter the name of the item to delete: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    index = findItem(name);

    if (index == -1) {
        printf("Error: Item '%s' not found in inventory.\n", name);
        return;
    }

    // Shift all items after this index one position left
    for (int i = index; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    itemCount--; // Decrement the total item count
    
    // Optional: Clear the last (now duplicate) element
    // strcpy(inventory[itemCount].name, "");
    // inventory[itemCount].quantity = 0;
    // inventory[itemCount].price = 0.0;

    printf("\nItem '%s' deleted successfully!\n", name);
}

/**
 * @brief Searches for an item by name and displays its details.
 *
 * Prompts the user for an item name and prints its quantity
 * and price if found.
 */
void searchItem(void) {
    char name[MAX_NAME_LEN];
    int index;

    printf("\n--- Search for Item ---\n");
    printf("Enter the name of the item to search for: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    index = findItem(name);

    if (index == -1) {
        printf("Item '%s' not found in inventory.\n", name);
    } else {
        printf("\n--- Item Found ---\n");
        printf("Name:     %s\n", inventory[index].name);
        printf("Quantity: %d\n", inventory[index].quantity);
        printf("Price:    $%.2f\n", inventory[index].price);
        printf("--------------------\n");
    }
}