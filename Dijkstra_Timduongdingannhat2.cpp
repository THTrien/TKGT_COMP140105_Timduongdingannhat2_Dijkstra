#include<iostream>
#include<fstream>
using namespace std;
#define MAX 50 
#define TRUE 1 
#define FALSE  0
#define VOCUNG 10000000
int n;//số đỉnh của đồ thị.
int s;//đỉnh đầu.
int t;//đỉnh cuối
char chon;
int truoc[MAX];//mảng đánh dấu đường đi.
int d[MAX];//mảng đánh dấu khoảng cách.
int Matrix[MAX][MAX];//ma trận trọng số
int chuaxet[MAX];//mảng đánh dấu đỉnh đã được gán nhãn.

void Init(void) {

	cin >> n;
	cin >> s >> t;//nhập đỉnh đầu và đỉnh cuối của đồ thị.
	//nhập ma trận của đồ thị.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Matrix[i][j];
			if (Matrix[i][j] == 0) Matrix[i][j] = VOCUNG;
		}
	}
}
void Result(void) {
    cout << d[t] << endl;
	cout << t << "<-";// in đỉnh cuối
	int i = truoc[t];
	while (i != s) {
		cout << i << "<-";//in ra kết quả
		i = truoc[i];
	}
	cout << s;//in đỉnh đầu
	
}
void Dijkstra(void) {
	int u, minp;
	//khởi tạo nhãn tạm thời cho các đỉnh.
	for (int v = 1; v <= n; v++) {
		d[v] = Matrix[s][v];
		truoc[v] = s;
		chuaxet[v] = FALSE;
	}
	truoc[s] = 0;
	d[s] = 0;
	chuaxet[s] = TRUE;
	//bươc lặp
	while (!chuaxet[t]) {
		minp = VOCUNG;
		//tìm đỉnh u sao cho d[u] là nhỏ nhất
		for (int v = 1; v <= n; v++) {
			if ((!chuaxet[v]) && (minp > d[v])) {
				u = v;
				minp = d[v];
			}
		}
		chuaxet[u] = TRUE;// u la dinh co nhan tam thoi nho nhat 
		if (!chuaxet[t]) {
			//gán nhãn lại cho các đỉnh.
			for (int v = 1; v <= n; v++) {
				if ((!chuaxet[v]) && (d[u] + Matrix[u][v] < d[v])) {
					d[v] = d[u] + Matrix[u][v];
					truoc[v] = u;
				}
			}
		}
	}
}
int main(void) {
	Init();
	Dijkstra();
	Result();
	return 0;
}
