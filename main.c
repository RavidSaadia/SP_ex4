#include <stdio.h>
#include <argz.h>
#include <malloc.h>
#include "trieh.h"


int main(int argc, char *argv[]) {
    node root;
    init_trie(&root);
    root = getInput(&root);
    if (argc != 2 || argv[1][0] != 'r') {
        start_from_a(&root);
    } else {
        start_from_z(&root);
    }
    return 0;
}

node getInput(node *root) {
    int flag = 1;
    while (flag) {
        char buffer;
        char *word = 0;
        size_t cur_len = 0;

        while (1) {
            buffer = (char) getc(stdin);
            if (buffer == EOF) {
                flag = 0;
                break;
            }
            if ((buffer >= 'a' && buffer <= 'z') || (buffer >= 'A' && buffer <= 'Z')) {
                char *extra = realloc(word, cur_len + 1);
                if (extra == NULL) {
                    perror("realloc() failed!\n");
                    break;
                }
                word = extra;
                word[cur_len] = buffer;
                cur_len += 1;
            } else if (buffer == '\n' || buffer == '\t' || buffer == '\r' || buffer == ' ') {
                break;
            }
        }

        // add '/0' in teh end of the current word
        char *extra = realloc(word, cur_len + 1);
        if (extra == NULL) {
            perror("realloc() failed!\n");
            break;
        }
        word = extra;
        word[cur_len] = '\0';
        add_word(root, word);
        free(word);
    }
    return (*root);
}

void start_from_a(node *root) {
    node *node_pointer = root;
    while (node_pointer) {
        if (node_pointer->children[node_pointer->i]) {
            node_pointer = node_pointer->children[node_pointer->i];
        } else {
            next_child(node_pointer);
            if (node_pointer->i == 26) {
                node *temp = node_pointer;
                node_pointer = node_pointer->father;
                if (!node_pointer) {
                    break;
                }
                node_pointer->i++;
                free(temp);
            }
        }
        unsigned long counter = node_pointer->count;
        if (counter != 0) {
            printf("%s %lu\n", node_pointer->word, counter);
            node_pointer->count = 0;
        }
    }
}

void start_from_z(node *root) {
    node *node_pointer = root;
    while (node_pointer) {
        if (node_pointer->j > -1 && node_pointer->children[node_pointer->j]) {
            node_pointer = node_pointer->children[node_pointer->j];
        } else {
            prev_child(node_pointer);
            if (node_pointer->j == -1) {
                unsigned long counter = node_pointer->count;
                if (counter != 0) {
                    printf("%s %lu\n", node_pointer->word, counter);
                    node_pointer->count = 0;
                }
                node *temp = node_pointer;
                node_pointer = node_pointer->father;
                if (!node_pointer) {
                    break;
                }
                node_pointer->j--;
                free(temp);
            }
        }
    }
}
