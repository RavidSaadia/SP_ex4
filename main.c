#include <stdio.h>
#include <argz.h>
#include "trieh.h"


int main(int argc, char *argv[]) {

    node root;
    init_trie(&root);
    char s1[WORD_LEN] = {0};
    unsigned long counter = 0;
    while (strcmp(s1, "exit")) {
        if (scanf(" %s", s1)) {
            add_word(&root, s1);
        }
    }
    if (argc != 2 || argv[1][0] != 'r') {
        node *node_pointer = &root;
        while (node_pointer) {
            if (node_pointer->children[node_pointer->i]) {
                node_pointer = node_pointer->children[node_pointer->i];
            } else {
                next_child(node_pointer);
                if (node_pointer->i == 26) {
                    node_pointer = node_pointer->father;
                }
            }
            counter = node_pointer->count;
            if (counter != 0) {
                printf("%s\t%lu\n", node_pointer->word, counter);
            }
        }
    } else {


    }

    return 0;
}
