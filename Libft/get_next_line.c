#include "libft.h"

void *myfree(void *str) // yani cidden mi? Buna gerek var mı?
{
    free(str);
    return (NULL);
}

char *get_next_line(int fd)
{
    int rd_byte;
    int i;
    char buffer;
    char *line;

    rd_byte = 1;
    i = 0;
    line = (char *)malloc(sizeof(char) * 8888);
    buffer = 0;
    if (fd < 0)
        return (NULL);
    while (rd_byte > 0)
    {
        rd_byte = read(fd, &buffer, 1);
        if (rd_byte <= 0)
            break;
        line[i++] = buffer;
        if (buffer == '\n')
            break;
    }
    line[i] = '\0';
    if (!*line)
        myfree(line); // free(str); olma mı?
    return (line);
}