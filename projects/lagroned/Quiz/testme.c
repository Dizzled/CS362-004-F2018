/*
 *Dustin LaGrone
 *Random Testing Quiz 2
 *CS 362 Software Engineering 2*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

char inputChar()
{
    //40-126 ASCII characters
	char random = (rand() % 94) + 32;
    return random;
    
}

char *inputString()
{
	static char s[6];		
	int i = 0;

	
	while (i < 5)
	{
		s[i] = (rand() % 16)+ 101;
		i++;
	}

    return s;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1; //91
    if (c == '(' && state == 1) state = 2; //40
    if (c == '{' && state == 2) state = 3; //123
    if (c == ' ' && state == 3) state = 4; //32
    if (c == 'a' && state == 4) state = 5; //97
    if (c == 'x' && state == 5) state = 6; //120
    if (c == '}' && state == 6) state = 7; //125
    if (c == ')' && state == 7) state = 8;//41
    if (c == ']' && state == 8) state = 9;//93
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
