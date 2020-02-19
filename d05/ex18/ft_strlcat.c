/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 21:29:49 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/20 19:14:42 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Reproduce the behavior of the function strlcat (man strlcat).
Воспроизведите поведение функции strlcat (man strlcat).

Аргументы:

dest – указатель на массив в который будет добавлена строка.
src – указатель на массив из которого будет скопирована строка.
size — размер буфера назначения

Функция strlcat служит для конкатенации строк и делает это более безопасно, 
чем функция strncat.
Она принимает полный размер буфера и устанавливаетв конец строки нулевой символ '\0'.

Для корректной работы функции strlcat, ей необходимо передавать 
только нультерминальные строки(строки с завершающим нулем '\0').


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[i] && (dest_size < (size - 1)))
	{
		dest[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest_size);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

static int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (dst[len] && len < size)
		len++;
	i = len;
	while (src[len - i] && len + 1 < size)
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < size)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
