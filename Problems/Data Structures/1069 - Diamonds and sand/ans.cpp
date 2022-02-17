#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char input[1000];
    int n;

    scanf("%d", &n);
    while (n--)
    {

        int stack = 0, complete = 0;
        scanf("%s[^\n]", input);
        for (int i = 0; input[i] != '\0'; i++)
        {

            if (input[i] == '<')
                stack++;

            else if (input[i] == '>' && stack)
            {
                complete++;
                stack--;
            }
        }

        printf("%d\n", complete);
    }
}