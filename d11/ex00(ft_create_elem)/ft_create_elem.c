/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** *
 *
 * 
 *	• Создайте функцию "ft_create_elem", которая создает новый элемент типа" t_list".
 * 
 * 
 *	• Он должен присваивать "data" данному аргументу и к "next" присваивать "NULL".
 * 
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *										t_list		*ft_create_elem(void *data)
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"
#include <stdlib.h>

/* ************************************************************************** */


t_list		*ft_create_elem(void *data)
{
	t_list	*tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))
		return ((void *)0);
	tmp->data = data;
	tmp->next = ((void *)0);
	return (tmp);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

/* ************************************************************************** */

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

/* ************************************************************************** */

t_list		*ft_create_elem(void *data)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */