/*
** EPITECH PROJECT, 2018
** BSQ project
** File description:
** file.c
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

char *open_text(char *path)
{
    struct stat sts;
    int size = 0;
    int fd = 0;
    char *str = NULL;

    stat(path, &sts);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        exit(84);
    str = malloc(sizeof(char) * (sts.st_size + 1));
    if (str == NULL)
        exit(84);
    size = read(fd, str, sts.st_size);
    str[size] = '\0';
    close(fd);
    return (str);
}