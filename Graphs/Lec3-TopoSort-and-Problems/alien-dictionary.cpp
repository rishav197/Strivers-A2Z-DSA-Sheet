
class Solution {
    public:
      string findOrder(vector<string> &words) {
          vector<set<int>> graph(26); 
          vector<int> inDegree(26, 0);
          vector<int> isPresent(26, 0);
          
          for(const string & str : words){
              for(const char &ch: str) isPresent[ch - 'a']++;
          }
          
          int cnt = 0;
          for(int i=0; i<26; i++){
              if(isPresent[i] > 0) cnt++;
          }
          
          for (int i = 0; i < words.size() - 1; ++i) {
              string word1 = words[i];
              string word2 = words[i + 1];
              int len = min(word1.length(), word2.length());
              
              bool flag = true;
              for (int j = 0; j < len; ++j) {
                  if (word1[j] != word2[j]) {
                      int u = word1[j] - 'a';
                      int v = word2[j] - 'a';
                      if (graph[u].find(v) == graph[u].end()) {
                          graph[u].insert(v);
                          inDegree[v]++;
                      }
                      flag = false;
                      break;
                  }
              }
              
              if(word1.length() > word2.length() && flag) return "";
          }
          
          queue<int> q;
          for (int i = 0; i < 26; i++) {
              if (inDegree[i] == 0 && isPresent[i] > 0) {
                  q.push(i);
              }
          }
          
          string result;
          while (!q.empty()) {
              int u = q.front();
              q.pop();
              result += (u + 'a');
              
              for (auto v : graph[u]) {
                  inDegree[v]--;
                  if (inDegree[v] == 0) {
                      q.push(v);
                  }
              }
          }
          
          // cout<<result<<endl;
          if (result.length() < cnt) return "";
          
          return result;
          
      }
  };