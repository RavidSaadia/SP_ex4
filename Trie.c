//
// Created by ravid & David on 06/01/2021.
//

#include <argz.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "trieh.h"

void init_trie(node *n) {
    n->count = 0;
    n->letter = '\0';
    n->i = 0;
    n->j = 25;
    n->father = NULL;
    memset(n->word, 0, WORD_LEN);
    for (int i = 0; i < NUM_LETTERS; ++i) {
        n->children[i] = NULL;
    }
}

void add_word(node *root, char word[]) {
    node *trie_pointer = root;
    while (word[0]) {
        char c = (char) tolower(word[0]);
        node *pNode = trie_pointer->children[asci(c)];
        if (pNode != NULL) {
            trie_pointer = pNode;
            word += 1;
        } else {
            node *new_child = (struct node *) malloc(sizeof(node));
            if (new_child == NULL) {
                perror("malloc failed!!!\n");
                exit(-1);
            }
            memset(new_child, 0, sizeof(struct node));
            new_child->letter = c;
            new_child->j = 25;
            memset(new_child->word, 0, WORD_LEN);
            strcpy(new_child->word, trie_pointer->word);
            new_child->word[strlen(new_child->word)] = c;
            new_child->father = trie_pointer;
            trie_pointer->children[asci(c)] = new_child;
            trie_pointer = new_child;

            word += 1;
        }
    }
    if (trie_pointer != root) {
        trie_pointer->count += 1;
    }
}
int asci(char i) {
    return i - 'a';
}

void next_child(node *node) {
    while (node->children[node->i] == NULL && node->i < 26) {
        node->i++;
    }
}

void prev_child(node *node) {
    while (node->children[node->j] == NULL && node->j > -1) {
        node->j--;
    }
}