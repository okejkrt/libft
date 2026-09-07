#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

void	test_ft_isalpha(void)
{
	int	tests[] = {'a', 'z', 'A', 'Z', '`', '{', '@', '[', '0', ' ', 0, 127, -1};
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	res_ft;
	int	res_sys;
	int	errors = 0;

	printf("🔍 Testuji ft_isalpha: ");
	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_isalpha(tests[i]);
		res_sys = isalpha(tests[i]) ? 1 : 0;

		if (res_ft != res_sys)
		{
			if (errors == 0)
				printf("\n");
			printf("  ❌ Chyba u znaku s ASCII %d! Tvá: %d, Systémová: %d\n", tests[i], res_ft, res_sys);
			errors++;
		}
	}
	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ⚠️ Celkem chyb v ft_isalpha: %d\n", errors);
}

void	test_ft_isdigit(void)
{
	int	tests[] = {'0', '5', '9', '/', ':', 'a', 'A', ' ', 0, 127};
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	res_ft;
	int	res_sys;
	int	errors = 0;

	printf("🔍 Testuji ft_isdigit: ");
	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_isdigit(tests[i]);
		res_sys = isdigit(tests[i]) ? 1 : 0;

		if (res_ft != res_sys)
		{
			if (errors == 0)
				printf("\n");
			printf("  ❌ Chyba u znaku s ASCII %d! Tvá: %d, Systémová: %d\n", tests[i], res_ft, res_sys);
			errors++;
		}
	}
	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ⚠️ Celkem chyb v ft_isdigit: %d\n", errors);
}

void	test_ft_isalnum(void)
{
	int	tests[] = {'a', 'Z', '0', '5', '9', ' ', '!', '@', 0, 127};
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	res_ft;
	int	res_sys;
	int	errors = 0;

	printf("🔍 Testuji ft_isalnum: ");
	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_isalnum(tests[i]);
		res_sys = isalnum(tests[i]) ? 1 : 0;

		if (res_ft != res_sys)
		{
			if (errors == 0)
				printf("\n");
			printf("  ❌ Chyba u znaku s ASCII %d! Tvá: %d, Systémová: %d\n", tests[i], res_ft, res_sys);
			errors++;
		}
	}
	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ⚠️ Celkem chyb v ft_isalnum: %d\n", errors);
}

void	test_ft_isascii(void)
{
	int	tests[] = {0, 50, 127, 128, 255, -1, -100};
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	res_ft;
	int	res_sys;
	int	errors = 0;

	printf("🔍 Testuji ft_isascii: ");
	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_isascii(tests[i]);
		res_sys = isascii(tests[i]) ? 1 : 0;

		if (res_ft != res_sys)
		{
			if (errors == 0)
				printf("\n");
			printf("  ❌ Chyba u znaku s ASCII %d! Tvá: %d, Systémová: %d\n", tests[i], res_ft, res_sys);
			errors++;
		}
	}
	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ⚠️ Celkem chyb v ft_isascii: %d\n", errors);
}

void	test_ft_isprint(void)
{
	int	tests[] = {31, ' ', 'A', '~', 127, 0, -1};
	int	num_tests = sizeof(tests) / sizeof(tests);
	int	res_ft;
	int	res_sys;
	int	errors = 0;

	printf("🔍 Testuji ft_isprint: ");
	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_isprint(tests[i]);
		res_sys = isprint(tests[i]) ? 1 : 0;

		if (res_ft != res_sys)
		{
			if (errors == 0)
				printf("\n");
			printf("  ❌ Chyba u znaku s ASCII %d! Tvá: %d, Systémová: %d\n", tests[i], res_ft, res_sys);
			errors++;
		}
	}
	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ⚠️ Celkem chyb v ft_isprint: %d\n", errors);
}

void	test_ft_strlen(void)
{
	char	*tests[] = {"Hello", "", "42 Prague", "A\0B", "Long string with spaces and tabs \t\n"};
	int		num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	res_ft;
	size_t	res_sys;
	int		errors = 0;

	printf("🔍 Testuji ft_strlen: ");
	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_strlen(tests[i]);
		res_sys = strlen(tests[i]);

		if (res_ft != res_sys)
		{
			if (errors == 0)
				printf("\n");
			printf("  ❌ Chyba u řetězce \"%s\"! Tvá: %zu, Systémová: %zu\n", tests[i], res_ft, res_sys);
			errors++;
		}
	}
	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ⚠️ Celkem chyb v ft_strlen: %d\n", errors);
}

void	test_ft_memset(void)
{
	char	buffer_ft[20];
	char	buffer_sys[20];
	int		errors = 0;

	printf("🔍 Testuji ft_memset: ");

	ft_memset(buffer_ft, 'A', 10);
	memset(buffer_sys, 'A', 10);
	buffer_ft[10] = '\0';
	buffer_sys[10] = '\0';
	if (strcmp(buffer_ft, buffer_sys) != 0)
		errors++;

	ft_memset(buffer_ft, 0, 15);
	memset(buffer_sys, 0, 15);
	if (memcmp(buffer_ft, buffer_sys, 15) != 0)
		errors++;

	if (ft_memset(buffer_ft, 'B', 5) != buffer_ft)
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_memset!\n");
}

void	test_ft_bzero(void)
{
	char	buffer_ft[20];
	char	buffer_sys[20];
	int		errors = 0;

	printf("🔍 Testuji ft_bzero: ");

	memset(buffer_ft, 'X', 20);
	memset(buffer_sys, 'X', 20);

	ft_bzero(buffer_ft, 10);
	bzero(buffer_sys, 10);

	if (memcmp(buffer_ft, buffer_sys, 20) != 0)
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_bzero!\n");
}

int	main(void)
{
	printf("=========================================\n");
	printf("       🔥 SPUŠTĚNÍ LIBFT TESTU 🔥        \n");
	printf("=========================================\n\n");

	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	
	printf("\n=========================================\n");
	return (0);
}