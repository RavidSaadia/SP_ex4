//
// Created by ravid & David on 06/01/2021.
//

#include <argz.h>
#include <stdlib.h>
#include <ctype.h>
#include "trieh.h"

void init_trie(node *n) {
    n->count = 0;
    for (int i = 0; i < NUM_LETTERS; ++i) {
        n->children[i] = NULL;
    }
    n->letter = '\0';
}

void add_word(node *root, char word[]) {
    node *trie_pointer = root;
    while (word[0]) {
        char c = (char) tolower(word[0]);
        node *pNode = trie_pointer->children[asci(c)];
        if (pNode != NULL) {
            pNode->word[strlen(word)] = c;
//            strncat(pNode->word, &c, 1);
            trie_pointer = pNode;
            word += 1;
        } else {
            node *new_child = (struct node *) malloc(sizeof(node));//&new_node;
            memset(new_child, 0, sizeof(struct node));
            new_child->letter = c;

            trie_pointer->children[asci(c)] = new_child;
            trie_pointer = new_child;
            pNode->word[0] = c;
            word += 1;
        }
    }
    trie_pointer->count += 1;
}

int asci(char i) {
    return i - 'a';
}

void next_child(node *node) {

    while (node->children[node->i] == NULL) {
        node->i++;
    }
}