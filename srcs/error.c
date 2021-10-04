/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:31:53 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/04 08:06:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_putstr_fd("FDF closed. Bye Bye!\n", 1);
	else if (exit_code == 1)
		ft_putstr_fd("Wrong usage. Expected './fdf <file_path>'.\n", 1);
	else if (exit_code == 2)
		ft_putstr_fd("Cannot read file.\n", 1);
	else if (exit_code == 3)
		ft_putstr_fd("Cannot initialize fdf.\n", 1);
	else if (exit_code == 4)
		ft_putstr_fd("Cannot parse map.\n", 1);
	else if (exit_code == 5)
		ft_putstr_fd("Cannot create image.\n", 1);
	else if (exit_code == 6)
		ft_putstr_fd("Cannot initialize camera.\n", 1);
	else if (exit_code == 7)
		ft_putstr_fd("Unable to render.\n", 1);
	exit(exit_code);
}
