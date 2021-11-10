---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: BFS
    links: []
  bundledCode: "#line 2 \"lib/graph/bfs.hpp\"\ntemplate<class vFe >\nvoid bfs(int\
    \ n, int s, Graph g, vFe dtmn){\n\tvector<int>vis(n); vis[s] = 1;\n\tqueue<int>q({\
    \ s });\n\twhile(q.size()){\n\t\tint c = q.front(); q.pop();\n\t\tfor(auto e:\
    \ g[c])if(!vis[e.to])dtmn(e), vis[e.to] = 1, q.push(e.to);\n\t}\n}\n\n/*\n* @title\
    \ BFS\n*/\n"
  code: "#pragma once\ntemplate<class vFe >\nvoid bfs(int n, int s, Graph g, vFe dtmn){\n\
    \tvector<int>vis(n); vis[s] = 1;\n\tqueue<int>q({ s });\n\twhile(q.size()){\n\t\
    \tint c = q.front(); q.pop();\n\t\tfor(auto e: g[c])if(!vis[e.to])dtmn(e), vis[e.to]\
    \ = 1, q.push(e.to);\n\t}\n}\n\n/*\n* @title BFS\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/bfs.hpp
  requiredBy: []
  timestamp: '2021-11-09 20:40:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bfs.test.cpp
documentation_of: lib/graph/bfs.hpp
layout: document
title: BFS
---
