#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
int getword(char w[])
{
    char letter;
    int lettercounter=0;
    letter=getchar();
    while((letter != EOF)&& (letter !=' ') &&(letter!='\r') &&(letter != '\t')&&(letter != '\n') && (lettercounter < WORD))
    {
        w[lettercounter]=letter;
        lettercounter++;
        letter=getchar();
    }
    w[lettercounter]='\0';
    if (letter != EOF)
    {
        return ++lettercounter;
    }
    else
    {
        return lettercounter;
    }  
}
int get_line(char s[])
{
    char letter=getchar();
    int lettercounter=0;
    while(letter=='\n')  //remove the spare whitelines in the begening of the file.
			letter = getchar();
    while ((letter!='\n') && (letter!='\r') && (lettercounter<LINE) && (letter!=EOF))
    {
        s[lettercounter]=letter;
        lettercounter++;
        letter=getchar();
    }
    s[lettercounter]='\0';
    return lettercounter;
}
int substring( char * str1, char * str2)
{
    int i=0,j=0;
    int length=strlen(str2);
    while ((*(str1+i) != '\0') && (*(str1+i) != '\n') && (*(str1+i) != '\r'))
    {
        if (*(str1+i)==*(str2+j))
        {
            j++;
        }
        else{
            j=0;
        }
        if (j==length)
        {
            return 1;
        }
        i++;  
    }
    return 0;
}
int similar (char *s, char *t, int n)
{
	int i=0,j=0;
    int diffrent_letter_counter=0;// num of mistake

    if (strlen(s)!=strlen(t)+n)
    	return 0;
     while ((*(s + i) != '\0') && (*(s + i) != '\n'))
    {
    	if (*(s+i) == *(t+j))
    	{
    		i++;
            j++;
        }
    	else // if the char is not equals
    	{
    		diffrent_letter_counter++; 
            i++;
            if (diffrent_letter_counter>n)
              {
                 return 0;
              }
        }
    }
    if(*(s+i)=='\r')
    {
        *(s+i-1)='\0';
    }
    return 1;   
}
void print_lines(char *str)
{
	char line[LINE];
	int SizeLine = get_line(line);
	while(SizeLine != 0)
	{
		if(substring(line, str)==1)
			printf("%s\n", line);

		SizeLine = get_line(line); //line.next();
	}
}
void print_similar_words(char *str)
{
	char word[WORD];
	int SizeWord = getword(word);
	while(SizeWord != 0)
	{
		if((similar(word, str,1)==1) ||(similar(word, str,0)==1))
			printf("%s\n", word); 
		SizeWord = getword(word); //word.next();
	}
}
int main ()
{
   char word[WORD];
   char choise;
   getword(word); //take the first word in the first line
   scanf(" %c\n" , &choise);
   	if(choise == 'a')
   		print_lines(word);
   	else if(choise == 'b')
   		print_similar_words(word);
    return 0;
}