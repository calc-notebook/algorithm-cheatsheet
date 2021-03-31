#include <iostream>
#include <queue>
using namespace std;

const int N_MAX = 31;

struct Point{
	int x, y, z, d;
}start, destination, temp;
queue<Point> waitzone;

int L, R, C;
char maze[N_MAX][N_MAX][N_MAX];
bool visited[N_MAX][N_MAX][N_MAX];

int neighbor[8][3] = { { -1, 0, 0 }
, { 1, 0, 0 }
, { 0, -1, 0 }
, { 0, 1, 0 }
, { 0, 0, -1 }
, { 0, 0, 1 } };

int BFS(){
	// find the start and destination
	for (int l = 0; l < L; l++)
	for (int r = 0; r < R; r++)
	for (int c = 0; c < C; c++){
		if (maze[l][r][c] == 'S') { start.x = l; start.y = r; start.z = c; start.d = 0; }
		if (maze[l][r][c] == 'E') { destination.x = l; destination.y = r; destination.z = c; }
	}

	// BFS
	while (!waitzone.empty()) waitzone.pop();
	waitzone.push(start); visited[start.x][start.y][start.z] = true;
	while (!waitzone.empty()){
		Point cur_point = waitzone.front(); waitzone.pop();
		for (int p = 0; p < 6; p++){
			Point next_point;
			next_point.x = cur_point.x + neighbor[p][0];
			next_point.y = cur_point.y + neighbor[p][1];
			next_point.z = cur_point.z + neighbor[p][2];
			next_point.d = cur_point.d + 1;
			if (next_point.x == destination.x && next_point.y == destination.y && next_point.z == destination.z)
				return next_point.d;
			if (next_point.x < 0
				|| next_point.x >= L
				|| next_point.y < 0
				|| next_point.y >= R
				|| next_point.z < 0
				|| next_point.z >= C)
				continue;
			if (visited[next_point.x][next_point.y][next_point.z]) continue;
			if (maze[next_point.x][next_point.y][next_point.z] == '#') continue;
			waitzone.push(next_point);
			visited[next_point.x][next_point.y][next_point.z] = true;
		}
	}
	return -1;
}

int main(){
	while (scanf("%d%d%d", &L, &R, &C) != EOF && !(L == 0 && R == 0 && C == 0)){
		for (int l = 0; l < L; l++)
		for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++){
			cin >> maze[l][r][c];
			visited[l][r][c] = false;
		}
		int answer = BFS();
		if (answer >= 0) printf("Escaped in %d minute(s).\n", answer);
		else printf("Trapped!\n");
	}
	return 0;
}