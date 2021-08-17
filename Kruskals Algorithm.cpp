#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, wt;
};

bool comp (Edge& e1, Edge& e2) {
	return e1.wt < e2.wt;
}

// Find operation with Path Compression from DSU to reduce Time Complexity
int find(int a, vector<int>& par){
	if(par[a] < 0)
		return a;
	return par[a] = find(par[a], par);
}

// Union operation from DSU
void Union(int a, int b, vector<int>& par){
	par[a] = b;
}

int main(){
	int V = 4, E = 5;
	vector<Edge> edges;

    // Initialise every vertex as its parent
	vector<int> par(V, -1);

    // Input all the edges along with their weights
    for(int i = 0; i < E; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});
	}

	// Custom sort that sorts on the basis of weights
    sort(edges.begin(), edges.end(), comp);

    // Run the loop and keep on adding weights V-1 times
    int sum = 0;
    for(int i = 0; i < E; i++){
    	int a = find(edges[i].u, par);
    	int b = find(edges[i].v, par);
    	if(a != b){
    		sum += edges[i].wt;
    		cout << "Sum weight is : " << sum << "\n";
    		Union(a, b, par);
    	}
    }
    cout << "\nTotal weight in MST is : " << sum;
    return 0;
}
