//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//#define rint register int
#define MAXN 100005
int arr[MAXN + 1];

bool Max(int a, int b)
{
	if (arr[a] != arr[b]) return arr[a] > arr[b];
	return a > b;
}

bool Min(int a, int b)
{
	if (arr[a] != arr[b]) return arr[a] < arr[b];
	return a < b;
}

void swap(int &a, int &b)
{
	//rint t = a;
	int t = a;
	a = b;
	b = t;
}

struct PriorityQueue {
	int heap[MAXN+1], index[MAXN+1], hn;
	bool(*cmp)(int, int);

	void init(int flag) {
		hn = 0;
		cmp = flag ? Max : Min;
		for (int i = 0; i <= MAXN; i++) index[i] = 0;
	}

	int top() {
		if (hn == 0) return 0;
		return heap[1];
	}

	void push(int nd) {
		heap[++hn] = nd;
		index[nd] = hn;
		upheap(hn);
	}

	int pop() {
		if (hn == 0) return 0;
		int ret = heap[1];
		swap(heap[1], heap[hn]);
		index[heap[1]] = 1, index[heap[hn]] = 0;
		hn--;
		downheap(1);
		return ret;
	}

	void upheap(int idx) {
		for (int c = idx; c > 1; c /= 2) {
			if (cmp(heap[c], heap[c / 2])) {
				swap(heap[c], heap[c / 2]);
				swap(index[heap[c]], index[heap[c / 2]]);
			}
			else break;
		}
	}

	void downheap(int idx) {
		for (int c = idx * 2; c <= hn; c *= 2) {
			if (c < hn && cmp(heap[c + 1], heap[c])) c++;
			if (cmp(heap[c], heap[c / 2])) {
				swap(heap[c], heap[c / 2]);
				swap(index[heap[c]], index[heap[c / 2]]);
			}
			else break;
		}
	}

	void update(int tg) {
		int idx = index[tg];
		upheap(idx);
		downheap(idx);
	}

	void erase(int tg) {
		int idx = index[tg];
		if (idx == 0) return;
		for (; idx > 1; idx /= 2) {
			swap(heap[idx], heap[idx / 2]);
			swap(index[heap[idx]], index[heap[idx / 2]]);
		}
		pop();
	}
} minpq, maxpq;

int main(void) {
	int N, M;
	int num, cmd;
	maxpq.init(1);
	minpq.init(0);
	
	freopen("ref_priority_queue_input.txt", "r", stdin);

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &num);
		arr[i] = num;
		maxpq.push(i);
		minpq.push(i);
	}

	int idx, targnum;

	for (int i = 0; i < M; i++) {
		scanf("%d", &cmd);
		if (cmd == 1) { // 값 수정
			scanf("%d %d", &idx, &targnum);
			arr[idx] = targnum;
			maxpq.update(idx);
			minpq.update(idx);
		}
		else if (cmd == 2) { // 최소값 index 출력
			printf("%d\n", minpq.top());
		}
		else if (cmd == 3) { // 최대값 index 출력
			printf("%d\n", maxpq.top());
		}
	}

	return 0;
}