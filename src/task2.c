#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task2.h"

#define HUNDRED 100
#define FIFTEEN 15
#define TWOHUNDRED 200
#define TWENTY 20
#define FIFTY 50
#define TEN 10
#define EPSILON 0.0005
#define THOUSAND 1000

void SELECT(secretariat *s, char *str) {
    // cand fac conditiile trebuie sa tin cont de tipul de date
        if (strstr(str, "studenti") != 0) {
            for (int i = 0; i < s->nr_studenti; i++) {
                if (strchr(str, '*') != 0) {
                printf("%d %s %d %c %.2f", s->studenti[i].id, s->studenti[i].nume,
                s->studenti[i].an_studiu, s->studenti[i].statut, s->studenti[i].medie_generala);
                } else {
                    // copie a sirului
                    char cstr[HUNDRED] = "\0";
                    snprintf(cstr, sizeof(cstr), "%s", str);
                    // primul cuvant
                    char *camp = strtok(cstr, " ");
                    // separ campurile
                    camp = strtok(NULL, " ");
                    while (camp && strstr(camp, "FROM") == 0) {
                        if (camp[strlen(camp) - 1] == ',') {
                            if (strstr(camp, "id") != 0) {
                                printf("%d ", s->studenti[i].id);
                            }
                            if (strstr(camp, "nume") != 0) {
                                printf("%s ", s->studenti[i].nume);
                            }
                            if (strstr(camp, "an_studiu") != 0) {
                                printf("%d ", s->studenti[i].an_studiu);
                            }
                            if (strstr(camp, "statut") != 0) {
                                printf("%c ", s->studenti[i].statut);
                            }
                            if (strstr(camp, "medie_generala") != 0) {
                                printf("%.2f ", s->studenti[i].medie_generala);
                            }
                        } else {
                            if (strstr(camp, "id") != 0) {
                                printf("%d", s->studenti[i].id);
                            }
                            if (strstr(camp, "nume") != 0) {
                                printf("%s", s->studenti[i].nume);
                            }
                            if (strstr(camp, "an_studiu") != 0) {
                                printf("%d", s->studenti[i].an_studiu);
                            }
                            if (strstr(camp, "statut") != 0) {
                              printf("%c", s->studenti[i].statut);
                            }
                          if (strstr(camp, "medie_generala") != 0) {
                                printf("%.2f", s->studenti[i].medie_generala);
                            }
                        }
                        camp = strtok(NULL, " ");
                    }
                }
                printf("\n");
            }
        }
        if (strstr(str, "materii") != 0) {
                for (int i = 0; i < s->nr_materii; i++) {
                    if (strchr(str, '*') != 0) {
                        printf("%d %s %s", s->materii[i].id, s->materii[i].nume,
                        s->materii[i].nume_titular);
                    } else {
                        // copie a sirului
                        char cstr[HUNDRED] = "\0";
                        snprintf(cstr, sizeof(cstr), "%s", str);
                        // primul cuvant
                        char *camp = strtok(cstr, " ");
                        // separ campurile
                        camp = strtok(NULL, " ");
                        while (camp && strstr(camp, "FROM") == 0) {
                            if (camp[strlen(camp) - 1] == ',') {
                                if (strstr(camp, "id") != 0) {
                                    printf("%d ", s->materii[i].id);
                                }
                                if (strstr(camp, "nume") != 0 && strstr(camp, "nume_titular") == 0) {
                                    printf("%s ", s->materii[i].nume);
                                }
                                if (strstr(camp, "nume_titular") != 0) {
                                    printf("%s ", s->materii[i].nume_titular);
                                }
                            } else {
                                if (strstr(camp, "id") != 0) {
                                    printf("%d", s->materii[i].id);
                                }
                                if (strstr(camp, "nume") != 0 && strstr(camp, "nume_titular") == 0) {
                                    printf("%s", s->materii[i].nume);
                                }
                                if (strstr(camp, "nume_titular") != 0) {
                                    printf("%s", s->materii[i].nume_titular);
                                }
                            }
                            camp = strtok(NULL, " ");
                        }
                    }
                    printf("\n");
                }
        }
        if (strstr(str, "inrolari") != 0) {
            for (int i = 0; i < s->nr_inrolari; i++) {
                if (strchr(str, '*') != 0) {
                    printf("%d %d %0.2f %0.2f %0.2f", s->inrolari[i].id_student, s->inrolari[i].id_materie,
                    s->inrolari[i].note[0], s->inrolari[i].note[1], s->inrolari[i].note[2]);
                } else {
                    // copie a sirului
                    char cstr[HUNDRED] = "\0";
                    snprintf(cstr, sizeof(cstr), "%s", str);
                    // primul cuvant
                    char *camp = strtok(cstr, " ");
                    // separ campurile
                    camp = strtok(NULL, " ");
                    while (camp && strstr(camp, "FROM") == 0) {
                        if (camp[strlen(camp) - 1] == ',') {
                            if (strstr(camp, "id_student") != 0) {
                                printf("%d ", s->inrolari[i].id_student);
                            }
                            if (strstr(camp, "id_materie") != 0) {
                                printf("%d ", s->inrolari[i].id_materie);
                            }
                            if (strstr(camp, "note") != 0) {
                                printf("%0.2f %0.2f %0.2f ", s->inrolari[i].note[0],
                                s->inrolari[i].note[1], s->inrolari[i].note[2]);
                            }
                        } else {
                            if (strstr(camp, "id_student") != 0) {
                                printf("%d", s->inrolari[i].id_student);
                            }
                            if (strstr(camp, "id_materie") != 0) {
                                printf("%d", s->inrolari[i].id_materie);
                            }
                            if (strstr(camp, "note") != 0) {
                                printf("%0.2f %0.2f %0.2f", s->inrolari[i].note[0],
                                s->inrolari[i].note[1], s->inrolari[i].note[2]);
                            }
                        }
                        camp = strtok(NULL, " ");
                    }
                }
                printf("\n");
            }
        }
}



int compare_studenti(secretariat *s, char *field, char *comparatie, char* valoare, int nr) {
    float valfloat = (float)0.0;
    int valint = 0;
    char valchar = '\0';
    if (strstr(field, "id") != 0 || strstr(field, "an_studiu") != 0) {
        valint = atoi(valoare);
    }
    if (strstr(field, "statut") != 0) {
        valchar = valoare[0];
    }
    if (strstr(field, "medie_generala") != 0) {
        valfloat = (float)(atof(valoare) + 2 *  EPSILON);
    }
    // id
    if (strstr(field, "id") != 0) {
        if (strstr(comparatie, "<=") != 0) {
            if (s->studenti[nr].id <= valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">=") != 0) {
            if (s->studenti[nr].id >= valint) {
                return 1;
            }
        } else if (strstr(comparatie, "!=") != 0) {
            if (s->studenti[nr].id != valint) {
                return 1;
            }
        } else if (strstr(comparatie, "=") != 0) {
            if (s->studenti[nr].id == valint) {
                return 1;
            }
        } else if (strstr(comparatie, "<") != 0) {
            if (s->studenti[nr].id < valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">") != 0) {
            if (s->studenti[nr].id > valint) {
                return 1;
            }
        }
    }
    // an_studiu
    if (strstr(field, "an_studiu") != 0) {
        if (strstr(comparatie, "<=") != 0) {
            if (s->studenti[nr].an_studiu <= valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">=") != 0) {
            if (s->studenti[nr].an_studiu >= valint) {
                return 1;
            }
        } else if (strstr(comparatie, "!=") != 0) {
            if (s->studenti[nr].an_studiu != valint) {
                return 1;
            }
        } else if (strstr(comparatie, "=") != 0) {
            if (s->studenti[nr].an_studiu == valint) {
                return 1;
            }
        } else if (strstr(comparatie, "<") != 0) {
            if (s->studenti[nr].an_studiu < valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">") != 0) {
            if (s->studenti[nr].an_studiu > valint) {
                return 1;
            }
        }
    }
    // statut
    if (strstr(field, "statut") != 0) {
        if (strstr(comparatie, "<=") != 0) {
            if (s->studenti[nr].statut <= valchar) {
                return 1;
            }
        } else if (strstr(comparatie, ">=") != 0) {
            if (s->studenti[nr].statut >= valchar) {
                return 1;
            }
        } else if (strstr(comparatie, "!=") != 0) {
            if (s->studenti[nr].statut != valchar) {
                return 1;
            }
        } else if (strstr(comparatie, "=") != 0) {
            if (s->studenti[nr].statut == valchar) {
                return 1;
            }
        } else if (strstr(comparatie, "<") != 0) {
            if (s->studenti[nr].statut < valchar) {
                return 1;
            }
        } else if (strstr(comparatie, ">") != 0) {
            if (s->studenti[nr].statut > valchar) {
                return 1;
            }
        }
    }
    // medie_generala
    if (strstr(field, "medie_generala") != 0) {
        if (strstr(comparatie, "<=") != 0) {
            if (s->studenti[nr].medie_generala <= valfloat) {
                return 1;
            }
        } else if (strstr(comparatie, ">=") != 0) {
            if (s->studenti[nr].medie_generala >= valfloat) {
                return 1;
            }
        } else if (strstr(comparatie, "!=") != 0) {
            if (s->studenti[nr].medie_generala != valfloat) {
                return 1;
            }
        } else if (strstr(comparatie, "=") != 0) {
            if (s->studenti[nr].medie_generala == valfloat) {
                return 1;
            }
        } else if (strstr(comparatie, "<") != 0) {
            if (s->studenti[nr].medie_generala < valfloat) {
                return 1;
            }
        } else if (strstr(comparatie, ">") != 0) {
            if (s->studenti[nr].medie_generala > valfloat) {
                return 1;
            }
        }
    }
    return 0;
}

int compare_materii(secretariat *s, char *field, char *comparatie, char *valoare, int nr) {
    float valfloat = (float)0.0;
    int valint = 0;
    char valchar = '\0';
    if (strstr(field, "id") != 0 || strstr(field, "an_studiu") != 0) {
        valint = atoi(valoare);
    }
    if (strstr(field, "statut") != 0) {
        valchar = valoare[0];
    }
    if (strstr(field, "medie_generala") != 0) {
        valfloat = (float)(atof(valoare) + 2 *  EPSILON);
    }
    // id
    if (strstr(field, "id") != 0) {
        if (strstr(comparatie, "<=") != 0) {
            if (s->materii[nr].id <= valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">=") != 0) {
            if (s->materii[nr].id >= valint) {
                return 1;
            }
        } else if (strstr(comparatie, "!=") != 0) {
            if (s->materii[nr].id != valint) {
                return 1;
            }
        } else if (strstr(comparatie, "=") != 0) {
            if (s->materii[nr].id == valint) {
                return 1;
            }
        } else if (strstr(comparatie, "<") != 0) {
            if (s->materii[nr].id < valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">") != 0) {
            if (s->materii[nr].id > valint) {
                return 1;
            }
        }
    }
    return 0;
}

int compare_inrolari(secretariat *s, char *field, char *comparatie, char *valoare, int nr) {
    float valfloat = (float)0.0;
    int valint = 0;
    char valchar = '\0';
    if (strstr(field, "id") != 0 || strstr(field, "an_studiu") != 0) {
        valint = atoi(valoare);
    }
    if (strstr(field, "statut") != 0) {
        valchar = valoare[0];
    }
    if (strstr(field, "medie_generala") != 0) {
        valfloat = (float)(atof(valoare) + 2 *  EPSILON);
    }
    // id_student
    if (strstr(field, "id_student") != 0) {
        if (strstr(comparatie, "<=") != 0) {
            if (s->inrolari[nr].id_student <= valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">=") != 0) {
            if (s->inrolari[nr].id_student >= valint) {
                return 1;
            }
        } else if (strstr(comparatie, "!=") != 0) {
            if (s->inrolari[nr].id_student != valint) {
                return 1;
            }
        } else if (strstr(comparatie, "=") != 0) {
            if (s->inrolari[nr].id_student == valint) {
                return 1;
            }
        } else if (strstr(comparatie, "<") != 0) {
            if (s->inrolari[nr].id_student < valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">") != 0) {
            if (s->inrolari[nr].id_student > valint) {
                return 1;
            }
        }
    }
    // id_materie
    if (strstr(field, "id_materie") != 0) {
        if (strstr(comparatie, "<=") != 0) {
            if (s->inrolari[nr].id_materie <= valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">=") != 0) {
            if (s->inrolari[nr].id_materie >= valint) {
                return 1;
            }
        } else if (strstr(comparatie, "!=") != 0) {
            if (s->inrolari[nr].id_materie != valint) {
                return 1;
            }
        } else if (strstr(comparatie, "=") != 0) {
            if (s->inrolari[nr].id_materie == valint) {
                return 1;
            }
        } else if (strstr(comparatie, "<") != 0) {
            if (s->inrolari[nr].id_materie < valint) {
                return 1;
            }
        } else if (strstr(comparatie, ">") != 0) {
            if (s->inrolari[nr].id_materie > valint) {
                return 1;
            }
        }
    }
    return 0;
}

void SELECT_2condition(secretariat *s, char *str) {
    char field1[FIFTY], field2[FIFTY], comparatie1[TEN], comparatie2[TEN], valoare1[FIFTY], valoare2[FIFTY];
    // WHERE
    char *p = strtok(strstr(str, "WHERE"), " ");
    // field1
    p = strtok(NULL, " ");
    snprintf(field1, sizeof(field1), "%s", p);
    // comparatie1
    p = strtok(NULL, " ");
    snprintf(comparatie1, sizeof(comparatie1), "%s", p);
    // valoare1
    p = strtok(NULL, " ");
    snprintf(valoare1, sizeof(valoare1), "%s", p);
    // AND
    p = strtok(NULL, " ");
    // field2
    p = strtok(NULL, " ");
    snprintf(field2, sizeof(field2), "%s", p);
    // comparatie2
    p = strtok(NULL, " ");
    snprintf(comparatie2, sizeof(comparatie2), "%s", p);
    // valoare 2
    p = strtok(NULL, " ");
    snprintf(valoare2, sizeof(valoare2), "%s", p);
    // studenti
    if (strstr(str, "studenti") != 0) {
        for (int i = 0; i < s->nr_studenti; i++) {
            if (compare_studenti(s, field1, comparatie1, valoare1, i) != 0 &&
            compare_studenti(s, field2, comparatie2, valoare2, i) != 0) {
                if (strchr(str, '*') != 0) {
                printf("%d %s %d %c %.2f", s->studenti[i].id, s->studenti[i].nume,
                s->studenti[i].an_studiu, s->studenti[i].statut, s->studenti[i].medie_generala);
                } else {
                    // copie a sirului
                    char cstr[HUNDRED] = "\0";
                    snprintf(cstr, sizeof(cstr), "%s", str);
                    // primul cuvant
                    char *camp = strtok(cstr, " ");
                    // separ campurile
                    camp = strtok(NULL, " ");
                    while (camp && strstr(camp, "FROM") == 0) {
                        if (camp[strlen(camp) - 1] == ',') {
                            if (strstr(camp, "id") != 0) {
                                printf("%d ", s->studenti[i].id);
                            }
                            if (strstr(camp, "nume") != 0) {
                                printf("%s ", s->studenti[i].nume);
                            }
                            if (strstr(camp, "an_studiu") != 0) {
                                printf("%d ", s->studenti[i].an_studiu);
                            }
                            if (strstr(camp, "statut") != 0) {
                                printf("%c ", s->studenti[i].statut);
                            }
                            if (strstr(camp, "medie_generala") != 0) {
                                printf("%.2f ", s->studenti[i].medie_generala);
                            }
                        } else {
                            if (strstr(camp, "id") != 0) {
                                printf("%d", s->studenti[i].id);
                            }
                            if (strstr(camp, "nume") != 0) {
                                printf("%s", s->studenti[i].nume);
                            }
                            if (strstr(camp, "an_studiu") != 0) {
                                printf("%d", s->studenti[i].an_studiu);
                            }
                            if (strstr(camp, "statut") != 0) {
                              printf("%c", s->studenti[i].statut);
                            }
                          if (strstr(camp, "medie_generala") != 0) {
                                printf("%.2f", s->studenti[i].medie_generala);
                            }
                        }
                        camp = strtok(NULL, " ");
                    }
                }
                printf("\n");
            }
        }
    }
    // materii
    if (strstr(str, "materii") != 0) {
        for (int i = 0; i < s->nr_materii; i++) {
            if (compare_materii(s, field1, comparatie1, valoare1, i) != 0 &&
            compare_materii(s, field2, comparatie2, valoare2, i) != 0) {
                if (strchr(str, '*') != 0) {
                        printf("%d %s %s", s->materii[i].id, s->materii[i].nume,
                        s->materii[i].nume_titular);
                    } else {
                        // copie a sirului
                        char cstr[HUNDRED] = "\0";
                        snprintf(cstr, sizeof(cstr), "%s", str);
                        // primul cuvant
                        char *camp = strtok(cstr, " ");
                        // separ campurile
                        camp = strtok(NULL, " ");
                        while (camp && strstr(camp, "FROM") == 0) {
                            if (camp[strlen(camp) - 1] == ',') {
                                if (strstr(camp, "id") != 0) {
                                    printf("%d ", s->materii[i].id);
                                }
                                if (strstr(camp, "nume") != 0 && strstr(camp, "nume_titular") == 0) {
                                    printf("%s ", s->materii[i].nume);
                                }
                                if (strstr(camp, "nume_titular") != 0) {
                                    printf("%s ", s->materii[i].nume_titular);
                                }
                            } else {
                                if (strstr(camp, "id") != 0) {
                                    printf("%d", s->materii[i].id);
                                }
                                if (strstr(camp, "nume") != 0 && strstr(camp, "nume_titular") == 0) {
                                    printf("%s", s->materii[i].nume);
                                }
                                if (strstr(camp, "nume_titular") != 0) {
                                    printf("%s", s->materii[i].nume_titular);
                                }
                            }
                            camp = strtok(NULL, " ");
                        }
                    }
                    printf("\n");
            }
        }
    }
    // inrolari
    if (strstr(str, "inrolari") != 0) {
        for (int i = 0; i < s->nr_inrolari; i++) {
            if (compare_inrolari(s , field1, comparatie1, valoare1, i) != 0 &&
            compare_inrolari(s, field2, comparatie2, valoare2, i) != 0) {
                if (strchr(str, '*') != 0) {
                    printf("%d %d %0.2f %0.2f %0.2f", s->inrolari[i].id_student, s->inrolari[i].id_materie,
                    s->inrolari[i].note[0], s->inrolari[i].note[1], s->inrolari[i].note[2]);
                } else {
                    // copie a sirului
                    char cstr[HUNDRED] = "\0";
                    snprintf(cstr, sizeof(cstr), "%s", str);
                    // primul cuvant
                    char *camp = strtok(cstr, " ");
                    // separ campurile
                    camp = strtok(NULL, " ");
                    while (camp && strstr(camp, "FROM") == 0) {
                        if (camp[strlen(camp) - 1] == ',') {
                            if (strstr(camp, "id_student") != 0) {
                                printf("%d ", s->inrolari[i].id_student);
                            }
                            if (strstr(camp, "id_materie") != 0) {
                                printf("%d ", s->inrolari[i].id_materie);
                            }
                            if (strstr(camp, "note") != 0) {
                                printf("%0.2f %0.2f %0.2f ", s->inrolari[i].note[0],
                                s->inrolari[i].note[1], s->inrolari[i].note[2]);
                            }
                        } else {
                            if (strstr(camp, "id_student") != 0) {
                                printf("%d", s->inrolari[i].id_student);
                            }
                            if (strstr(camp, "id_materie") != 0) {
                                printf("%d", s->inrolari[i].id_materie);
                            }
                            if (strstr(camp, "note") != 0) {
                                printf("%0.2f %0.2f %0.2f", s->inrolari[i].note[0],
                                s->inrolari[i].note[1], s->inrolari[i].note[2]);
                            }
                        }
                        camp = strtok(NULL, " ");
                    }
                }
                printf("\n");
            }
        }
    }
}

void medie_fara(secretariat *s, int id, int inrolare) {
        float media = 0, suma = 0, nr = 0;
        for (int j = 0; j < s->nr_inrolari; j++) {
            if (id == s->inrolari[j].id_student && s->inrolari[j].id_materie != inrolare) {
                nr++;
                suma += s->inrolari[j].note[0] + s->inrolari[j].note[1] + s->inrolari[j].note[2];
            }
        }
        if (nr != 0) {
            media = (float)(suma / nr);
            s->studenti[id].medie_generala = (float)((media + EPSILON) * THOUSAND / THOUSAND);
        } else {
            s->studenti[id].medie_generala = 0;
        }
}

void medie_finala(secretariat *s, int id) {
        float media = 0, suma = 0, nr = 0;
        for (int j = 0; j < s->nr_inrolari; j++) {
            if (id == s->inrolari[j].id_student) {
                nr++;
                suma += s->inrolari[j].note[0] + s->inrolari[j].note[1] + s->inrolari[j].note[2];
            }
        }
        if (nr != 0) {
            media = (float)(suma / nr);
            s->studenti[id].medie_generala = (float)((media + EPSILON) * THOUSAND / THOUSAND);
        } else {
            s->studenti[id].medie_generala = 0;
        }
}

void DELETE(secretariat *s, char *str) {
    char field[TWENTY], comparatie[TEN], valoare[TWENTY], copy[HUNDRED];
    // copie  a lui str
    snprintf(copy, sizeof(copy), "%s", str);
    // WHERE
    char *p = strtok(strstr(copy, "WHERE"), " ");
    // field
    p = strtok(NULL, " ");
    snprintf(field, sizeof(field), "%s", p);
    // comparatie
    p = strtok(NULL, " ");
    snprintf(comparatie, sizeof(comparatie), "%s", p);
    // valoare
    p = strtok(NULL, " ");
    snprintf(valoare, sizeof(valoare), "%s", p);
    // studenti
    if (strstr(str, "studenti") != 0) {
        for (int i = 0; i < s->nr_studenti; i++) {
            if (compare_studenti(s, field, comparatie, valoare, i) != 0) {
                for (int j = i; j < s->nr_studenti - 1; j++) {
                    s->studenti[j] = s->studenti[j + 1];
                }
                i--;
                s->nr_studenti = s->nr_studenti - 1;
            }
        }
    }
    // materii
    if (strstr(str, "materii") != 0) {
        for (int i = 0; i < s->nr_materii; i++) {
            if (compare_materii(s, field, comparatie, valoare, i) != 0) {
                free(s->materii[i].nume);
                free(s->materii[i].nume_titular);
                for (int j = i; j < s->nr_studenti - 1; j++) {
                    s->materii[j] = s->materii[j + 1];
                }
                i--;
                s->nr_materii = s->nr_materii - 1;
            }
        }
    }
    // inrolari
    if (strstr(str, "inrolari") != 0) {
        for (int i = 0; i < s->nr_inrolari; i++) {
            if (compare_inrolari(s, field, comparatie, valoare, i) != 0) {
                // printf("%f ", s->studenti[s->inrolari[i].id_student].medie_generala);
                medie_fara(s, s->inrolari[i].id_student, s->inrolari[i].id_materie);
                // printf("%d %f\n", s->studenti[s->inrolari[i].id_student].id,
                // s->studenti[s->inrolari[i].id_student].medie_generala);
                for (int j = i; j < s->nr_inrolari - 1; j++) {
                    s->inrolari[j] = s->inrolari[j + 1];
                }
                i--;
                s->nr_inrolari = s->nr_inrolari - 1;
            }
        }
    }
}

void DELETE_2condition(secretariat *s, char *str) {
        char *p = strtok(strstr(str, "WHERE"), " ");  // WHERE
    char field1[TWENTY], comparatie1[TEN], valoare1[TWENTY];
    char field2[TWENTY], comparatie2[TEN], valoare2[TWENTY];
    // field1
    p = strtok(NULL, " ");
    snprintf(field1, sizeof(field1), "%s", p);
    // comparatie1
    p = strtok(NULL, " ");
    snprintf(comparatie1, sizeof(comparatie1), "%s", p);
    // valoare1
    p = strtok(NULL, " ");
    snprintf(valoare1, sizeof(valoare1), "%s", p);
    // AND
    p = strtok(NULL, " ");
    // field2
    p = strtok(NULL, " ");
    snprintf(field2, sizeof(field2), "%s", p);
    // comparatie2
    p = strtok(NULL, " ");
    snprintf(comparatie2, sizeof(comparatie2), "%s", p);
    // valoare2
    p = strtok(NULL, " ");
    snprintf(valoare2, sizeof(valoare2), "%s", p);
    // studenti
    if (strstr(str, "studenti") != 0) {
        for (int i = 0; i < s->nr_studenti; i++) {
            if (compare_studenti(s, field1, comparatie1, valoare1, i) != 0
            && compare_studenti(s, field2, comparatie2, valoare2, i) != 0) {
                for (int j = i; j < s->nr_studenti - 1; j++) {
                    s->studenti[j] = s->studenti[j + 1];
                }
                i--;
                s->nr_studenti = s->nr_studenti - 1;
            }
        }
    }
    // materii
    if (strstr(str, "materii") != 0) {
        for (int i = 0; i < s->nr_materii; i++) {
            if (compare_materii(s, field1, comparatie1, valoare1, i) != 0
            && compare_materii(s, field2, comparatie2, valoare2, i) != 0) {
                free(s->materii[i].nume);
                free(s->materii[i].nume_titular);
                for (int j = i; j < s->nr_inrolari - 1; j++) {
                    s->materii[j] = s->materii[j + 1];
                }
                i--;
                s->nr_materii = s->nr_materii - 1;
            }
        }
    }
    // inrolari
    if (strstr(str, "inrolari") != 0) {
        for (int i = 0; i < s->nr_inrolari; i++) {
            if (compare_inrolari(s, field1, comparatie1, valoare1, i) != 0
            && compare_inrolari(s, field2, comparatie2, valoare2, i) != 0) {
                medie_fara(s, s->inrolari[i].id_student, s->inrolari[i].id_materie);
                for (int j = i; j < s->nr_studenti - 1; j++) {
                    s->inrolari[j] = s->inrolari[j + 1];
                }
                i--;
                s->nr_inrolari = s->nr_inrolari - 1;
            }
        }
    }
}

void SELECT_condition(secretariat *s, char *str) {
    char field[FIFTY], comparatie[TEN], valoare[FIFTY];
    // WHERE
    char *p = strtok(strstr(str, "WHERE"), " ");
    // field
    p = strtok(NULL, " ");
    snprintf(field, sizeof(field), "%s", p);
    // comparatie
    p = strtok(NULL, " ");
    snprintf(comparatie, sizeof(comparatie), "%s", p);
    // valoare
    p = strtok(NULL, " ");
    snprintf(valoare, sizeof(valoare), "%s", p);
    // studenti
    if (strstr(str, "studenti") != 0) {
        for (int i = 0; i < s->nr_studenti; i++) {
            if (compare_studenti(s, field, comparatie, valoare, i) != 0) {
                if (strchr(str, '*') != 0) {
                printf("%d %s %d %c %.2f", s->studenti[i].id, s->studenti[i].nume,
                s->studenti[i].an_studiu, s->studenti[i].statut, s->studenti[i].medie_generala);
                } else {
                    // copie a sirului
                    char cstr[HUNDRED] = "\0";
                    snprintf(cstr, sizeof(cstr), "%s", str);
                    // primul cuvant
                    char *camp = strtok(cstr, " ");
                    // separ campurile
                    camp = strtok(NULL, " ");
                    while (camp && strstr(camp, "FROM") == 0) {
                        if (camp[strlen(camp) - 1] == ',') {
                            if (strstr(camp, "id") != 0) {
                                printf("%d ", s->studenti[i].id);
                            }
                            if (strstr(camp, "nume") != 0) {
                                printf("%s ", s->studenti[i].nume);
                            }
                            if (strstr(camp, "an_studiu") != 0) {
                                printf("%d ", s->studenti[i].an_studiu);
                            }
                            if (strstr(camp, "statut") != 0) {
                                printf("%c ", s->studenti[i].statut);
                            }
                            if (strstr(camp, "medie_generala") != 0) {
                                printf("%.2f ", s->studenti[i].medie_generala);
                            }
                        } else {
                            if (strstr(camp, "id") != 0) {
                                printf("%d", s->studenti[i].id);
                            }
                            if (strstr(camp, "nume") != 0) {
                                printf("%s", s->studenti[i].nume);
                            }
                            if (strstr(camp, "an_studiu") != 0) {
                                printf("%d", s->studenti[i].an_studiu);
                            }
                            if (strstr(camp, "statut") != 0) {
                              printf("%c", s->studenti[i].statut);
                            }
                          if (strstr(camp, "medie_generala") != 0) {
                                printf("%.2f", s->studenti[i].medie_generala);
                            }
                        }
                        camp = strtok(NULL, " ");
                    }
                }
                printf("\n");
            }
        }
    }
    // materii
    if (strstr(str, "materii") != 0) {
        for (int i = 0; i < s->nr_materii; i++) {
            if (compare_materii(s, field, comparatie, valoare, i) != 0) {
                if (strchr(str, '*') != 0) {
                        printf("%d %s %s", s->materii[i].id, s->materii[i].nume,
                        s->materii[i].nume_titular);
                    } else {
                        // copie a sirului
                        char cstr[HUNDRED] = "\0";
                        snprintf(cstr, sizeof(cstr), "%s", str);
                        // primul cuvant
                        char *camp = strtok(cstr, " ");
                        // separ campurile
                        camp = strtok(NULL, " ");
                        while (camp && strstr(camp, "FROM") == 0) {
                            if (camp[strlen(camp) - 1] == ',') {
                                if (strstr(camp, "id") != 0) {
                                    printf("%d ", s->materii[i].id);
                                }
                                if (strstr(camp, "nume") != 0 && strstr(camp, "nume_titular") == 0) {
                                    printf("%s ", s->materii[i].nume);
                                }
                                if (strstr(camp, "nume_titular") != 0) {
                                    printf("%s ", s->materii[i].nume_titular);
                                }
                            } else {
                                if (strstr(camp, "id") != 0) {
                                    printf("%d", s->materii[i].id);
                                }
                                if (strstr(camp, "nume") != 0 && strstr(camp, "nume_titular") == 0) {
                                    printf("%s", s->materii[i].nume);
                                }
                                if (strstr(camp, "nume_titular") != 0) {
                                    printf("%s", s->materii[i].nume_titular);
                                }
                            }
                            camp = strtok(NULL, " ");
                        }
                    }
                    printf("\n");
            }
        }
    }
    // inrolari
    if (strstr(str, "inrolari") != 0) {
        for (int i = 0; i < s->nr_inrolari; i++) {
            if (compare_inrolari(s, field, comparatie, valoare, i) != 0) {
                if (strchr(str, '*') != 0) {
                    printf("%d %d %0.2f %0.2f %0.2f", s->inrolari[i].id_student, s->inrolari[i].id_materie,
                    s->inrolari[i].note[0], s->inrolari[i].note[1], s->inrolari[i].note[2]);
                } else {
                    // copie a sirului
                    char cstr[HUNDRED] = "\0";
                    snprintf(cstr, sizeof(cstr), "%s", str);
                    // primul cuvant
                    char *camp = strtok(cstr, " ");
                    // separ campurile
                    camp = strtok(NULL, " ");
                    while (camp && strstr(camp, "FROM") == 0) {
                        if (camp[strlen(camp) - 1] == ',') {
                            if (strstr(camp, "id_student") != 0) {
                                printf("%d ", s->inrolari[i].id_student);
                            }
                            if (strstr(camp, "id_materie") != 0) {
                                printf("%d ", s->inrolari[i].id_materie);
                            }
                            if (strstr(camp, "note") != 0) {
                                printf("%0.2f %0.2f %0.2f ", s->inrolari[i].note[0],
                                s->inrolari[i].note[1], s->inrolari[i].note[2]);
                            }
                        } else {
                            if (strstr(camp, "id_student") != 0) {
                                printf("%d", s->inrolari[i].id_student);
                            }
                            if (strstr(camp, "id_materie") != 0) {
                                printf("%d", s->inrolari[i].id_materie);
                            }
                            if (strstr(camp, "note") != 0) {
                                printf("%0.2f %0.2f %0.2f", s->inrolari[i].note[0],
                                s->inrolari[i].note[1], s->inrolari[i].note[2]);
                            }
                        }
                        camp = strtok(NULL, " ");
                    }
                }
                printf("\n");
            }
        }
    }
}

secretariat *UPDATE_condition(secretariat *s, char *str) {
    char camp[FIFTY], valoare_noua[FIFTY];
    char field[FIFTY], comparatie[TEN], valoare[TWENTY];
    char copy[TWOHUNDRED], copy2[TWOHUNDRED];
    // copii a stringului initial
    snprintf(copy, sizeof(copy), "%s", str);
    snprintf(copy2, sizeof(copy2), "%s", str);
    // incarc conditia
    // WHERE
    char *p = strtok(strstr(copy, "WHERE"), " ");
    // field
    p = strtok(NULL, " ");
    snprintf(field, sizeof(field), "%s", p);
    // comparatie
    p = strtok(NULL, " ");
    snprintf(comparatie, sizeof(comparatie), "%s", p);
    // valoare
    p = strtok(NULL, " ");
    snprintf(valoare, sizeof(valoare), "%s", p);
    // incarc campurile ce trebuiesc schimbate
    // SET
    p = strtok(strstr(str, "SET"), " ");
    // camp
    p = strtok(NULL, " ");
    snprintf(camp, sizeof(camp), "%s", p);
    // =
    p = strtok(NULL, " ");
    // valoare_noua
    p = strtok(NULL, " ");
    snprintf(valoare_noua, sizeof(valoare_noua), "%s", p);
    // salvez valoarea noua in variabila potrivita
    int valint = 0;
    char valchar = '\0', valstr[HUNDRED];
    float valfloat = (float)0.0;
    float nota1 = (float)0.0, nota2 = (float)0.0, nota3 = (float)0.0;
    if (strstr(camp, "nume") != 0) {
        p = strtok(copy2, "\"");
        p = strtok(NULL, "\"");  // numele
        snprintf(valstr, sizeof(valstr), "%s", p);
    }
    // studenti
    if (strstr(str, "studenti") != 0) {
        if (strstr(camp, "id") != 0 || strstr(camp, "an_studiu") != 0) {
            valint = atoi(valoare_noua);
        }
        if (strstr(camp, "statut") != 0) {
            valchar = valoare_noua[0];
        }
        if (strstr(camp, "medie_generala") != 0 || strstr(camp, "note") != 0) {
            valfloat = (float)(atof(valoare_noua));
        }
    }
    // materii
    if (strstr(str, "materii") != 0) {
        if (strstr(camp, "id") != 0) {
            valint = atoi(valoare_noua);
        }
    }
    // innrolari
    if (strstr(str, "inrolari") != 0) {
        if (strstr(camp, "id") != 0) {
            valint = atoi(valoare_noua);
        }
        if (strstr(camp, "note") != 0) {
            nota1 = (float)(atof(valoare_noua));
            // nota2
            p = strtok(NULL, " ");
            nota2 = (float)(atof(p));
            // nota3
            p = strtok(NULL, " ");
            nota3 = (float)(atof(p));
        }
    }
    // actualizez in functie de conditie
    // studenti
    if (strstr(str, "studenti") != 0) {
        for (int i = 0; i < s->nr_studenti; i++) {
            if (compare_studenti(s, field, comparatie, valoare, i) != 0) {
                if (strstr(camp, "id") != 0) {
                    s->studenti[i].id = valint;
                }
                if (strstr(camp, "nume") != 0) {
                    snprintf(s->studenti[i].nume, sizeof(s->studenti[i].nume), "%s", valstr);
                }
                if (strstr(camp, "an_studiu") != 0) {
                    s->studenti[i].an_studiu = valint;
                }
                if (strstr(camp, "statut") != 0) {
                    s->studenti[i].statut = valchar;
                }
                if (strstr(camp, "medie_generala") != 0) {
                    s->studenti[i].medie_generala = valfloat;
                }
            }
        }
    }
    // materii
    if (strstr(str, "materii") != 0) {
        for (int i = 0; i < s->nr_materii; i++) {
            if (compare_materii(s, field, comparatie, valoare, i) != 0) {
                if (strstr(camp, "id") != 0) {
                    s->materii[i].id = valint;
                }
                if (strstr(camp, "nume_titular") != 0) {
                    snprintf(s->materii[i].nume_titular, sizeof(s->materii[i].nume_titular), "%s", valstr);
                } else if (strstr(camp, "nume") != 0) {
                    snprintf(s->materii[i].nume, sizeof(s->materii[i].nume), "%s", valstr);
                }
            }
        }
    }
    // inrolari
    if (strstr(str, "inrolari") != 0) {
        for (int i = 0; i < s->nr_inrolari; i++) {
            if (compare_inrolari(s, field, comparatie, valoare, i) != 0) {
                if (strstr(camp, "id_student") != 0) {
                    s->inrolari[i].id_student = valint;
                }
                if (strstr(camp, "id_materie") != 0) {
                    s->inrolari[i].id_materie = valint;
                }
                if (strstr(camp, "note") != 0) {
                    s->inrolari[i].note[0] = nota1;
                    s->inrolari[i].note[1] = nota2;
                    s->inrolari[i].note[2] = nota3;
                    // printf("%d %f %f %f\n", s->inrolari[i].id_student,
                    // s->inrolari[i].note[0], s->inrolari[i].note[1], s->inrolari[i].note[2]);
                    medie_finala(s, s->inrolari[i].id_student);
                }
            }
        }
    }
    return s;
}

secretariat *UPDATE_2condition(secretariat *s, char *str) {
    char camp[FIFTY], valoare_noua[FIFTY];
    char field1[FIFTY], comparatie1[TEN], valoare1[TWENTY];
    char field2[FIFTY], comparatie2[TEN], valoare2[TWENTY];
    char copy[TWOHUNDRED], copy2[TWOHUNDRED];
    // copii a stringului initial
    snprintf(copy, sizeof(copy), "%s", str);
    snprintf(copy2, sizeof(copy), "%s", str);
    // incarc conditia
    // WHERE
    char *p = strtok(strstr(copy, "WHERE"), " ");
    // field1
    p = strtok(NULL, " ");
    snprintf(field1, sizeof(field1), "%s", p);
    // comparatie1
    p = strtok(NULL, " ");
    snprintf(comparatie1, sizeof(comparatie1), "%s", p);
    // valoare1
    p = strtok(NULL, " ");
    snprintf(valoare1, sizeof(valoare1), "%s", p);
    // AND
    p = strtok(NULL, " ");
    // field2
    p = strtok(NULL, " ");
    snprintf(field2, sizeof(field2), "%s", p);
    // comparatie2
    p = strtok(NULL, " ");
    snprintf(comparatie2, sizeof(comparatie2), "%s", p);
    // valoare2
    p = strtok(NULL, " ");
    snprintf(valoare2, sizeof(valoare2), "%s", p);
    // printf("%s %s %s\n", field2, comparatie2, valoare2);
    // incarc campurile ce trebuiesc schimbate
    // SET
    p = strtok(strstr(copy2, "SET"), " ");
    // camp
    p = strtok(NULL, " ");
    snprintf(camp, sizeof(camp), "%s", p);
    // =
    p = strtok(NULL, " ");
    // valoare_noua
    p = strtok(NULL, " ");
    snprintf(valoare_noua, sizeof(valoare_noua), "%s", p);
    // salvez valoarea noua in variabila potrivita
    int valint = 0;
    char valchar = '\0', valstr[HUNDRED];
    float valfloat = (float)0.0;
    float nota1 = (float)0.0, nota2 = (float)0.0, nota3 = (float)0.0;
    if (strstr(camp, "nume") != 0) {
        p = strtok(copy2, "\"");
        snprintf(valstr, sizeof(valstr), "%s", p);
    }
    // studenti
    if (strstr(str, "studenti") != 0) {
        if (strstr(camp, "id") != 0 || strstr(camp, "an_studiu") != 0) {
            valint = atoi(valoare_noua);
        }
        if (strstr(camp, "statut") != 0) {
            valchar = valoare_noua[0];
        }
        if (strstr(camp, "medie_generala") != 0 || strstr(camp, "note") != 0) {
            valfloat = (float)(atof(valoare_noua));
        }
    }
    // materii
    if (strstr(str, "materii") != 0) {
        if (strstr(camp, "id") != 0) {
            valint = atoi(valoare_noua);
        }
    }
    // innrolari
    if (strstr(str, "inrolari") != 0) {
        if (strstr(camp, "id") != 0) {
            valint = atoi(valoare_noua);
        }
        if (strstr(camp, "note") != 0) {
            nota1 = (float)(atof(valoare_noua));
            // nota2
            p = strtok(NULL, " ");
            nota2 = (float)(atof(p));
            // nota3
            p = strtok(NULL, " ");
            nota3 = (float)(atof(p));
        }
    }
    // actualizez in functie de conditie
    // studenti
    if (strstr(str, "studenti") != 0) {
        for (int i = 0; i < s->nr_studenti; i++) {
            if (compare_studenti(s, field1, comparatie1, valoare1, i) != 0
            && compare_studenti(s, field2, comparatie2, valoare2, i) != 0) {
                if (strstr(camp, "id") != 0) {
                    s->studenti[i].id = valint;
                }
                if (strstr(camp, "nume") != 0) {
                    snprintf(s->studenti[i].nume, sizeof(s->studenti[i].nume), "%s", valstr);
                }
                if (strstr(camp, "an_studiu") != 0) {
                    s->studenti[i].an_studiu = valint;
                }
                if (strstr(camp, "statut") != 0) {
                    s->studenti[i].statut = valchar;
                }
                if (strstr(camp, "medie_generala") != 0) {
                    s->studenti[i].medie_generala = valfloat;
                }
            }
        }
    }
    // materii
    if (strstr(str, "materii") != 0) {
        for (int i = 0; i < s->nr_materii; i++) {
            if (compare_materii(s, field1, comparatie1, valoare1, i) != 0
            && compare_materii(s, field2, comparatie2, valoare2, i) != 0) {
                if (strstr(camp, "id") != 0) {
                    s->materii[i].id = valint;
                }
                if (strstr(camp, "nume_titular") != 0) {
                    snprintf(s->materii[i].nume_titular, sizeof(s->materii[i].nume_titular), "%s", valstr);
                } else if (strstr(camp, "nume") != 0) {
                    snprintf(s->materii[i].nume, sizeof(s->materii[i].nume), "%s", valstr);
                }
            }
        }
    }
    // inrolari
    if (strstr(str, "inrolari") != 0) {
        for (int i = 0; i < s->nr_inrolari; i++) {
            if (compare_inrolari(s, field1, comparatie1, valoare1, i) != 0
            && compare_inrolari(s, field2, comparatie2, valoare2, i) != 0) {
                if (strstr(camp, "id_student") != 0) {
                    s->inrolari[i].id_student = valint;
                }
                if (strstr(camp, "id_materie") != 0) {
                    s->inrolari[i].id_materie = valint;
                }
                if (strstr(camp, "note") != 0) {
                    s->inrolari[i].note[0] = nota1;
                    s->inrolari[i].note[1] = nota2;
                    s->inrolari[i].note[2] = nota3;
                    medie_finala(s, s->inrolari[i].id_student);
                }
            }
        }
    }
    return s;
}

int main(int argc, char *argv[]) {
    // TODO(student): Task 2
    int n = 0;
    secretariat *s = citeste_secretariat(argv[1]);
    scanf("%d", &n);
    // printf("%d", n);
    int nr_initial_studenti = s->nr_studenti;
    int nr_initial_materii = s->materii;
    int nr_initial_inrolari = s->inrolari;
    char *linie = malloc(TWOHUNDRED * sizeof(char));
    for (int i = 0; i <= n; i++) {
        // char *linie = malloc(HUNDRED * sizeof(char));
        fgets(linie, TWOHUNDRED, stdin);
        if (strstr(linie, "SELECT") != 0 && strstr(linie, "WHERE") == 0 && strstr(linie, "AND") == 0) {
            SELECT(s, linie);
        }
        if (strstr(linie, "SELECT") != 0 && strstr(linie, "WHERE") != 0 && strstr(linie, "AND") == 0) {
            SELECT_condition(s, linie);
        }

        if (strstr(linie, "SELECT") != 0 && strstr(linie, "AND") != 0) {
            SELECT_2condition(s, linie);
        }
        if (strstr(linie, "DELETE") != 0 && strstr(linie, "AND") == 0) {
            DELETE(s, linie);
            // medie_finala(s);
        }
        if (strstr(linie, "DELETE") != 0 && strstr(linie, "AND") != 0) {
            DELETE_2condition(s, linie);
            // medie_finala(s);
        }
        if (strstr(linie, "UPDATE") != 0 && strstr(linie, "AND") == 0) {
            UPDATE_condition(s, linie);
            // medie_finala(s);
        }
        if (strstr(linie, "UPDATE") != 0 && strstr(linie, "AND") != 0) {
            UPDATE_2condition(s, linie);
            // medie_finala(s);
        }
        // printf("%s", linie);
    }
    free(linie);
    elibereaza_secretariat(&s);
    return 0;
}
