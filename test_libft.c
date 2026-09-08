#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int	ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

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
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
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

void	test_ft_memcpy(void)
{
	char	src[] = "42 Prague";
	char	dest_ft[20] = {0};
	char	dest_sys[20] = {0};
	int		errors = 0;

	printf("🔍 Testuji ft_memcpy: ");

	ft_memcpy(dest_ft, src, 9);
	memcpy(dest_sys, src, 9);
	if (strcmp(dest_ft, dest_sys) != 0)
		errors++;

	if (ft_memcpy(NULL, NULL, 5) != NULL)
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_memcpy!\n");
}

void	test_ft_memmove(void)
{
	char	str1_ft[20] = "abcdefghij";
	char	str1_sys[20] = "abcdefghij";
	char	str2_ft[20] = "abcdefghij";
	char	str2_sys[20] = "abcdefghij";
	int		errors = 0;

	printf("🔍 Testuji ft_memmove: ");

	ft_memmove(str1_ft + 2, str1_ft, 6);
	memmove(str1_sys + 2, str1_sys, 6);
	if (memcmp(str1_ft, str1_sys, 20) != 0)
		errors++;

	ft_memmove(str2_ft, str2_ft + 2, 6);
	memmove(str2_sys, str2_sys + 2, 6);
	if (memcmp(str2_ft, str2_sys, 20) != 0)
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_memmove při překrývání paměti!\n");
}

void	test_ft_strlcpy(void)
{
	char	src[] = "Prague";
	char	dst_ft[10];
	size_t	res;
	int		errors = 0;

	printf("🔍 Testuji ft_strlcpy: ");

	res = ft_strlcpy(dst_ft, src, 10);
	if (res != 6 || strcmp(dst_ft, "Prague") != 0)
		errors++;

	res = ft_strlcpy(dst_ft, src, 4);
	if (res != 6 || strcmp(dst_ft, "Pra") != 0)
		errors++;

	dst_ft[0] = 'X';
	res = ft_strlcpy(dst_ft, src, 0);
	if (res != 6 || dst_ft[0] != 'X')
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strlcpy!\n");
}

void	test_ft_strlcat(void)
{
	char	dst1[20] = "Hello ";
	char	dst2[10] = "Hello ";
	char	dst3[5] = "Hell";
	char	src[] = "Prague";
	size_t	res;
	int		errors = 0;

	printf("🔍 Testuji ft_strlcat: ");

	// Test 1: Dostatek místa v bufferu (20 bajtů)
	res = ft_strlcat(dst1, src, 20);
	if (res != 12 || strcmp(dst1, "Hello Prague") != 0)
		errors++;

	// Test 2: Omezené místo (10 bajtů, vejde se jen "Hello Pra" + '\0')
	res = ft_strlcat(dst2, src, 10);
	if (res != 12 || strcmp(dst2, "Hello Pra") != 0)
		errors++;

	// Test 3: Velikost size je menší než stávající text v dst (size = 2, dst má 4)
	res = ft_strlcat(dst3, src, 2);
	if (res != 8 || strcmp(dst3, "Hell") != 0) // Nesmí nic změnit, vrátí 2 + 6 = 8
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strlcat!\n");
}

void	test_ft_toupper(void)
{
	int	tests[] = {'a', 'm', 'z', 'A', 'Z', '0', ' ', '@', 0, 127};
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	res_ft;
	int	res_sys;
	int	errors = 0;

	printf("🔍 Testuji ft_toupper: ");
	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_toupper(tests[i]);
		res_sys = toupper(tests[i]);

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
		printf("  ⚠️ Celkem chyb v ft_toupper: %d\n", errors);
}

void	test_ft_tolower(void)
{
	int	tests[] = {'A', 'M', 'Z', 'a', 'z', '0', ' ', '@', 0, 127};
	int	num_tests = sizeof(tests) / sizeof(tests[0]);
	int	res_ft;
	int	res_sys;
	int	errors = 0;

	printf("🔍 Testuji ft_tolower: ");
	for (int i = 0; i < num_tests; i++)
	{
		res_ft = ft_tolower(tests[i]);
		res_sys = tolower(tests[i]);

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
		printf("  ⚠️ Celkem chyb v ft_tolower: %d\n", errors);
}

void	test_ft_strchr(void)
{
	const char	str[] = "42 Prague";
	int			errors = 0;

	printf("🔍 Testuji ft_strchr: ");

	// Test 1: Běžné vyhledání znaku 'P'
	if (ft_strchr(str, 'P') != strchr(str, 'P'))
		errors++;

	// Test 2: Vyhledání znaku, který v řetězci není ('X')
	if (ft_strchr(str, 'X') != NULL)
		errors++;

	// Test 3: Vyhledání ukončovací nuly '\0' (Kritický chyták!)
	if (ft_strchr(str, '\0') != strchr(str, '\0'))
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strchr!\n");
}

void	test_ft_strrchr(void)
{
	const char	str[] = "42 Prague - bon jour";
	int			errors = 0;

	printf("🔍 Testuji ft_strrchr: ");

	// Test 1: Vyhledání znaku 'o' (v textu je 2x, musí vrátit ten blíž ke konci)
	if (ft_strrchr(str, 'o') != strrchr(str, 'o'))
		errors++;

	// Test 2: Vyhledání znaku, který v řetězci není ('X')
	if (ft_strrchr(str, 'X') != NULL)
		errors++;

	// Test 3: Vyhledání ukončovací nuly '\0' (Kritický chyták!)
	if (ft_strrchr(str, '\0') != strrchr(str, '\0'))
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strrchr!\n");
}

void	test_ft_strncmp(void)
{
	char	s1[] = "Prague";
	char	s2[] = "Praha";
	char	s3[] = "Prague";
	char	diak1[] = "Žluč";
	char	diak2[] = "Aluč";
	int		errors = 0;

	printf("🔍 Testuji ft_strncmp: ");

	// Test 1: Částečná shoda (prvních 3 znaků "Pra")
	if (ft_strncmp(s1, s2, 3) != 0)
		errors++;

	// Test 2: Neshoda na 4. znaku ('g' vs 'h')
	// Pro férovost se v testech 42 porovnává pouze znaménko (kladné/záporné/nula)
	if ((ft_strncmp(s1, s2, 5) < 0 && strncmp(s1, s2, 5) >= 0) ||
		(ft_strncmp(s1, s2, 5) > 0 && strncmp(s1, s2, 5) <= 0))
		errors++;

	// Test 3: Absolutní shoda celého řetězce
	if (ft_strncmp(s1, s3, 10) != 0) // Používáme fiktivní nebo přímé srovnání
		errors++;

	// Test 4: Kontrola n = 0 (musí vrátit 0)
	if (ft_strncmp(s1, s2, 0) != 0)
		errors++;

	// Test 5: Zátěžový test s diakritikou (unsigned char chyták)
	if ((ft_strncmp(diak1, diak2, 2) < 0 && strncmp(diak1, diak2, 2) >= 0) ||
		(ft_strncmp(diak1, diak2, 2) > 0 && strncmp(diak1, diak2, 2) <= 0))
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strncmp!\n");
}

void	test_ft_memchr(void)
{
	char	buffer[] = "Prague\0is\0cool";
	int		errors = 0;

	printf("🔍 Testuji ft_memchr: ");

	// Test 1: Běžné vyhledání znaku 'a' v prvních 6 bajtech
	if (ft_memchr(buffer, 'a', 6) != memchr(buffer, 'a', 6))
		errors++;

	// Test 2: Vyhledání znaku 'c', který leží až ZA nulovým bajtem (v řetězci by to selhalo, memchr musí uspět!)
	if (ft_memchr(buffer, 'c', 15) != memchr(buffer, 'c', 15))
		errors++;

	// Test 3: Vyhledání znaku, který v celém bloku není ('X')
	if (ft_memchr(buffer, 'X', 15) != NULL)
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_memchr!\n");
}

void	test_ft_memcmp(void)
{
	char	b1[] = "Prague\0A";
	char	b2[] = "Prague\0B";
	char	diak1[] = "\xde\xad";
	char	diak2[] = "\xdf\xad";
	int		errors = 0;

	printf("🔍 Testuji ft_memcmp: ");

	// Test 1: Absolutní shoda prvních 6 bajtů ("Prague")
	if (ft_memcmp(b1, b2, 6) != 0)
		errors++;

	// Test 2: Neshoda na 8. bajtu ('A' vs 'B') až ZA nulovým bajtem (strncmp by vrátil 0, memcmp musí najít neshodu!)
	if ((ft_memcmp(b1, b2, 8) < 0 && memcmp(b1, b2, 8) >= 0) ||
		(ft_memcmp(b1, b2, 8) > 0 && memcmp(b1, b2, 8) <= 0))
		errors++;

	// Test 3: Kontrola n = 0 (musí vrátit 0)
	if (ft_memcmp(b1, b2, 0) != 0)
		errors++;

	// Test 4: Zátěžový test s hodnotami nad 127 (unsigned char chyták)
	if ((ft_memcmp(diak1, diak2, 2) < 0 && memcmp(diak1, diak2, 2) >= 0) ||
		(ft_memcmp(diak1, diak2, 2) > 0 && memcmp(diak1, diak2, 2) <= 0))
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_memcmp!\n");
}

void	test_ft_strnstr(void)
{
	const char	*haystack = "42 Prague - School";
	int			errors = 0;

	printf("🔍 Testuji ft_strnstr: ");

	// Test 1: Úspěšné nalezení slova "Prague" v dostatečném limitu (15)
	if (ft_strnstr(haystack, "Prague", 15) != haystack + 3)
		errors++;

	// Test 2: Prázdná needle (musí okamžitě vrátit celý haystack)
	if (ft_strnstr(haystack, "", 10) != haystack)
		errors++;

	// Test 3: Slovo v textu sice je, ale až ZA limitem len (hledáme "School", ale len = 10)
	if (ft_strnstr(haystack, "School", 10) != NULL)
		errors++;

	// Test 4: Částečná shoda, která se ale nestihne dokončit kvůli malému len
	if (ft_strnstr(haystack, "Prague", 5) != NULL)
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strnstr!\n");
}

void	test_ft_atoi(void)
{
	int		errors = 0;

	printf("🔍 Testuji ft_atoi: ");

	// Test 1: Běžné kladné číslo
	if (ft_atoi("42") != atoi("42"))
		errors++;

	// Test 2: Záporné číslo
	if (ft_atoi("-1234") != atoi("-1234"))
		errors++;

	// Test 3: Bílé znaky na začátku a znaménko plus
	if (ft_atoi(" \t\n\r\v\f+56") != atoi(" \t\n\r\v\f+56"))
		errors++;

	// Test 4: Text za číslem (funkce se musí zastavit na prvním ne-čísle)
	if (ft_atoi("42 Prg 9") != atoi("42 Prg 9"))
		errors++;

	// Test 5: Neplatný vstup hned na začátku (musí vrátit 0)
	if (ft_atoi("Prague 42") != atoi("Prague 42"))
		errors++;

	// Test 5: Číslo větší než INT_MAX
	if (ft_atoi("9999999999999999") != atoi("9999999999999999"))
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_atoi!\n");
}

void	test_ft_calloc(void)
{
	unsigned char	*ptr_ft;
	int				errors = 0;
	size_t			i;

	printf("🔍 Testuji ft_calloc: ");

	// Test 1: Běžná alokace pole o 10 prvcích (každý o velikosti 1 bajt)
	ptr_ft = (unsigned char *)ft_calloc(10, 1);
	if (ptr_ft == NULL)
		errors++;
	else
	{
		// Ověříme, že jsou všechny bajty skutečně vynulované
		for (i = 0; i < 10; i++)
		{
			if (ptr_ft[i] != 0)
				errors++;
		}
		free(ptr_ft);
	}

	// Test 2: Okrajový stav se zadáním nuly (count = 0, size = 5)
	// Musí vrátit platný non-NULL ukazatel, který lze uvolnit
	ptr_ft = (unsigned char *)ft_calloc(0, 5);
	if (ptr_ft == NULL)
		errors++;
	else
		free(ptr_ft);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_calloc!\n");
}

void	test_ft_strdup(void)
{
	char	str[] = "42 Prague";
	char	*dup_ft;
	int		errors = 0;

	printf("🔍 Testuji ft_strdup: ");

	// Test 1: Běžná duplikace řetězce
	dup_ft = ft_strdup(str);
	if (dup_ft == NULL || strcmp(dup_ft, str) != 0)
		errors++;

	// Ověříme, že se jedná o novou adresu v paměti a ne stejný pointer
	if (dup_ft == str)
		errors++;

	free(dup_ft);

	// Test 2: Duplikace prázdného řetězce ""
	dup_ft = ft_strdup("");
	if (dup_ft == NULL || strcmp(dup_ft, "") != 0)
		errors++;
	free(dup_ft);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strdup!\n");
}

void	test_ft_substr(void)
{
	char	str[] = "42 Prague School";
	char	*sub;
	int		errors = 0;

	printf("🔍 Testuji ft_substr: ");

	// Test 1: Běžné vytvoření podřetězce "Prague" (od indexu 3, délka 6)
	sub = ft_substr(str, 3, 6);
	if (sub == NULL || strcmp(sub, "Prague") != 0)
		errors++;
	free(sub);

	// Test 2: Požadovaná délka len je větší než zbytek řetězce (len = 50, ale zbývá jen "School")
	sub = ft_substr(str, 10, 50);
	if (sub == NULL || strcmp(sub, "School") != 0)
		errors++;
	free(sub);

	// Test 3: Index start leží zcela MIMO rozsah původního řetězce (start = 100)
	// Musí bezpečně vrátit alokovaný prázdný řetězec ""
	sub = ft_substr(str, 100, 5);
	if (sub == NULL || strcmp(sub, "") != 0)
		errors++;
	free(sub);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_substr!\n");
}

void	test_ft_strjoin(void)
{
	char	*res;
	int		errors = 0;

	printf("🔍 Testuji ft_strjoin: ");

	// Test 1: Běžné spojení prefixu a suffixu
	res = ft_strjoin("42 ", "Prague");
	if (res == NULL || strcmp(res, "42 Prague") != 0)
		errors++;
	free(res);

	// Test 2: Spojení s prázdným řetězcem
	res = ft_strjoin("", "School");
	if (res == NULL || strcmp(res, "School") != 0)
		errors++;
	free(res);

	// Test 3: Spojení dvou prázdných řetězců
	res = ft_strjoin("", "");
	if (res == NULL || strcmp(res, "") != 0)
		errors++;
	free(res);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strjoin!\n");
}

void	test_ft_strtrim(void)
{
	char	*res;
	int		errors = 0;

	printf("🔍 Testuji ft_strtrim: ");

	// Test 1: Běžné oříznutí mezer a teček ze začátku i konce
	res = ft_strtrim("... Hello Prague ...", " .");
	if (res == NULL || strcmp(res, "Hello Prague") != 0)
		errors++;
	free(res);

	// Test 2: Řetězec složený POUZE z ořezávaných znaků (musí vrátit "")
	res = ft_strtrim("aaaaa", "a");
	if (res == NULL || strcmp(res, "") != 0)
		errors++;
	free(res);

	// Test 3: Žádný znak ze sady v textu není (musí vrátit kopii celého textu)
	res = ft_strtrim("Prague", "xyz");
	if (res == NULL || strcmp(res, "Prague") != 0)
		errors++;
	free(res);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strtrim!\n");
}

void	test_ft_split(void)
{
	char	**res;
	int		errors = 0;

	printf("🔍 Testuji ft_split: ");

	// Test 1: Běžné rozdělení věty podle mezer
	res = ft_split("Hello Prague School", ' ');
	if (res == NULL || strcmp(res[0], "Hello") != 0 || strcmp(res[1], "Prague") != 0 || strcmp(res[2], "School") != 0 || res[3] != NULL)
		errors++;
	// Uvolníme testovací pole
	if (res)
	{
		free(res[0]); free(res[1]); free(res[2]); free(res);
	}

	// Test 2: Více oddělovačů za sebou a na koncích
	res = ft_split("xxxAxxxBxxx", 'x');
	if (res == NULL || strcmp(res[0], "A") != 0 || strcmp(res[1], "B") != 0 || res[2] != NULL)
		errors++;
	if (res)
	{
		free(res[0]); free(res[1]); free(res);
	}

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_split!\n");
}

void	test_ft_itoa(void)
{
	char	*res;
	int		errors = 0;

	printf("🔍 Testuji ft_itoa: ");

	// Test 1: Běžné kladné číslo
	res = ft_itoa(1234);
	if (res == NULL || strcmp(res, "1234") != 0)
		errors++;
	free(res);

	// Test 2: Nula (Kritický okrajový stav)
	res = ft_itoa(0);
	if (res == NULL || strcmp(res, "0") != 0)
		errors++;
	free(res);

	// Test 3: Záporné číslo
	res = ft_itoa(-42);
	if (res == NULL || strcmp(res, "-42") != 0)
		errors++;
	free(res);

	// Test 4: Absolutní zátěž - INT_MIN chyták
	res = ft_itoa(-2147483648);
	if (res == NULL || strcmp(res, "-2147483648") != 0)
		errors++;
	free(res);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_itoa!\n");
}

static char	test_map_func(unsigned int i, char c)
{
	return (c + i);
}

void	test_ft_strmapi(void)
{
	char	*res;
	int		errors = 0;

	printf("🔍 Testuji ft_strmapi: ");

	// Test: Pošleme řetězec "0000"
	// Index 0: '0' + 0 = '0'
	// Index 1: '0' + 1 = '1'
	// Index 2: '0' + 2 = '2'
	// Index 3: '0' + 3 = '3'
	res = ft_strmapi("0000", test_map_func);
	if (res == NULL || strcmp(res, "0123") != 0)
		errors++;
	free(res);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_strmapi!\n");
}

static void	test_iter_func(unsigned int i, char *c)
{
	*c = *c + i;
}

void	test_ft_striteri(void)
{
	char	str[] = "0000";
	int		errors = 0;

	printf("🔍 Testuji ft_striteri: ");

	// Test: Modifikujeme řetězec přímo na místě
	ft_striteri(str, test_iter_func);
	if (strcmp(str, "0123") != 0)
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_striteri!\n");
}

void	test_ft_putchar_fd(void)
{
	printf("🔍 Testuji ft_putchar_fd (měl by vypsat '42'): [");
	fflush(stdout);

	// Vypíšeme znaky přímo do terminálu (fd = 1)
	ft_putchar_fd('4', 1);
	ft_putchar_fd('2', 1);

	printf("] ✅ Vizuálně zkontroluj\n");
}

void	test_ft_putstr_fd(void)
{
	printf("🔍 Testuji ft_putstr_fd (měl by vypsat 'Ahoj 42'): [");
	fflush(stdout); // Donutí printf vypsat závorku dříve, než nastane systémový write

	// Vypíšeme řetězec přímo do terminálu (fd = 1)
	ft_putstr_fd("Ahoj 42", 1);

	printf("] ✅ Vizuálně zkontroluj\n");
}

void	test_ft_putendl_fd(void)
{
	printf("🔍 Testuji ft_putendl_fd (měl by vypsat text a odřádkovat):\n[--- Start ---]\n");
	fflush(stdout);

	// Vypíšeme řetězec přímo do terminálu (fd = 1) s automatickým koncem řádku
	ft_putendl_fd("Ahoj z noveho radku", 1);

	printf("[---  End  ---] ✅ Vizuálně zkontroluj, zda je konec na novém řádku\n");
}

void	test_ft_putnbr_fd(void)
{
	printf("🔍 Testuji ft_putnbr_fd (vizuálně ověř hodnoty v závorkách):\n");

	printf("  Běžné číslo (123456):  ["); fflush(stdout);
	ft_putnbr_fd(123456, 1); printf("]\n");

	printf("  Nula (0):              ["); fflush(stdout);
	ft_putnbr_fd(0, 1); printf("]\n");

	printf("  Záporné (-42):         ["); fflush(stdout);
	ft_putnbr_fd(-42, 1); printf("]\n");

	printf("  Chyták (INT_MIN):      ["); fflush(stdout);
	ft_putnbr_fd(-2147483648, 1); printf("]\n");
}

void	test_ft_lstnew(void)
{
	t_list	*node;
	int		errors = 0;

	printf("🔍 Testuji ft_lstnew: ");

	// Test 1: Vytvoření uzlu s textem
	node = ft_lstnew("Test 42");
	if (node == NULL)
		errors++;
	else
	{
		if (strcmp((char *)node->content, "Test 42") != 0)
			errors++;
		if (node->next != NULL)
			errors++;
		free(node);
	}

	// Test 2: Vytvoření uzlu s NULL obsahem (naprosto legální stav)
	node = ft_lstnew(NULL);
	if (node == NULL)
		errors++;
	else
	{
		if (node->content != NULL)
			errors++;
		if (node->next != NULL)
			errors++;
		free(node);
	}

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstnew!\n");
}

void	test_ft_lstadd_front(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	int		errors = 0;

	printf("🔍 Testuji ft_lstadd_front: ");
	head = NULL;

	// Vytvoříme první uzel ("První") a přidáme na začátek prázdného seznamu
	node1 = ft_lstnew("Prvni");
	ft_lstadd_front(&head, node1);
	if (head != node1 || strcmp((char *)head->content, "Prvni") != 0)
		errors++;

	// Vytvoříme druhý uzel ("Druhy") a přidáme na začátek stávajícího seznamu
	node2 = ft_lstnew("Druhy");
	ft_lstadd_front(&head, node2);

	// Novou hlavou seznamu musí být node2, a jeho 'next' musí ukazovat na node1
	if (head != node2 || head->next != node1)
		errors++;
	if (strcmp((char *)head->content, "Druhy") != 0 || strcmp((char *)head->next->content, "Prvni") != 0)
		errors++;

	// Vyčistíme alokované uzly z tohoto testu
	free(node1);
	free(node2);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstadd_front!\n");
}

void	test_ft_lstsize(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	int		errors = 0;

	printf("🔍 Testuji ft_lstsize: ");
	head = NULL;

	// Test 1: Prázdný seznam (musí vrátit 0)
	if (ft_lstsize(head) != 0)
		errors++;

	// Sestavíme krátký seznam
	node1 = ft_lstnew("Uzel 1");
	node2 = ft_lstnew("Uzel 2");
	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);

	// Test 2: Seznam se dvěma prvky (musí vrátit 2)
	if (ft_lstsize(head) != 2)
		errors++;

	// Vyčistíme alokované uzly z tohoto testu
	free(node1);
	free(node2);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstsize!\n");
}

void	test_ft_lstlast(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	int		errors = 0;

	printf("🔍 Testuji ft_lstlast: ");
	head = NULL;

	// Test 1: Prázdný seznam (musí vrátit NULL)
	if (ft_lstlast(head) != NULL)
		errors++;

	// Sestavíme seznam: node2 -> node1 -> NULL
	node1 = ft_lstnew("Uzel 1");
	node2 = ft_lstnew("Uzel 2");
	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);

	// Test 2: Posledním uzlem musí být node1
	if (ft_lstlast(head) != node1)
		errors++;
	if (strcmp((char *)ft_lstlast(head)->content, "Uzel 1") != 0)
		errors++;

	// Vyčistíme alokované uzly z tohoto testu
	free(node1);
	free(node2);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstlast!\n");
}

void	test_ft_lstadd_back(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	int		errors = 0;

	printf("🔍 Testuji ft_lstadd_back: ");
	head = NULL;

	// Test 1: Přidání do prázdného seznamu (new se musí stát hlavou)
	node1 = ft_lstnew("Uzel 1");
	ft_lstadd_back(&head, node1);
	if (head != node1 || head->next != NULL)
		errors++;

	// Test 2: Přidání na konec existujícího seznamu
	node2 = ft_lstnew("Uzel 2");
	ft_lstadd_back(&head, node2);
	if (head != node1 || head->next != node2 || node2->next != NULL)
		errors++;

	// Vyčistíme alokované uzly z tohoto testu
	free(node1);
	free(node2);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstadd_back!\n");
}

static void	test_del_func(void *content)
{
	if (content)
		*((char *)content) = 'X';
}

void	test_ft_lstdelone(void)
{
	t_list	*node;
	char	content[] = "42";
	int		errors = 0;

	printf("🔍 Testuji ft_lstdelone: ");

	node = ft_lstnew(content);
	if (node == NULL)
		errors++;
	else
	{
		ft_lstdelone(node, test_del_func);
		if (content[0] != 'X')
			errors++;
	}

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstdelone!\n");
}

void	test_ft_lstclear(void)
{
	t_list	*head;
	int		errors = 0;

	printf("🔍 Testuji ft_lstclear: ");
	head = NULL;

	// Sestavíme seznam o 3 uzlech
	ft_lstadd_back(&head, ft_lstnew(strdup("A")));
	ft_lstadd_back(&head, ft_lstnew(strdup("B")));
	ft_lstadd_back(&head, ft_lstnew(strdup("C")));

	// Vymažeme celý seznam (pro skutečně alokovaný strdup použijeme volné free)
	ft_lstclear(&head, free);

	// Hlavní ukazatel musí po vyčištění skončit jako NULL
	if (head != NULL)
		errors++;

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstclear!\n");
}

static void	test_iter_lst_func(void *content)
{
	if (content)
		*((char *)content) = 'X';
}

void	test_ft_lstiter(void)
{
	t_list	*head;
	int		errors = 0;

	printf("🔍 Testuji ft_lstiter: ");
	head = NULL;

	// Sestavíme seznam: "A" -> "B" -> NULL
	ft_lstadd_back(&head, ft_lstnew(strdup("A")));
	ft_lstadd_back(&head, ft_lstnew(strdup("B")));

	// Spustíme iteraci, která přepíše první znak na 'X'
	ft_lstiter(head, test_iter_lst_func);

	// Ověříme, že data v uzlech byla správně upravena na "X"
	if (strcmp((char *)head->content, "X") != 0 || strcmp((char *)head->next->content, "X") != 0)
		errors++;

	// Vyčistíme alokovanou paměť
	ft_lstclear(&head, free);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstiter!\n");
}

static void	*test_map_lst_func(void *content)
{
	char	*new_str;

	if (!content)
		return (NULL);
	new_str = strdup((char *)content);
	if (new_str)
		*new_str = 'X'; // Přepíše první znak na 'X'
	return (new_str);
}

void	test_ft_lstmap(void)
{
	t_list	*head;
	t_list	*mapped;
	int		errors = 0;

	printf("🔍 Testuji ft_lstmap: ");
	head = NULL;

	// Sestavíme původní seznam: "A" -> "B" -> NULL
	ft_lstadd_back(&head, ft_lstnew(strdup("A")));
	ft_lstadd_back(&head, ft_lstnew(strdup("B")));

	// Namapujeme ho do nového seznamu
	mapped = ft_lstmap(head, test_map_lst_func, free);

	if (mapped == NULL)
		errors++;
	else
	{
		// Ověříme, že nový seznam má změněný obsah ("X" a "X")
		if (strcmp((char *)mapped->content, "X") != 0 || strcmp((char *)mapped->next->content, "X") != 0)
			errors++;
		// Ověříme, že původní seznam zůstal NETKNUTÝ ("A" a "B")
		if (strcmp((char *)head->content, "A") != 0 || strcmp((char *)head->next->content, "B") != 0)
			errors++;
	}

	// Vyčistíme oba seznamy z paměti
	ft_lstclear(&head, free);
	ft_lstclear(&mapped, free);

	if (errors == 0)
		printf("✅ OK\n");
	else
		printf("  ❌ Chyba v ft_lstmap!\n");
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
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_atoi();
	test_ft_calloc();
	test_ft_strdup();
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_strmapi();
	test_ft_striteri();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	test_ft_lstnew();
	test_ft_lstadd_front();
	test_ft_lstsize();
	test_ft_lstlast();
	test_ft_lstadd_back();
	test_ft_lstdelone();
	test_ft_lstclear();
	test_ft_lstiter();
	test_ft_lstmap();

	printf("\n=========================================\n");
	return (0);
}