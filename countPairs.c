// HashMap implementation
typedef struct {
    struct TreeNode *key;
    struct TreeNode **value;
    int value_size;
} HashMapEntry;

typedef struct {
    HashMapEntry *entries;
    int size;
    int capacity;
} HashMap;

void initHashMap(HashMap *map) {
    map->entries = NULL;
    map->size = 0;
    map->capacity = 0;
}

void putHashMap(HashMap *map, struct TreeNode *key, struct TreeNode **value, int value_size) {
    if (map->size == map->capacity) {
        map->capacity = map->capacity == 0 ? 1 : map->capacity * 2;
        map->entries = realloc(map->entries, map->capacity * sizeof(HashMapEntry));
    }
    map->entries[map->size].key = key;
    map->entries[map->size].value = value;
    map->entries[map->size].value_size = value_size;
    map->size++;
}

struct TreeNode **getHashMap(HashMap *map, struct TreeNode *key, int *size) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            *size = map->entries[i].value_size;
            return map->entries[i].value;
        }
    }
    *size = 0;
    return NULL;
}

void findLeaves(struct TreeNode *node, struct TreeNode **trail, int trail_size, 
                struct TreeNode **leaves, int *leaves_size, HashMap *map) {
    if (node == NULL) return;

    struct TreeNode **tmp = malloc((trail_size + 1) * sizeof(struct TreeNode*));
    memcpy(tmp, trail, trail_size * sizeof(struct TreeNode*));
    tmp[trail_size] = node;

    if (node->left == NULL && node->right == NULL) {
        putHashMap(map, node, tmp, trail_size + 1);
        leaves[*leaves_size] = node;
        (*leaves_size)++;
        return;
    }

    findLeaves(node->left, tmp, trail_size + 1, leaves, leaves_size, map);
    findLeaves(node->right, tmp, trail_size + 1, leaves, leaves_size, map);

    free(tmp);
}

int countPairs(struct TreeNode* root, int distance) {
    HashMap map;
    initHashMap(&map);
    struct TreeNode *leaves[10000];
    int leaves_size = 0;
    struct TreeNode *trail[10000];

    findLeaves(root, trail, 0, leaves, &leaves_size, &map);

    int res = 0;
    for (int i = 0; i < leaves_size; i++) {
        for (int j = i + 1; j < leaves_size; j++) {
            int size_i, size_j;
            struct TreeNode **list_i = getHashMap(&map, leaves[i], &size_i);
            struct TreeNode **list_j = getHashMap(&map, leaves[j], &size_j);

            for (int k = 0; k < (size_i < size_j ? size_i : size_j); k++) {
                if (list_i[k] != list_j[k]) {
                    int dist = size_i - k + size_j - k;
                    if (dist <= distance) res++;
                    break;
                }
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < map.size; i++) {
        free(map.entries[i].value);
    }
    free(map.entries);

    return res;
}
