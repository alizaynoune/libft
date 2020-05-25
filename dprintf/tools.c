#include "ft_dprintf.h"

void	_exit_error(t_data *d)
{
	free(d);
	exit(-1);
}

void	reset_data(t_data *d)
{
	ft_bzero(&d->wid_pre, sizeof(t_width_precision));
	d->flag = 0;
	d->specif = 0;
	d->length = 0;
}
