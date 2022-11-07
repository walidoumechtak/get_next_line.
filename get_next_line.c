/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woumecht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:03:19 by woumecht          #+#    #+#             */
/*   Updated: 2022/11/07 17:18:01 by woumecht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

char *get_the_fucking_ling(char *join, char *buf)
{
    int ret;
    
    while (ft_strchr(join,'\n') == 0)
    {
        ret = read();       
    }
}

char *get_next_line(int fd)
{
    int ret;
    char *buf;
    static char *join;
    char *len;
    
    if (fd == -1)
        return (NULL);
    buf = ft_calloc(BUFFER_SIZE,1);
    ret = read(fd,buf,10);
    if (ret == -1)
        return (NULL);
    buf[ret] = '\0';
    join = ft_strjoin(join, buf);
    if (ft_strchr(join,'\n') != 0)
        len = ft_substr(join);
        
    len = get_the_fucking_ling(join,buf);
    
    
    return (len);
}

int main()
{
    int fd;
    char *a;
    char *b;
    
    fd = open("walid.txt", O_RDONLY);
    a = get_next_line(fd);
    //b = get_next_line(fd);
    printf("%s \n", a);
    //printf("%s \n", b);
}