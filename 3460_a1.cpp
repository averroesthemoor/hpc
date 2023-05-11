#include<bits/stdc++.h>
#include<omp.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

int N = 10, M = 10;
vector<int> graph [10];
void bfs_p(int start) {
	vector<bool> vis(N);
	queue<int> q;
	q.push(start);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		if(!vis[cur]) {
			vis[cur] = 1; cout << cur <<" ";
			
			#pragma omp parallel for
			for (int next: graph[cur]) {
				if(!vis[next]) q.push(next);			
			}		
		}	
	}
}

void bfs(int start) {
	vector<bool> vis(N);
	queue<int> q;
	q.push(start);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		if(!vis[cur]) {
			vis[cur] = 1; cout << cur <<" ";
			
			for (int next: graph[cur]) {
				if(!vis[next]) q.push(next);			
			}		
		}	
	}
}

void dfs_p(int start) {
	vector<bool> vis(N);
	stack<int> q;
	q.push(start);

	while(!q.empty()) {
		int cur = q.top();
		q.pop();
		if(!vis[cur]) {
			vis[cur] = 1; cout << cur <<" ";
			
			#pragma omp parallel for
			for (int next: graph[cur]) {
				if(!vis[next]) q.push(next);			
			}		
		}	
	}
}
void dfs(int start) {
	vector<bool> vis(N);
	stack<int> q;
	q.push(start);

	while(!q.empty()) {
		int cur = q.top();
		q.pop();
		if(!vis[cur]) {
			vis[cur] = 1; cout << cur <<" ";
			
			for (int next: graph[cur]) {
				if(!vis[next]) q.push(next);			
			}		
		}	
	}
}

int main() {
	cout << "Enter 4 edges :" << endl;
	for(int i = 0; i < 4; i++) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);	
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Paralel BFS traversal : ";

	auto start = high_resolution_clock::now();
	bfs_p(0);
	cout << endl;
	auto end = high_resolution_clock::now();
	auto dur = duration_cast<microseconds>(end - start);
	cout << "Time taken : " <<dur.count() << " ms" <<endl; 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Normal BFS traversal : ";

	start = high_resolution_clock::now();
	bfs(0);
	cout << endl;
	end = high_resolution_clock::now();
	dur = duration_cast<microseconds>(end - start);
	cout << "Time taken : " <<dur.count() << " ms" <<endl; 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	cout << "Paralel DFS traversal : ";
	start = high_resolution_clock::now();
	dfs_p(0);
	cout << endl;
	end = high_resolution_clock::now();
	dur = duration_cast<microseconds>(end - start);
	cout << "Time taken : " <<dur.count() << " ms" <<endl; 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	cout << "Common DFS traversal : ";
	start = high_resolution_clock::now();
	dfs(0);
	cout << endl;
	end = high_resolution_clock::now();
	dur = duration_cast<microseconds>(end - start);
	cout << "Time taken : " <<dur.count() << " ms" <<endl; 
	
}
