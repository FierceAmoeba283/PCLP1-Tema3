    TASK1
La inceput declar cate o variabila de numarare a elementelor din fiecare vector structura, pe care le voi incrementa cu citirea unei noi linii aferente structurii respective (nr1, nr2, nr3). De asemenea am declarat o variabila numita "mod" prin care tin cont de locatia si structura corecta a informatiilor din fisier. Avand asta in vedere, citesc din fisier linie cu linie folosind fgets si impart fiecare linie in cuvinte folosind strtok, pentru a face separarea campurilor cat mai simpla. avand in vedere ca in functie de mod fiecare linie din fisier respecta aceeasi structura generala, se poate stii cu usurinta carei structuri ii corespunde informatia.
    TASK2
Pentru a face implementarea codului cat mai usoara am implementat trei functii de comparare a conditiei pentru comenzile conditionate (select, delete, update). Aceste functii (aferente fiecarei structuri) preiau trei stringuri, primul reprezentand campul, al doilea reprezentand comparatia si al treilea reprezentand valoarea cu care se compara. Aceste functii prelucreaza stringurile si transforma valorile in variabilele specifice tipului de date, urmand ca ulterior sa verifice daca conditia transmisa de cele trei siruri de caractere este valida. Daca da, returneaza 1, altfel 0.
Implementarea celor trei functii de select este asemanatoare, cele conditionate urmand sa foloseasca functia compare_select. Am implementat functia select spargand comanda citita cu strtok, astfel permitand selectarea campurilor. Dupa selecatera campurilor ce trebuie afisate, am parcurs tot vectorul de studenti si am afisat pe ecran doar elementele specificate. Pentru select-urile conditionate, am introduc un if care verifica daca respectiva sau respectivele comenzi sunt valide pentru fieccare student, afisandu-i doar pe cei la care conditia sau ocnditiile se indeplinesc.
Functia delete a fost implementata asemeni simplii stergeri de elemente dintr-un vector, invatata in liceu, diferenta fiind ca functiile delete au folosit functia de verificare a conditiilor.
Comanda update functioneaza asemanator comenzii select cand vine vorba de selectarea campurilor, aceasta fiind implementata cu strtok pentru o mai eficienta detetctare a valorilor ce trebuiesc actualizate, precum si a conditiilor.
In main am scris un for aferent numarului de comenzi citite din fisier, pentrufiecare repetarea  acestuia urmand a se apela functia specifica comenizii citite, acest lucru facandu-se printr-un strstr.
    TASK3
Am inceput prin a calcula lungimea cu padding a vectorului criptat, facand acest lucru folosindu-ma de divizibilitatea cu 4. Stiind acest lucru am putut afla dimensoiunea unui bloc. Astfel am putut declara patru pointeri diferiti (block1,block2, block3, block4) care arata catre zona de memorie aferenta fiecarui bloc. Astfel am putut usura operatiile ce urmeaza, urmand sa aplic xor, s_box si p_box fiecarui bloc. La final am afisat in fisier fiecare bloc encriptat, avand grija sa nu las spatiu intre afisarile lor.