/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
//*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


/* Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */


#include <unistd.h>

int 	ft_putchar(char n)			/* функция вывода символа */
{
	write(1, &n, 1);

	return (0);
}

void	ft_putnbr(int nb)     		 /* Функция вывода числа */
{
	int		temp;
	int		size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)(temp / size) + '0');
		temp %= size;
		size /= 10;
	}
}
/* #######################################################################*/
/* Эта функция делит параметров а, B и сохраняет результат в переменной типа int,
на который указывает элемент div. Он также хранит остаток деления a на b в int,
указанном элементом mod. */

/* В переменные 'a' и 'b' отправляются делимое и делитель которые будут помогать нам делать обычное деление и деление по модулю */
/* А ДАЛЬШЕ(в указатель div и указатель mod(они обьявлены в скобках)) ПРИНИМАЕТСЯ И ЗАПИСЫВАЕТСЯ АДРЕСС 
ОТПРАВЛЯЕМЫХ ПЕРЕМЕННЫХ, ПО АДРЕСАМ КОТРЫХ МЫ ОТПРАВИМ ЧИСЛО ОТ ПРОСТОГО ДЕЛЕНИЯ(в div) И ОТ ДЕЛЕНИЯ ПО МОДУЛЮ(в mod) */

void	ft_div_mod(int a, int b, int *div, int *mod) 
{
	*div = a / b;					/* делим число из перменнной 'a' на число из пременной 'b' и сохраняем результат в ячейку адресс которой хранит указатель 'div' с помощью операции разыменовывания(*div) */
	*mod = a % b;					/* делим по модулю число из перменнной 'a' на число из пременной 'b' и сохраняем результат в ячейку адресс которой хранит указатель 'mod' с помощью операции разыменовывания(*mod) */
}


int		main(void)
{
	int		i;			/* обьявляем переменные типа инт, котрые будут хранить числа делимого и делителя */
	int		t;
	int 	D;			/* обьявляем переменные типа инт, котрые будут хранить результат деления и остаток от деления */
	int		M;

	i = 452;				/* Запишем туда  452 */
	t = 88;					/* Запишем туда  88 */
	D = 0;					/* Запишем туда  0 */
	M = 0;					/* Запишем туда  0 */


	ft_div_mod(i, t, &D, &M);		/* Вызываем функцию и отправляем туда делимое, делитель, и адреса переменных в котрые хотим записать результат деления и остаток от деления */


	/* Сейчас консоль должна вывести делимое, делитель, результат деления и остаток от деления"452 88 5 12" и перейти на сл. строку */ /* если сомневаетесь проверьте на калькуляторе */

	ft_putnbr(i);			/* печатаем делимое i */
	ft_putchar(' ');		/* Печатаем симпол ' ' */
	ft_putnbr(t);			/* печатаем делитель t */
	ft_putchar(' ');		/* Печатаем симпол ' ' */
	ft_putnbr(D);			/* печатаем результат деления D */
	ft_putchar(' ');		/* Печатаем симпол ' ' */
	ft_putnbr(M);			/* печатаем делимое M */
	ft_putchar('\n');		/* печатаем символ переноса строки '\n' */


	return (0);
}


