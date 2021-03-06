//
// Created by ravid on 06/01/2021.
//

#ifndef EX4_TRIEH_H
#define EX4_TRIEH_H
#define NUM_LETTERS ((int) 26)
#define WORD_LEN  30

typedef struct node {
    long unsigned int count;
    struct node *children[NUM_LETTERS];
    int i;
    int j;
    char word[WORD_LEN];
    struct node *father;
} node;

int asci(char i);

void init_trie(node *n);

void add_word(node *root, char word[]);

void next_child(node *node);

void start_from_z(node *root);

node getInput(node *root);

void start_from_a(node *root);


void prev_child(node *node);

#endif //EX4_TRIEH_H