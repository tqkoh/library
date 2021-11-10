---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Dijkstra
    links: []
  bundledCode: "#line 2 \"lib/graph/dijkstra.hpp\"\nstruct status{\n\tlint dist;\n\
    \tstatus(lint n){\n\t\tif(!n)dist = 0; //initial\n\t\telse dist = linf; //infinity\n\
    \t}\n};\nconstexpr bool operator<(const status& lhs, const status& rhs){\n\treturn\
    \ lhs.dist<rhs.dist;\n}\nstatus operator+(status cur, length cost){\n\tcur.dist\
    \ += cost;\n\treturn cur;\n}\n\npair<vector<status>, vector<int>> dijkstra(Graph\
    \ g, int s, vector<length>&cost){\n\tvector<int> prv(g.size());\n\tvector<status>\
    \ d(g.size(), linf);\n\tusing cont = pair<status, int>;\n\tpriority_queue<cont,\
    \ vector<cont>, greater<cont> > q;\n\n\td[s] = 0; q.push({ 0,s });\n\twhile(q.size()){\n\
    \t\tstatus cd = q.top().first;\n\t\tint cv = q.top().second;\n\t\tq.pop();\n\t\
    \tif(d[cv]<cd)continue;\n\t\tfor(edge& e:g[cv])if(cd+cost[e.id]<d[e.to]){\n\t\t\
    \td[e.to] = cd+cost[e.id];\n\t\t\tprv[e.to] = cv;\n\t\t\tq.push({ d[e.to],e.to\
    \ });\n\t\t}\n\t}\n\treturn { d,prv };\n}\n\n/*\n* @title Dijkstra\n*/\n"
  code: "#pragma once\nstruct status{\n\tlint dist;\n\tstatus(lint n){\n\t\tif(!n)dist\
    \ = 0; //initial\n\t\telse dist = linf; //infinity\n\t}\n};\nconstexpr bool operator<(const\
    \ status& lhs, const status& rhs){\n\treturn lhs.dist<rhs.dist;\n}\nstatus operator+(status\
    \ cur, length cost){\n\tcur.dist += cost;\n\treturn cur;\n}\n\npair<vector<status>,\
    \ vector<int>> dijkstra(Graph g, int s, vector<length>&cost){\n\tvector<int> prv(g.size());\n\
    \tvector<status> d(g.size(), linf);\n\tusing cont = pair<status, int>;\n\tpriority_queue<cont,\
    \ vector<cont>, greater<cont> > q;\n\n\td[s] = 0; q.push({ 0,s });\n\twhile(q.size()){\n\
    \t\tstatus cd = q.top().first;\n\t\tint cv = q.top().second;\n\t\tq.pop();\n\t\
    \tif(d[cv]<cd)continue;\n\t\tfor(edge& e:g[cv])if(cd+cost[e.id]<d[e.to]){\n\t\t\
    \td[e.to] = cd+cost[e.id];\n\t\t\tprv[e.to] = cv;\n\t\t\tq.push({ d[e.to],e.to\
    \ });\n\t\t}\n\t}\n\treturn { d,prv };\n}\n\n/*\n* @title Dijkstra\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-11-09 20:40:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.test.cpp
documentation_of: lib/graph/dijkstra.hpp
layout: document
title: Dijkstra
---

## 説明
- 負辺のない g: Graph に対して、(頂点 s: int から各頂点への最短パスの長さ: vector<length>, 前の頂点: vector<int>)を求める

## 時間計算量
- O(E log V)
