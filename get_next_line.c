/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:49:42 by yohasega          #+#    #+#             */
/*   Updated: 2024/06/02 18:00:15 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_nullset(char **str)
{
	if (*str == NULL)
		return (*str);
	free(*str);
	*str = NULL;
	return (*str);
}

// (0)NG  (1)OK
int	read_from_fd(int fd, char **temp)
{
	char	*buf;
	ssize_t	bytes;

	// 初期化
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	// tempに改行がないならEOFまでずっとループする
	while (ft_strchr(*temp, '\n') == 0)
	{
		// 新しい文字列を取得
		bytes = read(fd, buf, BUFFER_SIZE);
		// 読み込みエラーならbufとtempを解放し、エラー報告
		if (bytes == -1)
		{
			free_nullset(&buf);
			free_nullset(temp);
			return (0);
		}
		// これ以上読み込むものがなければループを抜ける
		if (bytes == 0)
			break ;
		// 終端セット
		buf[bytes] = '\0';
		// 新しく取得した文字列を一時保存文字列に結合する、失敗したらエラー報告
		if (ft_strjoin(temp, buf) == 0)
			return (0);
	}
	free_nullset(&buf);
	return (1);
}

char	*get_newline(char *str)
{
	size_t	len;
	char	*line;

	// 初期化
	len = 0;
	// 引数チェック
	if (str == NULL || *str == 0)
		return (NULL);
	// 文字列が 行の終わり（ \0 か \n ）になる位置まで数える
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	// // １行分のメモリ（文字列 ＋ '\0' or '\n' ＋ '\0'）を確保
	line = (char *)malloc(sizeof(char) * (len + 2));
	// メモリ確保に失敗したらNULLを返して即終了
	if (line == NULL)
		return (NULL);
	// １行（ \0 か \n 含む）をコピー
	ft_strlcpy(line, str, len + 2);
	return (line);
}

// (0)NG  (1)OK
int	remove_line_from_temp(char **str)
{
	size_t	len;
	char	*new_temp;

	len = 0;
	// 今回の１行の長さを取得
	while ((*str)[len] != '\0' && (*str)[len] != '\n')
		len++;
	len++;
	// １行に入らなかった余り部分をメモリを確保して取得
	new_temp = ft_substr(*str, len, ft_strlen(*str) - len);
	if (new_temp == NULL)
		return (0);
	// 元の一時保存を解放して入れ直す
	free(*str);
	*str = new_temp;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*temp_str;
	char		*line;

	// 引数チェック
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// 一時保存に改行がない場合のみ、fdから新たに読み込む
	if (ft_strchr(temp_str, '\n') == 0)
	{
		if (read_from_fd(fd, &temp_str) == 0)
			return (NULL);
	}
	// 一時保存から１行作る
	line = get_newline(temp_str);
	if (line == NULL)
		return (free_nullset(&temp_str));
	// 一時保存から１行を削除する
	if (remove_line_from_temp(&temp_str) == 0)
	{
		free_nullset(&temp_str);
		return (free_nullset(&line));
	}
	return (line);
}

// #include <fcntl.h> // open
// #include <stdio.h> // fgets printf

// int	main(void)
// {
// 	int fd;
// 	int i;
// 	char *line;

// 	fd = open("./test.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line == NULL)
// 			break ;
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
