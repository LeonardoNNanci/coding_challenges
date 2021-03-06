#include <bits/stdc++.h>

using namespace std;

map<string, string> dict{{"brasil", "Feliz Natal!"},
                         {"alemanha", "Frohliche Weihnachten!"},
                         {"austria", "Frohe Weihnacht!"},
                         {"coreia", "Chuk Sung Tan!"},
                         {"espanha", "Feliz Navidad!"},
                         {"grecia", "Kala Christougena!"},
                         {"estados-unidos", "Merry Christmas!"},
                         {"inglaterra", "Merry Christmas!"},
                         {"australia", "Merry Christmas!"},
                         {"portugal", "Feliz Natal!"},
                         {"suecia", "God Jul!"},
                         {"turquia", "Mutlu Noeller"},
                         {"argentina", "Feliz Navidad!"},
                         {"chile", "Feliz Navidad!"},
                         {"mexico", "Feliz Navidad!"},
                         {"antardida", "Merry Christmas!"},
                         {"canada", "Merry Christmas!"},
                         {"irlanda", "Nollaig Shona Dhuit!"},
                         {"belgica", "Zalig Kerstfeest!"},
                         {"italia", "Buon Natale!"},
                         {"libia", "Buon Natale!"},
                         {"siria", "Milad Mubarak!"},
                         {"marrocos", "Milad Mubarak!"},
                         {"japao", "Merii Kurisumasu!"}};

int main() {
  char country[100];
  while (scanf("%s", country) != EOF) {
    auto translation = dict[country];
    if (translation.empty())
      cout << "--- NOT FOUND ---" << '\n';
    else
      cout << dict[country] << '\n';
  }
}