class Solution {
    private int[] parent;
    private int[] rank;

    public int countComponents(int n, int[][] edges) {
        parent = new int[n];
        rank = new int[n];

        // Initially, each node is its own parent (self root)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        int components = n;

        for (int[] edge : edges) {
            if (union(edge[0], edge[1])) {
                components--;
            }
        }

        return components;
    }

    // Find root parent with path compression
    private int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank returns true if union is successful (parents were different)
    private boolean union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
}
