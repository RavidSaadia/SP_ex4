//
// Created by ravid on 06/01/2021.
//

#ifndef EX4_TRIEH_H
#define EX4_TRIEH_H
#define NUM_LETTERS ((int) 26)
#define WORD_LEN  30


typedef struct node {
    char letter;
    long unsigned int count;
    struct node *children[NUM_LETTERS];
    int i;
    char word[WORD_LEN];
} node;

int asci(char i);

void init_trie(node *n);

void add_word(node *root, char word[]);

void next_child(node *node);

#endif EX4_TRIEH_H
