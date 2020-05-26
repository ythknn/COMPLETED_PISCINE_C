/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include "ft_ultimator.h"

void	ft_putstr(char *str)		/* функция печати строки */
{
	while(*str)
		write(1, str++, 1);
}

void	ft_destroy(char ***factory)	/* функция освобождает выделенную нами память пробегаясь по всем
									 * указателям в которых мы сохранили адреса выделеной памяти */
{
	int i;
	int j;

	i = 0;
	while (factory[i])
	{
		j = 0;
		while (factory[i][j] != ((void *)0))
		{
			free(factory[i][j]);
			j++;
		}
		free(factory[i]);
		i++;
	}
	free(factory);
}


int		main()										/* Основная функция */
{	
	char	***ptr;									/* Обьявим указатель на указатель на указатель, в который сохраним адресс выделенной нами памяти */
	int i;											/* Обьявим счетчик для перемещения по указателям на указатели */
	int j;											/* Обьявим счетчик для перемещения по указателям в которые запишем адреса памяти выделенной под строки */

	if ((ptr = (char ***)malloc(1)) == ((void *)0))	/* Выделяем память и приводим ее к типу "указатели на указатели на указатели", там будут храниться адреса указателей на указатели, сохраняем ее в ptr */
		return (0);									/* Если память выделить не удалось возвращаем ноль и завершаем функцию main */
	i = 0;
	while (i < 1)
	{	
		if ((ptr[i] = (char **)malloc(3)) == ((void *)0))/* Выделяем память и приводим ее к типу "указатели на указатели", там будут храниться адреса указателей, сохраняем ее в **ptr */
			return (0);								/* Если память выделить не удалось возвращаем ноль и завершаем функцию main */
		j = 0;
		while (j < 3)
		{
			if ((ptr[i][j] = (char *)malloc(5)) == ((void *)0))/* Выделяем память под пять символов и сохраняем ее адресс в указателе ptr[i][j] */
				return (0);							/* Если память выделить не удалось возвращаем ноль и завершаем функцию main */
			ptr[i][j][0] = (char)'h';				/* Запишем в выделенную под символы память любые символы, например строку "hola" */
			ptr[i][j][1] = (char)'o';
			ptr[i][j][2] = (char)'l';
			ptr[i][j][3] = (char)'a';
			ptr[i][j][6] = (char)'\0';
			j++;
		}
		i++;
	}

													/* Проверим как прошло выделение памяти */
	j = 0;											/* Создадим цикл с помощью которого возьмем из памяти символы и напечатаем их */
	while (j < 3)
	{	
		ft_putstr(ptr[0][j]);
		j++;
	}
	ft_destroy(ptr);								/* Теперь можно проверить функцию ft_destroy, которая освобождает выделеную память нами */
	return 0;
}