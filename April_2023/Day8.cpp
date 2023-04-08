/*  Question: Clone Graph
    Source: https://leetcode.com/problems/clone-graph
  
    CODE:                                                  */

class Solution {
public:
    unordered_map<Node* , Node*> mp; 
    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }
        Node* first = new Node(node -> val, {});
        mp[node] = first;        
        queue<Node*> q; 
        q.push(node); 
        while(q.empty() == false) 
        {
            Node* curr = q.front(); 
            q.pop();
            
            for(auto adj: curr -> neighbors) 
            {
                if(mp.find(adj) == mp.end())
                {
                    mp[adj] = new Node(adj -> val, {});
                    q.push(adj);   
                }
                mp[curr] -> neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
    }
};
