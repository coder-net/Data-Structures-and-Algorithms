#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

#define ll long long
#define lpair pair<ll,ll>

template <typename T>
class DisjointSet {
public:
    DisjointSet() : size(0) {}
    void make_set(T value) {
        val_to_index[value] = size;
        rank.push_back(0);
        parent.push_back(size);
        size++;
    }
    T find_set(T value) {
        if (val_to_index.count(value) == 0) {
            throw runtime_error("No such element");
        }
        int index = val_to_index[value];
        return find(index);
    }
    void union_set(T s1, T s2) {
        int first = find_set(s1), second = find_set(s2);
        if (first == second) {
            return;
        }
        if (rank[first] < rank[second]) {
            parent[first] = second;
        } else {
            parent[second] = first;
            if (rank[first] == rank[second]) {
                rank[first]++;
            }
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
    map<T, int> val_to_index;
    int size;

    T find(T index) {
        if (index != parent[index]) {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }
};

struct Node {
    double weight;
    ll v1;
    ll v2;
    Node(double w, ll v1_, ll v2_) : weight(w), v1(v1_), v2(v2_) {}
};

bool operator<(const Node& n1, const Node& n2) {
    return tie(n1.weight, n1.v1, n1.v2) < tie(n2.weight, n2.v1, n2.v2);
}

double kruskal_MST(const vector<lpair>& vert, set<Node>& edges) {
    DisjointSet<ll> ds;
    for (ll i = 0; i < vert.size(); i++) {
        ds.make_set(i);
    }
    double weights = 0;
    while (!edges.empty()) {
        Node node = *edges.begin();
        if (ds.find_set(node.v1) != ds.find_set(node.v2)) {
            weights += node.weight;
            ds.union_set(node.v1, node.v2);
        }
        edges.erase(edges.begin());
    }
    return weights;
}

double distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    ll n;
    cin >> n;
    set<Node> edges;
    vector<lpair> vert(n);
    for (ll i = 0; i < n; i++) {
        ll first, second;
        cin >> first >> second;
        vert[i] = make_pair(first, second);
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            // cout << distance(vert[i].first, vert[i].second, vert[j].first, vert[j].second);
            edges.insert(Node(distance(vert[i].first, vert[i].second, vert[j].first, vert[j].second), i, j));
        }
    }
    cout << std::setprecision(10) << kruskal_MST(vert, edges);
    return 0;
}
