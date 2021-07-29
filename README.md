build

```bash
cc main.c input.c -o db
```

```bash
cc main.c processor.c table.c input.c -o db
```

```
gem install rspec --user-install
```
根据安装提示加 PATH


strtok

❯ ./db   
db > insert -1 sc bar@foo.com
buffer: insert -1 sc bar@foo.com
insert, -1, sc, bar@foo.com, insert
ID must be positive.
db > .exit

```c
#include <string.h>
#include <stdio.h>

int main()
{
   const char str[80] = "This is - www.gitbook.net - website";
   const char s[2] = "-";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) 
   {
      printf( " %s", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}
/*
This is 
www.gitbook.net 
website
*/
```

lseek

