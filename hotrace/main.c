/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:26:24 by avolgin           #+#    #+#             */
/*   Updated: 2018/03/25 21:16:10 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/hotrace.h"
#include "./includes/get_next_line.h"

static t_pair	*struct_hash_init(void)
{
	int		size;
	t_pair	*hash_table;

	size = SIZE;
	if (!(hash_table = (t_pair *)malloc(sizeof(t_pair) * SIZE)))
		return (NULL);
	while (--size)
	{
		hash_table[size].next = NULL;
		hash_table[size].key = NULL;
		hash_table[size].value = NULL;
	}
	return (hash_table);
}

void			print_key(int fd, char **buff, t_pair hash_table[])
{
	unsigned int	key;
	t_pair			*head;

	if (*buff)
		free(*buff);
	while (get_next_line(fd, buff) > 0)
	{
		key = hash_func_jenk(*buff, ft_strlen(*buff));
		if (ft_strcmp(hash_table[key % SIZE].key, *buff) == 0)
			ft_putendl(hash_table[key % SIZE].value);
		else
		{
			head = &(hash_table[key % SIZE]);
			while (head->next && ft_strcmp(head->key, *buff))
				head = head->next;
			if (!ft_strcmp(head->key, *buff))
				ft_putendl(head->value);
			else
			{
				ft_putstr(*buff);
				ft_putendl(": Not found.");
			}
		}
		free(*buff);
	}
}

unsigned int	put_key(char *buff, t_pair hash_table[])
{
	unsigned int	key;
	t_pair			*head;
	t_pair			*temp;

	head = (void*)0;
	key = (hash_func_jenk(buff, ft_strlen(buff))) % SIZE;
	if (!hash_table[key].key)
		hash_table[key].key = buff;
	else
	{
		temp = &(hash_table[key]);
		while (temp->next && temp->key)
			temp = temp->next;
		head = (t_pair *)malloc(sizeof(t_pair));
		head->key = buff;
		head->next = NULL;
		temp->next = head;
	}
	return (key);
}

void			put_value(char *buff, unsigned int key, t_pair hash_table[])
{
	t_pair			*head;

	head = (void*)0;
	if (!hash_table[key].value)
		hash_table[key].value = buff;
	else
	{
		head = &(hash_table[key]);
		while (head->next)
			head = head->next;
		head->value = buff;
	}
}

int				main(void)
{
	char			*buff;
	unsigned int	key;
	int				i;
	t_pair			*hash_table;

	i = 0;
	if (!(hash_table = struct_hash_init()))
		return (0);
	buff = (void*)0;
	while (get_next_line(0, &buff) > 0)
	{
		if (!(i % 2) && buff[0] != '\0')
			key = put_key(buff, hash_table);
		else if (buff[0] != '\0')
			put_value(buff, key, hash_table);
		if (buff[0] == '\0')
		{
			print_key(0, &buff, hash_table);
			break ;
		}
		i++;
	}
	del_hash_table(hash_table);
	return (0);
}
