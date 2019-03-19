## Minimum spanning trees (MST)

#### Visualization:
* [Kruskal's algorithm][kruskal]

#### Realization (pseudocode):
* Kruskal's algorithm:

```python
# python + cpp = pseudocode
kruskal(v, e):
	DisjointSet ds
	for vi in v:
		ds.make_set(vi)
	sort(e)
	weights = 0
	while not e.empty():
		min_weight = e[0]
		if ds.find_set(i) != ds.find_set(j)
			weight += min_weight
			ds.union_set(i, j)
		del(e[0])
	return weights
```	

* Prim's algorithm:

```python 
# python + cpp
prim(v, e):
	for all u in V:
		cont[u] = inf
		parent[u] = None
	# pick any initial vertex u0
	cost[u0] = 0
	# create priority queue
	for all u in V:
		pq.insert(u)
	while not pq.empty():
		v = pq.ExtractMax()
		for all {v, z} in E:
			if z in pq and cost[z] > weight(v, z):
				cost[z] = weight(v, z)
				parent[z] = v
				ChangePriority(pq, z, cost[z])
```

[kruskal]: https://www.cs.usfca.edu/~galles/visualization/Kruskal.html
