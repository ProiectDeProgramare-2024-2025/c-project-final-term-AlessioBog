
/*Joc de tip Vrei să fii milionar?
Aplicația oferă utilizatorului opțiunea de a intra în joc, joc unde îi sunt adresate 15 întrebări.
Fiecare întrebare oferă 4 variante de răspuns, din care una este adevărată. La finalul jocului (fie
când a răspuns corect la cele 15 întrebări, fie când a greșit), utilizatorul trebuie să introducă un
nume. Aplicația permite vizualizarea unui clasament general (fiecare întrebare valorează un punct) și
vizualizarea unui istoric de jocuri pentru un utilizator introdus. La orice întrebare, utilizatorul
poate folosi opțiunea "50/50", opțiune care șterge 2 variante de răspuns greșite (această opțiune poate
fi folosită la toate cele 15 întrebări, însă înjumătățește scorul primit pentru întrebarile la care este
folosită de la 1 punct la 0.5 puncte).*/


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE *intrare;
FILE *iesire;

typedef struct clasament {
    char name[100];
    double scor;
}clasament;

int alegere() {
    int choice = 0;
    char input[10];
    int valid = 0;

    while (!valid) {
        printf("Introduceti optiunea dorita (1-4): ");

        if (fgets(input, sizeof(input), stdin)) {
            valid = 1;
            for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
                if (!isdigit(input[i])) {
                    valid = 0;
                    break;
                }
            }

            if (valid) {
                choice = atoi(input);
                if (choice < 1 || choice > 4) {
                    valid = 0;
                    printf("Eroare: Introduceti un numar intre 1 si 4!\n");
                }
            } else {
                printf("Eroare: Trebuie introdus un numar!\n");
            }
        }
    }

    return choice;
}

bool esteNume(const char *name) {
    if (strlen(name) == 0) return false;

    bool areLit = false;
    char *result = strchr(name, ' ');

    if (result != NULL)
        return false;
    for (int i = 0; name[i]; i++) {
        if (isalpha(name[i]) ||  name[i] == '-') {
            if (isalpha(name[i])) {
                areLit = true;
            }
        } else {
            return false;
        }
    }
    return areLit;
}

void sortare(clasament a[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i].scor < a[j].scor) {
                clasament temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else if (a[i].scor == a[j].scor) {
                if (strcmp(a[i].name,a[j].name) > 0) {
                    clasament temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

float intrebare1() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m1: Care este primul pas recomandat pentru a deveni \033[0;32mmilionar?\033[0m\n\n");
    printf("1) Castiga la loto\n");
    printf("2) Investeste constant si inteligent\n");
    printf("3) Primesti o mostenire\n");
    printf("4) Imprumuta o suma mare de bani\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m1 (50/50):\n");
        printf("1) Investeste constant si inteligent\n");
        printf("2) Imprumuta o suma mare de bani\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 1) ? 0.5 : 0.0;
    }

    return (raspuns == 2) ? 1.0 : 0.0;
}

float intrebare2() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m2: Care dintre urmatoarele este o trasatura comuna a \033[0;32mmilionarilor?\033[0m\n\n");
    printf("1) Cheltuieste mai mult decat castiga\n");
    printf("2) Evita orice forma de investitii\n");
    printf("3) Are un mindset de crestere financiara\n");
    printf("4) Se bazeaza doar pe noroc\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m2 (50/50):\n");
        printf("1) Cheltuieste mai mult decat castiga\n");
        printf("2) Are un mindset de crestere financiara\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 2) ? 0.5 : 0.0;
    }

    return (raspuns == 3) ? 1.0 : 0.0;
}

float intrebare3() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m3: Ce procent din \033[0;32mmilionarii \033[0;33mdin lume si-au construit averea singuri?\033[0m\n\n");
    printf("1) 20%\n");
    printf("2) 50%\n");
    printf("3) 80%\n");
    printf("4) 95%\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m3 (50/50):\n");
        printf("1) 50%\n");
        printf("2) 80%\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 2) ? 0.5 : 0.0;
    }

    return (raspuns == 3) ? 1.0 : 0.0;
}

float intrebare4() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m4: Care este cea mai buna strategie pentru a acumula bogatie pe termen lung?\033[0m\n\n");
    printf("1) Specula la bursa zilnic\n");
    printf("2) Economisirea si investitia pasiva\n");
    printf("3) Jocurile de noroc\n");
    printf("4) Cheltuieli impulsive\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m4 (50/50):\n");
        printf("1) Economisirea si investitia pasiva\n");
        printf("2) Jocurile de noroc\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 1) ? 0.5 : 0.0;
    }

    return (raspuns == 2) ? 1.0 : 0.0;
}

float intrebare5() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m5: Ce principiu al \033[0;32mmilionarilor \033[0;33mspune ca \"banii trebuie sa lucreze pentru tine\"?\033[0m\n\n");
    printf("1) Cheltuielile excesive\n");
    printf("2) Dobanda compusa\n");
    printf("3) Indatorarea maxima\n");
    printf("4) Evitarea oricaror investitii\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m5 (50/50):\n");
        printf("1) Dobanda compusa\n");
        printf("2) Indatorarea maxima\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 1) ? 0.5 : 0.0;
    }

    return (raspuns == 2) ? 1.0 : 0.0;
}

float intrebare6() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m6: Cat de important este bugetul in devenirea \033[0;32mmilionar?\033[0m\n\n");
    printf("1) Deloc important\n");
    printf("2) Putin important\n");
    printf("3) Foarte important\n");
    printf("4) Doar pentru cei saraci\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m6 (50/50):\n");
        printf("1) Putin important\n");
        printf("2) Foarte important\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 2) ? 0.5 : 0.0;
    }

    return (raspuns == 3) ? 1.0 : 0.0;
}

float intrebare7() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m7: Care dintre urmatoarele NU este o sursa comuna de venit pentru \033[0;32mmilionari?\033[0m\n\n");
    printf("1) Investitii in actiuni\n");
    printf("2) Intreprinderi proprii\n");
    printf("3) Salariu fix la un loc de munca obisnuit\n");
    printf("4) Venituri din chirii\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m7 (50/50):\n");
        printf("1) Salariu fix la un loc de munca obisnuit\n");
        printf("2) Intreprinderi proprii\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 1) ? 0.5 : 0.0;
    }

    return (raspuns == 3) ? 1.0 : 0.0;
}

float intrebare8() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m8: Ce procent din venit recomanda finantistii sa fie economisit pentru a acumula bogatie?\033[0m\n\n");
    printf("1) 5-10%\n");
    printf("2) 15-20%\n");
    printf("3) 30-50%\n");
    printf("4) Peste 70%\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m8 (50/50):\n");
        printf("1) 5-10%\n");
        printf("2) 15-20%\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 2) ? 0.5 : 0.0;
    }

    return (raspuns == 2) ? 1.0 : 0.0;
}

float intrebare9() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m9: Care este cel mai bun mod de a-ti proteja averea?\033[0m\n\n");
    printf("1) Ti-o tii in casa\n");
    printf("2) Diversificarea investitiilor\n");
    printf("3) Imprumuti toti banii\n");
    printf("4) Nu platesti taxe\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m9 (50/50):\n");
        printf("1) Diversificarea investitiilor\n");
        printf("2) Imprumuti toti banii\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 1) ? 0.5 : 0.0;
    }

    return (raspuns == 2) ? 1.0 : 0.0;
}

float intrebare10() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m10: Cine a spus: \033[0;36m\"Nu conteaza cat de mult castigi, ci cat de mult retii\"\033[0m?\033[0m\n\n");
    printf("1) Warren Buffett\n");
    printf("2) Bill Gates\n");
    printf("3) Jeff Bezos\n");
    printf("4) Elon Musk\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m10 (50/50):\n");
        printf("1) Warren Buffett\n");
        printf("2) Bill Gates\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 1) ? 0.5 : 0.0;
    }

    return (raspuns == 1) ? 1.0 : 0.0;
}

float intrebare11() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m11: Cat timp ia, in medie, sa devii \033[0;32mmilionar\033[0;33m prin economisire si investitii?\033[0m\n\n");
    printf("1) 1-2 ani\n");
    printf("2) 5-10 ani\n");
    printf("3) 15-20 ani\n");
    printf("4) Peste 30 de ani\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m11 (50/50):\n");
        printf("1) 5-10 ani\n");
        printf("2) 15-20 ani\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 2) ? 0.5 : 0.0;
    }

    return (raspuns == 3) ? 1.0 : 0.0;
}

float intrebare12() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m12: Care este cea mai mare greseala financiara care impiedica oamenii sa devina \033[0;32mmilionari?\033[0m\n\n");
    printf("1) Cheltuieli excesive si datorii\n");
    printf("2) Investitii prea sigure\n");
    printf("3) Castigarea unui salariu mare\n");
    printf("4) Economisirea prea multa\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m12 (50/50):\n");
        printf("1) Cheltuieli excesive si datorii\n");
        printf("2) Castigarea unui salariu mare\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 1) ? 0.5 : 0.0;
    }

    return (raspuns == 1) ? 1.0 : 0.0;
}

float intrebare13() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m13: Ce carte este considerata \033[0m\"Biblia independentei financiare\"?\033[0m\n\n");
    printf("1) \"Rich Dad Poor Dad\" - Robert Kiyosaki\n");
    printf("2) \"Think and Grow Rich\" - Napoleon Hill\n");
    printf("3) \"The Millionaire Next Door\" - Thomas Stanley\n");
    printf("4) \"The Intelligent Investor\" - Benjamin Graham\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m13 (50/50):\n");
        printf("1) \"Rich Dad Poor Dad\" - Robert Kiyosaki\n");
        printf("2) \"Think and Grow Rich\" - Napoleon Hill\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 1) ? 0.5 : 0.0;
    }

    return (raspuns == 1) ? 1.0 : 0.0;
}

float intrebare14() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m14: Ce procent din \033[0;32mmilionari \033[0;33mciteste cel putin o carte pe luna?\033[0m\n\n");
    printf("1) 20%\n");
    printf("2) 50%\n");
    printf("3) 75%\n");
    printf("4) 88%\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m14 (50/50):\n");
        printf("1) 50%\n");
        printf("2) 88%\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 2) ? 0.5 : 0.0;
    }

    return (raspuns == 4) ? 1.0 : 0.0;
}

float intrebare15() {
    system("cls");
    int raspuns = 0;
    bool valid_input = false;

    printf("\033[0;33m15: Care este cea mai buna mentalitate pentru a deveni \033[0;32mmilionar?\033[0m\n\n");
    printf("1) \"Vreau sa fiu rapid bogat\"\n");
    printf("2) \"Vreau sa muncesc cat mai putin\"\n");
    printf("3) \"Vreau sa invat si sa cresc constant\"\n");
    printf("4) \"Vreau sa depind de altii\"\n");
    printf("5) 50/50\n");

    while (!valid_input) {
        printf("Introduceti raspunsul (1-5): ");
        if (scanf("%d", &raspuns) != 1) {
            printf("Eroare: Te rog introdu un numar!\n");
            while (getchar() != '\n');
            continue;
        }
        if (raspuns < 1 || raspuns > 5) {
            printf("Eroare: Introdu un numar intre 1 si 5!\n");
            continue;
        }
        valid_input = true;
    }

    if (raspuns == 5) {
        raspuns = 0;
        system("cls");
        valid_input = false;
        printf("\033[0;33m15 (50/50):\n");
        printf("1) \"Vreau sa fiu rapid bogat\"\n");
        printf("2) \"Vreau sa invat si sa cresc constant\"\n");

        while (!valid_input) {
            printf("Introduceti raspunsul adevarat (1-2): ");
            if (scanf("%d", &raspuns) != 1) {
                printf("Eroare: Te rog introdu un numar!\n");
                while (getchar() != '\n');
                continue;
            }
            if (raspuns < 1 || raspuns > 2) {
                printf("Eroare: Introdu 1 sau 2!\n");
                continue;
            }
            valid_input = true;
        }
        return (raspuns == 2) ? 0.5 : 0.0;
    }

    return (raspuns == 3) ? 1.0 : 0.0;
}
int main()
{
    clasament a[100];
    clasament actu;
    intrare = fopen("clasament.txt", "r");
    int i=0;
    while (fscanf(intrare, "%99s %lf", a[i].name,&a[i].scor) == 2) {
        i++;

        if (i>=100) break;
    }
    fclose(intrare);
    iesire = fopen("clasament.txt", "w");
    for(int j=0;j<i;j++)
        fprintf(iesire, "%s %.2lf\n", a[j].name, a[j].scor);
    fclose(iesire);
    while (1)
    {
        system("cls");
        printf("- Vrei sa fii \033[0;32mmilionar?\033[0m -\n");
        printf("1 - \033[0;35mStart\033[0mjoc\n");
        printf("2 - Vezi \033[0;31mclasament\033[0m\n");
        printf("3 - Vezi \033[0;33mscor \033[0mpe \033[0;32m nume\033[0m\n");
        printf("4 - \033[0;31mIesire\033[0m\n");

        int choice = alegere();

        system("cls");
        float s = 0;
        char nume[20];
        switch (choice) {




            case 1:
                s += intrebare1();
            s += intrebare2();
            s += intrebare3();
            s += intrebare4();
            s += intrebare5();
            s += intrebare6();
            s += intrebare7();
            s += intrebare8();
            s += intrebare9();
            s += intrebare10();
            s += intrebare11();
            s += intrebare12();
            s += intrebare13();
            s += intrebare14();
            s += intrebare15();
            system("cls");
            printf("Scor final: %.1f puncte\n", s);




            do {

                printf("Introduceti doar numele:");
                fgets(nume, sizeof(nume), stdin);
                nume[strcspn(nume, "\n")] = '\0';
                if (!esteNume(nume)) {
                    printf("Nume invalid! Te rog introdu un nume real (fara numere sau simboluri).\n");
                }
            } while (!esteNume(nume));





            if (i >= 100){
                if (s > a[i].scor || (s == a[i].scor && strcmp(nume ,a[i].name) < 0))
                    strcpy(a[i].name, nume);
                    a[i].scor = s;
                    }
            else {
                strcpy(a[i].name, nume);
                a[i].scor = s;
                i++;
            }
            sortare(a,i);
            system("pause");
            break;



            case 2:
                iesire = fopen("clasament.txt", "w");
            printf("\033[0;31m");
            printf("Nr\t");
            printf("\033[0m");


            printf("\033[0;35m");
            printf("Nume\t\t ");
            printf("\033[0m");


            printf("\033[0;36m");
            printf("Scor\n");
            printf("\033[0m");
                for(int j=0;j<i;j++){
                    fprintf(iesire, "%s %.2lf\n", a[j].name, a[j].scor);
                    printf("%d\t%s\t\t%.2f\n",j+1,a[j].name,a[j].scor);
                }
            fclose(iesire);
            system("pause");
            break;
            case 3:{
                system("cls");
                char coata[100];
                printf("Introduceti numele de cautat: ");
                scanf("%s", coata);
                coata[strcspn(coata, "\n")] = '\0';

                bool gasit = false;
                for (int j = 0; j < i; j++) {
                    if (strcasecmp(a[j].name, coata) == 0) {
                        printf("Scor pentru %s: %.2f\n", a[j].name, a[j].scor);
                        gasit = true;
                    }
                }

                if (!gasit) {
                    printf("Numele nu a fost gasit in clasament.\n");
                }
                system("pause");
                break;
            }


        case 4:
            iesire = fopen("clasament.txt", "w");
            for(int j=0;j<i;j++)
                fprintf(iesire, "%s %.2lf\n", a[j].name, a[j].scor);
            fclose(iesire);
            return 0;
        }
    }
}
