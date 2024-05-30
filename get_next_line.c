/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohasega <yohasega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:35:41 by yohasega          #+#    #+#             */
/*   Updated: 2024/05/30 15:27:18 by yohasega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_fd(int fd, char *temp)
{
	char	*buf;
	ssize_t	bytes;

	// 初回の初期化されたtempの場合のみ、０セットする　  ここの初期化って省略できないの？
	if (temp == NULL)
		temp = (char *)ft_calloc(1, sizeof(char) * 1);
	// 初期化
	buf = (char *)ft_calloc(1, sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL || temp == NULL)
		return (NULL);
	// tempに改行がないならEOFまでずっとループする
	bytes = 1;
	while (ft_strchr(temp, '\n') == NULL && bytes != 0)
	{
		// 新しい文字列を取得
		bytes = read(fd, buf, BUFFER_SIZE);
		// 読み込みエラーならbufを解放し、NULLを返して即終了
		if (bytes == -1)
		{
			free(buf);
			free(temp);
			return (NULL);
		}
		// 終端セット　※使い回してるため０埋めされていない
		buf[bytes] = '\0';
		// 新しく取得した文字列を一時保存文字列に結合する
		temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*get_newline(char *str)
{
	size_t	len;
	char	*line;

	// 初期化
	len = 0;
	// 引数チェック
	if (str[len] == 0)
		return (NULL);
	// 文字列が 行の終わり（ \0 か \n ）になる位置まで数える
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	// // １行分のメモリ（文字列 ＋ '\0' or '\n' ＋ '\0'）を確保
	line = (char *)ft_calloc(1, sizeof(char) * (len + 2));
	// メモリ確保に失敗したらNULLを返して即終了
	if (line == NULL)
		return (NULL);
	// １行（ \0 か \n 含む）をコピー
	ft_memcpy(line, str, len + 1);
	return (line);
}

char	*remove_line_from_temp(char *temp, size_t line_end)
{
	size_t	len;
	size_t	i;
	char	*new_temp;

	// 余りの文字列の長さを数える
	len = ft_strlen(temp) - line_end;
	// これ以上文字列がなければtempを解放しし、NULLを返して即終了
	if (len == 0)
	{
		free(temp);
		return (NULL);
	}
	// 文字があれば新たにメモリ確保
	new_temp = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (new_temp == NULL)
		return (NULL);
	// 残りの文字列をコピー
	i = 0;
	while (temp[line_end + i] != 0)
	{
		new_temp[i] = temp[line_end + i];
		i++;
	}
	// 元の一時保存文字列は不要になったのでメモリを解放
	free(temp);
	return (new_temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp_str;

	// 引数チェック（ fd , BUFFER_SIZE ）　　// fd < 0 <- ０はいいとして１と２は？
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// 新しい文字列を取得して一時保存する
	temp_str = read_from_fd(fd, temp_str);
	if (temp_str == NULL)
	{
		free(temp_str);
		return (NULL);
	}
	// 一時保存の文字列から１行の文字列を作る
	line = get_newline(temp_str);
	// １行に入らなかった余りを新たに一時保存する
	temp_str = remove_line_from_temp(temp_str, ft_strlen(line));
	// １行を返す
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	char *line;

// 	fd = open("./test3.txt", O_RDONLY);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free (line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
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
