#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function declarations
const char* random_noun();
const char* random_verb();
const char* random_adjective();
const char* random_adverb();
const char* random_determiner();
const char* random_preposition();

void noun_phrase(char *buffer);
void verb_phrase(char *buffer);
void prepositional_phrase(char *buffer);
void simple_sentence(char *buffer);
void complicated_sentence(char *buffer);

#endif
