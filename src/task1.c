#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task1.h"

#define HUNDRED 100
#define FIFTY 50
#define TWOHUNDRED 200
#define THOUSAND 1000
#define EPSILON 0.0005

secretariat *citeste_secretariat(const char *nume_fisier) {
    // TODO(student): 1.1
    secretariat *s = calloc(1, sizeof(secretariat));
    s->studenti = calloc(TWOHUNDRED, sizeof(student));
    s->materii = calloc(TWOHUNDRED, sizeof(materie));
    s->inrolari = calloc(TWOHUNDRED, sizeof(inrolare));
    FILE *fisier = fopen(nume_fisier, "r");
    char *linie = malloc(HUNDRED * sizeof(char));
    // line = malloc(MAXSIZE);
    char *mod = malloc(HUNDRED * sizeof(char));
    int nr1 = 0, nr2 = 0, nr3 = 0;
    // nr elemente din fiecare vector din secretariat
    while (fgets(linie, HUNDRED, fisier)) {
        if (linie[0] == '[') {
            // strcpy(mod, linie);
            snprintf(mod, sizeof(mod), "%s", linie);
        } else {
            if (mod[1] == 'S') {
                // adaug id de student
                char *p = strtok(linie, ",");
                s->studenti[nr1].id = atoi(p);
                // adaug numele studentului
                p = strtok(NULL, ",");
                // strcpy(s->studenti[nr1].nume, p + 1);
                snprintf(s->studenti[nr1].nume, sizeof(s->studenti[nr1].nume), "%s", p + 1);
                // adaug anul de studiu
                p = strtok(NULL, ",");
                s->studenti[nr1].an_studiu = atoi(p);
                // adaug metoda de finantare
                p = strtok(NULL, ",");
                s->studenti[nr1].statut = p[1];
                // inicrementez pentru urmatoarea linie din fisier
                nr1++;
                // aloc mai multa memorie in vector
                s->studenti = (student*)realloc(s->studenti, (nr1 + 1) * sizeof(student));
            }
            if (mod[1] == 'M') {
                // aloc memorie ptr nume si nume_titular
                char nume[FIFTY], nume_titular[FIFTY];
                // adaug id materie
                char *p = strtok(linie, ",");
                s->materii[nr2].id = atoi(p);
                // adaug numele materiei
                p = strtok(NULL, ",");
                // strcpy(s->materii[nr2].nume, p + 1);
                // snprintf(s->materii[nr2].nume, sizeof(s->materii[nr2].nume), "%s", p + 1);
                snprintf(nume, sizeof(nume), "%s", p + 1);
                s->materii[nr2].nume = strdup(nume);
                // adaug nume titular
                p = strtok(NULL, ",");
                p[strlen(p) - 1] = '\0';
                // strcpy(s->materii[nr2].nume_titular, p + 1);
                // snprintf(s->materii[nr2].nume_titular, 3 * sizeof(s->materii[nr2].nume_titular), "%s", p + 1);
                snprintf(nume_titular, sizeof(nume_titular), "%s", p + 1);
                s->materii[nr2].nume_titular = strdup(nume_titular);
                // incrementez pentru urmatoarea linie din fisier
                nr2++;
                // aloc mai multa memorie in vector
                // s->materii = (materie*)realloc(s->materii, (nr2 + 1) * sizeof(materie));
            }
            if (mod[1] == 'I') {
                // adaug id student
                char *p = strtok(linie, " ");
                s->inrolari[nr3].id_student = atoi(p);
                // adaug id materie
                p = strtok(NULL, " ");
                s->inrolari[nr3].id_materie = atoi(p);
                // adaug notele
                p = strtok(NULL, " ");
                int i = 0;
               while (p) {
                    // int cif1 = 0, cif2 = 0, cif3 = 0;
                    // cif1 = p[0] - '0';
                    // cif2 = p[2] - '0';
                    // cif3 = p[3] - '0';
                    // s->inrolari[nr3].note[i] = (float)((cif1 * 100 + cif2 * 10+ cif3) / 100.0);
                    s->inrolari[nr3].note[i] = (float)atof(p);
                    // printf("%s ", p);
                    p = strtok(NULL, " ");
                    i++;
                    // e posibil sa fie gresita nota pentru ca imi afiseaza mai mult de doua zecimale
                }
                // incrementez pentru urmatoarea linie din fisier
                nr3++;
                // aloc mai multa memorie in vector
                s->inrolari = (inrolare*)realloc(s->inrolari, (nr3 + 1) * sizeof(inrolare));
            }
        }
    }
    free(mod);
    free(linie);
    s->nr_studenti = nr1;
    s->nr_materii = nr2;
    s->nr_inrolari = nr3;
    // s->studenti = realloc(s->studenti, s->nr_studenti * sizeof(student));
    // s->materii = realloc(s->materii, s->nr_materii * sizeof(materie));
    // s->inrolari = realloc(s->inrolari, s->nr_inrolari * sizeof(inrolare));
    for (int i = 0; i < nr1; i++) {
        float media = 0, suma = 0, nr = 0;
        s->studenti[i].medie_generala = 0;
        for (int j = 0; j < nr3; j++) {
            if (s->studenti[i].id == s->inrolari[j].id_student) {
                nr++;
                suma += s->inrolari[j].note[0] + s->inrolari[j].note[1] + s->inrolari[j].note[2];
            }
        }
        if (nr != 0) {
            media = (float)(suma / nr);
        }
        s->studenti[i].medie_generala = (float)((media + EPSILON) * THOUSAND / THOUSAND);
    }
    // printf("[STUDENTI]\n");
    // printf("%d %d %d\n", s->nr_studenti, s->nr_materii, s->nr_inrolari);
    // for (int i = 0; i < nr1; i++) {
    //     printf("%d, %s, %d, %c, %f\n", s->studenti[i].id, s->studenti[i].nume,
    // s->studenti[i].an_studiu, s->studenti[i].statut, s->studenti[i].medie_generala);
    // }
    // printf("[MATERII]\n");
    // for (int i = 0; i < nr2; i++) {
    //     printf("%d, %s, %s\n", s->materii[i].id, s->materii[i].nume, s->materii[i].nume_titular);
    // }
    // printf("[INROLARI]\n");
    // for (int i = 0; i < nr3; i++) {
    //     printf("%d, %d, %f %f %f\n", s->inrolari[i].id_student,
    // s->inrolari[i].id_materie, s->inrolari[i].note[0], s->inrolari[i].note[1], s->inrolari[i].note[2]);
    // }
    return s;
}

void adauga_student(secretariat *s, int id, char *nume, int an_studiu, char statut, float medie_generala) {
    // TODO(student): 1.2
    s->nr_studenti++;
    s->studenti[s->nr_studenti - 1].id = id;
    // strcpy(s->studenti[s->nr_studenti - 1].nume, nume);
    snprintf(s->studenti[s->nr_studenti - 1].nume, sizeof(s->studenti[s->nr_studenti - 1].nume), "%s", nume);
    s->studenti[s->nr_studenti - 1].an_studiu = an_studiu;
    s->studenti[s->nr_studenti - 1].statut = statut;
    s->studenti[s->nr_studenti - 1].medie_generala = medie_generala;
}

void elibereaza_secretariat(secretariat **s) {
    // trbuie mai intai sa eliberez fiecare vector din secretariat
    for (int i = 0; i < (*s)->nr_materii; i++) {
        free((*s)->materii[i].nume);
        free((*s)->materii[i].nume_titular);
    }
    free((*s)->studenti);
    free((*s)->materii);
    free((*s)->inrolari);
    free((*s));
    (*s) = NULL;
    // TODO(student): 1.3
}
