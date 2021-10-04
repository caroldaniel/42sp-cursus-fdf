/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:31:53 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/04 00:18:08 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	error(int exit_code)
{
	if (exit_code == 0)
		printf("FDF closed. Bye Bye!\n");
	else if (exit_code == 1)
		printf("Wrong usage. Expected './fdf <file_path>'.\n");
	else if (exit_code == 2)
		printf("Cannot read file.\n");
	else if (exit_code == 3)
		printf("Cannot initialize fdf.\n");
	else if (exit_code == 4)
		printf("Cannot parse map.\n");
	else if (exit_code == 5)
		printf("Cannot create image.\n");
	else if (exit_code == 6)
		printf("Cannot initialize camera.\n");
	else if (exit_code == 7)
		printf("Unable to render.\n");
	exit(exit_code);
}
