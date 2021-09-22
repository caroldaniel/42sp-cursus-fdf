/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:10:49 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/21 20:02:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>
void	error(int exit_code)
{
	if (exit_code == 1)
		printf("Wrong usage. Expected './fdf <file_path>'.\n");
	else if (exit_code == 2)
		printf("Cannot read file.");
	exit(exit_code);
}
