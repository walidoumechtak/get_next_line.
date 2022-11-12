/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:03:19 by woumecht          #+#    #+#             */
/*   Updated: 2022/11/12 22:47:58 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*free_it(char **s1)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = 0;
	}
	return (0);
}

char    *read_line(int fd, char *join)
{
    char    *buf;
    char    *tmp;
    int i;
    
    tmp = NULL;
    buf = (char *) malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    i = read(fd,buf,BUFFER_SIZE);
    if (i <= 0)
        return (free(buf), NULL);
    while (i > 0)
    {
        if (i < 0)
            return(free_it(&buf));
        buf[i] = '\0';
        tmp = ft_strjoin(join,buf);
        free(join);
        join = tmp;
        if (ft_strchr(join,'\n') > -1)
            break ;
        i = read(fd,buf,BUFFER_SIZE);
    }
    free(buf);
    return (join);
}

char    *get_the_line(char *buf)
{
    char    *new_line;
    int i;
    int j;

    if (!buf)
        return (NULL);
    i = 0;
    while (buf[i] != '\n' && buf[i])
        i++;
    new_line = (char *) malloc(i + 2);
    if (!new_line)
        return (NULL);
    j = 0;
    while (j <= i)
    {
        new_line[j] = buf[j];
        j++;
    }
    new_line[j] = '\0';
    return (new_line);
}

char    *get_the_rest(char *buf)
{
    char *rest;
    //char *tmp;
    int i;
    
    i = 0;
    if (!buf)
        return (free(buf), NULL);
    while (buf[i] && buf[i] != '\n')
        i++;
    if (!buf[i])
        return (free(buf), NULL);
    i++;
    rest = ft_strdup(buf + i);
    free(buf);
    if (rest[0] == '\0') // hadi dartha fach tandiro new line f lfile bohdo
        return (NULL);
    return (rest);
}

char    *get_next_line(int fd)
{
    //char    *join;
    static char    *buf;
    char    *temp;
    char    *len;
    
    //join = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(buf), NULL);
    temp = read_line(fd,NULL);
    //printf("temp :::////%s//// \n",temp);
    buf = ft_strjoin(buf,temp);
    free_it(&temp);
    //printf("buf :::---%s---\n", buf);
    len = get_the_line(buf);
    //printf("len :::***%s***\n", len);
    buf = get_the_rest(buf);
    
    
    //printf("buf :::+++%s+++\n", buf);
    
    return (len);
}


// int main()
// {
//     int fd;
//     char *a;
//     char *b;
//     char *c;
//     char *d;
//     char *e;
    
//         //printf("\n\n\n\n");
//      fd = open("walid.txt", O_RDONLY);
//       a = get_next_line(fd);
//       printf("%s", a);
//     //printf("\n\n\n\n");
//      b = get_next_line(fd);
//     printf("%s", b);
//      //printf("\n\n\n\n");
//      c = get_next_line(fd);
//      printf("%s", c);
//      //printf("\n\n\n\n");
//      d = get_next_line(fd);
//     printf("%s", d);
//      e = get_next_line(fd);
//     printf("%s", e);
//  }
