/*
** EPITECH PROJECT, 2019
** SBMLparser
** File description:
** parser
*/

#include "sbml.h"
#include <stdio.h>

static char *fill_str(char *str)
{
    char *tag = NULL;

    tag = malloc(sizeof(char) * strlen(str) + 1);
    strcpy(tag, str);
    return (tag);
}

static char **init_list_of_tags(char **list)
{
    int i = 0;

    list[0] = fill_str("compartment");
    list[1] = fill_str("species");
    list[2] = fill_str("reaction");
    list[3] = fill_str("speciesReference");
    list[4] = fill_str("listOfCompartments");
    list[5] = fill_str("listOfSpecies");
    list[6] = fill_str("listOfReactions");
    list[7] = fill_str("listOfReactants");
    list[8] = fill_str("listOfProducts");
    return (list);
}

static char *find_tags(char *line)
{
    int i = 0;
    char *tag = NULL;
    char **list = NULL;

    list = malloc(sizeof(char *) * 9);
    list = init_list_of_tags(list);
    if (!line)
        return (NULL);
    while (i <= 8) {
        if (strcmp(list[i], line) == 0)
            return (line);
        i++;
    }
    i = 0;
    while (i <= 8) {
        free(list[i]);
        i++;
    }
    return (NULL);
}

char **parser(char *sbml)
{
    int i = 0;
    char **tags = NULL;

    tags = my_str_to_word_array_synthesis(sbml);
    while (tags[i]) {
        tags[i] = find_tags(tags[i]);
        i++;
    }
    return (tags);
}