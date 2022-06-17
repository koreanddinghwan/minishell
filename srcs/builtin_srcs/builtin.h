
typedef struct s_envlst
{
	void			*key;
	void			*value;
	void			*env_line;
	struct s_envlst	*next;
	struct s_envlst	*back;
}	t_envlst;

void    execve_pull(char **envp);

/*
 * cd
 * */
void	ft_cd(t_data *data, char *path);
t_envlst	*ft_envlst_last(t_envlst *envlst);
void	ft_envlst_pushback(t_envlst **envlst, t_envlst *new);
t_envlst	*ft_envlst_new(void *c);

/*
 * pwd
 * */
void	ft_pwd();

/*
 * export
 * */
void	ft_export(t_data *data, char *str);

/*
 * unset
 * */
void	ft_unset(t_data *data, char *key);

/*
 * echo
 * */
void	ft_echo(t_data *data, int flag, char *str);

/*
 * exit
 * */
void	ft_exit(int ac, char *av[]);


