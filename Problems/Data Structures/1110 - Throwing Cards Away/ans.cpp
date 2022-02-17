#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    queue<int> deck;

    scanf("%d", &n);
    while (n)
    {

        for (int i = 1; i <= n; i++)
            deck.push(i);

        printf("Discarded cards:");

        if (n > 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                printf(" %d,", deck.front());
                deck.pop();
                deck.push(deck.front());
                deck.pop();
            }
            printf(" %d", deck.front());
            deck.pop();
            deck.push(deck.front());
            deck.pop();
        }
        printf("\nRemaining card: %d\n", deck.front());

        while (!deck.empty())
            deck.pop();

        scanf("%d", &n);
    }

    return 0;
}