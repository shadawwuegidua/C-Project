#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 54  // 扑克牌总数（包括大小王）
#define CARDS_PER_PLAYER 17  // 每个玩家手牌数量
#define NUM_PLAYERS 3 // 玩家数量

// 定义玩家结构体
typedef struct {
    int hand[CARDS_PER_PLAYER];
    int handSize; // 记录手牌数量
} Player;

// 函数声明
void shuffle(int deck[]);
void dealCards(int deck[], Player players[], int numPlayers);
void printHand(Player player);
int checkCardValidity(int out[], int cardCount);
int compareCards(int playerCard[], int opponentCard[], int playerCardCount, int opponentCardCount);
void sortHand(Player* player);

int main() {
    srand(time(NULL));  // 初始化随机数种子

    int deck[NUM_CARDS];  // 扑克牌堆
    Player players[NUM_PLAYERS];  // 三个玩家

    // 初始化扑克牌
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i] = i + 1;
    }

    shuffle(deck);  // 洗牌
    dealCards(deck, players, NUM_PLAYERS);  // 分牌

    // 随机叫地主
    int landlord = rand() % NUM_PLAYERS;  // 随机选择一个地主
    printf("玩家 %d 是地主\n", landlord + 1);

    // 输出每个玩家的牌
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("玩家 %d 的牌: ", i + 1);
        printHand(players[i]);
    }

    // 游戏主循环
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("玩家 %d 出牌: (请输入出几张牌，随后输入牌的编号，用空格隔开)\n", i + 1);
        int cardCount;
        scanf("%d", &cardCount); // 输入出牌数量

        int out[cardCount];
        for (int j = 0; j < cardCount; j++) {
            scanf("%d", &out[j]); // 输入出牌内容
        }

        if (checkCardValidity(out, cardCount)) {
            printf("玩家 %d 出牌合法！\n", i + 1);
        } else {
            printf("玩家 %d 出牌不合法，判负！\n", i + 1);
            break;
        }
    }

    return 0;
}

// 洗牌函数
void shuffle(int deck[]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// 分牌函数
void dealCards(int deck[], Player players[], int numPlayers) {
    int cardIndex = 0;
    for (int i = 0; i < numPlayers; i++) {
        players[i].handSize = CARDS_PER_PLAYER;
        for (int j = 0; j < CARDS_PER_PLAYER; j++) {
            players[i].hand[j] = deck[cardIndex++];
        }
        sortHand(&players[i]);  // 给每个玩家的手牌排序，方便之后的操作
    }
}

// 打印玩家手牌
void printHand(Player player) {
    for (int i = 0; i < player.handSize; i++) {
        printf("%d ", player.hand[i]);
    }
    printf("\n");
}

// 排序玩家手牌，简单的冒泡排序
void sortHand(Player* player) {
    for (int i = 0; i < player->handSize - 1; i++) {
        for (int j = i + 1; j < player->handSize; j++) {
            if (player->hand[i] > player->hand[j]) {
                int temp = player->hand[i];
                player->hand[i] = player->hand[j];
                player->hand[j] = temp;
            }
        }
    }
}

// 检测出牌是否合法
int checkCardValidity(int out[], int cardCount) {
    if (cardCount == 1) {
        return 1; // 单张合法
    } else if (cardCount == 2) {
        if (out[0] == out[1]) {
            return 1; // 对子合法
        }
    } else if (cardCount == 3) {
        if (out[0] == out[1] && out[1] == out[2]) {
            return 1; // 三张合法
        }
    }
    // 这里只是简化的判断，实际上需要更复杂的规则判断
    return 0; // 默认不合法
}

// 比较两组牌的大小
int compareCards(int playerCard[], int opponentCard[], int playerCardCount, int opponentCardCount) {
    // 简化的比较规则：这里可以扩展比较规则
    return 0; // 默认返回0，表示平局
}
