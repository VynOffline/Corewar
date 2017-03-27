/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czalewsk <czalewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 01:43:51 by czalewsk          #+#    #+#             */
/*   Updated: 2017/03/26 18:00:08 by czalewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern	char	*g_delim;

static	void	add_label(t_lx *lx, t_list **label, size_t index)
{
	t_label		*new;

	if (!label || !(new = ft_memalloc(sizeof(t_label))))
		return ;
	new->name = lx->word;
	new->index = index;
	ft_lst_pushend(label, ft_lstnew(new, sizeof(t_label)));
	ft_memdel((void**)&new);
}

static	void	fix_lex(t_lx *lex, t_list **label)
{
	static size_t	index = 0;

	if (!lex)
		return ;
	if (lex->type == DIRECT && ft_strisnumber(lex->word + 1))
		lex->valeur = ft_atoi(lex->word + 1);
	else if (lex->type == INDIRECT)
		lex->valeur = ft_atoi(lex->word);
	else if (lex->type == REGISTRE && ft_strisnumber(lex->word + 1))
		lex->valeur = ft_atoi(lex->word + 1);
	if (++index && lex->type == LABEL)
		add_label(lex, label, index);
}

static	void	set_lex_ext(t_list *lst, t_lx *lx)
{
	if (lst->next && !ft_strcmp(lx->word, NAME_CMD_STRING))
		((t_lx *)lst->next->content)->type = NAME;
	if (lst->next && !ft_strcmp(lx->word, COMMENT_CMD_STRING))
		((t_lx *)lst->next->content)->type = COMMENT;
	if (ft_strchr(g_delim, lx->word[0]))
		lx->type = SEPARATEUR;
	if (lx->word[0] == DIRECT_CHAR && !lx->word[1])
		lx->type = DIRECTCHAR;
	if (lst->next && ft_strchr(((t_lx *)lst->next->content)->word,
				LABEL_CHAR) && lx->word[0] != DIRECT_CHAR)
		lx->type = LABEL;
	else if (lst->next && lst->next->next && lx->word[0] == DIRECT_CHAR
		&& ft_strchr(((t_lx *)lst->next->content)->word, LABEL_CHAR))
		((t_lx *)lst->next->next->content)->type = LABELREF;
	else if (lx->word[0] == DIRECT_CHAR)
		lx->type = DIRECT;
	else if (lx->word[0] == 'r')
		lx->type = REGISTRE;
	else if (ft_strisnumber(lx->word))
		lx->type = INDIRECT;
	else if (lx->type == -1 && !ft_strchr(g_delim, lx->word[0]))
		lx->type = INSTRUCTION;
}

void			set_lex(t_list *lst, t_list **label)
{
	t_lx	*lx;

	while (lst)
	{
		lx = lst->content;
		set_lex_ext(lst, lx);
		fix_lex(lx, label);
		lst = lst->next;
	}
}