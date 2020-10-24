// Arup Guha
// 10/24/01 edited 2/24/04 for COP 3502 Lecture
// Linked List Example

// Edited on 3/31/08 to implement a hashtable of strings.
// In particular, this implements separate chaining hashing.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 39
#define TABLE_SIZE 59999

// Struct used to form a linked list of integers.
struct ll {
    char word[MAX_SIZE+1];
    struct ll *next;
};

struct HashTable {
    struct ll* entries[TABLE_SIZE];
};

// Linked List Functions.
void print(struct ll *front);
struct ll* insert_front(struct ll *front, char word[]);
struct ll* delete(struct ll *front, char word[]);
void dellist(struct ll *p);
int search(struct ll *front, char word[]);

// Hash Table Functions.
void initTable(struct htable *h);
int getHash(char word[]);
void insertTable(char word[], struct htable *h);
int searchTable(struct htable *h, char word[]);
void deleteTable(struct htable *h, char word[]);
void killTable(struct htable *h);

/**
 * Open input dictionary of words
 * 
 * @param[in] argc - Number of arguments, including the program name
 * @param[in] argv - Array of character pointers listing all arguments
 * 
 * @return ifp - Input file pointer to dictionary
 */
FILE *openInputDictionary(int argc, char **argv) {

    printf("\n");

    // Verify arguments
    if (argc < 2) {
        printf("Too few arguments...\n"
               "    (1) Program name required\n"
               "    (2) Path to input dictionary required\n");
        exit(-1);
    }

    // Get file path to input dictionary
    char **dictionaryFilepath = (char **) malloc(strlen(argv[1]) * sizeof(char *));
    strcpy(argv[2], dictionaryFilepath);

    // Verify the file path
    FILE *ifp = fopen(dictionaryFilepath, "r");
    if (ifp == NULL) {
        perror("Failed to open dictionary: ");
        printf("\n");
        exit(-1);
    }

    printf("\n");

    return ifp;
}

/**
 * Read all words from the dictionary into a hash table
 * 
 * @param[in] *ifp - Input file pointer to dictionary
 * 
 * @return dictTable - HashTable struct
 */
struct HashTable readInputDictionary(FILE *ifp) {

    printf("\n");

    // First line of dictionary file contains number of words
    size_t numWords;
    fscanf(ifp, "%d", &numWords);
    printf("Number of words: %d\n", numWords);

    // Create hash table for storing words from dictionary
    struct HashTable dictTable;
    makeHashTable(&dictTable);

    // Read in all words into the hash table
    char word[MAX_WORD_SIZE + 1];
    for (size_t i = 0; i < numWords; ++i) {
        fscanf(ifp, "%s", word);
        printf("Read in... %s\n", word);
        insertTable(word, &dictTable);
    }

    printf("\n");

    return dictTable;
}


int main(int argc, char **argv) {

    char word[MAX_WORD_SIZE + 1];
    int ans;

    // Read input dictionary
    FILE *dictFp = openInputDictionary(argc, argv);
    struct hashTable dictTable = readInputDictionary(dictFp);
    
    // Allow the user to make changes to the hash table and search for words.
    do {

        printf("Do you want to 1)search word, 2) add word, 3) delete a word?\n");
        scanf("%d", &ans);

        // Search for a word.
        if (ans == 1) {

            printf("What word are you looking for?\n");
            scanf("%s", word);
            if (searchTable(&dictTable, word))
                printf("%s was found.\n", word);
            else
                printf("%s was NOT found.\n", word);
        }

        // Add a word.
        else if (ans == 2) {

            printf("What word do you want to add?\n");
            scanf("%s", word);
            if (searchTable(&dictTable, word))
                printf("%s was ALREADY in the table\n", word);
            else
                insertTable(word, &dictTable);
        }

        // Delete a word.
        else if (ans == 3) {

            printf("What word do you want to delete?\n");
            scanf("%s", word);
            deleteTable(&dictTable, word);

        }

    } while (ans < 4); // Not very user friendly, just quits for any number > 3.

    // Not totally necessary since our program is ending, but good style.
    killTable(&dictTable);

    system("PAUSE");
    return 0;
}


// Pre-condition: none
// Post-condition: Initializes the struct pointed to by h to be a valid empty
//                 hash table.
void initTable(struct htable *h) {

    // Set all of these to NULL!
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        h->entries[i] = NULL;
    }
}

void killTable(struct htable *h) {

    int i;

    // Set all of these to NULL!
    for (i=0; i<TABLE_SIZE; i++) {
        dellist(h->entries[i]);
    }
}

// Pre-condition: none
// Post-condition: Calculates a hash value for word.
int getHash(char word[]) {

    int sum=0;

    // Basically represents the value of word in base 128 (according to ascii
    // values) and returns its value mod the TABLE_SIZE.
    for (size_t i = 0; i < strlen(word); ++i)
        sum = (128*sum + (int)(word[i]))%TABLE_SIZE;

    return sum;
}

// Pre-condition: h points to a valid hash table.
// Post-condition: word will be inserted into the table h.
void insertTable(char word[], struct htable *h) {

    int hashVal = getHash(word);
    h->entries[hashVal] = insert_front(h->entries[hashVal], word);
}

// Pre-condition: h points to a valid hash table.
// Post-condition: 1 will be returned iff word is stored in the table pointed to
//                 by h. Otherwise, 0 is returned.
int searchTable(struct htable *h, char word[]) {

    int hashval;
    hashval = getHash(word);
    return search(h->entries[hashval], word);
}

// Pre-condition: h points to a valid hash table.
// Post-condition: deletes word from the table pointed to by h, if word is
//                 stored here. If not, no change is made to the table pointed
//                 to by h.
void deleteTable(struct htable *h, char word[]) {

    int hashval;
    hashval = getHash(word);
    h->entries[hashval] = delete(h->entries[hashval], word);
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: each value in the list will be printed, in order.
void print(struct ll *front) {

    while (front !=NULL) {
        printf("%d ", front->word);
        front = front -> next;
    }
    printf("\n");
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: if val is stored in the list, 1 will be returned,
//                 otherwise 0 will be.
int search(struct ll *front, char word[]) {

    while (front != NULL) {

         if (strcmp(front->word, word) == 0)
             return 1;
         front = front->next;
    }

    return 0;
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: a new node storing num will be inserted to the front of
//                 this list and a pointer to this node will be returned.
struct ll* insert_front(struct ll *front, char word[]) {

    struct ll *temp;

    // Create temp node and link it to front.
    temp = (struct ll*)malloc(sizeof(struct ll));
    strcpy(temp->word, word);
    temp->next = front;

    // Return the new front of the list.
    return temp;
}

// Pre-condition: front points to the head of a linked list structure.
// Post-condition: The first node that contains the value num will be
//                 removed from the list. A pointer to the front of the
//                 list will be returned. If no such value is stored,
//                 the list will remain unchanged.
struct ll* delete(struct ll *front, char word[]) {

    struct ll *temp, *del;
    temp = front;

    // Only need to delete if the list is not null.
    if (temp != NULL) {

        // Take care of the case where first node needs to be deleted.
        if (strcmp(temp->word,word) == 0) {

            del = temp -> next;
            free(temp);
            return del;
        }

        // Otherwise, loop until you find the node to delete and do so.
        while (temp->next != NULL) {

            if (strcmp(temp ->next->word,word) == 0) {

                del = temp -> next;
                temp->next = temp ->next->next;
                free(del);
                return front;
            }
            temp = temp -> next;
        }
    }
    return front;
}

// Pre-condition: p points to a linked list.
// Post-condition: All the memory for the linked list pointed to by p is
//                 freed for use.
void dellist(struct ll *p) {

    struct ll *temp;

    // Recursively free each element in the list.
    if (p !=NULL) {
        temp = p -> next;
        dellist(temp);
        free(p);
    }
}
