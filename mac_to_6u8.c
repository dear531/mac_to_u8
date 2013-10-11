#include <stdio.h>
#include <stdlib.h>

int mac_str_to_bin( char *str, char *mac)
{
	int i;
	char *s, *e;

	if ((mac == NULL) || (str == NULL))
	{
		return -1;
	}

	s = (char *) str;
	for (i = 0; i < 6; ++i)
	{
		mac[i] = s ? strtoul (s, &e, 16) : 0;
		if (s)
			s = (*e) ? e + 1 : e;
	}
	return 0;
}
int main(void)
{
	char *p = "11:22:33:44:55:66";
	char dst[6];
	mac_str_to_bin(p,dst);

	printf("mac:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x:%2.2x\n",
			dst[0], dst[1], dst[2], dst[3], dst[4], dst[5]);
	return 0;
}
#define NOTE	0
#if NOTE
unsigned long long int strtoull(const char *ptr, char **end, int base)
{
	unsigned long long ret = 0;

	if (base > 36)
		goto out;

	while (*ptr) {
		int digit;

		if (*ptr >= '0' && *ptr <= '9' && *ptr < '0' + base)
			digit = *ptr - '0';
		else if (*ptr >= 'A' && *ptr < 'A' + base - 10)
			digit = *ptr - 'A' + 10;
		else if (*ptr >= 'a' && *ptr < 'a' + base - 10)
			digit = *ptr - 'a' + 10;
		else
			break;

		ret *= base;
		ret += digit;
		ptr++;
	}

out:
	if (end)
		*end = (char *)ptr;

	return ret;
}
#endif

