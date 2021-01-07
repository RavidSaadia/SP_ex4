#include <stdio.h>
#include <argz.h>
#include <malloc.h>
#include "trieh.h"


int main(int argc, char *argv[]) {

    node root;
    init_trie(&root);
//    char s1[WORD_LEN] = {0};
    unsigned long counter = 0;
//    while (strcmp(s1, "x")) {
//        if (scanf(" %s", s1)) {
//            add_word(&root, s1);
//        }
//    }
    int flag = 1;
    while (flag) {
        char buffer = 'a';
        char *word = 0;
        size_t cur_len = 0;

        while (1) {
//            scanf("%c", &buffer);

            buffer = getc(stdin);
            if (buffer == EOF) {
                flag = 0;
                break;
            }
            if ((buffer >= 'a' && buffer <= 'z') || (buffer >= 'A' && buffer <= 'Z')) {
                char *extra = realloc(word, cur_len + 1);
                if (extra == NULL) {
                    perror("realloc() failed!\n");
                }
                word = extra;
                strcpy(word + cur_len, &buffer);
                cur_len += 1;
            } else if (buffer == '\n' || buffer == '\t' || buffer == '\r' || buffer == ' ') {
                break;
            }
        }

        // add '/0' in teh end of the current word
        char *extra = realloc(word, cur_len + 1);
        if (extra == NULL) break;
        word = extra;
        word[cur_len] = '\0';
        add_word(&root, word);
//        printf("%s [%d]\n", word, (int) strlen(word));
        free(word);
    }

    if (argc != 2 || argv[1][0] != 'r') {
        node *node_pointer = &root;
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
//                    node_pointer->children[node_pointer->i] = NULL;
                    free(temp);
                }
            }
            counter = node_pointer->count;
            if (counter != 0) {
                printf("%s\t%lu\n", node_pointer->word, counter);
                node_pointer->
                        count = 0;
            }
        }
    } else {


    }
//    free(&root);
    return 0;
}
