## Disjoint Sets

Attaced slides from [coursera][crs]

[Visualization][vis] of Disjoint Sets with and without Path Compression and Union by Rank heuristics

[Tuturial][tut] on Disjoint Sets

#### Realization (pseudocode):

```cpp
template <typename T>
class DisjointSet {
public:
	void make_set(T val) {
		values.push_back(val);
		parent.push_back(values.size() - 1);
		rank.push_back(0);
	}
	// if find by value, can use hashtable for mapping values to indexes
	void find_set(int index) {
		if (index == parent(index)) {
			parent[index] = find_set(parent[index]);
		}
		return parent[index];
	}
	// by value, see above
	void union_set(int u1, int u2) {
		int r1 = find_set(u1), r2 = find_set(u2);
		if (r1 == r2) {
			return;
		}
		if (rank(r1) < rank(r2)) {
			parent[r1] = r2;
		} else {
			parent[r2] = r1;
			if (rank[r1] == rank[r2]) {
				rank[r1]++;
			}
		}
	}
private:
	vector<T> values;
	vector<int> rank;
	vector<int> parent;
}
```


[tut]: https://www.topcoder.com/community/competitive-programming/tutorials/disjoint-set-data-structures/

[vis]: https://www.cs.usfca.edu/~galles/visualization/DisjointSets.html

[crs]: https://www.coursera.org/learn/data-structures/home/week/3
