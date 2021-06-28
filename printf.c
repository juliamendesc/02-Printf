#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>


// "ola %s %d %i"

int ft_printf(const char *fmt, ...)
{
	va_list args;
	int i = 0;

	char	*str;
	int		num;

	va_start(args, fmt);

	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%'){
			i++;
			if (fmt[i] == 's')
			{
				str = va_arg(args, char *);
				printf("%s", str);
			}
			if (fmt[i] == 'd')
			{
				num = va_arg(args, int);
				printf("%d", num);
			}
			if (fmt[i] == 'i')
			{
				num = va_arg(args, int);
				printf("%d", num);
			}

			//if s -> putstr
			//if d -> putnbr
			//if i -> putnbr
			//if u -> putnbr
			//if e -> putnbr
			//if o -> putnbrbase
			//if x -> putnbrbase
			//if % -> write %
		}
		write(1, &fmt[i], 1);
		i++;
	}
	va_end(args);

	return (0);

}


int main ()
{
	ft_printf("ola %s %d %i", "string", 10, 5);
}