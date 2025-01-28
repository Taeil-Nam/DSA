#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

char *ft_lltoa(long long n)
{
	int n_len = 0;
	char *buffer;

	for (long long temp = n; temp > 0;)
	{
		temp /= 10;
		n_len++;
	}

	buffer = (char *)malloc(sizeof(char) * (n_len + 1));
	for (int i = 0; n > 0;)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}

	for (int i = 0; i < n_len / 2; i++)
	{
		char temp = buffer[i];
		buffer[i] = buffer[n_len - i - 1];
		buffer[n_len - i - 1] = temp;
	}
	buffer[n_len] = '\0';

	return (buffer);
}

long long solution(long long n)
{
	char *n_str;
	char temp;
	long long result;

	n_str = ft_lltoa(n);

	for (int i = 0; i < strlen(n_str); i++)
	{
		for (int j = i + 1; j < strlen(n_str); j++)
		{
			if (n_str[i] < n_str[j])
			{
				temp = n_str[i];
				n_str[i] = n_str[j];
				n_str[j] = temp;
			}
		}
	}

	result = atoll(n_str);

	return result;
}
