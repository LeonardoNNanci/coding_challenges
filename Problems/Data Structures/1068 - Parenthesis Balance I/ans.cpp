#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char input[1000];
    while (scanf("%s", input) != EOF)
    {
        int stack = 0;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] == '(')
                stack++;
            else if (input[i] == ')')
                stack--;

            if (stack < 0)
                break;
        }

        if (stack != 0)
            printf("incorrect\n");
        else
            printf("correct\n");
    }
}