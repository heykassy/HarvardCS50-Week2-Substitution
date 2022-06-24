#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool only_26letters(string key);
bool char_compare(string key);
string encrypted(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check if the user is inputing just one command-line argument, otherwise print how they should use it
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if argv[1] is a 26-letter argument, otherwise print how user should use it
    bool iskeyright = only_26letters(argv[1]);
    if (iskeyright == false)
    {
        printf("Key must contain 26 letters, and letters only.\n");
        return 1;
    }

    // Check if there are any duplicate letters, if so, print how user should use it
    bool arethereduplicates = char_compare(argv[1]);
    if (arethereduplicates == false)
    {
        printf("Each letter must be written only once.\n");
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");

    // Print encrypted message
    string ciphertext = encrypted(plaintext, argv[1]);
    printf("ciphertext: %s\n", ciphertext);


}


// Function to check if command-line argument is only letters and if it's 26 characters long
bool only_26letters(string key)
{
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    if (key[26] != 0)
    {
        return false;
    }
    return true;
}

// Function to check if any letter has been written more than once
bool char_compare(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int j = 0; j < strlen(key); j++)
    {
        for (int k = j + 1; k < strlen(key); k++)
        {
            if (key[j] == key[k])
            {
                return false;
            }
        }
    }
    return true;
}

// Function to encrypt plaintext
string encrypted(string plaintext, string key)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = toupper(key[plaintext[i] - 65]);
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = tolower(key[plaintext[i] - 97]);
        }
    }
    return plaintext;
}