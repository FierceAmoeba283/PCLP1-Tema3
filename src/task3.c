#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task3.h"

void cripteaza_studenti(secretariat *secretariat, void *key, size_t key_len,
                        void *iv, size_t iv_len, char *cale_output) {
    // // TODO(student): Cripteaza vectorul secretariat->studenti si scrie rezultatul in fisierul cale_output
    FILE *fisier = fopen(cale_output, "wb");
    int block_size = 0, size = 0;
    unsigned char *init = (unsigned char*)iv;
    unsigned char *cheie = (unsigned char*)key;
    int delta = (int)(secretariat->nr_studenti * sizeof(student)) % 4;
    // gasesc dimensiunile vectorului de blocuri cu padding
    // size = (int)(secretariat->nr_studenti * sizeof(struct student) +
    // (4 - (secretariat->nr_studenti * sizeof(struct student)) % 4));
    if (secretariat->nr_studenti * sizeof(student) % 4 != 0) {
        size = (int)(secretariat->nr_studenti * sizeof(struct student) +
        (4 - (secretariat->nr_studenti * sizeof(struct student)) % 4));
    } else {
        size = (int)(secretariat->nr_studenti * sizeof(struct student));
    }
    block_size = size / 4;
    // aloc vectorul de blocuri
    unsigned char *blocks = calloc(1, size);
    // copiez vectorul de studenti in vectorul de blocuri
    memcpy(blocks, secretariat->studenti, size - delta);
    // impart memoria in  4
    unsigned char *block1 = blocks;
    unsigned char *block2 = blocks + block_size;
    unsigned char *block3 = blocks + 2 * block_size;
    unsigned char *block4 = blocks + 3 * block_size;
    // criptarea primului bloc folosind iv
    unsigned char *buffer = calloc(1, block_size);
    size_t cnt = 0;
    memcpy(block1, blocks, block_size);
    memcpy(block2, blocks + block_size, block_size);
    memcpy(block3, blocks + 2 * block_size, block_size);
    memcpy(block4, blocks + 3 * block_size, block_size);
    // init
    for (int i = 0; i < block_size; i++) {
        if (cnt == iv_len) {
            cnt = 0;
        }
        block1[i] = block1[i] ^ init[cnt];
        cnt++;
    }
    // S_BOX
    cnt = 0;
    for (int i = 0; i < block_size; i++) {
        if (cnt == key_len) {
            cnt = 0;
        }
        block1[i] = block1[i] ^ cheie[cnt];
        cnt++;
    }
    // P_BOX
    unsigned char *alt = calloc(1, block_size);
    for (int i = 0; i < block_size; i++) {
        int j = (i * (block_size - 1) + 2) % block_size;
        alt[j] = block1[i];
    }
    for (int i = 0; i < block_size; i++) {
        block1[i] = alt[i];
    }
    // block 2
    for (int i = 0; i < block_size; i++) {
        block2[i] = block2[i] ^ block1[i];
    }
    cnt = 0;
    for (int i = 0; i < block_size; i++) {
        if (cnt == key_len) {
            cnt = 0;
        }
        block2[i] = block2[i] ^ cheie[cnt];
        cnt++;
    }
    for (int i = 0; i < block_size; i++) {
        int j = (i * (block_size - 1) + 2) % block_size;
        alt[j] = block2[i];
    }
    for (int i = 0; i < block_size; i++) {
        block2[i] = alt[i];
    }
    // block 3
    for (int i = 0; i < block_size; i++) {
        block3[i] = block3[i] ^ block2[i];
    }
    cnt = 0;
    for (int i = 0; i < block_size; i++) {
        if (cnt == key_len) {
            cnt = 0;
        }
        block3[i] = block3[i] ^ cheie[cnt];
        cnt++;
    }
    for (int i = 0; i < block_size; i++) {
        int j = (i * (block_size - 1) + 2) % block_size;
        alt[j] = block3[i];
    }
    for (int i = 0; i < block_size; i++) {
        block3[i] = alt[i];
    }
    // block 4
    for (int i = 0; i < block_size; i++) {
        block4[i] = block4[i] ^ block3[i];
    }
    cnt = 0;
    for (int i = 0; i < block_size; i++) {
        if (cnt == key_len) {
            cnt = 0;
        }
        block4[i] = block4[i] ^ cheie[cnt];
        cnt++;
    }
    for (int i = 0; i < block_size; i++) {
        int j = (i * (block_size - 1) + 2) % block_size;
        alt[j] = block4[i];
    }
    for (int i = 0; i < block_size; i++) {
        block4[i] = alt[i];
    }
    // afisare
    for (int i = 0; i < block_size; i++) {
        fprintf(fisier, "%c", block1[i]);
    }
    for (int i = 0; i < block_size; i++) {
        fprintf(fisier, "%c", block2[i]);
    }
    for (int i = 0; i < block_size; i++) {
        fprintf(fisier, "%c", block3[i]);
    }
    for (int i = 0; i < block_size; i++) {
        fprintf(fisier, "%c", block4[i]);
    }
    free(alt);
    free(blocks);
}
