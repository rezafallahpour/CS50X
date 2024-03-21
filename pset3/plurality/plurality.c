#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int x = 0; x < candidate_count; x++)
    {
        if (strcmp(name, candidates[x].name) == 0)
        {
            candidates[x].votes++;
            return true; // Return true when a valid vote is cast
        }
    }
    // If the loop completes without finding a matching candidate, the vote is invalid
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int maxnum = 0;
    string maxname;
    for (int z = 0; z < candidate_count; z++)
    {
        if (maxnum < candidates[z].votes)
        {
            maxnum = candidates[z].votes;
            maxname = candidates[z].name;
        }
    }
    printf("%s\n", maxname);
    for (int p = 0; p < candidate_count; p++)
    {
        if (maxnum == candidates[p].votes && (strcmp(maxname, candidates[p].name) != 0))
        {
            printf("%s\n", candidates[p].name);
        }
    }
    return;
}