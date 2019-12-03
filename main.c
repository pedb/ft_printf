#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char		s1[] = "Lookie";
	char		s2[] = "Here";
	char		s3[] = "Wow this is a really big string wowow";
	char		s4[] = "Old man";
	char		*nlptr = NULL;


	char		c1 = '&';
	char		c2 = 'D';
	char		c3 = '7';
	char		c4 = 48;

	int			i1 = 8902;
	int			i2 = 97;
	int			i3 = 0;
	int			i4 = INT_MIN;
	int			i5 = INT_MAX;

	unsigned	o1 = 11;
	unsigned	o2 = 67;
	unsigned	o3 = 88;
	unsigned	o4 = 111;

	unsigned	x1 = 15;
	unsigned	X1 = 15;
	unsigned	x2 = 23;
	unsigned	X2 = 23;
	unsigned	x3 = 64;
	unsigned	X3 = 64;
	unsigned	x4 = 128;
	unsigned	X4 = 128;

	char		n1;
	char		n2;
	char		*nstr1;
	int			H = 7;
	char		*str;

	ft_printf("\033[0;31m");
	ft_printf("Strings: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-8s$ %7s$ %.8s$ %.*s$", s1, s2, s3, H, s4));
	printf("<- %i\n\n", printf("%-8s$ %7s$ %.8s$ %.*s$", s1, s2, s3, H, s4));
	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("Strings: -010Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-10s$ %+s$ %-8.7s$ %#s$", s1, s2, s3, s4));
	printf("<- %i \n\n", printf("%-10s$ %+s$ %-8.7s$ %#s$", s1, s2, s3, s4));
	ft_printf("\033[0m");

	ft_printf("\033[0;32m");
	ft_printf("Chars: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%7c$ %07c$ %.8c$ %.*c$", c1, c2, c3, 0, c4));
	printf("<- %i \n\n", printf("%7c$ %07c$ %.8c$ %.*c$", c1, c2, c3, 0, c4));
	ft_printf("\033[0m");

	ft_printf("\033[1;32m");
	ft_printf("Chars: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-0c$ %+0c$ %-8.7c$ %#c$", c1, c2, c3, c4));
	printf("<- %i \n\n", printf("%-0c$ %+0c$ %-8.7c$ %#c$", c1, c2, c3, c4));
	ft_printf("\033[0m");

	ft_printf("\033[0;33m");
	ft_printf("Integers: .6(-3) +.7(-446) 07(-54) +5(432)\n");
	ft_printf("<- %i \n", ft_printf("%.6i, |%+.7i, |%07i, |%+5i", -3, -446, -54, 432));
	printf("<- %i \n\n", printf("%.6i, |%.7i, |%07i, |%+5i", -3, -446, -54, 432));
	ft_printf("\033[0m");

	ft_printf("\033[1;33m");
	printf("Integers: +08.6, +8.6, +07,       +7,     + 7,     +.7,      +0.7:\n");
	ft_printf("<- %i \n", ft_printf("%+08.6d , |%+8.6d, |%+07d, |%+7d, |%+ 7d, |%+.7d, |%+0.7d", 32, 32, 32, 32, 32, 32, 32));
	printf("<- %i \n\n", printf("%+08.6d , |%+8.6d, |%+07d, |%+7d, |%+ 7d, |%+.7d, |%+0.7d", 32, 32, 32, 32, 32, 32, 32));
	ft_printf("<- %i \n", ft_printf("%+08.6d , |%+8.6d, |%+07d, |%+7d, |%+ 7d, |%+.7d, |%+0.7d", -32, -32, -32, -32, -32, -32, -32));
	printf("<- %i \n\n", printf("%+08.6d , |%+8.6d, |%+07d, |%+7d, |%+ 7d, |%+.7d, |%+0.7d", -32, -32, -32, -32, -32, -32, -32));
	ft_printf("\033[0m");

	ft_printf("\033[0;34m");
	ft_printf("Octals: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-3o$ %07o$ %.8o$ %.*o$", o1, o2, o3, 5, o4));
	printf("<- %i \n\n", printf("%-3o$ %07o$ %.8o$ %.*o$", o1, o2, o3, 5, o4));
	ft_printf("\033[0m");

	ft_printf("\033[1;34m");
	ft_printf("Octals: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i\n", ft_printf("%-3o$ %+0o$ %-8.7o$ %#o$", o1, o2, o3, o4));
	printf("<- %i \n\n", printf("%-3o$ %+0o$ %-8.7o$ %#o$", o1, o2, o3, o4));
	ft_printf("\033[0m");

	ft_printf("\033[0;35m");
	ft_printf("hexadecimals: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%3x$ %07x$ %.8x$ %.*x$", x1, x2, x3, 11, x4));
	printf("<- %i \n\n", printf("%3x$ %07x$ %.8x$ %.*x$", x1, x2, x3, 11, x4));
	ft_printf("\033[0m");

	ft_printf("\033[1;35m");
	ft_printf("hexadecimals: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-0x$ %+0x$ %-8.7x$ %x$", x1, x2, x3, x4));
	printf("<- %i \n\n", printf("%-0x$ %+0x$ %-8.7x$ %x$", x1, x2, x3, x4));
	ft_printf("\033[0m");

	ft_printf("\033[0;36m");
	ft_printf("HEXADECIMALS: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-3X$ %07X$ %.8X$ %.*X$", X1, X2, X3, 8, X4));
	printf("<- %i \n\n", printf("%-3X$ %07X$ %.8X$ %.*X$", X1, X2, X3, 8, X4));
	ft_printf("\033[0m");

	ft_printf("\033[1;36m");
	ft_printf("HEXADECIMALS: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-0X$ %+0X$ %-8.7X$ %#X$", X1, X2, X3, X4));
	printf("<- %i \n\n", printf("%-0X$ %+0X$ %-8.7X$ %#X$", X1, X2, X3, X4));
	ft_printf("\033[0m");

	ft_printf("\033[0;31m");
	ft_printf("Pointer addresses (discards all flags) :\n");
	ft_printf("<- %i \n", ft_printf("%-8p$ %07p$ %.8p$ %.*p$", &s1, &s2, &s3, H, &s4));
	printf("<- %i \n\n", printf("%-8p$ %07p$ %.8p$ %.*p$", &s1, &s2, &s3, H, &s4));
	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("Simply check each conversion without any flags \n\n");
	ft_printf("<- %i \n", ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %% ", c1, s1, &s1, i1, i2, o1, x1, X1));
	printf("<- %i \n\n", printf("%c, %s, %p, %d, %i, %u, %x, %X, %% ", c1, s1, &s1, i1, i2, o1, x1, X1));

	ft_printf("\033[0;32m");
	printf("Try special case like 0 or smallest int or empty string or null pointer\n");
	ft_printf("<- %i \n", ft_printf("%i, %i, %s, %p $and some final words after the last conversion$", 0, -2147483648, "", &nlptr));
	printf("<- %i \n\n\n", printf("%i, %i, %s, %p $and some final words after the last conversion$", 0, -2147483648, "", &nlptr));

	ft_printf("\033[1;32m");
	ft_printf("\033[0;33m");

	ft_printf("Simple Flags Management:\n");
	ft_printf("<- %i \n", ft_printf("%7s, %7s, %7s, %*s$", s1, s2, s3, 7, s4));
	printf("<- %i \n\n", printf("%7s, %7s, %7s, %*s$", s1, s2, s3, 7, s4));
	ft_printf("\033[1;33m");
	ft_printf("<- %i \n", ft_printf("%-7s, %-7s, %-7s, %-8s$", s1, s2, s3, s4));
	printf("<- %i \n\n", printf("%-7s, %-7s, %-7s, %-8s$", s1, s2, s3, s4));
	ft_printf("\033[0;34m");
	ft_printf("%i \n", ft_printf("%7s, %7s, %7s, %7s$", s1, s2, s3, s4));
	printf("%i \n\n", printf("%7s, %7s, %7s, %7s$", s1, s2, s3, s4));
	ft_printf("\033[1;34m");
	ft_printf("<- %i \n", ft_printf("%6.8s, %8.6s, %.5s, %.23s$", s1, s2, s3, s4));
	printf("<- %i \n\n\n", printf("%6.8s, %8.6s, %.5s, %.23s$", s1, s2, s3, s4));
	ft_printf("\033[0m");

	ft_printf("\033[0;35m");
	ft_printf("Advanced Flags Management:\n");
	ft_printf("<- %i \n", ft_printf("%*s, %*s, %*s, %*s$", -1, s1, 0, s2, 9, s3, 7, s4));
	printf("<- %i \n\n", printf("%*s, %*s, %*s, %*s$", -1, s1, 0, s2, 9, s3, 7, s4));
	ft_printf("\033[1;35m");
	ft_printf("<- %i \n", ft_printf("Precision *: %.*s, %.*s, %.*s,%*.*s", -1, s1, 0, s2, 23, s3, 8, 7, s4));
	printf("<- %i \n\n", printf("Precision *: %.*s, %.*s, %.*s,%*.*s", -1, s1, 0, s2, 23, s3, 8, 7, s4));
	ft_printf("\033[0;36m");
	ft_printf("<- %i \n", ft_printf("Duplicate flags: %---i, %###X, %009s, %**i$", -20, 67, s2, 7, 8, 90127));
  	printf("<- %i \n\n", printf("Duplicate flags: %---i, %###X, %009s, %**i$", -20, 67, s2, 7, 8, 90127));

	ft_printf("\033[1;36m");
	ft_printf("Now for the bonus tests:\n\n");

	ft_printf("\033[0;31m");
	ft_printf("Testing the n flag\n");
	ft_printf("%s - 123456789%n\n", "voorbeeldstring1", &n2);
	ft_printf("%i\n", n2);
	printf("%s - 123456789%n\n", "voorbeeldstring2", &n1);
	printf("%i\n\n", n1);

	ft_printf("\033[1;31m");
	ft_printf("Starting with l and ll flags: LONG_MIN, LONG_MAX, UINT_MAX, ULONG_MAX \n\n");
	ft_printf("<- %i \n", ft_printf("%li, %li, %u, %uli$", LONG_MIN, LONG_MAX, UINT_MAX, ULONG_MAX));
	printf("<- %i \n\n", printf("%li, %li, %u, %uli$", LONG_MIN, LONG_MAX, UINT_MAX, ULONG_MAX));

	ft_printf("\033[0;32m");
	ft_printf("Now some h and hh flags:\n\n");
	ft_printf("<- %i \n", ft_printf("%hi, %hhi, %h7i, %hh8.6i$", i1, i2, i3, i4));
	printf("<- %i \n\n", printf("%hi, %hhi, %h7i, %hh8.6i$", i1, i2, i3, i4));

	ft_printf("\033[1;32m");
	ft_printf("2 with #flag and 2 with +flag:\n\n");
	ft_printf("<- %i \n", ft_printf("%#x, %#-7o, %+10.8i, %+u", x1, o1, i1, x3));
	printf("<- %i \n\n", printf("%#x, %#-7o, %+10.8i, %+u", x1, o1, i1, x3));


	ft_printf("\033[0;33m");
	ft_printf(" ' flags and \\  :\n\n");

	ft_printf("\033[1;33m");
	ft_printf("Edge case checks: negative precision, negative width w/e \n");
	ft_printf("<- %i \n", ft_printf("%*i, %.*i, %*.*i$", -5, i1, -6, i2, -3, -5, i3));
	printf("<- %i \n", printf("%*i, %.*i, %*.*i$", -5, i1, -6, i2, -3, -5, i3));

	ft_printf("\033[1;31m");
	ft_printf("R ");
	ft_printf("\033[1;32m");
	ft_printf("A ");
	ft_printf("\033[1;33m");
	ft_printf("I ");
	ft_printf("\033[1;34m");
	ft_printf("N ");
	ft_printf("\033[1;35m");
	ft_printf("B ");
	ft_printf("\033[1;36m");
	ft_printf("O ");
	ft_printf("\033[1;31m");
	ft_printf("W ");
	ft_printf("\033[1;32m");
	ft_printf("!\n");

	return 0;
}
