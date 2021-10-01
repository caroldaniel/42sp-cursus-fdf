/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:31:53 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 21:38:27 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	error(int exit_code)
{
	if (exit_code == 1)
		printf("Wrong usage. Expected './fdf <file_path>'.\n");
	else if (exit_code == 2)
		printf("Cannot read file.\n");
	else if (exit_code == 3)
		printf("Memory allocation error: unable to initialize map.\n");
	else if (exit_code == 4)
		printf("Parsing error: invalid file format.\n");
	else if (exit_code == 5)
		printf("Memory allocation error: unable to initialize image.\n");
	else if (exit_code == 6)
		printf("Memory allocation error: unable to initialize camera.\n");
	exit(exit_code);
}
