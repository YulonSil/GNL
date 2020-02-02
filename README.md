# Get Next Line

A function that reads from a file descriptor, returning the next line on each call. Used in a loop to iterate on each line.

## Final grade : 105/115

Mandatory part : 100/100

Bonus part : 5/15

### How to use it

Include ``get_next_line.h`` in your project's header. You can call the function by sending it a file descriptor, and a pointer to where you want the line :

```
int		get_next_line(int fd, char **line);
```

The function returns ``1`` after a successful read, and ``0`` with the last line. It will return ``-1`` in case of error.
