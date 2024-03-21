#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int number_of_ch(string sentence);
int number_of_word(string sentence);
int number_of_sentences(string sentence);

int main(void)
{
    string s = get_string("Text: ");
    int Let = number_of_ch(s);
    int word = number_of_word(s);
    int sentence = number_of_sentences(s);
    /*printf("number of letters: %i\n",Let);
    printf("number of words: %i\n",word);
    printf("number of sentences: %i\n",sentence);*/
    float L = 100 * Let / word;
    float S = 100 * sentence / word;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // printf("number of index: %i\n",index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// calculate number of charecters
int number_of_ch(string sentence)
{
    char WF[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int number_of_ch = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (islower(sentence[i]))
        {
            sentence[i] = toupper(sentence[i]);
        }
        for (int j = 0; j < 29; j++)
        {
            if (sentence[i] == WF[j])
            {
                number_of_ch++;
            }
        }
    }
    return number_of_ch;
}
// calculate number of words
int number_of_word(string sentence)
{
    char space[] = " .?!\0,";
    char WF[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ-";
    int number_of_w = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (islower(sentence[i]))
        {
            sentence[i] = toupper(sentence[i]);
        }
        for (int j = 0; j < 30; j++)
        {
            if (sentence[i] == WF[j] && (sentence[i + 1] == space[0] || sentence[i + 1] == space[1] ||
                                         sentence[i + 1] == space[2] || sentence[i + 1] == space[3] ||
                                         sentence[i + 1] == space[3] || sentence[i + 1] == space[4] || sentence[i + 1] == space[5]))
            {
                number_of_w++;
            }
        }
    }
    return number_of_w;
}
// calculate number of sentences
int number_of_sentences(string sentence)
{
    char WF[] = "!.?";
    int number_of_s = 0;
    for (int i = 0; i < strlen(sentence); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sentence[i] == WF[j])
            {
                number_of_s++;
            }
        }
    }
    return number_of_s;
}