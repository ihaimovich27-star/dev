//Idan Haimovich, 🎯 HONORS ONLY: "Optional" Unit 1 Project from BJC (not optional for Honors students)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// WORD LISTS - all random words (basically what the project started with)
const char *nouns[]       = {"cat", "house", "water", "car", "tree"};
const char *verbs[]       = {"runs", "jumps", "sits down", "climbs", "talks"};
const char *adjectives[]  = {"little", "silly", "wise", "young", "tired"};
const char *adverbs[]     = {"quickly", "angrily", "happily"};
const char *determiners[] = {"the", "a", "my", "your", "his", "her"};
const char *prepositions[] = {"over", "near", "towards", "in front of"};

// Function to pick a random word from a list
const char* random_from(const char *list[], int size) {
    return list[rand() % size];
}

// BASIC RANDOM WORD REPORTERS
const char* random_noun() { return random_from(nouns, 5); }
const char* random_verb() { return random_from(verbs, 5); }
const char* random_adjective() { return random_from(adjectives, 5); }
const char* random_adverb() { return random_from(adverbs, 3); }
const char* random_determiner() { return random_from(determiners, 6); }
const char* random_preposition() { return random_from(prepositions, 4); }

// PHRASE BUILDERS 

// green noun phrase
void noun_phrase(char *buffer) {
    // randomly decide: determiner+noun or determiner+adjective+noun
    int use_adj = rand() % 2;

    if (use_adj)
        sprintf(buffer, "%s %s %s", random_determiner(), random_adjective(), random_noun());
    else
        sprintf(buffer, "%s %s", random_determiner(), random_noun());
}

// green verb phrase
void verb_phrase(char *buffer) {
    // randomly decide: verb only OR verb + adverb
    int add_adverb = rand() % 2;

    if (add_adverb)
        sprintf(buffer, "%s %s", random_verb(), random_adverb());
    else
        sprintf(buffer, "%s", random_verb());
}

// green prepositional phrase
void prepositional_phrase(char *buffer) {
    char np[100];
    noun_phrase(np);

    sprintf(buffer, "%s %s", random_preposition(), np);
}

// ---- SENTENCES ----

// simple sentence: determiner + noun + verb
void simple_sentence(char *buffer) {
    sprintf(buffer, "%s %s %s", random_determiner(), random_noun(), random_verb());
}

// complicated sentence: noun phrase + verb phrase + prepositional phrase
void complicated_sentence(char *buffer) {
    char np[100], vp[100], pp[100];
    noun_phrase(np);
    verb_phrase(vp);
    prepositional_phrase(pp);

    sprintf(buffer, "%s %s %s", np, vp, pp);
}

// MAIN
int main() {
    srand(time(NULL));

    char buffer[300];

    simple_sentence(buffer);
    printf("Simple sentence:\n%s\n\n", buffer);

    complicated_sentence(buffer);
    printf("Complicated sentence:\n%s\n\n", buffer);

    return 0;
}

