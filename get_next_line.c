/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:03:19 by woumecht          #+#    #+#             */
/*   Updated: 2022/11/11 12:59:00 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char *get_the_line(char *buf, int fd, int ret)
// {
//     char    *len;
//     static char *join;

//     if (!join)
//          join = "";
//     {
//         join = malloc(1);
//         join[0] = '\0';
//     }
//     join = ft_strjoin(join, buf);
//     while (ft_strchr(join,'\n') == -1 && ret > 0)
//     {
//         //buf = malloc(BUFFER_SIZE);
//         ret = read(fd,buf,BUFFER_SIZE);
//         if (ret < 0)
//         {
//             free_it(&buf);
//             break ;
//         }
//         if (ret == 0 && ft_strchr(buf,'\n') == -1)
//             return (buf);
//         join = ft_strjoin(join,buf);  
//         //free_it(&buf);    
//     }
//     len = ft_substr(join,0,ft_strchr(join, '\n') + 1);
//     join = ft_substr(join,ft_strchr(join, '\n') + 1,ft_strlen(join));
//     free_it(&buf);
//     if (ret == 0)
//     {
//         free_it(&join);
//         join = NULL;
//     }
//     return (len);
// }

// char *get_next_line(int fd)
// {
//     int ret;
//     char *buf;     
//     char *len;
    
//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);
//     buf = malloc(BUFFER_SIZE + 1);
//     if (!buf)
//         return (NULL);
//     ret = read(fd,buf,BUFFER_SIZE);
//     if (ret == -1 || ret == 0)
//         return (free_it(&buf));
//     len = get_the_line(buf, fd, ret);
//     return (len);
// }


// read the line
// get the line
// get the rest of the line 

// line 1
// line 2
// line 3

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
    int i;
    
    buf = (char *) malloc(BUFFER_SIZE + 1);
    i = read(fd,buf,BUFFER_SIZE);
    if (i < 0)
        return(free_it(&buf));
    if (i == 0 && buf[0])
        return (ft_strjoin(join,buf));
    if (i == 0)
    {
        free_it(&buf);
        return (join);
    }
    join = ft_strjoin(join, buf);
    while (ft_strchr(join, '\n') == -1 && i > 0)
    {
        i = read(fd, buf, BUFFER_SIZE);
        if (i < 0)
            return (free_it(&buf));
        join = ft_strjoin(join, buf);
    }
    return (join);
}

char    *get_line(int fd, char *buf)
{
    
}

char    *get_next_line(int fd)
{
    static char    *join;
    char    *buf;
    char    *len;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    join = malloc(1);
    if (!join)
        return (NULL);
    join[0] = '\0';
    buf = read_line(fd,join);
    len = 
}


int main()
{
    int fd;
    char *a;
    char *b;
    char *c;
    char *d;
    char *e;
    
    
    fd = open("walid.txt", O_RDONLY);
    a = get_next_line(fd);
    printf("%s", a);
    b = get_next_line(fd);
    printf("%s", b);
    c = get_next_line(fd);
    printf("%s", c);
    d = get_next_line(fd);
    printf("%s", d);
    e = get_next_line(fd);
    printf("%s", e);
}
