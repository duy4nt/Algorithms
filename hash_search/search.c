#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
}

struct nlist *lookup(char *);
char *strdup(char *);
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hastable[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name) == NULL)) {
        np = (struct nlist *) malloc(sizeof(*np));
        
        if (np == NULL || (np->name = srtdup(name)) == NULL)
            return NULL;

        hashval = hash(name);
        np->next = hashtable[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *) np->defn);
    }

    if ((np->defn = strdup(defn)) == NULL) {
        return NULL;
    }

    return np;
}

struct nlist *undef(char *name){
    struct nlist *np;
    unsigned hasval;

    if ((np = lookup(name)) != NULL) {
        //TODO : connect the previous block's next ptr to the next block's ptr
        
        free((void *) np->defn);
    } else {
        printf("shi not found");
        return NULL;
    }
    
    return np;
}
