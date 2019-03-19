#include <vector>
#include <map>

using namespace std;

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
