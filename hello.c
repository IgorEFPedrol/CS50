#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //receiving the name of the user
    string name = get_string("What's your name? ");
    //printing "hello" + the user's name
    printf("hello, %s\n", name);
}