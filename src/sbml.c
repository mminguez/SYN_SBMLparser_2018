/*
** EPITECH PROJECT, 2019
** SBML
** File description:
** main file of project
*/

#include "sbml.h"
#include <stdio.h>

int error_handling(int ac, char **av)
{
    if (ac < 2)
        return (84);
}

int main(int ac, char **av)
{
    char *sbml = NULL;
    char **tags = NULL;
    int i= 0;

    if (error_handling(ac, av) == 84)
        return (84);
    sbml = open_text(av[1]);
    tags = parser(sbml);
    while (tags[i]) {
        printf("%s\n", tags[i]);
        i++;
    }
}