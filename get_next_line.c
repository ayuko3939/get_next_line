/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:35:41 by yohasega          #+#    #+#             */
/*   Updated: 2024/05/28 16:48:19 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*function1(int fd, char *temp)
{
	char	*str;
	char	*get_str;
	ssize_t	len;

	str = (char *)ft_calloc(1, 1);
	str = ft_strjoin(str, temp);
	get_str = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	while (1)
	{
		len = read(fd, get_str, BUFFER_SIZE);
		if (len < 0)
			return (NULL);
		str = ft_strjoin(str, get_str);
		if (ft_strchr(get_str, '\n') != NULL)
			break ;
	}
	return (str);
}

char	*function2(char *str)
{
	size_t	len;
	char	*line;

	len = 0;
	while (str[len] != '\n')
		len++;
	line = (char *)ft_calloc(1, sizeof(char) * (len + 2));
	ft_memcpy(line, str, len + 1);
	return (line);
}

char	*function3(char *str, size_t start)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	len = ft_strlen(str + start);
	new_str = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	i = 0;
	while (start - i)
	{
		str++;
		i++;
	}
	i = 0;
	while (len - i > 0)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*read_str;
	static char	*temp_str;
	size_t		len;
	char		*line;

	// （０）下準備系
	if (temp_str == NULL)
		temp_str = (char *)ft_calloc(1, 1);
	// 引数チェック（ fd , BUFFER_SIZE ）
	if (fd <= 2 || BUFFER_SIZE < 0)
		return (NULL);
	// 初期化
	len = 0;
	// （１）文字列を取得する　＆　エラー処理
	read_str = function1(fd, temp_str);
	if (read_str == NULL)
		return (NULL);
	// （２）１行を作る
	line = function2(read_str);
	// （３）余りを静的変数に格納する
	len = ft_strlen(line);
	temp_str = function3(read_str, len);
	return (line);
}

// // 改行か終端が来るまで繰り返す
// while (read_size > 0)
// {
// 	// 文字列を取得
// 	read_size = read(fd, temp, BUFFER_SIZE);
// 	// 旧文字列と合体して新文字列を作る
// 	str = ft_strjoin(str, temp);
// 	if (read_size > 0 && ft_strchr(temp, '\n'))
// 	{
// 		line = function1(str);
// 		break ;
// 	}
// }

// // BUFFER_SIZE 1 ver
// char	*get_next_line(int fd)
// {
// 	char	*temp;
// 	char	*str;
// 	int		read_size;

// 	temp = (char *)ft_calloc(1, 1);
// 	str = (char *)ft_calloc(1, 1);
// 	read_size = 1;
// 	// 改行か終端が来るまで繰り返す
// 	while (*temp != '\n' && read_size != 0)
// 	{
// 		// １文字を取得
// 		read_size = read(fd, temp, BUFFER_SIZE);
// 		// 旧文字列と１文字を合体して新文字列を作り、旧文字列をfree
// 		str = ft_strjoin(str, temp);
// 	}
// 	// 文字列を出力する
// 	ft_putstr_fd(str, 1);
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	char		*temp;
// 	char		*line;
// 	int			read_size;

// 	// 引数チェック
// 	if (fd <= 2)
// 		return (NULL);
// 	// 改行までread関数(buf1)を繰り返して行を作る

// 	// メモリ確保
// 	temp = (char *)ft_calloc(1, BUFFER_SIZE);
// 	// 確保に失敗したら解放
// 	if (temp == NULL)
// 		free(temp);
// 	// read関数の戻り値を確認
// 	read_size = read(fd, temp, BUFFER_SIZE);
// 	// 読み取りに失敗した場合は、即終了
// 	if (read_size == -1)
// 		return (NULL);
// 	// ファイルの終端に達してる場合は、文字列を出力して終了
// 	else if (read_size == 0)
// 	{
// 		ft_putstr_fd(temp, 1);
// 		return (temp);
// 	}
// 	// 終端なしで文字列を読み込んだ場合は、改行があるなら改行まで出力、なければNULL
// 	else if (ft_strchr(temp, '\n'))
// 	{
// 		ft_putstr_fd(line, 1);
// 		return (line);
// 	}
// 	return (NULL);
// }
