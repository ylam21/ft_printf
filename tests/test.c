#include "../ft_printf.h"
#include <stdio.h>
#include <assert.h>

int main()
{
	int me_ret;
	int lib_ret;
	char *me_str;
	char *lib_str;

	printf("CATEGORY: c\n");
	unsigned char c = 0;
	while (c < 256)
	{
		// check return
		me_ret = ft_printf("%c",c);
		lib_ret = printf("%c",c);
		assert(me_ret == lib_ret);
		// check string
		me_str = 
	}


	printf("CATEGORY: p\n");












	me = ft_printf(".me: %p$\n",-1);
	lib = printf("lib: %p$\n",-1);
	printf("ret: %d/%d\n",me,lib);
	return 0;
}

