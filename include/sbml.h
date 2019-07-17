/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** sbml
*/

#ifndef SBML_H_
#define SBML_H_

#include <string.h>
#include <stdlib.h>

char *open_text(char *path);
char **my_str_to_word_array_synthesis(char const *str);
char ***parser(char *sbml);
char **my_str_to_wordtab(char *str);

#endif /* !SBML_H_ */
