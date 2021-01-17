/*
 File:				lab2_in-lab_exercises.c
 Purpose:			Implementation of functions for lab 2 in-lab exercises
 Author:			Clive Fransen and Mihir Bhatia
 Student #s:	    11807328 and 76149921
 CS Accounts:	    cfransen@students.cs.ubc.ca and mbhati01@students.cs.ubc.ca
 Date:				29 September 2020
 */

#include "lab2_in-lab_exercises.h"
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996) //disables warnings about strcpy

 /*
  * Let's start with something easy.  There are 3 unit tests
  * for this function.
  *
  * Swaps the contents of two integer variables using pointers
  *
  * PARAM:     first_int is a pointer to an int
  * PARAM:     second_int is a pointer to an int
  * PRE:       both pointers are valid pointers to int
  * POST:      the contents of two integer variables are swapped
  * RETURN:    VOID
  */
void swap_ints(int* first_int, int* second_int)
{
	int temp = *first_int; //temporary int
	*first_int = *second_int; //swap
	*second_int = temp; //use temporary for last swap
}

/*
 * Now let's try something a little more challenging.
 *
 * Reverses the contents of the string passed to the
 * function.  Does not move the terminating null '\0'
 * character.
 *
 * PARAM:     string is a pointer to an array of char (a string)
 * PRE:       the array of char terminates with a null '\0'
 * POST:      the char array has been reversed
 * RETURN:    VOID
 */
void reverse_string(char* string)
{

	int length = strlen(string);
	char* q = (char*)malloc(length*sizeof(string)); //creates a pointer identical in length & (bit) size to string on the heap

	if (q != NULL) { //this is just to get rid of an error
		strcpy(q, string); //fill q with string
		for (int i = 0, j = length - 1; i < j; i++, j--) {
			char temp = *(q + i);
			*(q + i) = *(q + j);
			*(q + j) = temp;
			//swap elements of q
		}
		strcpy(string, q); //copy q (reversed string) back onto string
	}

}

/*
 * Let's see how well you read the lab document.
 *
 * Determines if candidate contains sample, and returns
 * 1 if  it does, and 0 if it does not.
 *
 * PARAM:     candidate is a pointer to an array of char (a string)
 * PARAM:     sample is a pointer to an array of char (a string)
 * PRE:       the arrays of char terminate with a null '\0'
 * PRE:       candidate != NULL; sample != NULL
 * POST:      N/A
 * RETURN:    IF candidate contains sample THEN 1
 *            ELSE 0.
 */
int contains_sample(char* candidate, char* sample)
{
	char* result = NULL;
	result = strstr(candidate, sample); //result will be a subset string of candidate starting where sample appears
	if (result != NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

/*
 * Returns the first index where sample is located inside the
 * candidate.  For example:
 * IF candidate = "Hello", sample = "Hello", RETURNS 0
 * IF candidate = "soupspoon", sample = "spoon", RETURNS 4
 * IF candidate = "ACGTACGTA", sample = "CGT", RETURNS 1
 * IF candidate = "CGTACGTA", sample = "CGTT", returns -1
 *
 * PARAM:     candidate is a pointer to an array of char (a string)
 * PARAM:     sample is a pointer to an array of char (a string)
 * PRE:       the arrays of char terminate with a null '\0'
 * POST:      N/A
 * RETURN:    IF candidate contains sample
 *            THEN the index where the first letter of sample is inside candidate
 *            ELSE -1.
 */
int find_index(char* candidate, char* sample)
{
	//ex candidate "ACGTACGTA" and sample "CGT"
	char* result = strstr(candidate, sample); // ex:  result is "CGTACGTA"
	if (result == NULL) { //but if result isn't "CGTACGTA" or some string
		return -1;
	}
	else {
		int index = (result - candidate); //turns the result & candidate into an integer value, returns the difference, I would cast but gradescope doesn't like it.
		return index;
		//candidate as an int = the int value of the first address ex: 123
		//result as an int = the address of the found index ex: in our example, the index is the second character, so 124
		//index = 124 - 123 = 1
	}
}