#define HASH_SIZE 100003
typedef struct HashNode {
    int x, y;
    struct HashNode* next;
} HashNode;
HashNode* hashMap[HASH_SIZE];
int hash(int x, int y) {
    return (abs(x * 30001 + y)) % HASH_SIZE;
}
void insertObstacle(int x, int y) {
    int h = hash(x, y);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->x = x;
    newNode->y = y;
    newNode->next = hashMap[h];
    hashMap[h] = newNode;
}
bool isObstacle(int x, int y) {
    int h = hash(x, y);
    HashNode* node = hashMap[h];
    while (node) {
        if (node->x == x && node->y == y) return true;
        node = node->next;
    }
    return false;
}
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    for (int i = 0; i < obstaclesSize; ++i) {
        insertObstacle(obstacles[i][0], obstacles[i][1]);
    }
    int x = 0, y = 0;
    int direction = 0;
    int maxDistSq = 0;
    for (int i = 0; i < commandsSize; ++i) {
        int command = commands[i];
        if (command == -2) {
            direction = (direction + 3) % 4;
        } else if (command == -1) {
            direction = (direction + 1) % 4;
        } else {
            for (int j = 0; j < command; ++j) {
                int newX = x + dx[direction];
                int newY = y + dy[direction];
                if (!isObstacle(newX, newY)) {
                    x = newX;
                    y = newY;
                    int distSq = x * x + y * y;
                    if (distSq > maxDistSq) {
                        maxDistSq = distSq;
                    }
                } else {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < HASH_SIZE; ++i) {
        HashNode* current = hashMap[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
        hashMap[i] = NULL;
    }    
    return maxDistSq;
}
