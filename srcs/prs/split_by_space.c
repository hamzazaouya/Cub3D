# include "parser.h"

static int	count_words(const char *str)
{
	int	i;
	int	switch_it;

	i = 0;
	switch_it = 0;
	while (*str)
	{
		if (!is_space(*str) && switch_it == 0)
		{
			switch_it = 1;
			i++;
		}
		else if (is_space(*str))
			switch_it = 0;
		str++;
	}
	return (i);
}

static char	*word_duplicating(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	initialize_variables(size_t *i, size_t *j, int *index)
{
	*i = 0;
	*j = 0;
	*index = -1;
}

char	**split_by_space(char const *s)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc ((count_words(s) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	initialize_variables(&i, &j, &index);
	while (i <= ft_strlen(s))
	{
		if (!is_space(s[i]) && index < 0)
			index = i;
		else if ((is_space(s[i]) || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_duplicating(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}