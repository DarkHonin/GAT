#ifndef GAT_H
# define GAT_H
# define S_BUFF_SIZE 255
# define S_STD_IN "STDIN"
# define S_STD_OUT "STDOUT"
#include <libft.h>
#include <fcntl.h>

typedef enum e_s_type{
	STD_INPUT,
	STD_OUT,
	FILE
} t_stream_type;

typedef struct s_stream
{
	t_buff			*buffer;
	size_t			item_size;
	t_stream_type	type;
} t_stream;

t_stream *open_stream(size_t data_size, char *src);
int     read_stream(t_stream *stream);
int close_stream(t_stream *stream);

#endif

