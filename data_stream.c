#include "gat.h"

/*
**  Open_stream creates a stream object and should
**  make all preperations for reading from or to
**  the descriptor.
**
**  retuens NULL if it failed to open the descriptor
**  returns a new stream struct if everything is ok
*/

t_stream *open_stream(size_t data_size, char *src)
{
    t_stream *ret;
    int fd;

    if (!src)
        return (NULL);
    ret = (t_stream *)ft_memalloc(sizeof(t_stream));
    if (ft_strcmp(S_STD_IN, src) == 0)
        ret->type = fd = 0;
    if (ft_strcmp(S_STD_OUT, src) == 0)
        ret->type = fd = 1;
    else
    {
        fd = open(src, _O_RDWR);
        ret->type = FILE;
    }
    ret->buffer = ft_buffnew(S_BUFF_SIZE, fd);
    ret->item_size = data_size;
   // if (read_stream(ret) == -1)
  //  {
  //      close_stream(ret);
  //      return (NULL);
  //  }
    return (ret);
}

int     read_stream(t_stream *stream)
{
    void *rd_start;
    size_t status;

    status = ft_buffstat(stream->buffer);
    if (status < S_BUFF_SIZE && status > 0)
        rd_start = ft_buffshift(stream->buffer);
    else if (status <= 0)
    {
        ft_buffreset(stream->buffer);
        rd_start = stream->buffer->pointer;
    }
    return (read(stream->buffer->meta, rd_start, S_BUFF_SIZE - (stream->buffer->data - rd_start)));
}


/*
** stream_next returns a void pointer to the next value in the stream.
** If there is no enough data in the stream buffer it tries to read more
** and try again otherwhise it returns a null.
*/

void    *stream_next(t_stream *e)
{
    void *ret;

    ret = NULL;
    if(ft_buffget(e->item_size, e->buffer, ret) <= 0)
    {
        if(read_stream(e) <= 0)
            return (NULL);
        else if (ft_buffget(e->item_size, e->buffer, ret) <= 0)
            return (NULL);
    }
    return (ret);
}

/*
** The close function makes sure the file descriptor is
** closed propperly and then frees all supporting memory
** allocated to reading the stream.
**
** Returns 0 if there is nothing to be done.
** Returns 1 if everyting went ok
** Returns -1 if there was an error
*/

int close_stream(t_stream *stream)
{
    close(stream->buffer->meta);

    return (-1);
}