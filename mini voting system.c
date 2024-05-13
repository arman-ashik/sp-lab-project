#include <stdio.h>
#include <string.h>

// Define maximum number of candidates
#define MAX_CANDIDATES 5
// Define maximum number of voters
#define MAX_VOTERS 100

// Structure for candidate
struct Candidate {
    char name[50];
    int votes;
};

// Function prototypes
int authenticateVoter(char username[], char password[]);
void castVote(struct Candidate candidates[], int numCandidates);
void generateReport(struct Candidate candidates[], int numCandidates, int totalVotes);

int main() {
    // Hardcoded candidates
    struct Candidate candidates[MAX_CANDIDATES] = {
        {"Candidate 1", 0},
        {"Candidate 2", 0},
        {"Candidate 3", 0},
        {"Candidate 4", 0},
        {"Candidate 5", 0}
    };
    int totalVotes = 0;

    // Simulation of user authentication
    char username[50];
    char password[50];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    if (authenticateVoter(username, password)) {
        printf("Authentication successful!\n");
        castVote(candidates, MAX_CANDIDATES);
        totalVotes++;
    } else {
        printf("Authentication failed. Access denied.\n");
        return 0;
    }

    // Generate report
    generateReport(candidates, MAX_CANDIDATES, totalVotes);

    return 0;
}

// Function to authenticate the user
int authenticateVoter(char username[], char password[]) {
    // Hardcoded user credentials for demonstration
    char validUsername[] = "user123";
    char validPassword[] = "password123";

    if (strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0) {
        return 1; // Authentication successful
    } else {
        return 0; // Authentication failed
    }
}

// Function to cast a vote
void castVote(struct Candidate candidates[], int numCandidates) {
    int choice;
    printf("\nCandidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("Enter your choice (1-%d): ", numCandidates);
    scanf("%d", &choice);

    // Validate choice
    if (choice >= 1 && choice <= numCandidates) {
        candidates[choice - 1].votes++;
        printf("Thank you for casting your vote!\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

// Function to generate voting report
void generateReport(struct Candidate candidates[], int numCandidates, int totalVotes) {
    printf("\nVoting Report:\n");
    printf("Total votes cast: %d\n", totalVotes);
    printf("Candidate\tVotes\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}
