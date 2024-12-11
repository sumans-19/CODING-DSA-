// 1) Design, Develop and Implement a Program in C for the following operations on
// Strings
// a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
// b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR
// with REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR.
// c. Pattern Matching Algorithm: Brute Force
// d. Support the program with functions for each of the above operations. Don't use Builtin functions
// e. Check the following test cases.
// Test Case 1: STR = “VVCE MYSURU”, PAT=” MYSURU”, REP=” KARNATAKA”, OUTPUT=”
// VVCE KARNATAKA”
// Test Case 2: STR = “COMPUTER SCIENCE”, PAT=” COMPUTER”, REP=” BASIC”,
// OUTPUT=” BASIC SCIENCE”

CODE :
#include <stdio.h>
#include <stdlib.h>
char str[100], pat[50], rep[50], ans[100];
int i, j, c, m, k, flag = 0;
void stringmatch()
{
    i = m = c = j = 0;
    while (str[c] != '\0')
    {
        if (str[m] == pat[i])
        {
            i++;
            m++;
            if (pat[i] == '\0')
            {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++)
                    ans[j] = rep[k];
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
        }
    }
    ans[j] = '\0';
}
void main()
{
    printf("Enter a main string \n");
    gets(str);
    printf("Enter a pattern string \n");
    gets(pat);
    printf("Enter a replace string \n");
    gets(rep);
    stringmatch();
    if (flag == 1)
        printf("The resultant string is\n %s", ans);
    else
        printf("Pattern string NOT found\n");
}
