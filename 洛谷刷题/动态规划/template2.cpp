#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 函数：移除指定数量数字，返回最小数（处理前导零）
// num: 原始数字数组, len: 原始长度, delete_cnt: 要删除的数字个数
void removeDigits(int num[], int len, int delete_cnt) {
    int res_len = len - delete_cnt; // 结果保留的数字长度
    if (res_len <= 0) { // 边界：删除位数≥原长度，直接输出0
        printf("0\n");
        return;
    }

    int res[500]; // 存储结果的数组
    int res_idx = 0; // 结果数组的当前索引
    int last_pos = -1; // 上一个选中数字的位置（初始为-1，表示还未选）

    // 核心逻辑：逐位选择最小数字，保证剩余位数足够
    while (res_idx < res_len) {
        int min_val = 10; // 数字0-9，初始化为比最大数字大的值
        int min_pos = last_pos + 1; // 最小数字的位置

        // 遍历范围：[last_pos+1, len - (res_len - res_idx)]
        // 保证后续还有足够的数字可以选满res_len位
        int end = len - (res_len - res_idx);
        for (int i = last_pos + 1; i <= end; ++i) {
            if (num[i] < min_val) {
                min_val = num[i];
                min_pos = i;
            }
        }

        res[res_idx++] = min_val; // 选中当前最小数字
        last_pos = min_pos; // 更新上一个位置
    }

    // 处理前导零
    int start = 0;
    while (start < res_len && res[start] == 0) {
        start++;
    }

    // 输出结果：全零则输出0，否则输出非零开头的数字
    if (start == res_len) {
        printf("0");
    } else {
        for (int i = start; i < res_len; ++i) {
            printf("%d", res[i]);
        }
    }
    printf("\n");
}

int main() {
    char num_str[500]; // 原始数字字符串
    int delete_cnt;    // 要删除的数字个数

    // 输入处理
    scanf("%s%d", num_str, &delete_cnt);
    int len = strlen(num_str);

    // 字符串转数字数组（char→int）
    int num[500];
    for (int i = 0; i < len; ++i) {
        num[i] = num_str[i] - '0';
    }

    // 调用核心函数处理
    removeDigits(num, len, delete_cnt);

    return 0;
}