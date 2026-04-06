#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MessageNode {
    int id;
    char text[256];
    struct MessageNode *firstChild;
    struct MessageNode *nextSibling;
} MessageNode;

// Function Prototypes
MessageNode* createNode(int id, char* text);
MessageNode* findNode(MessageNode* root, int id);
void addReply(MessageNode* root, int parentId, int newId, char* text);
void displayThreads(MessageNode* root, int depth);
void updateMessage(MessageNode* root, int id, char* newText);
MessageNode* deleteNode(MessageNode* root, int id);
void freeTree(MessageNode* root);

int main() {
    MessageNode* root = createNode(0, "ROOT THREAD"); // Initial Chat Header
    int choice, id, parentId, nextId = 1;
    char text[256];

    while (1) {
        printf("\n--- Message Thread Tree CRUD ---");
        printf("\n1. Add Message/Reply\n2. Delete Message\n3. Update Message\n4. Search Message\n5. Display All\n6. Exit\nSelection: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Parent ID (0 for root): ");
                scanf("%d", &parentId);
                printf("Enter message: ");
                getchar(); // Clear buffer
                fgets(text, 256, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline
                addReply(root, parentId, nextId++, text);
                break;
            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                if (id == 0) printf("Cannot delete root.\n");
                else root = deleteNode(root, id);
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new message: ");
                getchar();
                fgets(text, 256, stdin);
                updateMessage(root, id, text);
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                MessageNode* found = findNode(root, id);
                if (found) printf("Found: [%d] %s\n", found->id, found->text);
                else printf("Message not found.\n");
                break;
            case 5:
                printf("\n--- CHAT FEED ---\n");
                displayThreads(root, 0);
                break;
            case 6:
                freeTree(root);
                exit(0);
        }
    }
    return 0;
}

// --- CRUD Functions ---

MessageNode* createNode(int id, char* text) {
    MessageNode* newNode = (MessageNode*)malloc(sizeof(MessageNode));
    newNode->id = id;
    strcpy(newNode->text, text);
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// READ: Recursive Search
MessageNode* findNode(MessageNode* root, int id) {
    if (root == NULL) return NULL;
    if (root->id == id) return root;
    
    MessageNode* res = findNode(root->firstChild, id);
    if (res) return res;
    
    return findNode(root->nextSibling, id);
}

// CREATE: Add node as a child of a specific parent
void addReply(MessageNode* root, int parentId, int newId, char* text) {
    MessageNode* parent = findNode(root, parentId);
    if (!parent) {
        printf("Error: Parent ID %d not found.\n", parentId);
        return;
    }
    MessageNode* newNode = createNode(newId, text);
    if (parent->firstChild == NULL) {
        parent->firstChild = newNode;
    } else {
        MessageNode* temp = parent->firstChild;
        while (temp->nextSibling != NULL) temp = temp->nextSibling;
        temp->nextSibling = newNode;
    }
}

// UPDATE: Modify data
void updateMessage(MessageNode* root, int id, char* newText) {
    MessageNode* target = findNode(root, id);
    if (target) {
        strcpy(target->text, newText);
        printf("Message updated.\n");
    } else printf("Not found.\n");
}

// DELETE: Remove node and its entire sub-thread
MessageNode* deleteNode(MessageNode* root, int id) {
    if (root == NULL) return NULL;

    if (root->id == id) {
        MessageNode* next = root->nextSibling;
        // In a real app, you'd recursively free the root's children here
        free(root); 
        return next;
    }

    root->firstChild = deleteNode(root->firstChild, id);
    root->nextSibling = deleteNode(root->nextSibling, id);
    return root;
}

// DISPLAY: Indented tree view
void displayThreads(MessageNode* root, int depth) {
    if (root == NULL) return;
    for (int i = 0; i < depth; i++) printf("  "); // Indentation for levels
    printf("|-- [%d] %s\n", root->id, root->text);
    
    displayThreads(root->firstChild, depth + 1);
    displayThreads(root->nextSibling, depth);
}

void freeTree(MessageNode* root) {
    if (root == NULL) return;
    freeTree(root->firstChild);
    freeTree(root->nextSibling);
    free(root);
}