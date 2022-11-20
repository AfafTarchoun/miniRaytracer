/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:41:43 by atarchou          #+#    #+#             */
/*   Updated: 2022/11/19 21:38:01 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser/parser.h"

int parse_file(char *file)
{
    int fd;
    char *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("error\n");
        return(0);
    }
    line = get_next_line(fd);
    while(line > 0)
    {
        if (line[0] != '\0')
            printf("lol\n");
        free (line);
    }
    close(fd);
    return 0;
}
