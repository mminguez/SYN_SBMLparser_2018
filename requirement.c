/*
** EPITECH PROJECT, 2019
** synthesis project 01
** File description:
** requirement
*/

#include <stdlib.h>

static int end_line(char c)
{
if (c >= 'A' && c <= 'Z')
    return (1);
else if (c >= 'a' && c <= 'z')
    return (1);
else if (c >= '0' && c <= '9')
    return (1);
return (0);
}

static char *my_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while (n > 0 && *(src + i))
        {
        *(dest + i) = *(src + i);
        ++i;
        --n;
        }
    if (n > 0)
        *(dest + i) = '\0';
    return (dest);
}

static int word_count(char *str)
{
    int   i;
    int   word;

    word = 1;
    i = 0;
    while (str != NULL && str[i] != '\0') {
        if (end_line(str[i]) == 1 && end_line(str[i + 1]) == 0)
            word = word + 1;
        i = i + 1;
        }
    return (word);
}

char **my_str_to_word_array_synthesis(char const *str)
{
    int	j = 0;
    int	i = -1;
    int	len = 0;
    char **wordtab;

    if ((wordtab = malloc((word_count(str) + 1) * sizeof(char *))) == 0)
        return (NULL);
    while (wordtab != NULL && str != NULL && str[++i] != '\0') {
            if (end_line(str[i]))
                len += 1;
            if (end_line(str[i]) == 1 && end_line(str[i + 1]) == 0) {
                if ((wordtab[j] = malloc((len + 1) * sizeof(char))) == 0)
                    return (wordtab);
                my_strncpy(wordtab[j], &str[i - len + 1], len);
                len = 0;
                j++;
            }
        }
    wordtab[j] = NULL;
    return (wordtab);
}