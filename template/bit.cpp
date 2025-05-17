int N;
int BIT[10001];  // Array size should be large enough (e.g., 10001)

void update(int pos, int val) {
    while (pos <= N) {
        BIT[pos] += val;
        pos += pos & -pos;  // Correct the negative sign
    }
}

int query(int pos) {
    int sum = 0;
    while (pos > 0) {
        sum += BIT[pos];
        pos -= pos & -pos;  // Correct the negative sign
    }
    return sum;
}

