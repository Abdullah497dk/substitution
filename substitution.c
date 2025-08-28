#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("key nust contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        int letter = tolower(key[i]) - 'a';

        if (seen[letter])
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }

        seen[letter] = true;
    }

    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {

            int x = tolower(text[i]) - 'a';
            if (isupper(text[i]))
            {
                printf("%c", toupper(key[x]));
            }
            else if (islower(text[i]))
            {
                printf("%c", tolower(key[x]));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
}
