class Solution {
    public String foreignDictionary(String[] words) {
        // Step 1: Build graph
        Map<Character, Set<Character>> graph = new HashMap<>();
        Map<Character, Integer> indegree = new HashMap<>();
        
        // Initialize graph nodes
        for (String word : words) {
            for (char c : word.toCharArray()) {
                graph.putIfAbsent(c, new HashSet<>());
                indegree.putIfAbsent(c, 0);
            }
        }
        
        // Step 2: Build edges by comparing adjacent words
        for (int i = 0; i < words.length - 1; i++) {
            String w1 = words[i];
            String w2 = words[i + 1];
            
            int len = Math.min(w1.length(), w2.length());
            boolean foundDifference = false;
            for (int j = 0; j < len; j++) {
                char c1 = w1.charAt(j);
                char c2 = w2.charAt(j);
                if (c1 != c2) {
                    if (!graph.get(c1).contains(c2)) {
                        graph.get(c1).add(c2);
                        indegree.put(c2, indegree.get(c2) + 1);
                    }
                    foundDifference = true;
                    break; // Only the first difference matters
                }
            }
            // Edge case: prefix invalid (e.g., ["abc","ab"])
            if (!foundDifference && w1.length() > w2.length()) {
                return "";
            }
        }
        
        // Step 3: Topological sort (Kahn's algorithm)
        Queue<Character> queue = new LinkedList<>();
        for (char c : indegree.keySet()) {
            if (indegree.get(c) == 0) queue.offer(c);
        }
        
        StringBuilder sb = new StringBuilder();
        while (!queue.isEmpty()) {
            char c = queue.poll();
            sb.append(c);
            for (char nei : graph.get(c)) {
                indegree.put(nei, indegree.get(nei) - 1);
                if (indegree.get(nei) == 0) queue.offer(nei);
            }
        }
        
        // Step 4: Check for cycles
        if (sb.length() != indegree.size()) return "";
        return sb.toString();
    }
}
